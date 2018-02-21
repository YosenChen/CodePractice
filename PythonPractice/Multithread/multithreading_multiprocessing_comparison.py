# View more python learning tutorial on my Youtube and Youku channel!!!

# Youtube video tutorial: https://www.youtube.com/channel/UCdyjiB5H8Pu7aDTNVXTTpcg
# Youku video tutorial: http://i.youku.com/pythontutorial

import multiprocessing as mp
import threading as td
import time

def job(q):
    res = 0
    for i in range(1000000):
        res += i+i**2+i**3
    q.put(res) # queue

def multicore():
    q = mp.Queue()
    p1 = mp.Process(target=job, args=(q,))
    p2 = mp.Process(target=job, args=(q,))
    p1.start()
    p2.start()
    p1.join()
    p2.join()
    res1 = q.get()
    res2 = q.get()
    print('multicore:' , res1+res2)

def normal():
    res = 0
    for _ in range(2):
        for i in range(1000000):
            res += i+i**2+i**3
    print('normal:', res)

def multithread():
    q = mp.Queue()
    t1 = td.Thread(target=job, args=(q,))
    t2 = td.Thread(target=job, args=(q,))
    t1.start()
    t2.start()
    t1.join()
    t2.join()
    res1 = q.get()
    res2 = q.get()
    print('multithread:', res1+res2)

if __name__ == '__main__':
    st = time.time()
    normal()
    st1= time.time()
    print('normal time:', st1 - st)
    multithread()
    st2 = time.time()
    print('multithread time:', st2 - st1)
    multicore()
    print('multicore time:', time.time()-st2)



"""

idfs@idfs-K42Jr:~/Dropbox/ProgrammingPractice/PythonPractice/Multithread$ python multithreading_multiprocessing_comparison.py 
('normal:', 499999666667166666000000L)
('normal time:', 5.777315139770508)
('multithread:', 499999666667166666000000L)
('multithread time:', 6.281231880187988)
('multicore:', 499999666667166666000000L)
('multicore time:', 3.3822200298309326)

https://docs.python.org/2/library/multiprocessing.html
multiprocessing is a package that supports spawning processes 
using an API similar to the threading module. 
The multiprocessing package offers both local and remote concurrency, 
effectively side-stepping the Global Interpreter Lock by using subprocesses instead of threads. 
Due to this, 
the multiprocessing module allows the programmer to fully leverage multiple processors 
on a given machine.

"""