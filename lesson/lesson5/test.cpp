#include <string>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Person;

class House{
    string houseID, address;
    vector<Person*> owners;

public:
//constructor
    House(string id, string addr){
        this->setID(id);
        this->setAddr(addr);
    }
//access method
//setter
    void setID(string id){ 
        this->houseID=id;
    }
    void setAddr(string addr){ 
        this->address=addr;
    }
//getter
    string getID(){
        return this->houseID;
    }
    string getAddr(){
        return this->address;
    }
// relationship
void addOwner(Person* owner);

// display
void display(); 
};

class Person{
    string name, id;
    list<House*> houses;
public:
//constructor
    Person(string name, string id){
        this->setName(name);
        this->setID(id);
    }
//access method
//setter
    void setName(string name){
        this->name=name;
    }
    void setID(string id){
        this->id=id;
    }
//getter
    string getName(){
        return this->name;
    }
    string getID(){
        return this->id;
    }
// relationship
void addHouse(House* house);

// display
void display();
};

void House::addOwner(Person* owner) {
    owners.push_back(owner);
}

void Person::addHouse(House* house) {
    houses.push_back(house);
    house->addOwner(this);
}

//display
void House::display() {
    cout << "\nHouse ID: " << this->getID() << endl;
    cout << "Address: " << this->getAddr() << endl;
    cout << "Owners: " << endl;
    for (Person* owner : owners) {
        cout << " - " << owner->getName() << endl;
    }
}
void Person::display() {
    cout << "\nName: " << this->getName() << endl;
    cout << "ID: " << this->getID() << endl;
    cout << "Houses: " << endl;
    for (House* house : houses) {
        cout << " - " << house->getAddr() << endl;
    }
}

int main() {
    //create 3 persons
    Person p1("Nguyen Van A", "123");
    Person p2("Nguyen Van B", "456");
    Person p3("Nguyen Van C", "789");
    
    //create 2 houses
    House h1("183/5", "Bui Vien St");
    House h2("01", "Le Van Chi St");
    
    //add owners to houses
    p1.addHouse(&h1);
    p2.addHouse(&h1);
    p3.addHouse(&h1);
    p3.addHouse(&h2);

    //Display
    cout<<"Owners 's information"<<endl;
    p1.display();
    p2.display();
    p3.display();
    cout<<"Houses 's information"<<endl;
    h1.display();
    h2.display();
    
    delete h1;
    delete h2;
    delete p1;
    delete p2;
    delete p3;

    return 0;
}