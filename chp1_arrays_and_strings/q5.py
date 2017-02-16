# Write a method to replace all spaces in a string with %20

def replaceSpacesEasy(str1):
    print(str1)
    str1 = str1.replace(" ", "%20")
    print(str1)

def replaceSpaces(str1):
    print(str1)
    cur = 0
    length = len(str1)
    while cur < length:
        if str1[cur] == " ":
            str1 = str1[:cur] + "%20" + str1[cur+1:]
            length = len(str1)
        cur += 1
    print(str1)

replaceSpaces("a ds asd asd kasd ads ")
