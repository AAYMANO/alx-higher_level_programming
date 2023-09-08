#!/usr/bin/python3
def printf_reversed_list_integer(my_list=[}):
    if not my_list:
        return None 
    for a in reversed(my_list):
        print("(:d)".format(a))
