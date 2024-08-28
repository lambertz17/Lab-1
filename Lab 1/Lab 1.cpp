// Lab 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <cmath>    // For sqrt and pow
#include <limits>   // For numeric_limits
#include <sstream>  // For stringstream
#include <ctime> //to use time() function
using namespace std;

int main() {
    string in1, in2, in3, in4;
    int x1, y1, x2, y2; // stores point 1 and point 2 x and y value
    float dist1, dist2; // stores point 1 and point 2 distance from the origin
    char choice1 = 'Y'; // gives the user the option to continue.
    char choice2; // gives the user the choice of either 'e' or 'g'

    while (choice1 == 'Y') { // initalized while loop to continue until the user choise1 doesn't equal 'Y'
        cout << "How would you like to get the 4 values (enter 'e' to input values, 'g' to generate them): ";
        cin >> choice2;
        choice2 = tolower(choice2);

        //Used ChatGPT for if the user chooses 'e'.
        // In the prompt I entered the lines of code that we given in the lab handout
        // cout << "Please enter 4 values:;
        // cin >> in1 >> in2 >> in3 >> in4;
        // After that I stated the requirements that the code should do with the values given from the user.
        // Should make sure it is a numeric value, within range of -10 and 10, if not display error message and end program.
        
        if (choice2 == 'e') {
            cout << "Please enter 4 values:" << endl;
            cin >> in1 >> in2 >> in3 >> in4; // excepts the user input 

            string inputs[4] = { in1, in2, in3, in4 }; // This stores the user's 4 values into an array called inputs, which will hold the values as strings.
            int values[4]; //This is an array that will hold the 4 values as integers.

            for (int i = 0; i < 4; i++) { //This for loop will iterate through the array inputs.
                stringstream ss(inputs[i]); // stringstream ss applied to the array inputs to convert the string into an integer.
                if (ss >> values[i] && ss.eof() && values[i] >= -10 && values[i] <= 10) { // This takes the value from the stringstream into the index at value[i]
                    continue;                                                            // If this works that means it was a valid input, move to the next iteration.
                }
                else {
                    cout << "Error: Input must be numeric and between -10 and 10. Exiting Program." << endl; // This this branch executes that means the user either entered a non numeric value or the numeric value is out of range.
                    return 1; // 
                }
            }

            // If all inputs are valid, assign them to x1, y1, x2, y2
            x1 = values[0];
            y1 = values[1];
            x2 = values[2];
            y2 = values[3];

            // This calculates the distance from origin for both points.
            dist1 = sqrt(pow(x1, 2) + pow(y1, 2));
            dist2 = sqrt(pow(x2, 2) + pow(y2, 2));

            //Displays the distances of point1 and point2.
            cout << "The distance from point 1 to origin is: " << dist1 << endl;
            cout << "The distance from point 2 to origin is: " << dist2 << endl;

            //Compares point1 and point2 distances and display which one is closer to origin.
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
        else if (choice2 == 'g') {
            // using time function so the sequence of numbers will be different.
            srand(time(0));
            // Generate random values
            x1 = rand() % 21 - 10;
            y1 = rand() % 21 - 10;
            x2 = rand() % 21 - 10;
            y2 = rand() % 21 - 10;

            // Computes distances from point 1 and point2 to the origin
            dist1 = sqrt(pow(x1, 2) + pow(y1, 2));
            dist2 = sqrt(pow(x2, 2) + pow(y2, 2));

            // Output the results
            cout << "Generated values:" << endl;
            cout << "x1 = " << x1 << endl;
            cout << "y1 = " << y1 << endl;
            cout << "x2 = " << x2 << endl;
            cout << "y2 = " << y2 << endl;

            // Outputs the distance values for point 1 and point 2
            cout << "The distance from point 1 (" << x1 << "," << y1 << ") to origin is: " << dist1 << endl;
            cout << "The distance from point 2 (" << x2 << "," << y2 << ") to origin is: " << dist2 << endl;

            // Compares the point 1 and point 2 distances and displays which one is closer to origin.
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
        else {
            // Error message if the user doesn't enter an 'e' or a 'g'.
            cout << "Invalid choice. Please enter 'e' or 'g'." << endl;
        }
         // Continue option for user.
        cout << "Do you want to continue? (Y/N): ";
        cin >> choice1;
        choice1 = toupper(choice1);
    }

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
