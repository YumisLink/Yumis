dsize = 10
prefix = "apexis"
import os
from subprocess import run
import datetime

os.chdir(prefix + "/")
for i in range(dsize):
    os.rename(prefix + str(i) + ".in", prefix + ".in")
    st = datetime.datetime.now()
    run(["./" + prefix])
    elapsed = datetime.datetime.now() - st
    print("Data No.", i, (elapsed.microseconds / 1000000.0), 's')
    os.rename(prefix + ".in", prefix + str(i) + ".in")
    os.rename(prefix + ".out", prefix + str(i) + ".out")