import os, re
from subprocess import check_output as px
import time


r = re.compile("real.*(\d+\.\d\d\d)s")
create = "./tg.sh foo {} {}"

def mean(ls):
	return sum(ls)/len(ls)

def run_test(files=1, lines=1, threads=1, times=10):
	os.system("rm -f idir/*")
	os.system("rm -f odir/*")
	os.system(create.format(files, lines))
	ret = []	

	for i in range(times):
		start = time.clock()
		px(["./sorter","-i","idir","-o","odir","-t",str(threads)], universal_newlines=True)
		end = time.clock()
		ret.append(end-start)

	return ret


for f in [1000, 10000, 10000]:
	for l in [1000, 10000, 10000]:
		for t in [1,2,4,8,16]:
			print("Running test with {} files, {} lines, and {} threads:".format(f,l,t))
			ls = run_test(files=f, lines=l, threads=t)
			for i in range(len(ls)):
				print("{}: {}".format(i,ls[i]))
			print("Average: {}\n".format(mean(ls)))

