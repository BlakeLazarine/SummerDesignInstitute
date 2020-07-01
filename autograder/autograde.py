import os

import re

name = "pointersanswers"
f = open(name + ".c", "r")
contents = f.read()
f.close()
contents = contents.replace('main', 'oldmain')


reg = r'abracadabra.*\n((.|\n|\r)*)\n.*alakazam'
explain = re.search(reg, contents)


correctMain = open("correctMain.c", "r")
contents = contents + correctMain.read()

fin = open(name + "done.c", "wt")
fin.write(contents)
fin.close()



compile = os.popen('gcc -w ' + name + 'done.c').read()
if len(compile) == 0:
    output = os.popen('./a.out').read()
    keyout = os.popen('./key').read()

    studentName = r'My Name is: .*'
    m = re.search(studentName, output)
    print(m.group(0))

    print("problem 1")
    split = 12
    valreg = r'value: (\d+), addr'
    printarrout = re.findall(valreg, output)
    printarroutkey = re.findall(valreg, keyout)
    print("printArr match" if printarrout == printarroutkey else "printArr Dont Match")
    memaddr = re.findall(r'value: \d+, addr: (.*)', output)
    prev_addr = int(memaddr[0], 16)
    for i in range(1, len(memaddr)):
        hex_int = int(memaddr[i], 16)
        if hex_int - prev_addr != 4 and i != split:
            print("not 4 at idx", i)
        prev_addr = hex_int

    print('')
    print("problem 2")
    swaps = re.findall(r'a: (\d+) b:(\d+)', output)
    swapskey = re.findall(r'a: (\d+) b:(\d+)', keyout)
    print("swaps match" if swaps == swapskey else "swaps dont match")

    print('')
    print('problems 3,4,5')
    errors = re.findall(r'error: .*', output)
    if len(errors) == 0:
        print('no errors')
    else:
        for e in errors:
            print(e)

    print("problem 5 explanation")
    print(explain.group(1))
    # print(output)

else:
    print (compile)
