def decimal_to_binary(n):
    binary = ""
    if n == 0:
        binary = "0"  # Special case for input 0
    else:
        while n > 0:
            binary = str(n % 2) + binary
            n = n // 2

    print("Binary: " + binary)

def decimal_to_hexadecimal(n):
    alpha_dict = {
        10: "A",
        11: "B",
        12: "C",
        13: "D",
        14: "E",
        15: "F"
    }
    hexadecimal = ""
    if n == 0:
        hexadecimal = "0"
    else:
        while n > 0:
            remainder = n % 16
            if remainder >= 10:
                hexadecimal = alpha_dict[remainder] + hexadecimal
            else:
                hexadecimal = str(remainder) + hexadecimal
            n //= 16

    print("Hexadecimal:", hexadecimal)


def main():
    num = int(input("Enter Decimal Number: "))
    decimal_to_binary(num)
    decimal_to_hexadecimal(num)



if __name__ == '__main__':
    main()