import re

name = "name"
f = open(name + ".c", "r")
contents = f.read()
f.close()
contents = contents.replace('main', 'oldmain')

studentName = r'My Name is: .*'
m = re.search(studentName, contents)
print(m.group(0))

reg = r'abracadabra.*\n((.|\n|\r)*)\n.*alakazam'
m = re.search(reg, contents)
print(m.group(1))

correctMain = open("correctMain.c", "r")
contents = contents + correctMain.read()

fin = open(name + "done.c", "wt")
fin.write(contents)
fin.close()
