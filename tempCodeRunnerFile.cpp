#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Car {
    string registrationNumber, brand;
    bool isRented;

public:
    // Constructor
    Car(string registrationNumber, string brand) {
        this->registrationNumber = registrationNumber;
        this->brand = brand;
        this->isRented = false;
    }

    // Setters
    void setRegistrationNumber(string reg) { registrationNumber = reg; }
    void setBrand(string b) { brand = b; }
    void setIsRented(bool status) { isRented = status; }

    // Getters
    string getRegistrationNumber() { return registrationNumber; }
    string getBrand() { return brand; }
    bool getIsRented() { return isRented; }

    void display() {
        cout << "- " << brand << " [" << registrationNumber << "]" << (isRented ? " (Rented)" : "") << endl;
    }
};

class Customer {
    string name, id;
    vector<Car*> rentedCars;

public:
    // Constructor
    Customer(string name, string id) {
        this->name = name;
        this->id = id;
    }

    // Setters
    void setName(string name) { this->name = name; }
    void setID(string id) { this->id = id; }

    // Getters
    string getName() { return name; }
    string getID() { return id; }

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

    // Display
    void display() {
        cout << "\nCustomer: " << name << " (ID: " << id << ")" << endl;
        cout << "Rented Cars:" << endl;
        if (rentedCars.empty()) {
            cout << "  No cars rented." << endl;
        } else {
            for (Car* car : rentedCars) {
                car->display();
            }
        }
    }
};

int main() {
    // Create 2 customers
    Customer customer1("Nguyen Van A", "123");
    Customer customer2("Nguyen Van B", "456");

    // Create 3 cars
    Car car1("ABC", "Toyota");
    Car car2("DEF", "Honda");
    Car car3("GHI", "Lead");

    // Cho khách hàng 1 thuê 2 xe đầu
    customer1.rentCar(&car1);
    customer1.rentCar(&car2);

    // Khách hàng 2 thuê xe 3
    customer2.rentCar(&car3);

    // Khách hàng 1 trả xe 2, khách hàng 2 thuê xe đó
    customer1.returnCar(&car2);
    customer2.rentCar(&car2);

    // Hiển thị thông tin khách hàng 2 và các xe đang mượn
    customer2.display();

    return 0;
}
