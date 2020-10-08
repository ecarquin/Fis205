# Python program to
# demonstrate protected members


# Creating a base class
class Base:
    def __init__(self):

        # Protected member
        self._a = 2

# Creating a derived class    
class Derived(Base):
    def __init__(self):

        self._b = 3
        
        # Calling constructor of
        # Base class
        Base.__init__(self) 
        print("Calling protected member of base class: ")
        print(self._a)

    def _getb(self):
        return self._b

obj1 = Derived()

obj2 = Base()

# Calling protected member
# Outside class will  result in 
# AttributeError
print(obj1.getb())

print(obj2._a)

#print(obj2.a)
