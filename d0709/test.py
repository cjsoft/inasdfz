for i in xrange(4):
    for j in xrange(4):
        if (((i | j) ^ i) != 0):
	        print (j ^ i), ((i | j) ^ i)