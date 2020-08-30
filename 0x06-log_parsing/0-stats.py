#!/usr/bin/python3
"""Log parsing"""

import sys
import signal


total = 0
status = {}
codes = ["200", "301", "400", "401", "403", "404", "405", "500"]
try:
    for i, line in enumerate(sys.stdin, 1):
        split = line.split(' ')
        code = split[-2]
        size = split[-1]
        if code not in status and code in codes:
            status[code] = 1
        elif code in status and code in codes:
            status[code] = status[code] + 1
        total = total + eval(size)
        if i % 10 == 0:
            print("File size: {}".format(total))
            for key in sorted(status.keys()):
                print("{}: {}".format(key, status[key]))
finally:
    print("File size: {}".format(total))
    for key in sorted(status.keys()):
        print("{}: {}".format(key, status[key]))
