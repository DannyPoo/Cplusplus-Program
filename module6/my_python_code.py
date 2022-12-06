import re
import string


def printsomething():
    print("Hello from python!")

def MultiplicationTable(value):
    """
    Takes in a value to make a multiplication table
    @param value - an integer to determine the multiplication table
    @returns - returns a 1 if succeeded 
    """
    num = value
    for x in range(1, 11):
        print(num, 'x', x, '=', num*x)
    return 1;


def DoubleValue(value):
    """
    Takes in a value to double
    @param value - an integer to be doubled
    @returns - the doubled the value
    """
    return value * 2



    
