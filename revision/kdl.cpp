#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Lớp cơ sở Account
class Account {
protected:
    string accountNumber;
    double balance;
public:
    Account(string accountNumber, double balance) {
        this->accountNumber = accountNumber;
        this->balance = balance;
    }

    virtual void guiTien(double amount) {
        balance += amount;
    }

    virtual bool rutTien(double amount) = 0; // abstract

    virtual void display() = 0;

    string getAccountNumber() {
        return accountNumber;
    }

    double getBalance() {
        return balance;
    }

    virtual ~Account() {}
};

// Tài khoản thường
class NormalAccount : public Account {
public:
    NormalAccount(string accountNumber, double balance)
        : Account(accountNumber, balance) {}

    bool rutTien(double amount) override {
        if (amount <= balance) {
            balance -= amount;
            return true;
        }
        cout << "Insufficient balance in normal account!" << endl;
        return false;
    }

    void display() override {
        cout << "Normal Account Number: " << accountNumber << ", Balance: " << balance << endl;
    }
};

// Tài khoản vàng lai (có hạn mức thấu chi)
class PremiumAccount : public Account {
private:
    double creditLimit;
public:
    PremiumAccount(string accountNumber, double balance, double creditLimit)
        : Account(accountNumber, balance), creditLimit(creditLimit) {}

    bool rutTien(double amount) override {
        if (amount <= balance + creditLimit) {
            balance -= amount;
            return true;
        }
        cout << "Exceeds balance and credit limit in premium account!" << endl;
        return false;
    }

    void display() override {
        cout << "Premium Account Number: " << accountNumber
             << ", Balance: " << balance
             << ", Credit Limit: " << creditLimit << endl;
    }
};

// Ngân hàng
class Bank {
private:
    string name;
    vector<Account*> accounts;
public:
    Bank(string name, vector<Account*> accounts)
        : name(name), accounts(accounts) {}

    void displayAccounts() {
        cout << "Bank Name: " << name << endl;
        for (auto acc : accounts) {
            acc->display();
        }
    }

    ~Bank() {
        for (auto acc : accounts)
            delete acc;
    }
};

// Main
int main() {
    Account* acc1 = new NormalAccount("123456", 1000.0);
    Account* acc2 = new PremiumAccount("654321", 2000.0, 500.0);

    Bank* bank = new Bank("MyBank", {acc1, acc2});

    // Gửi tiền
    acc1->guiTien(500);
    acc2->guiTien(500);

    // Rút tiền
    acc1->rutTien(300);    // hợp lệ
    acc2->rutTien(2750);   // hợp lệ (vì 2000 + 500 >= 2500)

    // Hiển thị thông tin
    bank->displayAccounts();

    delete bank;
    return 0;
}
