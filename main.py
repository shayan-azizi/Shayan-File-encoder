import sys

argument = sys.argv [1:]

data  = []

file = open(argument[0], "rb")

for i in file:
    data.append(i)


print (data[0[0]])
print (data[1])
print (data[2])
print (data[3])
