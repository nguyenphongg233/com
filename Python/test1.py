a = 10.0345
b = 100
print(type(a))

from decimal import*
getcontext().prec = 30

print(decimal(10)/decimal(1000))