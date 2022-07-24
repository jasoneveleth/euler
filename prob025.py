def mult(p1, p2):
    # takes in two phi structs: (a + b*sqrt(5)) / c
    a,b,c = p1
    d,e,f = p2
    return (a*d + 5*b*e, a*e + b*d, c*f)

def phi_pow(base, n):
    if n == 0:
        val = (1, 0, 1)
    else:
        val = phi_pow(mult(base, base), n//2)
        if n & 1:
            val = mult(base, val)
    return val

def fib(n):
    phi = (1, 1, 2)
    weird_phi = (1, -1, 2)
    a,b,c = phi_pow(phi, n)
    d,e,f = phi_pow(weird_phi, n)
    # for this formula to return an integer these need
    # to be satisfied
    assert(a*f - c*d == 0)
    assert((f*b - c*e) % (c*f) == 0)
    return (f*b - c*e) // (c*f)

i = 2
while len(str(fib(i))) < 1_000:
    i += 1
print(i-1)
print(fib(i-1))

