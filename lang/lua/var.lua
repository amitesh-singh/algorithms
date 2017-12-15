-- local variables
local a, b

-- initialization
a = 30
b = 10

print("value of a:", a)
print("value of b:", b)

--swapping of vars

b, a = a, b

print("value of a:", a)
print("value of b:", b)

f = 70.0/30.0

print("value of f: ", f)

c, d = 20, 30

print("value of c:", c)
print("value of d:", d)

s = nil

print(type("what is this type"))
print(type(3.0))
print(type(nil))
print(type(print))

s1, s2 = "Hello", " World!"
print(s1..s2)
-- size of (s1..s2)
print(#(s1..s2))
