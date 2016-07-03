#coding=utf-8
import os
import random
def gen():
    f = open('in', 'w')
    f.write('5000 %d %d %d %d\n'%(random.randint(1, 10000000), random.randint(1, 10000000), random.randint(1, 10000000), random.randint(1, 10000000)))
    f.close()
os.popen('g++ aria.cpp -oa')
os.popen('g++ experiment.cpp -ob')
id = 1
for i in xrange(100):
    gen()
    os.popen('a.exe < in > out')
    os.popen('b.exe < in > ans')
    if len(os.popen('diff ans out').read()) == 0:
        print 'Case %d passed'%i
    else:
        print 'Case %d failed'%i
        break