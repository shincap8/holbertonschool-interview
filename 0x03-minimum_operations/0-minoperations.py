#!/usr/bin/python3
"""Minimum operations"""


def minOperations(n):
    if type(n) is not int or n <= 0:
        return 0
    nH = 1
    copy = 1
    operations = 1
    while nH < n:
        if n % nH == 0 and nH != copy:
            copy = nH
            operations += 1
        nH = nH + copy
        operations += 1
    if nH == n:
        return operations
    return 0
