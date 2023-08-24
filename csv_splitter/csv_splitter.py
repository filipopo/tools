# Script to split csv into smaller parts which can be processed in other functions using StringIO

import os

def is_aws_env():
  return os.getenv('AWS_LAMBDA_FUNCTION_NAME') or os.getenv('AWS_EXECUTION_ENV')

if is_aws_env():
  import boto3

def csv_splitter(arr, n):
  res = []
  for i in range(1, len(arr), n):
    chunk = [arr[0]] + arr[i:i + n]
    chunk = '\n'.join(chunk)

    res.append(chunk)

  return res

def lambda_handler(event, context):
  ### Set defaults
  csv_input = event['input'] if event else 'input.csv'
  csv_split = int(os.getenv('csv_split', 10))

  if is_aws_env():
    bucket = os.getenv('bucket', 'examplebucket')
    bucket = boto3.resource('s3').Bucket(bucket)
    bucket.download_file(csv_input, f'/tmp/{csv_input}')
    csv_input = f'/tmp/{csv_input}'

  with open(csv_input) as file:
    csv_input = file.read().splitlines()

  csv_input = csv_splitter(csv_input, csv_split)

  print(csv_input)
  return csv_input

if not is_aws_env():
  # Runs the "main" function
  lambda_handler({}, {})
