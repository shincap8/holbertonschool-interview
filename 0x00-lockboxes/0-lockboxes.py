#!/usr/bin/python3
"""Determines if all the boxes can be opened."""


def canUnlockAll(boxes):
    keys = [0]
    bxindex = [i for i in range(len(boxes))]
    opened = False

    while len(bxindex):
        ktemp = []
        for i in keys:
            if i in bxindex:
                opened = True
                for j in boxes[i]:
                    if j not in keys and j in bxindex:
                        ktemp.append(j)
                bxindex.remove(i)
        keys.extend(ktemp)
        if opened is False:
            return False
        opened = False
    return True
