#!/usr/bin/env python3

import sys


def sum_of_priorities(lines):
    sum = 0
    for i in range(0, len(lines), 3):
        common = set(lines[i]).intersection(set(lines[i+1]), set(lines[i+2]))
        letter = ord(common.pop())
        sum += letter - 96 if letter >= 97 else letter - 38
    return sum


if __name__ == '__main__':
    with open(sys.argv[1]) as f:
        lines = [line.strip() for line in f]
    print(sum_of_priorities(lines))
