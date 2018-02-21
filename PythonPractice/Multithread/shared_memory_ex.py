# ref
# https://docs.python.org/2/library/multiprocessing.html

from multiprocessing import Process, Value, Array
import sys

def acc_shared_mem(v):
    # v: the shared Value
    for i in range(1, 11):
        with v.get_lock():
            v.value += i

def acc_normal(v):
    # v: a normal variable (list)
    for i in range(1, 11):
        v[0] += i

if __name__ == '__main__':
    v1 = Value('i', 0)
    v2 = [0]

    num_pr = int(sys.argv[1])
    prArr1 = [Process(target=acc_shared_mem, args=(v1,)) for i in range(num_pr)]
    for ele in prArr1:
        ele.start()
    for ele in prArr1:
        ele.join()

    print "v1 = %d" % v1.value

    prArr2 = [Process(target=acc_normal, args=(v2,)) for i in range(num_pr)]
    for ele in prArr2:
        ele.start()
    for ele in prArr2:
        ele.join()

    print "multiprocessing v2 = %d" % v2[0]

    acc_normal(v2)

    print "direct call v2 = %d" % v2[0]



"""

https://docs.python.org/2/library/multiprocessing.html#multiprocessing.Lock
A recursive lock must be released by the process or thread that acquired it. 
Once a process or thread has acquired a recursive lock, 
the same process or thread may acquire it again without blocking; 
that process or thread must release it once for each time it has been acquired.

https://docs.python.org/2/library/multiprocessing.html#multiprocessing.Value
multiprocessing.Value(typecode_or_type, *args[, lock])
Operations like += which involve a read and write are not atomic. 
So if, for instance, you want to atomically increment a shared value 
it is insufficient to just do:
counter.value += 1

Assuming the associated lock is recursive (which it is by default) you can instead do:
with counter.get_lock():
    counter.value += 1


without     with v.get_lock():
    idfs@idfs-K42Jr:~/Dropbox/ProgrammingPractice/PythonPractice/Multithread$ python shared_memory_ex.py 100
    v1 = 5114
    multiprocessing v2 = 0
    direct call v2 = 55

with        with v.get_lock():
    idfs@idfs-K42Jr:~/Dropbox/ProgrammingPractice/PythonPractice/Multithread$ python shared_memory_ex.py 100
    v1 = 5500
    multiprocessing v2 = 0
    direct call v2 = 55

"""