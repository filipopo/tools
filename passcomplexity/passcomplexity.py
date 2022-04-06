# Tests password complexity and generates complex passwords, a complex password in this program is defined as having
# a length of at least 8 characters consisting of at least one of the following:
# An uppercase letter, a lowercase letter, a number and a special character
import re
import secrets
import string
import rstr

def is_complex(password):
  if len(password) < 8:
    return 0

  regex = r"^(?=\S*[A-Z])(?=\S*[a-z])(?=\S*\d)(?=\S*[{}])\S+$".format(string.punctuation)
  mo = re.search(regex, password)

  if mo:
    return 1
  else:
    return 0

def gen_password():
  rs = rstr.Rstr(secrets.SystemRandom())
  incl = secrets.choice(string.ascii_uppercase) + secrets.choice(string.ascii_lowercase) + secrets.choice(string.digits) + secrets.choice(string.punctuation)
  return rs.nonwhitespace(8, 30, include = incl)

if __name__ == "__main__":
  try:
    inp = input("Enter a password to check it's complexity:\n")
    
    if is_complex(inp):
      print("'", inp, "' is a complex password", sep = "")
    else:
      print("'", inp, "' isn't a complex password, example of a complex password:\n", gen_password(), sep = "")
  except KeyboardInterrupt:
    pass
