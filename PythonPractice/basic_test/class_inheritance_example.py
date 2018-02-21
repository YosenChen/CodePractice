"""
       A
      / \
     B  C
      \ /\
       E  D
        \/
        F
"""
class A(object): pass

class B(A): pass

class C(A): pass

class E(B, C): pass

class D(C): pass

class F(E, D): pass

if __name__ == "__main__":
    f = F()
    print f.__class__        # <class '__main__.F'>
    print F.__bases__        # (<class '__main__.E'>, <class '__main__.D'>)
    print F.__name__         # F

    print F.__mro__          # (<class '__main__.F'>, <class '__main__.E'>, 
                             # <class '__main__.B'>, <class '__main__.D'>, 
                             # <class '__main__.C'>, <class '__main__.A'>, <type 'object'>)

    print F.mro()            # [<class '__main__.F'>, <class '__main__.E'>, 
                             # <class '__main__.B'>, <class '__main__.D'>, 
                             # <class '__main__.C'>, <class '__main__.A'>, <type 'object'>]

    print F.__subclasses__() # []
    print C.__subclasses__() # [<class '__main__.E'>, <class '__main__.D'>]


"""
https://docs.python.org/2/library/stdtypes.html#class.__mro__
"""

"""
You use == when comparing values and is when comparing identities.



idfs@idfs-K42Jr:~/Dropbox/ProgrammingPractice/PythonPractice/basic_test$ python
Python 2.7.11+ (default, Apr 17 2016, 14:00:29) 
[GCC 5.3.1 20160413] on linux2
Type "help", "copyright", "credits" or "license" for more information.
>>> from class_inheritance_example import *
>>> f = F()
>>> f.__class__ is F
True
>>> f.__class__ == F
True
>>> F.__bases__[0]
<class 'class_inheritance_example.E'>
>>> F.__bases__[1]
<class 'class_inheritance_example.D'>
>>> F.__bases__[0] is E
True
>>> F.__bases__[1] is D
True
>>> F.__bases__[1] is E
False
>>> F.__name__ == "F"
True
>>> F.__name__ == "E"
False
>>> F.__mro__[0]
<class 'class_inheritance_example.F'>
>>> F.__mro__[0] == 'F'
False
>>> F.__mro__[0] == "F"
False
>>> F.__mro__[0] is "F"
False
>>> F in F.mro()
True
>>> E in F.mro()
True
>>> object in F.mro()
True
>>> len(F.__subclasses__())
0
>>> len(C.__subclasses__())
2
>>> E in C.__subclasses__()
True
>>> A in C.__subclasses__()
False



"""