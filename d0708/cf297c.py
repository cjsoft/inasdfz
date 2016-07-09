#coding=utf-8

n = int(raw_input())
lst = map(int, raw_input().strip().split(' '))

lst = lst[:n]
print lst
size = n / 3
class data(object):
    def __init__(self, id, d):
        self.id = id
        self.d = d
    def __lt__(self, other):
        return d < other.d
    def __repr__(self):
        return '(%s: %s)'%(self.id, self.d)
for i in xrange(n):
    lst[i] = data(i + 1, lst[i])
print lst
# for i in xrange(size):
