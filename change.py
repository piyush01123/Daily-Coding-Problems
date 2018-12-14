import os
import glob

for i in range(1, 15):
    txt = open('%s/problem.md' %i, 'r').read()
    g = open('%s/README.md' %i, 'w')
    g.write(txt)
    g.close()
