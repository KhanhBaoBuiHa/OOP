#include <iostream>
#include <string.h>
#include <ctime> 

using namespace std;

class Person {
    string name, dateOfBirth;
public:
    Person(string name, string dateOfBirth) {
        this->name = name;
        this->dateOfBirth = dateOfBirth;
    }
    string getName(){
        return this->name;
    }
    int getAge(){
        // lấy thời gian hiện tại
        time_t now=time(0);
        tm *ltm = localtime(&now);
        int currentYear = 1900 + ltm->tm_year;
        
        // tách năm sinh
        int birthYear = stoi(dateOfBirth.substr(0,4));
        
        return currentYear-birthYear; 
    }
    string changeName(string newName){
        name=newName;
        return name;
    }
    void display(){
        cout<<"Name: "<<this->getName()<<endl;
        cout<<"Age: "<<this->getAge()<<endl;
    }
};
int main(){
    Person p("Khanh","2005-06-08");
    p.display();
    p.changeName("Tieu");
    p.display();
    return 0;
}