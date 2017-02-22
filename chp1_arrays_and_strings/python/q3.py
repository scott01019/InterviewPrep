# Design an algorithm and write code to remove the duplicate characters in a
# string without using any additional buffer. You may use one or two extra
# variables.
# Follow Up: Write the test cases for this method.

import string

strs = [ "asdcklasdanlsdz", "abcdefghijklmnopqrstuvwxyz",
         "aaaa", "", "a", "abcabceabc" ]

def removeDuplicates(strz):
    print(strz)
    cur = 0
    length = len(strz)
    while cur < length:
        i = cur + 1
        while i < length:
            if strz[cur] == strz[i]:
                strz = strz[:i] + strz[i+1:]
                length = len(strz)
                i = cur + 1
            else:
                i += 1
        cur += 1
    print(strz)   

for strz in strs:
    removeDuplicates(strz)
