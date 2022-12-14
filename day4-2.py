#!/usr/bin/env python3

import sys


def fully_contained(lines):
    count = 0
    for line in lines:
        s1_start = int(line.split('-')[0].split(',')[0])
        s1_end = int(line.split('-')[1].split(',')[0])+1
        s2_start = int(line.split(',')[1].split('-')[0])
        s2_end = int(line.split(',')[1].split('-')[1])+1

        s1 = set(range(s1_start, s1_end))
        s2 = set(range(s2_start, s2_end))

        if not s1.isdisjoint(s2):
            count += 1

    return count


if __name__ == '__main__':
    with open(sys.argv[1]) as f:
        lines = [line.strip() for line in f]
    print(fully_contained(lines))
