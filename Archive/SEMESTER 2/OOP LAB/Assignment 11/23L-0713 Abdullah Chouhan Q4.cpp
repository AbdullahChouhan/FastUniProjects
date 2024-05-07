#include <iostream>
#include <cstring>

class BankAccount {
    private:
        int accountNumber;
        std::string accountType;
        double balance, interestRate;
    public:
        BankAccount(int accountNumber, std::string accountType, double balance, double interestRate) : accountNumber(accountNumber), accountType(accountType), balance(balance), interestRate(interestRate) {
            std::cout << "Bank Account created\n";
        }

        BankAccount(BankAccount &obj) : accountNumber(obj.accountNumber), accountType(obj.accountType), balance(obj.balance), interestRate(obj.interestRate) {}

        void setAccountNumber(int accountNumber) {
            this->accountNumber = accountNumber;
        }

        void setAccountType(std::string accountType) {
            this->accountType = accountType;
        }

        void setBalance(double balance) {
            this->balance = balance;
        }

        void setInterestRate(double interestRate) {
            this->interestRate = interestRate;
        }
        
        virtual void withdraw(double amount) {
            if(balance - amount < 0) {
                std::cout << "Insufficient balance\n";
            } else {
                balance -= amount;
            }
        }

        int getProductId() {
            return accountNumber;
        }

        std::string getAccountType() {
            return accountType;
        }

        double getBalance() {
            return balance;
        }
        double getInterestRate() {
            return interestRate;
        }
        ~BankAccount() {
            std::cout << "Bank Account destroyed\n";
        }
};

class SavingsAccount : public BankAccount {
    private:
        double minimumBalance;
    public:
        SavingsAccount(int accountNumber, std::string accountType = "Savings", double balance = 0, double interestRate = 0, double minimumBalance = 0) : BankAccount(accountNumber, accountType, balance, interestRate), minimumBalance(minimumBalance) {
            std::cout << "Savings Account created\n";
        }
        void setMinimumBalance(double minimumBalance) {
            this->minimumBalance = minimumBalance;
        }
        double getMinimumBalance() {
            return minimumBalance;
        }
        void withdraw(double amount) override {
            if(this->getBalance() - amount < minimumBalance) {
                std::cout << "Insufficient balance\n";
            } else {
                this->setBalance(this->getBalance() - amount);
            }
        }
        ~SavingsAccount() {
            std::cout << "Savings Account destroyed\n";
        }
};

class CheckingAccount : public BankAccount {
    private:
        double overdraftLimit;
    public:
        CheckingAccount(int accountNumber, std::string accountType = "Checking", double balance = 0, double interestRate = 0, double overdraftLimit = 0) : BankAccount(accountNumber, accountType, balance, interestRate), overdraftLimit(overdraftLimit) {
            std::cout << "Checking Account created\n";
        }
        void setOverdraftLimit(double overdraftLimit) {
            this->overdraftLimit = overdraftLimit;
        }
        double getOverdraftLimit() {
            return overdraftLimit;
        }
        ~CheckingAccount() {
            std::cout << "Checking Account destroyed\n";
        }
};

class FixedDepositAccount : public BankAccount {
    private:
        int termLength;
    public:
        FixedDepositAccount(int accountNumber, std::string accountType = "Fixed Deposit", double balance = 0, double interestRate = 0, int termLength = 0) : BankAccount(accountNumber, accountType, balance, interestRate), termLength(termLength) {
            std::cout << "Fixed Deposit Account created\n";
        }
        void setTermLength(int termLength) {
            this->termLength = termLength;
        }
        void decrementTermLength() {
            this->termLength--;
        }
        int getTermLength() {
            return termLength;
        }
        void withdraw(double amount) override {
            if (termLength > 0) {
                std::cout << "Cannot withdraw\n";
            } else {
                this->setBalance(this->getBalance() - amount);
            }
        }
        ~FixedDepositAccount() {
            std::cout << "Fixed Deposit Account destroyed\n";
        }
};

int main() {
    BankAccount** accounts = new BankAccount*[3];
    accounts[0] = new SavingsAccount(1, "Savings", 1000, 0.05, 500);
    accounts[1] = new CheckingAccount(2, "Checking", 2000, 0.1, 1000);
    accounts[2] = new FixedDepositAccount(3, "Fixed Deposit", 3000, 0.2, 5);
    for (int i = 0; i < 3; i++) {
        accounts[i]->withdraw(500);
        delete accounts[i];
    }
    delete[] accounts;
    return 0;
}