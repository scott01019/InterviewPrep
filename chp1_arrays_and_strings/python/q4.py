# Write a method to decide if two strings are anagrams or not.

def anagrams(s1, s2):
    s1 = s1.lower()
    s2 = s2.lower()
    s1Dict = dict()
    for s in s1:
        if s not in s1Dict:
            s1Dict[s] = 1
        else:
            s1Dict[s] += 1
    for s in s2:
        if s not in s1Dict or s1Dict[s] != s2.count(s):
            return False
    return True

def anagrams2(s1, s2):
    s1 = s1.lower()
    s2 = s2.lower()
    return sorted(s1) == sorted(s2)

str1 = "ascasfdsjdfgjksfnkacsads"
str2 = str1[:3] + str1[15:] + str1[3:15]
str3 = "kasdjklasdklajsdjcas"
str4 = "bob"
str5 = "oBB"

print(anagrams(str1, str2))
print(anagrams(str1, str3))
print(anagrams(str4, str5))

print(anagrams2(str1, str2))
print(anagrams2(str1, str3))
print(anagrams2(str4, str5))
