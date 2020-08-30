#!/usr/bin/python3
"""Log parsing"""

import sys
import signal


total = 0
status = {}
try:
    for i, line in enumerate(sys.stdin, 1):
        split = line.split(' ')
        code = split[-2]
        size = split[-1]
        if code not in status:
            status[code] = 1
        else:
            status[code] = status[code] + 1
        total = total + eval(size)
        if (i % 10 == 0 and i != 0):
            print("File size: {}".format(total))
            for key, value in status.items():
                print("{}: {}".format(key, value))
finally:
    print("File size: {}".format(total))
    for key, value in status.items():
        print("{}: {}".format(key, value))
