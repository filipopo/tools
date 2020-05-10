#!/usr/bin/python
from imghdr import what
from random import randint
from time import sleep
from asciimatics.screen import ManagedScreen
from asciimatics.scene import Scene
from asciimatics.effects import Print, Scroll
from asciimatics.renderers import ImageFile, ColourImageFile

class loopy:
	txts = []
	imgs = []

	def __init__(self, files = []):
		for file in files:
			if what(file): # Image
				self.imgs.append(file)
			else:
				self.txts.append(file)

	def try_kb(func):
		def inner(self, **kwargs):
			try:
				func(self, **kwargs)
			except KeyboardInterrupt:
				pass #screen.clear()
		return ManagedScreen(inner)

	@try_kb
	def text(self, file = None, screen = None):
		if file == None:
			file = self.txts[0]

		with open(file) as art:
			lines = art.readlines()
			pic = len(lines[0]) // 20
			min=10 ** pic
			max=10 * min - 1

		for i in range(0, len(lines)):
			lines[i] = lines[i].split('\n')[0]

		pic += 1
		pic_end = len(lines[0]) + pic
		line = 0

		while 1:
			pos = 0
			for i in range(line, screen.height + line):
				screen.print_at(str(randint(min, max)), 0, pos, 2)
				screen.print_at(lines[i % len(lines)], pic, pos, i%7 + 1)
				screen.print_at(str(randint(min, max)), pic_end, pos, 2)
				#screen.print_at(' ' + str(i - line) + ' ' + str(i) + ' ' + str(line), pic_end + pic, pos)
				pos += 1
			screen.refresh()
			sleep(0.05)
			line = (line + 1) % len(lines)

	@try_kb
	def gray(self, file = None, screen = None):
		if file == None:
			file = self.imgs[0]

		scenes = []
		effects = [
			Print(screen,
				ImageFile(file, screen.height, colours = screen.colours),
				screen.height,
				pic),
			Scroll(screen, 2)
		]
		scenes.append(Scene(effects))
		screen.play(scenes)

	@try_kb
	def color(self, file = None, screen = None):
		if file == None:
			file = self.imgs[0]

		scenes = []
		effects = [
			Print(screen,
				ColourImageFile(screen, file, screen.height, uni = screen.unicode_aware, dither = screen.unicode_aware),
				screen.height),
			Scroll(screen, 2)
		]
		scenes.append(Scene(effects))
		screen.play(scenes)

if __name__ == '__main__':
	from sys import argv, exit

	try:
		file = argv[1]
	except IndexError:
		file = 'art.txt'

	try:
		mode = argv[2]
	except IndexError:
		try:
			with open(file) as art:
				mode = 'text'
		except FileNotFoundError:
			print('You need to have the ' + file + ' file in the same folder :)')
			sleep(2)
			exit()

	loop = loopy([file])
	try:
		getattr(loop, mode)()
	except KeyError:
		print('Valid mode please')
