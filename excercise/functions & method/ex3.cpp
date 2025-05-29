#include <iostream>
#include <string.h>

using namespace std;

class House {
    string theAddress;
    int theNumberOfRooms;

public:
House(string anAddress, int aNumberOfRooms){
    this->setAddress(anAddress);
    this->setNumberOfRooms(aNumberOfRooms);
}
void setAddress(string Address) {
    this->theAddress = Address;
}
void setNumberOfRooms(int NumberOfRooms) {
    this->theNumberOfRooms = NumberOfRooms;
}

string getAddress() {
    return this->theAddress;
}
int getNumberOfRooms() {
    return this->theNumberOfRooms;
}
void extend(int aNumberOfRooms) {
    this->theNumberOfRooms += aNumberOfRooms;
} //Add new rooms

void display() {
    cout << "Address: " << this->theAddress << endl;
    cout << "Number of Rooms: " << this->theNumberOfRooms << endl;
}

};
int main(){
    House myHouse("01 Ta Quang Buu", 3);
    myHouse.display();
    myHouse.extend(2);
    myHouse.display();
    return 0;
}