import sys
import threading as td
import time

print(sys.version)

def job1(str, b):
    for i in range(b):
        print (str)
        time.sleep(1)


if __name__ == '__main__':
    th1 = td.Thread(target=job1, args=('hello', 10))
    th2 = td.Thread(target=job1, args=('yes', 10))
    th1.start()
    th2.start()
    th1.join()
    th2.join()



"""

idfs@idfs-K42Jr:~/Dropbox/ProgrammingPractice/PythonPractice/Multithread$ python ex1.py 
2.7.11+ (default, Apr 17 2016, 14:00:29) 
[GCC 5.3.1 20160413]
hello
yes
yes
hello
yes
hello
yes
hello
yes
hello
hello
yes
hello
yes
hello
yes
hello
yes
hello
yes


"""



