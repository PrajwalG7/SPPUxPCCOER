# define a Person class to store a person's name and mobile number
class Person:
    def __init__(self, name, mobile):
        self.name = name
        self.mobile = mobile
    
    def __repr__(self):
        return f"{self.name}: {self.mobile}"

# define a Phonebook class to store a list of Person objects and provide 
# methods for searching and inserting
class Phonebook:
    def __init__(self):
        self.phonebook = []
    
    def insert(self, person):
        # insert the person into the phonebook in sorted order
        i = 0
        while i < len(self.phonebook) and self.phonebook[i].name < person.name:
            i += 1
        self.phonebook.insert(i, person)
    
    def search_fibonacci(self, name):
        # create the Fibonacci sequence
        fib1 = 0
        fib2 = 1
        fib = fib1 + fib2
        
        # find the smallest Fibonacci number that is greater than or equal 
        # to the length of the phonebook
        while fib < len(self.phonebook):
            fib1 = fib2
            fib2 = fib
            fib = fib1 + fib2
        
        # initialize the offset to be the largest Fibonacci number that is 
        # less than the length of the phonebook
        offset = -1
        while fib > 1:
            # find the index that is offset Fibonacci numbers away from 
            # the current position
            i = min(offset+fib2, len(self.phonebook)-1)
            
            # if the person at that index has a name that comes after the 
            # specified name, set the offset to be the current offset minus 
            # fib1 and set fib to be fib1
            if self.phonebook[i].name < name:
                fib = fib1
                fib2 = fib1
                fib1 = fib - fib2
                offset = i
            
            # if the person at that index has a name that comes before the 
            # specified name, set fib to be fib2 and fib2 to be fib1
            elif self.phonebook[i].name > name:
                fib = fib2
                fib1 = fib2
                fib2 = fib - fib1
            
            # if the person at that index has the specified name, return 
            # their index
            else:
                return i
        
        # if the offset is less than 0, the person was not found
        if offset < 0:
            return None
        
        # if the person at the offset has the specified name, return 
        # their index
        elif self.phonebook[offset].name == name:
            return offset
        
        # if the person at the offset has a name that comes before the 
        # specified name, return None
        else:
            return None
    
    def search(self, name):
          # call the Fibonacci search function
        index = self.search_fibonacci(name)
    
    # if the search function returns a valid index, return the 
    # Person object at that index
        if index is not None:
          return self.phonebook[index]
    
    # if the search function returns None, the person was not found
        else:
            return None
        
        
# create a Phonebook object
phonebook = Phonebook()

# insert some friends into the phonebook
phonebook.insert(Person("Alice", "123-456-7890"))
phonebook.insert(Person("Bob", "234-567-8901"))
phonebook.insert(Person("Charlie", "345-678-9012"))
phonebook.insert(Person("David", "456-789-0123"))
phonebook.insert(Person("Eve", "567-890-1234"))

# search for Bob
bob = phonebook.search("Bob")
print(bob)

# search for Alice
alice = phonebook.search("Alice")
print(alice)

# search for Eve
eve = phonebook.search("Eve")
print(eve)

# search for Frank (who is not in the phonebook)
frank = phonebook.search("Frank")
print(frank)

