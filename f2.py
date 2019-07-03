import os
import string
import shutil
import re

#Open the file
f = open("myfile.txt","r")

#Get content and modify it
text2 = f.read()
#text1 = text1.replace("\d ",",")

text3 = ""
i = 0
j = 0

# for line in text1:
    # if line.isspace():
        # i = i+1;
        # if(i % 3 == 0):
            # line = line + '\n'
    # text2 = text2 + line


for line in text2.splitlines():
	line = re.sub('\s+',', ', line, flags = re.M)
	line = '{' + line + '},'
	text3 = text3 + line + '\\' + '\n'

text3 = text3 + '}}' + '\\'

f = open("myfile.txt","w")
f.write(text3)

#Close the file
f.close()

