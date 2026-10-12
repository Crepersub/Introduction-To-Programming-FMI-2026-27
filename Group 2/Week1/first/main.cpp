#include <iostream>
using namespace std;
int main(){
    int first_num;
    int second_num;
    cout << "Enter first number: ";
    cin >> first_num;
    cout << "Enter second number: ";
    cin >> second_num;
    cout << first_num << " + " << second_num << " = " << first_num + second_num << endl;
    cout << first_num << " - " << second_num << " = " << first_num - second_num << endl;
    cout << first_num << " * " << second_num << " = " << first_num * second_num << endl;
    if (second_num != 0)
    {
        cout << first_num << " / " << second_num << " = " << (double)first_num / (double)second_num << endl;
        cout << first_num << " % " << second_num << " = " << first_num % second_num << endl;
    }
    else {
        cout << "Error: Cannot divide by 0";
    }
    return 0;
}