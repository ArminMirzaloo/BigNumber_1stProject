//

#ifndef BIGNUMBER1_BIGNUMBERADD_H
#define BIGNUMBER1_BIGNUMBERADD_H
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class BigNumberAdd {
private:
    int digits[100] = {0};                                 // An array to store the digits of a number in reverse
    int size;

public:

    BigNumberAdd(const string& number) {                   // Constructor to receive large number as string
        size = number.size();
        for (int i = 0; i < size; ++i) {
            digits[i] = number[size - 1 - i] - '0';
        }
    }


    BigNumberAdd add(const BigNumberAdd& other) const {     // The method of adding two large numbers
        BigNumberAdd result("0");
        int carry = 0;
        int n1 = size;
        int n2 = other.size;
        int n = max(n1, n2);

        for (int i = 0; i < n || carry != 0; ++i) {
            int digit1 = (i < n1) ? digits[i] : 0;
            int digit2 = (i < n2) ? other.digits[i] : 0;

            int sum = digit1 + digit2 + carry;
            result.digits[i] = sum % 10;
            carry = sum / 10;

            result.size = i + 1;                            // Size update every step
        }

        return result;
    }


    void print() const {                                    // Print the add of BigNumbers
        for (int i = size - 1; i >= 0; --i) {
            cout << digits[i];
        }
        cout << endl;
    }
};


#endif //BIGNUMBER1_BIGNUMBERADD_H
