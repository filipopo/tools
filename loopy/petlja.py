#!/usr/bin/python
from sys import argv, exit
from random import randint
from time import sleep
from asciimatics.screen import ManagedScreen
from asciimatics.scene import Scene
from asciimatics.effects import Print, Scroll
from asciimatics.renderers import ImageFile, ColourImageFile

try:
	mode=argv[1]
except IndexError:
	try:
		with open("art.txt") as art:
			mode="0"
	except FileNotFoundError:
		try:
			with open("art.jpg") as art:
				with ManagedScreen() as screen:
					if screen.colours < 256:
						mode="1"
					else:
						mode="2"
		except FileNotFoundError:
			print("You need to have an art text or image file in the same folder :)")
			sleep(2)
			exit()

def try_kb(func):
	def inner(screen):
		try:
			func(screen)
		except KeyboardInterrupt:
			screen.clear()
	return ManagedScreen(inner)

@try_kb
def zero(screen=None):
	with open("art.txt") as art:
		lines=art.readlines()
		pic=len(lines[0])//20
		min=10**pic
		max=10*min-1

	for i in range(0,len(lines)):
		lines[i]=lines[i].split('\n')[0]

	pic+=1
	pic_end=len(lines[0])+pic
	line=0

	while 1:
		pos=0
		for i in range(line,screen.height+line):
			screen.print_at(str(randint(min,max)),0,pos,2)
			screen.print_at(lines[i%len(lines)],pic,pos,i%7+1)
			screen.print_at(str(randint(min,max)),pic_end,pos,2)
			#screen.print_at(" "+str(i-line)+" "+str(i)+" "+str(line),pic_end+pic,pos)
			pos+=1
		screen.refresh()
		#sleep(0.05)
		line=(line+1)%len(lines)

@try_kb
def one(screen=None):
	scenes = []
	effects = [
		Print(screen,
			ImageFile("art.jpg", screen.height, colours=screen.colours),
			screen.height,
			pic),
		Scroll(screen, 2)
	]
	scenes.append(Scene(effects))
	screen.play(scenes)

@try_kb
def two(screen=None):
	scenes = []
	effects = [
		Print(screen,
			ColourImageFile(screen, "art.jpg", screen.height, uni=screen.unicode_aware, dither=screen.unicode_aware),
			screen.height),
		Scroll(screen, 2)
	]
	scenes.append(Scene(effects))
	screen.play(scenes)

@try_kb
def three(screen=None):
	pass
	
switcher = {
	"0": zero,
	"1": one,
	"2": two,
	"3": three
}

try:
	switcher[mode]()
except KeyError:
	print("Valid value please")
