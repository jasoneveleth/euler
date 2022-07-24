# ================== new and improved ====================
# uses the factorial number system: https://en.wikipedia.org/wiki/Factorial_number_system
def n2fac_base(n):
    lst = []
    i = 1
    while n > 1:
        lst.insert(0, n % i)
        n //= i
        i += 1
    return lst

def fac_base2perm(lst, fac_base):
    perm = []
    i = 0
    while len(lst) > 0:
        perm.append(lst.pop(fac_base[i]))
        i += 1
    return perm

print(fac_base2perm(list('0123456789'), n2fac_base(999999)))

#================== old =======================
# uses recursive backtracking
def nth_permutation(digits_left, n, counter=0):
    if len(digits_left) == 0:
        return counter + 1
    for i in range(len(digits_left)):
        removed_digit = digits_left.pop(i)
        permutation[9 - len(digits_left)] = removed_digit
        counter = nth_permutation(digits_left, n, counter)
        digits_left.insert(i, removed_digit)
        if counter == n:
            return counter
    return counter

permutation = [0]*10
nth_permutation(list('0123456789'), 1e6)
print(permutation)

