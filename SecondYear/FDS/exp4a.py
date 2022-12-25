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
    
    def search_recursive(self, name, start, end):
        # base case: if start and end indices are equal and the person at 
        # that index does not have the specified name, the person is not 
        # in the phonebook
        if start == end:
            return None
        
        # find the midpoint of the list
        mid = (start + end) // 2
        
        # if the person at the midpoint has the specified name, return 
        # their index
        if self.phonebook[mid].name == name:
            return mid
        
        # if the person at the midpoint has a name that comes after the 
        # specified name, search the left half of the list
        elif self.phonebook[mid].name > name:
            return self.search_recursive(name, start, mid)
        
        # if the person at the midpoint has a name that comes before the 
        # specified name, search the right half of the list
        else:
            return self.search_recursive(name, mid+1, end)
    
    def search(self, name):
        # start the binary search at the beginning and end of the list
        start = 0
        end = len(self.phonebook)
        
        # call the recursive search function
        index = self.search_recursive(name, start, end)
        
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

# search

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
