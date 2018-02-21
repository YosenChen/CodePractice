def assign_static():
    print "assign_static!"
    return 1


def assign_static2():
    print "assign_static2!"
    return 100

#  Note: super() only works for new-style classes.
class TestModule1(object):
    var1 = assign_static()

    @classmethod
    def incrVar1_clsMethod(cls, inc=1):
        cls.var1 += inc
        return cls.var1

    @classmethod
    def getVar1_clsMethod(cls):
        return cls.var1

    def incrVar1_insMethod(self, inc=1):
        self.var1 += inc
        return self.var1

    def getVar1_insMethod(self):
        return self.var1

    @classmethod
    def msg_cls(cls): return "clsYes"

    def msg_ins(self): return "insYes"


class TestModuleDerived(TestModule1):
    var2 = assign_static2()

    @classmethod
    def incrVar1By2_super_clsMethod(cls):
        #  super(TestModuleDerived, cls).var1 += 2 
        #  AttributeError: 'super' object has no attribute 'var1'
        super(TestModuleDerived, cls).incrVar1_clsMethod(2)
        return super(TestModuleDerived, cls).getVar1_clsMethod()
    
    def incrVar1By2_super_insMethod(self):
        #  super(TestModuleDerived, self).var1 += 2
        #  AttributeError: 'super' object has no attribute 'var1'
        super(TestModuleDerived, self).incrVar1_insMethod(2)
        return super(TestModuleDerived, self).getVar1_insMethod()

    @classmethod
    def incrVar1By2_clsMethod(cls):
        cls.var1 += 2
        return cls.var1

    def incrVar1By2_insMethod(self):
        self.var1 += 2
        return self.var1
 
    @classmethod
    def getVar1_values_clsMethod(cls):
        return [cls.var1, super(TestModuleDerived, cls).getVar1_clsMethod(), cls.getVar1_clsMethod()]

    def getVar1_values_insMethod(self):
        return [self.var1, super(TestModuleDerived, self).getVar1_insMethod(), self.getVar1_insMethod()]

    @classmethod
    def test_super_cls(cls):
        return [cls.msg_cls(), super(TestModuleDerived, cls).msg_cls()]

    def test_super_ins(self):
        return [self.msg_ins(), super(TestModuleDerived, self).msg_ins()]

    @classmethod
    def msg_cls(cls): return "clsHello"

    def msg_ins(self): return "insHello"



if __name__ == "__main__":
    print "classmethod of inherited class"
   
    print "TestModule1.incrVar1_clsMethod()                ", TestModule1.incrVar1_clsMethod()
    print "TestModule1.incrVar1_clsMethod(100)             ", TestModule1.incrVar1_clsMethod(100)                                         
    
    print "TestModule1.getVar1_clsMethod()                 ", TestModule1.getVar1_clsMethod()
    print "TestModuleDerived.getVar1_clsMethod()           ", TestModuleDerived.getVar1_clsMethod()
    print "TestModuleDerived.getVar1_values_clsMethod()    ", TestModuleDerived.getVar1_values_clsMethod()

    print "TestModuleDerived.incrVar1_clsMethod(10)        ", TestModuleDerived.incrVar1_clsMethod(10)
    print "TestModule1.incrVar1_clsMethod(5)               ", TestModule1.incrVar1_clsMethod(5)
    print "TestModuleDerived.incrVar1_clsMethod(20)        ", TestModuleDerived.incrVar1_clsMethod(20)
    
    print "TestModule1.getVar1_clsMethod()                 ", TestModule1.getVar1_clsMethod()
    print "TestModuleDerived.getVar1_clsMethod()           ", TestModuleDerived.getVar1_clsMethod()
    print "TestModuleDerived.getVar1_values_clsMethod()    ", TestModuleDerived.getVar1_values_clsMethod()

    print "TestModuleDerived.incrVar1By2_super_clsMethod() ", TestModuleDerived.incrVar1By2_super_clsMethod()
    print "TestModule1.incrVar1_clsMethod()                ", TestModule1.incrVar1_clsMethod()
    print "TestModuleDerived.incrVar1_clsMethod(1000)      ", TestModuleDerived.incrVar1_clsMethod(1000)
    print "TestModuleDerived.incrVar1By2_super_clsMethod() ", TestModuleDerived.incrVar1By2_super_clsMethod()

    print "TestModule1.getVar1_clsMethod()                 ", TestModule1.getVar1_clsMethod()
    print "TestModuleDerived.getVar1_clsMethod()           ", TestModuleDerived.getVar1_clsMethod()
    print "TestModuleDerived.getVar1_values_clsMethod()    ", TestModuleDerived.getVar1_values_clsMethod()

    print ""

    print "instance method of inherited class"
    tm1 = TestModule1()
    tmd1 = TestModuleDerived()
    print "tm1.getVar1_insMethod()            ", tm1.getVar1_insMethod()
    print "tmd1.getVar1_insMethod()           ", tmd1.getVar1_insMethod()
    print "tmd1.getVar1_values_insMethod()    ", tmd1.getVar1_values_insMethod()

    print "tm1.incrVar1_insMethod(10)         ", tm1.incrVar1_insMethod(10)
    print "tmd1.incrVar1_insMethod(100)       ", tmd1.incrVar1_insMethod(100)
    print "tmd1.incrVar1By2_super_insMethod() ", tmd1.incrVar1By2_super_insMethod()
 
    print "tm1.getVar1_insMethod()            ", tm1.getVar1_insMethod()
    print "tmd1.getVar1_insMethod()           ", tmd1.getVar1_insMethod()
    print "tmd1.getVar1_values_insMethod()    ", tmd1.getVar1_values_insMethod()

    print "TestModuleDerived.incrVar1By2_clsMethod()    ", TestModuleDerived.incrVar1By2_clsMethod()
    print "tmd1.incrVar1By2_insMethod()                 ", tmd1.incrVar1By2_insMethod()
    print "TestModuleDerived.getVar1_values_clsMethod() ", TestModuleDerived.getVar1_values_clsMethod()
    print "tmd1.getVar1_values_insMethod()              ", tmd1.getVar1_values_insMethod()

    print "" 
    print "TestModuleDerived.test_super_cls(): ", TestModuleDerived.test_super_cls()
    print "tmd1.test_super_ins():              ", tmd1.test_super_ins()


"""

idfs@idfs-K42Jr:~/Dropbox/ProgrammingPractice/PythonPractice/basic_test$ python class_instance_method2.py
assign_static!
assign_static2!
classmethod of inherited class
TestModule1.incrVar1_clsMethod()                 2
TestModule1.incrVar1_clsMethod(100)              102
TestModule1.getVar1_clsMethod()                  102
TestModuleDerived.getVar1_clsMethod()            102
TestModuleDerived.getVar1_values_clsMethod()     [102, 102, 102]
TestModuleDerived.incrVar1_clsMethod(10)         112
TestModule1.incrVar1_clsMethod(5)                107
TestModuleDerived.incrVar1_clsMethod(20)         132
TestModule1.getVar1_clsMethod()                  107
TestModuleDerived.getVar1_clsMethod()            132
TestModuleDerived.getVar1_values_clsMethod()     [132, 132, 132]
TestModuleDerived.incrVar1By2_super_clsMethod()  134
TestModule1.incrVar1_clsMethod()                 108
TestModuleDerived.incrVar1_clsMethod(1000)       1134
TestModuleDerived.incrVar1By2_super_clsMethod()  1136
TestModule1.getVar1_clsMethod()                  108
TestModuleDerived.getVar1_clsMethod()            1136
TestModuleDerived.getVar1_values_clsMethod()     [1136, 1136, 1136]

instance method of inherited class
tm1.getVar1_insMethod()             108
tmd1.getVar1_insMethod()            1136
tmd1.getVar1_values_insMethod()     [1136, 1136, 1136]
tm1.incrVar1_insMethod(10)          118
tmd1.incrVar1_insMethod(100)        1236
tmd1.incrVar1By2_super_insMethod()  1238
tm1.getVar1_insMethod()             118
tmd1.getVar1_insMethod()            1238
tmd1.getVar1_values_insMethod()     [1238, 1238, 1238]
TestModuleDerived.incrVar1By2_clsMethod()     1138
tmd1.incrVar1By2_insMethod()                  1240
TestModuleDerived.getVar1_values_clsMethod()  [1138, 1138, 1138]
tmd1.getVar1_values_insMethod()               [1240, 1240, 1240]

TestModuleDerived.test_super_cls():  ['clsHello', 'clsYes']
tmd1.test_super_ins():               ['insHello', 'insYes']


"""

"""
Conclusion:
    - both classmethod and instance method can use super(),
      based on super()'s definition, 
      super() is useful for accessing inherited methods that have been overridden in a class.
      if we use super() for a non-overridden method (both classmethod and instance method)
      then it's useless, since we always call the base-class method, no matter with super or without super
      like:
        TestModuleDerived.getVar1_values_clsMethod()  [1138, 1138, 1138]
        tmd1.getVar1_values_insMethod()               [1240, 1240, 1240]
      since:
        cls.var1 == super(TestModuleDerived, cls).getVar1_clsMethod() == cls.getVar1_clsMethod()
        self.var1 == super(TestModuleDerived, self).getVar1_insMethod() == self.getVar1_insMethod()

      super is only used for overridden methods, like:
        TestModuleDerived.test_super_cls():  ['clsHello', 'clsYes']
        tmd1.test_super_ins():               ['insHello', 'insYes']

        super(type[, object-or-type])
        Return a proxy object that delegates method calls to a parent or sibling class of type. 
        This is useful for accessing inherited methods that have been overridden in a class. 
        The search order is same as that used by getattr() except that the type itself is skipped.

    - for classmethod:
        - when we first access TestModuleDerived.getVar1_clsMethod(), 
          the var1 is cloned to TestModuleDerived (with its current value)
          after that, TestModuleDerived and TestModule1 have their own independent var1's
        - when a base-class classmethod is not overridden by the derived class, 
          super has no effect, that is, in TestModuleDerived
          cls.var1 == super(TestModuleDerived, cls).getVar1_clsMethod() == cls.getVar1_clsMethod()
        - TestModuleDerived.incrVar1_clsMethod() and TestModuleDerived.incrVar1By2_super_clsMethod()
          and TestModuleDerived.incrVar1By2_clsMethod(), they 3 all work on the same var1, 
          of course, the first 2 both call incrVar1_clsMethod() of base class
          and the third one uses cls.var1 in TestModuleDerived.
          This implies that in TestModuleDerived, there's only 1 var1 which can be accessed by:
            cls.var1
            base classmethod

    - for instance method:
        - when an object is created, 
          the current var1 gets copied from the class (TestModule1, TestModuleDerived)
          then the object gets its own independent copy of var1
        - tmd1.incrVar1_insMethod() and tmd1.incrVar1By2_super_insMethod() and
          tmd1.incrVar1By2_insMethod() all 3 work on the same var1
          just like the observation about classmethod
          for a given object, there's only 1 var1 which can be accessed by:
            self.var1
            base instance method
        - 

"""

