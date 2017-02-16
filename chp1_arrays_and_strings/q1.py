# Implement an algoirthm to determine if a string has all unique characters.
# What if you can not use additional data structures?

def allUnique(str, cur, check):
    if cur == 0 or len(str) <= 1:
        return True
    elif check < 0:
        return allUnique(str, cur-1, cur-2)
    elif str[cur] != str[check]:
        return allUnique(str, cur, check-1)
    else:
        return False

def AllUnique(str):
    if len(str) > 1:
        return allUnique(str, len(str) - 1, len(str) - 2)
    else:
        return True

def loopAllUnique(str):
    for i in range(0, len(str) - 1):
        for j in range(i+1, len(str)):
            if str[i] == str[j]:
                return False
    return True

import string

def usingLibAllUnique(str):
    for s in str:
        if string.count(str, s) > 1:
            return False
    return True

def usingSetAllUnique(str):
    return len(set(list(str))) == len(str)
        
strs = ["abcdefghijklmnopqrstuvwxyz", "", "aa", "a", "abckdioja", "abcdabcd", "abcddefg" ]

for s in strs:
    print("testing '" + s + "'")
    print(AllUnique(s))
    print(loopAllUnique(s))
    print(usingLibAllUnique(s))
    print(usingSetAllUnique(s))
