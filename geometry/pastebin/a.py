import sys
from collections import Counter

def spliter(line: str):
    key, count = line.split('\t')
    return (key, int(count))

def count(word_count):
    counter = Counter()
    for key,count in word_count:
        counter[key] += count
    return counter

def print_counter(counter):
    count_list = [(key, count) for key, count in counter.items()]
    for key, count in sorted(count_list, key=lambda x: -x[1]):
        print(f"{key}\t{count}")

lines = sys.stdin.readlines()
word_count = list(map(spliter, lines))
counter = count(word_count)
print_counter(counter)