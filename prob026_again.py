def list_of_divisors(divisor):
    remainders_list = []

    dividend = 1
    while dividend != 0:
        while dividend < divisor:
            dividend = 10 * dividend
        dividend = dividend % divisor
        if dividend in remainders_list:
            remainders_list.append(dividend)
            break
        remainders_list.append(dividend)
    return remainders_list

for i in range(2, 1000):
    if i % 2 == 0 or i % 5 == 0:
        # decimals that terminate fucks up my function
        continue
    backward = list(reversed(list_of_divisors(i)))
    first_repeat = 1
    while backward[first_repeat] != backward[0]:
        first_repeat = first_repeat + 1
    print(f"{first_repeat} <- nrepeats, number: {i}")