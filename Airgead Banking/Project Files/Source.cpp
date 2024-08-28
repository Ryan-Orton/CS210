// Ryan Orton
// CS210
// 8-2-24
// Project 2

#include <iostream>
#include "investment.h"

using namespace std;

// Constructor implementation for the Investment class
Investment::Investment(double initial, double monthly, double interest, int years) :
    initialInvestment(initial), monthlyDeposit(monthly), annualInterest(interest), numberOfYears(years) {}

// Function to calculate year-end balance without additional monthly deposits
void Investment::calculateYearEndBalanceWithoutDeposits() {
    double openingAmount = initialInvestment;
    for (int year = 1; year <= numberOfYears; ++year) {
        double yearEndInterest = 0;
        for (int month = 1; month <= 12; ++month) {
            double interest = (openingAmount * (annualInterest / 100) / 12);
            yearEndInterest += interest;
            openingAmount += interest;
        }
        // Display year-end balance and interest
        cout << "Year " << year << ": Year End Balance = " << openingAmount << ", Year End Earned Interest = " << yearEndInterest << endl;
    }
}

// Function to calculate year-end balance with additional monthly deposits
void Investment::calculateYearEndBalanceWithDeposits() {
    double openingAmount = initialInvestment;
    for (int year = 1; year <= numberOfYears; ++year) {
        double yearEndInterest = 0;
        for (int month = 1; month <= 12; ++month) {
            double total = openingAmount + monthlyDeposit;
            double interest = (total * (annualInterest / 100) / 12);
            yearEndInterest += interest;
            openingAmount = total + interest;
        }
        // Display year-end balance and interest
        cout << "Year " << year << ": Year End Balance = " << openingAmount << ", Year End Earned Interest = " << yearEndInterest << endl;
    }
}

int main() {
    double initialInvestment, monthlyDeposit, annualInterest;
    int numberOfYears;
    char continueOption;

    // Prompt user for initial investment amount
    cout << "Initial Investment Amount: ";
    cin >> initialInvestment;

    // Prompt user for monthly deposit amount
    cout << "Monthly Deposit: ";
    cin >> monthlyDeposit;

    // Prompt user for annual interest rate
    cout << "Annual Interest (Compounded): ";
    cin >> annualInterest;

    // Prompt user for number of years
    cout << "Number of Years: ";
    cin >> numberOfYears;

    // Display message to continue
    cout << "Press any key to continue...";

    // Create an Investment object with user inputs
    Investment investment(initialInvestment, monthlyDeposit, annualInterest, numberOfYears);

    // Calculate and display year-end balances without additional monthly deposits
    investment.calculateYearEndBalanceWithoutDeposits();

    // Calculate and display year-end balances with additional monthly deposits
    investment.calculateYearEndBalanceWithDeposits();

    // Ask user if they want to test different values
    cout << "Do you want to test different values? (yes/no): ";
    cin >> continueOption;

    // Loop to allow user to test different values
    while (continueOption == 'yes') {
        // Prompt user for initial investment amount
        cout << "Initial Investment Amount: ";
        cin >> initialInvestment;

        // Prompt user for monthly deposit amount
        cout << "Monthly Deposit: ";
        cin >> monthlyDeposit;

        // Prompt user for annual interest rate
        cout << "Annual Interest (Compounded): ";
        cin >> annualInterest;

        // Prompt user for number of years
        cout << "Number of Years: ";
        cin >> numberOfYears;

        // Create a new Investment object with user inputs
        Investment newInvestment(initialInvestment, monthlyDeposit, annualInterest, numberOfYears);

        // Calculate and display year-end balances without additional monthly deposits
        newInvestment.calculateYearEndBalanceWithoutDeposits();

        // Calculate and display year-end balances with additional monthly deposits
        newInvestment.calculateYearEndBalanceWithDeposits();

        // Ask user if they want to test different values again
        cout << "Do you want to test different values? (yes/no): ";
        cin >> continueOption;
    }

    return 0;
}
