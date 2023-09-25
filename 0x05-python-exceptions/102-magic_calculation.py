#!/usr/bin/python3


def magic_calculation(a, b):
    result = 0
    for p in range(1, 3):
        try:
            if p > a:
                raise Exception('Too far')
            else:
                result += a ** b / p
        except:
            result = b + a
            break
    return (result)
