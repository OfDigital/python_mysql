#include <iostream>
#include <string>
using namespace std;

void decimalToBinary(int n) {
    string binary = "";
    while (n > 0) {
        binary = to_string(n % 2) + binary;
        n /= 2;
    }
    cout << "Binary: " << binary << endl;
}

void decimalToHexadecimal(int n) {
    string hexadecimal = "";
    while (n > 0) {
        int remainder = n % 16;
        if (remainder < 10) {
            hexadecimal = to_string(remainder) + hexadecimal;
        } else {
            char hexChar = 'A' + remainder - 10;
            hexadecimal = hexChar + hexadecimal;
        }
        n /= 16;
    }
    cout << "Hexadecimal: " << hexadecimal << endl;
}

int main() {
    cout << "Enter number: ";
    int n;
    cin >> n;
    cout << endl;

    cout << "Decimal number: " << n << endl;
    char hexChar = 'A' + 2;
    decimalToBinary(n);
    decimalToHexadecimal(n);

    return 0;
}