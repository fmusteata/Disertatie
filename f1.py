import os
import string
import shutil
import re

#Open the file
f = open("myfile.txt","r")

#Get content and modify it
text1 = f.read()
#text1 = text1.replace("\d ",",")

text2 = ""
text3 = ""
i = 0
j = 0

for line in text1.splitlines():
    j = j + 1
    if(j%5 == 0 and (j != 0)):
        line = line + '\n'
    
    text3 = text3 + line + '\n'

text3 = '\n' + text3

for line in text3.splitlines():
	i = i + 1
	line = re.sub('\d\s+',',', line, flags = re.M)
	line = re.sub('\s+','{', line, flags = re.M)
	
	if(i % 6 == 2):
		line = '{' + line
	
	if (i < 6) and (i > 1):
		line = line + '},'
	elif (i>=6):
		if (i % 6 == 0):
			line = line + '}'
		else:	
			line = line + '},'

	text2 = text2 + line + '\\' + '\n'

text2 = text2 + '}}' + '\\'

f = open("myfile.txt","w")
f.write(text2)

#Close the file
f.close()

