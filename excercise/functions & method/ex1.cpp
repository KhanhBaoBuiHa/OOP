#include <iostream>
#include <string.h>

using namespace std;

class Car {
    string theMake;
    string theModel;
    int theCapacity;

public:

Car(string aMake, string aModel, int aCapacity) {
    this->setMake(aMake);
    this->setModel(aModel);
    this->setCapacity(aCapacity;)
}

void setMake(string Make){
    this->theMake=Make;
}
void setModel(string Model){
    this->theModel=Model;
}
void setCapacity(int Capacity){
    this->theCapacity=Capacity;
}

string getMake(){
    return this->theMake;
}

string getModel(){
    return this->theModel;
}
int getCapacity(){
    return this->theCapacity;
}


};
int  main(){

}