h = "t0E520196"
# a = h[2:-1]
res = bytes(h, 'utf-8')

print(type(res))
print(res)

for i in range(len(h)):
    print(h[i].hex())