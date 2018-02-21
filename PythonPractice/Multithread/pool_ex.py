# ref
# https://www.youtube.com/watch?v=w7SG9hhhwvI&list=PLXO45tsB95cJgYDaJbwhg629-Il5cfkhe&index=5

import multiprocessing as mp

def job(x):
    return x*x

def multicore():
    pool = mp.Pool()
    num = 10
    res = pool.map(job, range(num))
    print res
    res = pool.apply_async(job, (2,))
    print res.get()
    multi_res = [pool.apply_async(job, (i,)) for i in range(num)]
    print [res.get() for res in multi_res]
    multi_res2 = [pool.apply_async(job, (i,)) for i in range(num)]
    print [multi_res2[i].get() for i in range(len(multi_res2))]


if __name__ == '__main__':
    multicore()


"""

idfs@idfs-K42Jr:~/Dropbox/ProgrammingPractice/PythonPractice/Multithread$ python pool_ex.py 
[0, 1, 4, 9, 16, 25, 36, 49, 64, 81]
4
[0, 1, 4, 9, 16, 25, 36, 49, 64, 81]
[0, 1, 4, 9, 16, 25, 36, 49, 64, 81]


"""


