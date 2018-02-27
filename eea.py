# Implementation of the Extended Euclidian Algorithm
# Takes an a and b integer and returns an integer, t, such that as+bt=gcd(a,b)


print("  This program takes an a and b integer and returns an integer, t, which"
     " represents b^-1 mod a where as+bt=gcd(a,b)")
a = int(input("  Please enter a: "))
b = int(input("  Please enter b: "))
prevs = 1   #s0
s = 0       #s1
prevt = 0   #t0
t = 1       #t1
while a>0:  #until r(i) = 0
    q = b//a #Quotient is the floor division of a and b
    t, prevt = prevt - q*t, t #t is the previous t - quotient * t, prevt is old t
    s, prevs = prevs - q*s, s #s is the previous s - quotient * s, prevs is old s
    b, a = a, b % a #r(i-1) becomes r(i), r(i) becomes r(i-2) mod r(i-1)
print("  b^-1 mod a = {}".format(t))
input("  Press enter to exit.")
