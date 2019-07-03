import os
import string
import shutil
import re

#Open the file
f = open("myfile.txt","r")

#Get content and modify it
text1 = f.read()
#text1 = text1.replace(","," ")

for line in text1
    line = re.sub('')

#Clear the content
#f.seek(0)
#f.truncate()


f = open("myfile.txt","w")

#Write with new content
f.write(text1)

#Close the file
f.close()

#Copy file to other destination
#shutil.copy2("f.txt", dst)
#print (f.read(0))

for line in fileinput.input():
    line = re.sub('foo','bar', line.rstrip())
    print(line)