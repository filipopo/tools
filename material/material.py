#!/usr/bin/python
# Replaces materials in maps
# Basic usage:
# python material.py name.ext material
# Advanced usage:
# python material.py name.ext oldmat1,oldmat2 newmat1,newmat2
# python material.py name.ext oldmat1,oldmat. newmat1,newmat2 -r
# Output file:
# name-edit.ext

from sys import argv
from os.path import splitext
from re import compile

# Defines what is a material with regex
switcher = {
	'.t3d': r'(Texture[ =])([\w.]+)',
	'.vmf': '("material" ")(.*)(")',
	'.map': r'(\(.*\) )([\w/]+)',
	'.vmap': '(materials/)(.*)(.vmat)'
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
		if args > 4 and argv[4] == '-r':
			for each in src:
				reg = compile(each)
				# Regex matches the material with the given patterns
				if reg.search(x.group(2)):
					# Finds the material to replace the regex matched one with
					index = [i for i, item in enumerate(src) if reg.search(item)]
					res += dest[index[0]]

					break
		else:
			if x.group(2) in src:
				res += dest[src.index(x.group(2))]

		# If it doesn't match return it the way it was
		if len(res) == len(x.group(1)):
			return x.group(0)
	else:
		res += argv[2]

	# Adds '"' at the end
	if len(x.groups()) > 2:
		res += x.group(3)

	return res

# Reads the map line by line and makes the edited file
with open(argv[1]) as map_f:
	with open(name + '-edit' + ext, 'w') as res:
		pr = compile(syntax)
		for line in map_f:
			text = pr.sub(repl, line)
			res.write(text)
