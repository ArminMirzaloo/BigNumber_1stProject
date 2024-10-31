//

#ifndef BIGNUMBER1_BIGNUMBERSUB_H
#define BIGNUMBER1_BIGNUMBERSUB_H
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class BigNumberSub {
private:
    int digits[100] = {0};                                           // An array to store the digits of a number in reverse
    int size;

public:

    BigNumberSub(const string& number) {                            // Constructor to receive large number as string
        size = number.size();
        for (int i = 0; i < size; ++i) {
            digits[i] = number[size - 1 - i] - '0';
        }
    }

    BigNumberSub subtract(const BigNumberSub& other) const {        // The method of subtracting two large numbers

            if (this->isLessThan(other)) {                          // Checking which number is larger to subtract from larger to smaller
            cout << "Error: Cannot perform subtraction as the"
                    " result would be negative." << endl;
            return BigNumberSub("0");                        // بReturn zero for a negative result
        }

        BigNumberSub result("0");
        int borrow = 0;

        for (int i = 0; i < size; ++i) {
            int digit1 = digits[i];
            int digit2 = (i < other.size) ? other.digits[i] : 0;

            int sub = digit1 - digit2 - borrow;
            if (sub < 0) {
                sub += 10;
                borrow = 1;
            }
            else {
                borrow = 0;
            }

            result.digits[i] = sub;
        }

        // Find the new size without extra zeros on the left
        result.size = size;
        while (result.size > 1 && result.digits[result.size - 1] == 0) {
            result.size--;
        }

        return result;
    }

    bool isLessThan(const BigNumberSub& other) const {     // Helper method to check if the current number is smaller than another number
        if (size != other.size)
            return size < other.size;

        for (int i = size - 1; i >= 0; --i) {
            if (digits[i] != other.digits[i])
                return digits[i] < other.digits[i];
        }
        return false;
    }

    void print() const {
        for (int i = size - 1; i >= 0; --i) {
            cout << digits[i];
        }
        cout << endl;
    }
};


#endif //BIGNUMBER1_BIGNUMBERSUB_H
