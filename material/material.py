#!/usr/bin/python
# Replaces materials in maps
# Basic usage:
# python material.py name.ext material
# Advanced usage:
# python material.py name.ext oldmat1,oldmat2 newmat1,newmat2
# Output file:
# name-edit.ext

from sys import argv
from os.path import splitext
from re import compile

# Reads the map line by line
with open(argv[1]) as map:
	lines = map.readlines()

# Defines what is a material with regex
switcher = {
	'.t3d': r'(Texture[ =])([\w.]+)',
	'.vmf': r'("material" ")(.*)(")',
	'.map': r'(\(.*\) )([\w/]+)'
}

# Separates the name and extension
name, ext = splitext(argv[1])

# Sees if a file with a supported format is open
try:
	syntax = switcher[ext]
except KeyError:
	print('Unsupported extension')

# If we're not replacing with only one texture makes lists
args = len(argv)
if args > 3:
	src = argv[2].split(',')
	dest = argv[3].split(',')

# Decides what to do with each material
def repl(x):
	# Starts from '"material" "', works it's way up
	res = x.group(1)

	# Adds the actual material
	if args > 3:
		if x.group(2) in src:
			res += dest[src.index(x.group(2))]
		else:
			# Returns it the way it was
			return x.group(0)
	else:
		res += argv[2]

	# Adds '"' at the end
	if len(x.groups()) > 2:
		res += x.group(3)

	return res

# Makes the edited file
with open(name + '-edit' + ext, 'w') as res:
	pr = compile(syntax)
	for line in lines:
		text = pr.sub(repl, line)
		res.write(text)
