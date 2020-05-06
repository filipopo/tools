#!/usr/bin/python
from sys import argv
from re import compile
from os.path import splitext

with open(argv[1]) as map:
	lines = map.readlines()

switcher = {
	'.t3d': r'(Texture[ =])[\w.]+',
	'.vmf': r'("material" ").*(")',
	'.map': r'(\(.*\) )[\w/]+'
}	

name, ext = splitext(argv[1])

try:
	syntax = switcher[ext]
except KeyError:
	print('Unsupported extension')

def repl(x):                        
	res = x.group(1) + argv[2]
	if len(x.groups()) > 1:
		res += x.group(2)
	
	return res
	
with open(name + '-edit' + ext, 'w') as res:
	pr = compile(syntax)
	for line in lines:
		text = pr.sub(repl, line)
		res.write(text)
