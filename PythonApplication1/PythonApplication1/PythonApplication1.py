from Ar import *
from Domain import*
print ("This is the beginning of your first python program rae")
mylist = ["two", "two", "four"]

#print(extractChars(mylist))

var1 = extractSep(mylist)[0]#extract char

print(setConstDict(mylist))

x = Variable("na me",1 )
print(x)
for myVar in setDomainTable(extractChars(mylist)):
    print(myVar)
#dict1 = setConstDict(var1,mylist)#set dictionary

#print(extractSep(mylist))

#print(reverseWordList(mylist))

#print(getMaxWordLength(mylist))

#print(getColumn(3,mylist))