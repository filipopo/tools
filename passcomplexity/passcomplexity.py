import re
inp=input("Unesite sifru kojoj zelite da proverite kompleknost:")
RegexPr = re.compile(r'^(?=.*[A-Z])(?=.*[a-z])(?=.*\d)(?=.*[\W_]).{8,20}$')
mo = RegexPr.search(inp)
if mo != None:
        print("Sifra '",inp,"' je dovoljno kompleksna",sep="")
else:
    print("Sifra '",inp,"' je nedovoljno kompleksna",sep="")
