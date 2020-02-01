import re
import rstr

inp=input("Unesite sifru kojoj zelite da proverite kompleknost:\n")
string=r'^(?=.*[A-Z])(?=.*[a-z])(?=.*\d)(?=.*[\W_]).{8,20}$'
RegexPr = re.compile(string)
mo = RegexPr.search(inp)
if mo != None:
	print("Sifra '",inp,"' je dovoljno kompleksna",sep="")
else:
	print("Sifra '",inp,"' je nedovoljno kompleksna, primer kompleksne sifre:",sep="")
	print(rstr.xeger(string))
