from multiprocessing import Value
from operator import inv
import re
import string

file_name = "items.txt"


def read_file(filename):
    #Description: The read_file method takes in a file and reads the lines.
    #@param = filename, this is the name of the file that is being input.
    #returns - lines of the read file.
    lines = None
    with open ("items.txt") as input_file:
        lines = input_file.readlines()

        return lines


def get_inventory():
    #Description: The get_inventory method gets the items and their values and places it in a dictionary named inventory.
    #returns - inventory
    inventory = {}

    items = read_file(file_name)
    
    for item in items:

        item = item.strip()

        if item in inventory:
            inventory[item] += 1
        else:
            inventory[item] = 1

    return inventory

def determine_inventory():
    #Description: This method prints the item and how many for every item in the inventory.
    inventory = get_inventory()

    for key, value in inventory.items():
        print(key, value)


def determine_frequency(item):
    #Description: The method takes an item and finds how many there is in the inventory.
    #@param = item, the item the method is trying to find for the frequency.
    #returns - the frequency of the item. 
    inventory = get_inventory()
    return inventory[item]

def output_histogram():
    #Description: The method prints the items and the frequency to a file named frequency.dat
    inventory = get_inventory()
    with open("frequency.dat", "w") as file:
        for key, value in inventory.items():
            file.write(f'{key} {value}')

               



    
