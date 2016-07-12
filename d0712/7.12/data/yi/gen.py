from random import *
import os

def gen(N,id):
	print "Generating testcase #%d" %(id)
	f=open("yi%d.in"%(id),"w")
	n=randint(int(0.99*N),N)
	s="1"
	for i in xrange(1,n):
		s+="01"[randint(0,1)]
	print >>f,s
	f.close()
	os.system("time ./yi < yi%d.in > yi%d.out"%(id,id))

def Gen(id):
	if id in [0,1]: gen(1000,id)
	if id in [2,3]: gen(10000,id)
	if id in range(4,11): gen(3*10**5,id)

for id in xrange(0,11):
	Gen(id)
