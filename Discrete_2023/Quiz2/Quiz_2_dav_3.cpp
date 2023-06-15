#include <iostream>
#include <string>
using namespace std;

void decimalToTwelve(int n) {
    string twelve = "";
    while (n > 0) {
        int remainder = n % 12;
        if (remainder < 10) {
            twelve = to_string(remainder) + twelve;
        } else {
            char tweChar = 'A' + remainder - 10;
            twelve = tweChar + twelve;
        }
        n /= 12;
    }
    cout << "Twelve: " << twelve << endl;
}

int main() {
    cout << "Enter number: ";
    int n;
    cin >> n;
    cout << endl;

    cout << "Decimal number: " << n << endl;
    decimalToTwelve(n);

    return 0;
}
