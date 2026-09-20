a = int(input("Input first number: "))
b = int(input("Input second number: "))
print ( a > 10 and a < 20)
print ( a < 10 and b > 20)
print ( b > 10 and b < 20)
print ( a < 10 and b > 20)
print ( a == b)
print ( a != b)
a, b = b, a
print(a, b)
  