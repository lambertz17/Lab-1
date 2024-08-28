#include <iostream>
using namespace std;

int main() {
  // There is a logic error in this program.
  // Correct this error, test your changes and commit the changes.
  int guess = 0, solution = 15;
  char answer = 'y';
  cout << "Would you like to play? (y/n): "; // changed '222' to 'to'.
  cin >> answer;

  while (answer == 'y' || answer == 'Y') { // changed the while loop condition to check if answer is 'y' or 'Y', instead of while(answer != 'n').
    cout << "Enter your guess between 0 & 50: ";
    cin >> guess;

    
    if (guess < 0 || guess > 50) { // Added this to check if the guess is outside the range of 0 to 50, gives an error message if it is.
      cout << "Please enter a number between 0 and 50.\n"; //Added \n for formatting.
      continue;  // Ask the user to guess again without ending the game
    }

    // changed the else condition to an else if condition if the guess was too low. Added an else branch for if the user guessed correctly.
    if (guess > solution) {
      cout << "Sorry - your guess is too big.\n";
    } else if (guess < solution) {
      cout << "Sorry - your guess is too low.\n";
    } else {
      cout << "Congratulations! You guessed correctly.\n";
    }
  // Added (y/n) so the user knows what to input if they want to continue to play or to stop the program.
    cout << "Guess again? (y/n): ";
    cin >> answer;
  }
  // Added return 0 to end the program.
  return 0;
}
