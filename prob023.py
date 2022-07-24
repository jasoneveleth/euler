def divisors(n):
    divisor_list = []
    for i in range(1, n//2 + 1):
        if n % i == 0:
            divisor_list.append(i)
    return divisor_list

# create abundant set
abundant_set = set()
for i in range(1, 28123):
    if sum(divisors(i)) > i:
        abundant_set.add(i)

# add up all nums not summable by 2 abundant numbers
total = 0
for i in range(1, 28123):
    summable = False
    for j in abundant_set:
        if i - j in abundant_set:
            summable = True
            break
    if not summable:
        total += i

print(total)

