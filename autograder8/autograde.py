import os
import re

# This is an autograder for assignment 7 (the first one I made)
filenames = os.popen('ls -I correctMain.c').read()
names = re.findall(r'\w+\.c', filenames)
print(names)
keyout = os.popen('./key').read()
for name in names:
    print('-------------------------------------------------------')
    print(name)
    f = open(name, "r")
    contents = f.read()
    f.close()
    contents = contents.replace('main', 'oldmain')

    n = re.search(r'char name\[30\] = "(.*)";', contents)
    print(n.group(1))

    correctMain = open("correctMain.c", "r")
    contents = contents + correctMain.read()

    fin = open('mod' + name, "wt")
    fin.write(contents)
    fin.close()


    try:
        compile = os.popen('gcc -w -o ' + name[:-2] + ' mod' + name).read()

        os.system('rm mod' + name)
        if len(compile) == 0:
            output = os.popen('./' + name[:-2]).read()

            if output == keyout:
                print("100%")
            else:
                print(output)

            # print(output)
            os.system('rm ' + name[:-2])

        else:
            #print (compile)
            pass
    except:
        print("compilation error")
