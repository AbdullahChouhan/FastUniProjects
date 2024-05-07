#include <iostream>
#include <string>

class BankAccount {
    private:
        int accountNumber;
        std::string accountHolderName;
        float balance;
    
    public:
        BankAccount(int accountNumber, std::string accountHolderName, float balance) : accountNumber(accountNumber), accountHolderName(accountHolderName), balance(balance) {}

        BankAccount(BankAccount &obj) : accountNumber(obj.accountNumber), accountHolderName(obj.accountHolderName), balance(obj.balance) {}

        void setAccountNumber(int accountNumber) {
            this->accountNumber = accountNumber;
        }

        void setAccountHolderName(std::string accountHolderName) {
            this->accountHolderName = accountHolderName;
        }

        void setBalance(float balance) {
            this->balance = balance;
        }

        int getProductId() {
            return accountNumber;
        }

        std::string getAccountHolderName() {
            return accountHolderName;
        }

        float getBalance() {
            return balance;
        }
};

int main() {
    BankAccount Abdullah(1001, "Abdullah Chouhan", 1200.5);

    std::cout << "Account Number: " << Abdullah.getProductId()
    << "\nAccount Holder Name: " << Abdullah.getAccountHolderName()
    << "\nBalance: " << Abdullah.getBalance();

    BankAccount Chouhan(Abdullah);
    std::cout << "\n\nCopied Account Details:\nAccount Number: " << Chouhan.getProductId()
    << "\nAccount Holder Name: " << Chouhan.getAccountHolderName()
    << "\nBalance: " << Chouhan.getBalance();
}