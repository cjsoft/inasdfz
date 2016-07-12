from random import *
import os

v=[0,4,6,8,840,900,960,95760,97020,98280,99960]


def gen(n,m,id):
	print "Generating testcase #%d" %(id)
	f=open("jian%d.in"%(id),"w")
	print >>f,n,m
	f.close()
	os.system("time ./jian < jian%d.in > jian%d.out"%(id,id))

def Gen(id):
	if id in [1]: gen(4,8,id)
	if id in [2,3]: gen(v[id],randint(1,10**6/v[id])*v[id],id)
	if id in [4,5,6]: gen(v[id],randint(1,10**18/v[id])*v[id],id)
	if id in [7,8,9,10]: gen(v[id],randint(1,10**18/v[id])*v[id],id)

for id in xrange(1,11):
	Gen(id)
