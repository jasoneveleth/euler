import functools

def factors_sum(n):
    l = [1]
    for i in range(2, int(n**0.5)):
        if (n % i) == 0:
            l.append(i)
            l.append(n/i)
            assert n/i == n//i
    return functools.reduce(lambda a,x: a+x, l, 0)

d = {}
sum = 0

for i in range(2, 10000):
    if i in d:
        if d[i] == factors_sum(i):
            sum += i + d[i]
            continue

    d[factors_sum(i)] = i

print(sum)
