#include <string>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Customer;

class Car{
    string registrationNumber, brand;
    bool isRented;
public:
    //constructor
    Car(string registrationNumber, string brand){
        this->setRegistrationNumber(registrationNumber);
        this->setBrand(brand);
        this->isRented=false;
    }
    //access method
    //setter
    void setRegistrationNumber(string registrationNumber){
        this->registrationNumber=registrationNumber;
    }
    void setBrand(string brand){
        this->brand=brand;
    }
    void setIsRented(bool isRented){
        this->isRented=isRented;
    }
    //getter
    string getRegistrationNumber(){
        return this->registrationNumber;
    }
    string getBrand(){
        return this->brand;
    }
    bool getIsRented(){
        return this->isRented;
    }
};

class Customer{
    string name,id;
    vector<Car*> rentedCars;
public:
    //constructor
    Customer(string name, string id){
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

    // Rent a car
    void rentCar(Car* car) {
        if (!car->getIsRented()) {
            rentedCars.push_back(car);
            car->setIsRented(true);
        } else {
            cout << "Car " << car->getRegistrationNumber() << " is already rented.\n";
        }
    }

    // Return a car
    void returnCar(Car* car) {
        for (auto it = rentedCars.begin(); it != rentedCars.end(); ++it) {
            if (*it == car) {
                car->setIsRented(false);
                rentedCars.erase(it);
                return;
            }
        }
    }
    
    void display(){
        cout<<"Customer name: "<<this->getName()<<endl;
        cout<<"Customer ID: "<<this->getID()<<endl;
        cout<<"Rented cars: "<<endl;
        for (int i=0; i<rentedCars.size(); i++){
            cout<<rentedCars[i]->getBrand()<<" "<<rentedCars[i]->getRegistrationNumber()<<endl;
        }
    }
};

int main(){
    //create 2 persons
    Customer customer1("Nguyen Van A", "123");
    Customer customer2("Nguyen Van B", "456");

    //create 2 cars
    Car car1("ABC", "Toyota");
    Car car2("DEF", "Honda");
    Car car3("GHI", "Lead");

    customer1.rentCar(&car1);
    customer1.rentCar(&car2);
    customer2.rentCar(&car3);
    customer1.returnCar(&car2);
    customer2.rentCar(&car2);
    
    //display
    customer2.display();
    
    /*
    delete(&car1);
    delete(&car2);
    delete(&car3);
    delete(&customer1);
    delete(&customer2);
    return 0;
    */
}