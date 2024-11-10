#include <iostream>
#include <string>
#include <sstream>

class Account {
protected:
    static int nextAccountNo;
    std::string accountNo;
    std::string accountName;
    float balance;

public:
    Account(const std::string& name, float initBalance)
        : accountName(name), balance(initBalance) {
        accountNo = generateAccountNo();
    }

    virtual void description() const = 0;
    virtual ~Account() {}

protected:
    std::string generateAccountNo() {
        std::ostringstream oss;
        oss << "ACC-" << nextAccountNo++;
        return oss.str();
    }
};

int Account::nextAccountNo = 1;

class CurrentAccount : public Account {
    float cashCreditLimit;
    float cashCharge;

public:
    CurrentAccount(const std::string& name, float initBalance, float creditLimit, float charge)
        : Account(name, initBalance), cashCreditLimit(creditLimit), cashCharge(charge) {}

    void description() const override {
        std::cout << "Current Account: Cash credit limit and charges apply.\n";
    }
};

class SavingAccount : public Account {
    float interestRate;
    float minimumBalance;

public:
    SavingAccount(const std::string& name, float initBalance, float rate, float minBalance)
        : Account(name, initBalance), interestRate(rate), minimumBalance(minBalance) {}

    void description() const override {
        std::cout << "Saving Account: Interest applied with minimum balance requirement.\n";
    }
};

class MonthlyDepositScheme : public Account {
protected:
    float interestRate;
    float monthlyDepositAmount;
    int maximumTerm;

public:
    MonthlyDepositScheme(const std::string& name, float initBalance, float rate, float depositAmount, int term)
        : Account(name, initBalance), interestRate(rate), monthlyDepositAmount(depositAmount), maximumTerm(term) {}

    void description() const override {
        std::cout << "Monthly Deposit Scheme: Deposit a fixed amount monthly.\n";
    }
};

class LoanAccount : public Account {
    float interestRate;
    float loanAmount;
    int loanTerm;

public:
    LoanAccount(const std::string& name, float initBalance, float rate, float amount, int term)
        : Account(name, initBalance), interestRate(rate), loanAmount(amount), loanTerm(term) {}

    void description() const override {
        std::cout << "Loan Account: Repay a fixed loan amount over a term.\n";
    }
};

class TwoYearMDS : public MonthlyDepositScheme {
public:
    TwoYearMDS(const std::string& name, float initBalance, float rate, float depositAmount)
        : MonthlyDepositScheme(name, initBalance, rate, depositAmount, 24) {}

    void description() const override {
        std::cout << "Two-Year MDS: Fixed monthly deposits for 2 years.\n";
    }
};


int main()
{
    CurrentAccount currentAcc("John Doe", 1000.0, 500.0, 20.0);
    currentAcc.description();

    SavingAccount savingAcc("Jane Doe", 1500.0, 2.5, 100.0);
    savingAcc.description();

    MonthlyDepositScheme monthlyDep("Jack Doe", 2000.0, 3.5, 100.0, 12);
    monthlyDep.description();

    LoanAccount loanAcc("Jill Doe", 5000.0, 4.0, 3000.0, 24);
    loanAcc.description();

    TwoYearMDS twoYearMDS("Mike Doe", 1200.0, 3.0, 100.0);
    twoYearMDS.description();

    return 0;
}
