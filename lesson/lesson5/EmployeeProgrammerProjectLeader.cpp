#include <string>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Employee;
class Programmer;
//class SoftwareHouse;

class Employee
{
private:
    string number;
    string name;
    double salary;
public:
    void setNumber(string number){
        this->number=number;
    }
    void setName(string name){
        this->name=name;
    }
    void setSalary(double salary){
        this->salary=salary;
    }

    string getNumber(){
        return this->number;
    }
    string getName(){
        return this->name;
    }
    double getSalary(){
        return this->salary;
    }
    Employee(string number, string name, double salary){
        this->setNumber(number);
        this->setName(name);
        this->setSalary(salary);
    }
    //
    void display(){
        cout<<"Number: "<<this->getNumber()<<endl;
        cout<<"Name: "<<this->getName()<<endl;
        cout<<"Salary: "<<this->getSalary()<<endl;
    }

    virtual ~Employee() {}
};

class Programmer: public Employee {
    private:
        string language;
    public:
        Programmer(string number, string name, double salary, string language)
            : Employee(number, name, salary) {
            this->language = language;
        }
    
        void display(){
            Employee::display(); // tái sử dụng hàm hiển thị từ lớp cha
            cout << "Language: " << this->language << endl;
        }
    };
    

class SoftwareHouse{
    private:
    vector<Programmer*> theProgrammers;
public:
    void addProgrammer(Programmer* p) {
        theProgrammers.push_back(p);
    }

    void display() {
        cout << "--- Software House Programmers ---" << endl;
        for (auto p : theProgrammers) {
            p->display();
            cout << "---------------------------" << endl;
        }
    }

    ~SoftwareHouse() {
        for (auto p : theProgrammers) {
            delete p;
        }
    }
};
int main(){
    SoftwareHouse sh;

    Programmer* p1 = new Programmer("001", "Alice", 5000.0, "C++");
    Programmer* p2 = new Programmer("002", "Bob", 5500.0, "Java");
    Programmer* p3 = new Programmer("003", "Charlie", 6000.0, "Python");

    sh.addProgrammer(p1);
    sh.addProgrammer(p2);
    sh.addProgrammer(p3);

    sh.display();

    return 0;
}