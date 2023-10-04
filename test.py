import math

prisoners = 100

half_p = int(prisoners / 2)
print(half_p)

sum = 0

for i in range(half_p):
    sum += 1/(i+half_p+1)

print(1-sum)

