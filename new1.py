import serial

f = open("dump1.txt", "r")

l = f.readline()

l = l[2:-2]

print(type(l))

a = []
a.append(l)
print(a)










# lines = f.readlines()


# for i in range(len(lines)):
#     lines[i] = lines[i][2:-2]
# #     res = bytes(hex, 'utf-8')
# #     print(i)
