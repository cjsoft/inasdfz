#coding=utf-8
import os, sys

f = open('out', 'r')
p = f.read()
f.close()
lst = p.split('\n')
for i in lst:
    if i != '':
        f = open('toodifficult.out', 'w')
        f.write('1\n%s'%i)
        f.close()
        os.popen('checker.exe')
        f = open('toodifficult.in', 'r')
        s = f.read()
        f.close()
        sys.stdout.write(s)
        sys.stdout.flush()
