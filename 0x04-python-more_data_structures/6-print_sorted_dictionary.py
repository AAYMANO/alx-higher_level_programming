#!/usr/bin/python3
def print_sorted_dictionary(a_dictionary):
    list_ord = list(a_dictionary.keys())
    list_ord.sort()
    for a in list_ord:
        print("{}: {}".format(a, a_dictionary.get(a)))
