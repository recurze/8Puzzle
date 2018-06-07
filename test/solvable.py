def solvable(s):
    r = 0
    for i in xrange(8):
        for j in xrange(i+1, 9):
            r += (s[i] != '0') and (s[j] != '0') and (s[i] > s[j])
    return ~r&1

with open('test/all.txt') as f:
    for line in f:
        line = line.strip('\n')
        if solvable(line):
            print line


