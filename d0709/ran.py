#coding=utf-8
import random
f = open('in', 'w')
n = 5000
# f.write('%s\n'%n)

for i in xrange(n):
    f.write(chr(random.randint(0, 25) + ord('a')))

f.close()