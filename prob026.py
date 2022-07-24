max_cycle = 0
argmax = 0
for divisor in range(1, 1000):
    remainders = []
    dividend = 1
    quotient = ""
    while dividend != 0 and dividend not in remainders:
        remainders.append(dividend)
        dividend *= 10
        while dividend < divisor:
            quotient += "0"
            dividend *= 10
        quotient += str(dividend // divisor)
        dividend = dividend % divisor
    print(f"1/{divisor} = 0.{quotient}", end="")
    print("" if dividend == 0 else "...")
    if dividend != 0 and len(quotient) > max_cycle:
        max_cycle = len(quotient)
        argmax = divisor
print()
print(f"argmax: {argmax}")

