// TITLE:        ACC COSC-2436 - Lab 1
// AUTHOR:       Andrew Graziano
// Professor:    Kathryn Rehfield
// DESCRIPTION:  This program allows for a person to add, remove, sort, and search through an Array

#include <iostream>
#include <string>
#include "ArrayBag.h" // Include the header file for the ArrayBag class

using namespace std;

int main()
{
    int didSort; // Variable to track if the bag has been sorted
    ArrayBag<int> bag; // Create an instance of the ArrayBag class to hold integers
    int items[] = {1, 33, 6, 9, 2, 65, 4, 29, 5, 8, 39, 88, 7, 25, 51, 3, 99, 14, 11, 10}; // An array of integers to add to the bag

    cout << "Adding positive integers to the bag: " << endl;
    for (int i = 0; i < 20; i++)
    {
        bag.add(items[i]); // Add the integers from the 'items' array to the bag
    }

    bool isRestart = true; // A flag to control the main loop
    while (isRestart == true)
    {
        int clientInput; // Variable to store the user's menu choice
        cout << "Menu:\n"
             << "Press 1 to display the contents of the bag.\n"
             << "Press 2 to add values to the bag.\n"
             << "Press 3 to remove values from the bag.\n"
             << "Press 4 to sort the bag.\n"
             << "Press 5 to search for a value using iterative search.\n"
             << "Press 6 to search for a value using recursive search \n"
             << "Press 7 to Quit\n";

        // Input validation
        if (!(cin >> clientInput))
        {
            cin.clear(); // Clear the error state of cin.
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input.
            cout << "You did not enter a valid number. \n";
            continue; // Skip to the next iteration of the loop.
        }

        if (clientInput < 1 || clientInput > 7)
        {
            cout << "You did not enter a valid selection. \n";
            continue; // Skip to the next iteration of the loop.
        }// end if 

        // Handle valid input here.
        switch (clientInput)
        {
            case 1:
                displaylist(bag); // Display the contents of the bag
                break;
            case 2:
                bagAdder(bag); // Add values to the bag
                break;
            case 3:
                bagRemover(bag); // Remove values from the bag
                break;
            case 4:
                bagSort(bag, didSort); // Sort the bag
                break;
            case 5:
                FindIterative(bag, didSort); // Search for a value using iterative search
                break;
            case 6:
                FindRecursive(bag, didSort); // Search for a value using recursive search
                break;
            case 7:
                isRestart = false; // Quit the program
                break;
        }// end switch
    }// end while

    return 0; // Exit the program
}// end main
