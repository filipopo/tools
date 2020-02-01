import random
import time

try:
	with open("art.txt") as art:
		lines=art.readlines()
		min=10**(len(lines[0])//20)
		max=10*min-1

	for i in range(0,len(lines),1):
		lines[i]=lines[i].split('\n')[0]
		if not __debug__:
			lines[i]=str(random.randint(min,max))+lines[i]+str(random.randint(min,max))
	while(1):
		for line in lines:
			if __debug__:
				print(random.randint(min,max),line,random.randint(min,max),sep='')
			else:
				print(line)
			time.sleep(0.05)
except FileNotFoundError:
	print("You need to have an art.txt file with some ascii art in the same folder :)")
	time.sleep(2)
except KeyboardInterrupt:
	pass
