# Assume you have a method isSubstring which check if one word is a substring
# of another. Given two string s1 and s2, write code to check if s2 is a
# rotation of s1 using only one call to isSubstring (i.e., "waterbottle" is
# a rotation of "erbottlewat")

s1 = "erbottlewat"
s2 = "waterbottle"

def isRotation(s1, s2):
    if len(s1) == len(s2):
        s1s1 = s1 + s1
        return s2 in s1s1
    else:
        return False

print(isRotation(s1, s2))
