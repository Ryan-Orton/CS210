#ifndef AIRGEAD_BANKING_INVESTMENT_H_
#define AIRGEAD_BANKING_INVESTMENT_H_

class Investment {
private:
    double initialInvestment;
    double monthlyDeposit;
    double annualInterest;
    int numberOfYears;

public:
    // Constructor
    Investment(double initial, double monthly, double interest, int years);

    // Methods to calculate year-end balances
    void calculateYearEndBalanceWithoutDeposits();
    void calculateYearEndBalanceWithDeposits();

    // Getter and Setter methods (if necessary)
};

#endif  // AIRGEAD_BANKING_INVESTMENT_H_
