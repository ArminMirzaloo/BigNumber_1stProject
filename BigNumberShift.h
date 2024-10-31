//

#ifndef BIGNUMBER1_BIGNUMBERSHIFT_H
#define BIGNUMBER1_BIGNUMBERSHIFT_H
#include <iostream>
#include <string>

using namespace std;

class BigNumberShift {
private:
    int digits[100] = {0};                          // An array to store the digits of a number in reverse
    int size;

public:

    BigNumberShift(const string& number) {          // Constructor to receive large number as string
        size = number.size();
        for (int i = 0; i < size; ++i) {
            digits[i] = number[size - 1 - i] - '0';
        }
    }

    void shiftLeft() {                              // Shift to the left (add zero to the end of the number)
        if (size == 100) {
            cout << "Error: Cannot shift left, number too large." << endl;
            return;
        }
        for (int i = size; i > 0; --i) {
            digits[i] = digits[i - 1];
        }
        digits[0] = 0;
        size++;
    }

    void shiftRight() {                                 // Shift to the right (remove the least significant digit)
        if (size == 1 && digits[0] == 0) {
            cout << "Error: Cannot shift right, number is already zero." << endl;
            return;
        }
        for (int i = 0; i < size - 1; ++i) {
            digits[i] = digits[i + 1];
        }
        digits[size - 1] = 0;
        size--;
    }


    void shift(char direction) {                          // Shift based on user request
        if (direction == 'L' || direction == 'l') {
            shiftLeft();
        } else if (direction == 'R' || direction == 'r') {
            shiftRight();
        } else {
            cout << "Error: Invalid direction. Use 'L' for left and 'R' for right." << endl;
        }
    }

    void print() const {
        for (int i = size - 1; i >= 0; --i) {
            cout << digits[i];
        }
        cout << endl;
    }
};


#endif //BIGNUMBER1_BIGNUMBERSHIFT_H
