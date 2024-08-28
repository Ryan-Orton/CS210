// Ryan Orton
// 07/18/2024
// CS210 Project One


#include <iostream>
#include <string>
using namespace std;

// Declare global strings
string twelveHourTime;
string twentyFourHourTime;

// Declare functions to be called
void Convert12To24Hour();
void Convert24To12Hour();

// Prints Menu
void PrintMenu() {
	cout << "*************************" << endl;
	cout << "* 1- Add One Hour" << "       *" << endl;
	cout << "* 2- Add One Minute" << "     *" << endl;
	cout << "* 3- Add One Second" << "     *" << endl;
	cout << "* 4- Exit Program" << "       *" << endl;
	cout << "*************************" << endl;
}

// Prints 12 Hour Clock
void Print12HourClock(string) {
	cout << "*************************" << endl;
	cout << "*     12- Hour Clock    *" << endl;
	cout << "*       " << twelveHourTime << "     * " << endl;
	cout << "*************************" << endl;
}

// Prints 24 Hour Clock
void Print24HourClock(string) {
	cout << "*************************" << endl;
	cout << "*     24- Hour Clock    *" << endl;
	cout << "*       " << twentyFourHourTime << "        *" << endl;
	cout << "*************************" << endl;
}

// Determines if domestic/ international
string GetNationality() {
	string nationalityID;
	while (true) {
		cout << "Are you domestic or international?" << endl;
		cin >> nationalityID;
		if (nationalityID == "domestic" || nationalityID == "international") {
			break;
		}
		else {
			cout << "Invalid input. Please enter either 'domestic' or 'international'." << endl;
		}
	}
	return nationalityID;
}

// Gets current time in the user's format
void GetInputTime(string nationalityID) {
	if (nationalityID == "domestic") {
		cout << "Enter Current Time in 00:00:00 AM/PM format:" << endl;
        cin.ignore(); // Ignore leftover newline character from previous input
        getline(cin, twelveHourTime); // Use getline to handle spaces in AM/PM
        Convert12To24Hour();
	}
	else if (nationalityID == "international") {
		cout << "Enter Current Time in 00:00:00 format:" << endl;
		cin >> twentyFourHourTime;
        Convert24To12Hour();
	}
}

// Function to convert 12 our to 24 hour
void Convert12To24Hour() {
    string period = twelveHourTime.substr(9, 2); // AM or PM
    int hours = stoi(twelveHourTime.substr(0, 2));
    int minutes = stoi(twelveHourTime.substr(3, 2));
    int seconds = stoi(twelveHourTime.substr(6, 2));

    if (period == "PM" || "pm" && hours != 12) {
        hours += 12;
    }
    else if (period == "AM" && hours == 12) {
        hours = 0;
    }

    twentyFourHourTime = (hours < 10 ? "0" : "") + to_string(hours) + ":" +
        (minutes < 10 ? "0" : "") + to_string(minutes) + ":" +
        (seconds < 10 ? "0" : "") + to_string(seconds);
}

// Function to convert 24 hour to 12 hour
void Convert24To12Hour() {
    int hours = stoi(twentyFourHourTime.substr(0, 2));
    int minutes = stoi(twentyFourHourTime.substr(3, 2));
    int seconds = stoi(twentyFourHourTime.substr(6, 2));
    string period = "AM";

    if (hours >= 12) {
        period = "PM";
        if (hours > 12) {
            hours -= 12;
        }
    }
    else if (hours == 0) {
        hours = 12;
    }

    twelveHourTime = (hours < 10 ? "0" : "") + to_string(hours) + ":" +
        (minutes < 10 ? "0" : "") + to_string(minutes) + ":" +
        (seconds < 10 ? "0" : "") + to_string(seconds) + " " + period;
}

// Function adds one hour
void AddOneHour() {
    int hours = stoi(twentyFourHourTime.substr(0, 2));
    int minutes = stoi(twentyFourHourTime.substr(3, 2));
    int seconds = stoi(twentyFourHourTime.substr(6, 2));

    hours = (hours + 1) % 24;
    twentyFourHourTime = (hours < 10 ? "0" : "") + to_string(hours) + ":" +
        (minutes < 10 ? "0" : "") + to_string(minutes) + ":" +
        (seconds < 10 ? "0" : "") + to_string(seconds);

    Convert24To12Hour();
}

// Function adds one minute
void AddOneMinute() {
    int hours = stoi(twentyFourHourTime.substr(0, 2));
    int minutes = stoi(twentyFourHourTime.substr(3, 2));
    int seconds = stoi(twentyFourHourTime.substr(6, 2));

    minutes = (minutes + 1) % 60;
    if (minutes == 0) {
        hours = (hours + 1) % 24;
    }

    twentyFourHourTime = (hours < 10 ? "0" : "") + to_string(hours) + ":" +
        (minutes < 10 ? "0" : "") + to_string(minutes) + ":" +
        (seconds < 10 ? "0" : "") + to_string(seconds);

    Convert24To12Hour();
}

// Function adds one second
void AddOneSecond() {
    int hours = stoi(twentyFourHourTime.substr(0, 2));
    int minutes = stoi(twentyFourHourTime.substr(3, 2));
    int seconds = stoi(twentyFourHourTime.substr(6, 2));

    seconds = (seconds + 1) % 60;
    if (seconds == 0) {
        minutes = (minutes + 1) % 60;
        if (minutes == 0) {
            hours = (hours + 1) % 24;
        }
    }

    twentyFourHourTime = (hours < 10 ? "0" : "") + to_string(hours) + ":" +
        (minutes < 10 ? "0" : "") + to_string(minutes) + ":" +
        (seconds < 10 ? "0" : "") + to_string(seconds);

    Convert24To12Hour();
}

//Main program
int main() {
    int userInput;
    string nationality = GetNationality();

    GetInputTime(nationality);
   
    // Display initial times
    Print12HourClock(twelveHourTime);
    Print24HourClock(twentyFourHourTime);

    // Decision tree
    while (true) {
        PrintMenu();
        cin >> userInput;

        switch (userInput) {
        case 1:
            AddOneHour();
            break;
        case 2:
            AddOneMinute();
            break;
        case 3:
            AddOneSecond();
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice. Please select a valid option." << endl;
            break;
        }

        // Display updated times
        Print12HourClock(twelveHourTime);
        Print24HourClock(twentyFourHourTime);
    }
}
