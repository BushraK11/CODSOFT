#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main() {
    srand(time(0)); // seed the random number generator

    int number = rand() % 100 + 1; // generate a random number between 1 and 100
    int guess;
    
    cout << "Guess the number from 1 to 100: ";
    cin >> guess;

    while (guess != number) {
        if (guess < number) {
            cout << "Too low! Try again: ";
            cin >> guess;
        } else {
            cout << "Too high! Try again: ";
            cin >> guess;
        }
    }
    cout << "Congratulations! You guessed the number: " << number << endl;
    return 0;
}
