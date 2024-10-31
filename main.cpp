#include "BigNumberAdd.h"
#include "BigNumberSub.h"
#include "BigNumberShift.h"

using namespace std;

void Menu();

int main() {

    Menu();

    while(true) {

        int i;
        cout << "Enter a number: ";
        cin >> i;
        if (i == 1) {
            string num1, num2;

            cout << "Enter the first large number: ";
            cin >> num1;
            cout << "Enter the second large number: ";
            cin >> num2;

            // Create objects from class

            BigNumberAdd bigNum1(num1);
            BigNumberAdd bigNum2(num2);

            // Print the result of add to BigNumbers

            BigNumberAdd result = bigNum1.add(bigNum2);
            cout << "The result of addition is: ";
            result.print();
        }

        else if (i == 2) {
            string num1, num2;

            cout << "Enter the first large number: ";
            cin >> num1;
            cout << "Enter the second large number: ";
            cin >> num2;

            // Create objects from class

            BigNumberSub bigNum1(num1);
            BigNumberSub bigNum2(num2);

            // Print the answer to subtracting two numbers from each other

            BigNumberSub result = bigNum1.subtract(bigNum2);
            cout << "The result of subtraction is: ";
            result.print();
        }

        else if (i == 3) {
            string num;
            char direction;

            cout << "Enter a large number: ";
            cin >> num;
            BigNumberShift bigNum(num);

            cout << "Enter shift direction (L for left, R for right): ";
            cin >> direction;

            bigNum.shift(direction);

            cout << "The result after shift is: ";
            bigNum.print();
        }

        else if (i == 0)
            exit(0);
    }


    return 0;
}

void Menu() {
    cout << "**************************************************************************************" << endl;
    cout << "*" << " Enter the number '1' if you want to see the sum of 2 big numbers                   *" << endl;
    cout << "*" << " Enter the number '2' if you want to see the subtraction of 2 big numbers           *" << endl;
    cout << "*" << " Enter the number '3' if you want to see the left and right shift of a large number *" << endl;
    cout << "*" << " Enter the number '0' if you want to exit the program                               *" << endl;
    cout << "**************************************************************************************" << endl;
}