def fac_sum(n):
    a = 1
    while n > 0:
        a *= n
        n -= 1

    sum = 0
    for i in str(a):
        sum += int(i)
    return sum

print(fac_sum(100))
