import cmath
gol = ((1 + cmath.sqrt(5))/2).real
def poww(a, b):
    if b == 0: return 1
    k = poww(a, b//2)
    k *= k
    if b % 2 == 1: k *= a
    return k

def fibo(n):
    return round((poww(gol, n)/cmath.sqrt(5)).real)

for i in range(101): print(fibo(i))