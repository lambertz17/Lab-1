// Lab 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <cmath>    // For sqrt and pow
#include <limits>   // For numeric_limits
using namespace std;

bool getValidInteger(int& value, const string& prompt) {
    cout << prompt;
    while (true) {
        if (cin >> value && value >= -10 && value <= 10) {
            return true; // Valid integer in range
        }
        else {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter an integer between -10 and 10: ";
        }
    }
}

int main() {
    int x1, y1, x2, y2;
    float dist1, dist2;
    char choice1; // 'e' or 'g' choice
    char continueChoice; // continue choice
    srand(time(0));

    do {
        cout << "How would you like to get the 4 values ('e' for enter, 'g' for generate): ";
        cin >> choice1;
        choice1 = tolower(choice1);
        if (choice1 != 'e' && choice1 != 'g') {
            cout << "Invalid choice. Please enter 'e' or 'g'" << endl;
        }
    } while (choice1 != 'e' && choice1 != 'g');

    if (choice1 == 'e') {
        // Get valid integer inputs from the user
        getValidInteger(x1, "Enter x1 (-10 to 10): ");
        getValidInteger(y1, "Enter y1 (-10 to 10): ");
        getValidInteger(x2, "Enter x2 (-10 to 10): ");
        getValidInteger(y2, "Enter y2 (-10 to 10): ");


        // Compute distances from the origin
        dist1 = sqrt(pow(x1, 2) + pow(y1, 2));
        dist2 = sqrt(pow(x2, 2) + pow(y2, 2));

        // Output the results
        cout << "The distance from point 1 (" << x1 << "," << y1 << ") to origin is: " << dist1 << endl;
        cout << "The distance from point 2 (" << x2 << "," << y2 << ") to origin is: " << dist2 << endl;

        if (dist1 < dist2) {
            cout << "Point 1 is closer to the origin." << endl;
        }
        else if (dist1 > dist2) {
            cout << "Point 2 is closer to the origin." << endl;
        }
        else {
            cout << "Both points are equidistant from the origin." << endl;
        }
    }
    else if (choice1 == 'g') {
        // Generate random values
        x1 = rand() % 21 - 10;
        y1 = rand() % 21 - 10;
        x2 = rand() % 21 - 10;
        y2 = rand() % 21 - 10;

        // Compute distances from the origin
        dist1 = sqrt(pow(x1, 2) + pow(y1, 2));
        dist2 = sqrt(pow(x2, 2) + pow(y2, 2));

        // Output the results
        cout << "Generated values:" << endl;
        cout << "x1 = " << x1 << endl;
        cout << "y1 = " << y1 << endl;
        cout << "x2 = " << x2 << endl;
        cout << "y2 = " << y2 << endl;

        cout << "The distance from point 1 (" << x1 << "," << y1 << ") to origin is: " << dist1 << endl;
        cout << "The distance from point 2 (" << x2 << "," << y2 << ") to origin is: " << dist2 << endl;

        if (dist1 < dist2) {
            cout << "Point 1 is closer to the origin." << endl;
        }
        else if (dist1 > dist2) {
            cout << "Point 2 is closer to the origin." << endl;
        }
        else {
            cout << "Both points are equidistant from the origin." << endl;
        }
    }

    // Ask if the user wants to continue
    do {
        cout << "Do you want to run the program again? (Y/N): ";
        cin >> continueChoice;
        continueChoice = toupper(continueChoice);
        if (continueChoice != 'Y' && continueChoice != 'N') {
            cout << "Invalid choice. Please enter 'Y' or 'N'" << endl;
        }
    } while (continueChoice != 'Y' && continueChoice != 'N');

    return 0;
}





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
