# ref:
# https://www.youtube.com/watch?v=_TNIlBlV5c0&list=PLXO45tsB95cJgYDaJbwhg629-Il5cfkhe&index=3
import sys
import multiprocessing as mp

def job1(q):
    # q: Queue
    res = 0
    for i in range(1, 11):
        res += i
    q.put(res)


if __name__ == '__main__':
    q = mp.Queue()
    prArr = [] # init a process array
    num_pr = int(sys.argv[1]); # parse a numeric string to int
    # http://stackoverflow.com/questions/379906/parse-string-to-float-or-int
    # http://www.tutorialspoint.com/python/python_command_line_arguments.htm

    for i in range(num_pr):
        prArr.append(mp.Process(target=job1, args=(q,)))
    print ("init done")
    """
        you can't assign to a list element that doesn't already exist.
        One solution is to use the append method to add elements one by one
    """
    
    for i in range(num_pr):
        prArr[i].start()
    print ("all processers start")
    
    for i in range(num_pr):
        prArr[i].join()
    print ("all processers terminate")

    res = 0
    for i in range(num_pr):
        res += q.get()
    print "final result: %s" % res

"""

idfs@idfs-K42Jr:~/Dropbox/ProgrammingPractice/PythonPractice/Multithread$ python ex2.py 2
init done
all processers start
all processers terminate
final result: 110
idfs@idfs-K42Jr:~/Dropbox/ProgrammingPractice/PythonPractice/Multithread$ python ex2.py 100
init done
all processers start
all processers terminate
final result: 5500
idfs@idfs-K42Jr:~/Dropbox/ProgrammingPractice/PythonPractice/Multithread$ python ex2.py 1000
init done
all processers start
all processers terminate
final result: 55000


http://stackoverflow.com/questions/18428750/kill-python-interpeter-in-linux-from-the-terminal
idfs@idfs-K42Jr:~/Dropbox/ProgrammingPractice/PythonPractice/Multithread$ killall -9 python
    to kill all runing python processes

"""
