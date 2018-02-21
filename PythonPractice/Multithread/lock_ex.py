# ref
# https://docs.python.org/2/library/multiprocessing.html

from multiprocessing import Process, Lock
import sys

def print_w_lock(l, i):
    l.acquire()
    for j in range(4):
        print [i,j]
    l.release()

def print_wo_lock(i):
    for j in range(4):
        print [i,j]

if __name__ == '__main__':
    lock = Lock()
    max_num = int(sys.argv[1])

    print "---print_w_lock---"
    prArr = [Process(target=print_w_lock, args=(lock, num)) for num in range(max_num)]
    for ele in prArr: # for ele in iterable
        ele.start()
    for ele in prArr:
        ele.join()

    print "---print_wo_lock---"
    for num in range(max_num):
        Process(target=print_wo_lock, args=(num,)).start()

"""

From the execution result, we can see that:
- with lock, the printed messages of each processor are contiguous
  even though sometimes the printing order among all processors 
  does not strictly follow the order of for-loop start
- without lock, the printed messages of the processors might interleave (print in between).

idfs@idfs-K42Jr:~/Dropbox/ProgrammingPractice/PythonPractice/Multithread$ python lock_ex.py 5
---print_w_lock---
[0, 0]
[0, 1]
[0, 2]
[0, 3]
[1, 0]
[1, 1]
[1, 2]
[1, 3]
[2, 0]
[2, 1]
[2, 2]
[2, 3]
[3, 0]
[3, 1]
[3, 2]
[3, 3]
[4, 0]
[4, 1]
[4, 2]
[4, 3]
---print_wo_lock---
[2, 0]
[2, 1]
[2, 2]
[2, 3]
[0, 0]
[0, 1]
[0, 2]
[0, 3]
[1, 0]
[1, 1]
[3, 0]
[1, 2]
[3, 1]
[3, 2]
[1, 3]
[3, 3]
[4, 0]
[4, 1]
[4, 2]
[4, 3]


"""









