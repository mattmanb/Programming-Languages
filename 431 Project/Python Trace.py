#Created by: Matt Barrington
#Compiler: Python3

def main():
    total = total_tracker()
    inputNums = [1, [2, 3], 4, [5, [6, 7]], 8]
    listSum = sum(inputNums, total)
    print("The grand total of the list is", listSum)

def sum(list, total):
    print("Entering sum function.")
    for i in list:
        #IF the element i is a list
        if type(i) == type([]):
            print("Inner list found!")
            innerTotal = total_tracker()
            total.add(sum(i, innerTotal))
        else:
            total.add(i)
    print("Returning", total.getTotal(), "from sum function.")
    return total.getTotal()

class total_tracker:
    #instance data of total_tracker objects
    total = 0
    #__init__ functions are constructors
    def __init__(self):
        print("total_tracker object created.")

    def getTotal(self):
        return self.total
    
    def add(self, num):
        self.total = self.total + num

main()

# OUTPUT:
    # total_tracker object created.
    # Entering sum function.
    # Inner list found!
    # total_tracker object created.
    # Entering sum function.
    # Returning 5 from sum function.
    # Inner list found!
    # total_tracker object created.
    # Entering sum function.
    # Inner list found!
    # total_tracker object created.
    # Entering sum function.
    # Returning 13 from sum function.
    # Returning 18 from sum function.
    # Returning 36 from sum function.
    # The grand total of the list is 36