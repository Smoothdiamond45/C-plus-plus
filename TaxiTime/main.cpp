#include <iomanip>
#include <iostream>
#include <limits>
#include "DispatchSystem.h"
#include <string>

using namespace std;

// Global variables - these can be accessed from anywhere in the program
DispatchSystem dispatch;  // Our main dispatch system object
int choice;              // Stores the user's menu selection

// Function declarations
void executeChoice();
void displayMenu();
void clearScreen();      // New function to handle screen clearing across platforms

// New function to handle screen clearing for different operating systems
void clearScreen() {
// i am 40/60 on how all this works, i added the rest in cus i need it to work on my linux machine
// which is actually just my silicone macbook running a virtaulisted emulated version of ubuntu so i can use code blocks
// yes it does work
// yes its a pain in my backside
    #ifdef _WIN32
        // On Windows systems, use "cls" command
        system("cls");
    #elif defined(__unix__) || defined(__unix) || defined(__linux__) || defined(__APPLE__)
        // On Unix-like systems (Linux, macOS), use "clear" command
        system("clear");
    #else
        // For other systems where we can't clear the screen,
        // print several newlines to create visual separation
        for(int i = 0; i < 50; i++) {
            cout << '\n';
        }
    #endif
}


int main() {
    string input;

    while (true) {
        displayMenu();
        getline(cin, input);

        try {
            choice = stoi(input);

            if (choice >= 1 && choice <= 5) {
                executeChoice();

                if (choice == 5) {
                    break;
                }
            } else {
                cout << "Please enter a number between 1 and 5.\n";
            }

        } catch (const invalid_argument&) {
            cout << "Invalid input. Please enter a number.\n";
        } catch (const out_of_range&) {
            cout << "Number out of range. Please try again.\n";
        }
    }
    return 0;
}
// Display the main menu options to the user in a neat and very small way
void displayMenu() {
    cout << "\n=== Call Out Dispatch Services ===\n";
    cout << "1. Print All Vehicles and Drivers\n";
    cout << "2. Print All Booked Drivers and Vehicles\n";
    cout << "3. Make a Booking\n";
    cout << "4. Complete Fare\n";
    cout << "5. Exit Program\n";
    cout << "Enter your choice (1-5): ";
}
// the switch never dies im using this in every c++ project, cant stop me
void executeChoice() {
    switch(choice) {
        case 1:
            dispatch.printAllVehiclesandDrivers();
            break;
        case 2:
            dispatch.printBookedVehiclesAndDrivers();
            break;
        case 3:
            dispatch.makeBooking();
            break;
        case 4:
            dispatch.completeFare();
            break;
        case 5:
            cout << "Exiting program. Goodbye!\n"; // <- do i get extra points for being polite?
            return;
    }

    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    clearScreen(); // gets rid of that ugly copyes of the mcducking menu
}
