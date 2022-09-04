#!/bin/bash

# base 64 username and password
cc=$(cat <<EOT
ehlo example.com
AUTH LOGIN
ZmlsaXBAZXhhbXBsZS5jb20=
VGVzdHBhc3MxMjM=
mail from:<filip@example.com>
rcpt to:<filip@example2.com>
data
From: filip@example.com
Subject: test mail

this is a test
.

EOT
)

i=0
while [ $i -lt 30 ]; do
  echo $cc | nc 127.0.0.1 25
  #echo -e "Subject:test mail \n\n test321\n" | sendmail filip@example2.com
  i=$((i+1))
done
