#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int secret;

void guessNumber(int player) {
    int guess;
    cout << "Player " << player << ", enter your guess: ";
    cin >> guess;
    if (guess == secret) {
        cout << "Player " << player << " wins!" << endl;
        return;
    } else if (guess < secret) {
        cout << "Too low!" << endl;
    } else {
        cout << "Too high!" << endl;
    }
    guessNumber(player == 1 ? 2 : 1);
}

int main() {
    srand(time(0));
    secret = rand() % 100 + 1;
    cout << "Game started! Guess the number between 1 and 100." << endl;
    guessNumber(1);
    return 0;
}
