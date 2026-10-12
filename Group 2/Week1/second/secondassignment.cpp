#include <iostream>
using namespace std;
int main(){
    int number_of_animals;
    int number_of_legs;
    cin >> number_of_animals;
    cin >> number_of_legs;
    if (number_of_legs % 2 != 0 || number_of_legs < number_of_animals * 2 || number_of_animals < number_of_legs * 4 )
    {
        cout << "Input parameters are invalid";
        return 0;
    }
    
    int chickens = (4 * number_of_animals - number_of_legs) / 2;
    int cows = number_of_animals - chickens;
    cout << "Cows: " << cows << endl;
    cout << "Chickens: " << chickens;
    return 0;
}