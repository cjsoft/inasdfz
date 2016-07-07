
#coding=utf-8
INF = 0xffff
import os, sys
for j in xrange(10, 20):

    cin = open('..\\task\\parallel\\parallel%d.in'%j, 'r')
    p = map(int, cin.readline().split(' '))
    # qin = map(int, cin.readline(INF).strip().split(' '))
    pcase = cin.readline(INF).split(' ')
    ilegal = cin.readline(INF)
    s1 = ''
    s2 = ''
    d = {'1': '0', '0': '1'}
    for i in ilegal:
        if (i in {'0', '1'}):
            s1 = s1 + d[i] + '?'
            s2 = s2 + '1'
    f = open('parallel%d.out'%j, 'w')
    f.write('%s\n%s'%(s1, s2))
    f.close()