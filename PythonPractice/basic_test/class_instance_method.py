def assign_static():
    print "assign_static!"
    return 1

class TestModule1:
    var1 = assign_static()

    @classmethod
    def incrVar1_clsMethod(cls):
        cls.var1 += 1
        return cls.var1

    def incrVar1_insMethod(self):
        self.var1 += 1
        return self.var1

if __name__ == "__main__":
    print "before any call to TestModule1."
    print "ClassMethod: ", TestModule1.incrVar1_clsMethod()
    
    print "before creating TestModule1 object."

    tm1 = TestModule1()
    print "tm1 InstanceMethod: ", tm1.incrVar1_insMethod()

    tm2 = TestModule1()
    print "tm2 InstanceMethod: ", tm2.incrVar1_insMethod()

    tm3 = TestModule1()
    print "tm3 InstanceMethod: ", tm3.incrVar1_insMethod()

    print "tm2 InstanceMethod: ", tm2.incrVar1_insMethod()

    print "tm1 InstanceMethod: ", tm1.incrVar1_insMethod()

    print "ClassMethod: ", TestModule1.incrVar1_clsMethod()

    print "tm1 InstanceMethod: ", tm1.incrVar1_insMethod()

"""
idfs@idfs-K42Jr:~/Dropbox/ProgrammingPractice/PythonPractice/basic_test$ python class_instance_method.py 
assign_static!
before any call to TestModule1.
ClassMethod:  2
before creating TestModule1 object.
tm1 InstanceMethod:  3
tm2 InstanceMethod:  3
tm3 InstanceMethod:  3
tm2 InstanceMethod:  4
tm1 InstanceMethod:  4
ClassMethod:  3
tm1 InstanceMethod:  5


idfs@idfs-K42Jr:~/Dropbox/ProgrammingPractice/PythonPractice/basic_test$ python
Python 2.7.11+ (default, Apr 17 2016, 14:00:29) 
[GCC 5.3.1 20160413] on linux2
Type "help", "copyright", "credits" or "license" for more information.
>>> from class_instance_method import *
assign_static!
>>> TestModule1.incrVar1_clsMethod()
2
>>> TestModule1.incrVar1_clsMethod()
3
>>> tm1 = TestModule1()
>>> tm1.incrVar1_insMethod()
4
>>> tm1.incrVar1_insMethod()
5
>>> tm2 = TestModule1()
>>> tm2.incrVar1_insMethod()
4
>>> TestModule1.incrVar1_clsMethod()
4
>>> tm3 = TestModule1()
>>> tm3.incrVar1_insMethod()
5
>>> TestModule1.incrVar1_clsMethod()
5
>>> TestModule1.incrVar1_clsMethod()
6
>>> TestModule1.incrVar1_clsMethod()
7
>>> tm2.incrVar1_insMethod()
5




"""
"""

Conclusion:
    - var1 works like a class static member variable
      its initialization occurs at very begining
      EX:
        when you import this file first time
        before any call to this class
    - the ClassMethods are using this static member variable
      while the InstanceMethods are using its copies, 
    - when a class object is created, var1 will be copied to this object with its current value
      then all the following operations of this object will only affect this copy (its own var1)
      each class object has its own independent copy of var1
      then if we do more ClassMethods, it will only affect the following new created objects
    - you can view in this way: (compared with C++)
      ClassMethods are like the static class member functions, you can use them like singleton pattern
      InstanceMethods are like normal class member functions, only can be used when the object is created
      difference from C++
        static members are not shared for all objects, every object has its own copy (copy at different timing)


"""