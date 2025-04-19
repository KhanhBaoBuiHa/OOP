#include <iostream>
#include <string.h>

using namespace std;

class account {
    //attributes (constance)
    string theID;
    string theName;
    long long theBalance;
public:
//constructor
account(string theID, string theName, float theBalance){
    this->setName(theName);
    this->setID(theID);
    this->setBalence(theBalance);
}
//access method
//setters()
    void setID(string theID){
        this->theID=theID;
    }
    void setName(string theName){
        this->theName=theName;
    }
    void setBalence(float theBalance){
        this->theBalance=theBalance;
    }
    //getters()
    string getID(){
        return this->theID;
    }
    string getName(){
        return this->theName;
    }
    long long getBalance(){
        return this->theBalance;
    }
    //display()
    void display(){
        cout<<"ID: "<<this->getID()<<endl;
        cout<<"Name: "<<this->getName()<<endl;
        cout<<"Balance: "<<this->getBalance()<<endl;
    }
};

int main() {
   //declare objects
    account a1("123456789","Nguyen Van A",1000000);
   //display
   a1.display();
}