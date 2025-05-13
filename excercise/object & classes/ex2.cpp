#include <iostream>
#include <string.h>

using namespace std;

class account{
    long long balance;
    string accountHolder;

public:

account(long long balance, string accountHolder){
    this->setBalance(balance);
    this->setAccountHolder(accountHolder);
}
void setBalance(long long balance){
    this->balance=balance;
}
void setAccountHolder(string accountHolder){
    this->accountHolder=accountHolder;
}

long long getBalance(){
    return this->balance;
}
string getAccountHolder(){
    return this->accountHolder;
}

bool isOverDraw(){
    return balance<0;
}

// Ghi nợ (trừ tiền)
void debit(double amount) {
    balance -= amount;
}

// Ghi có (cộng tiền)
void credit(double amount) {
    balance += amount;
}

void display(){
    cout<<"Balance: "<<this->getBalance()<<endl;
    cout<<"AccountHolder: "<<this->getAccountHolder()<<endl;

}

};
int main(){
    account a(100000,"Khanh");
    a.display();

    a.debit(10000);
    a.display();

    a.credit(20000);
    a.display();

    return 0;
}