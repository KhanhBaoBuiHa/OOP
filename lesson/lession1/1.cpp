#include <iostream>
#include <string.h>

using namespace std;

class Person {
    //attributes (constance) thuộc tính
    string name="HaVanThao";
    string dateOfBirth="01/01/2000";
public:
    //getters() phương thức tương tác
    string getName(){
        return this->name;
    }
    string getDateOfBirth(){
        return this->dateOfBirth;
    }
    //display()3
    void display(){
        cout<<"Name: "<<this->getName()<<endl; //ko được gọi trực tiếp name do nó là private, vi phạm lỗi bảo mật
        cout<<"Date of birth: "<<this->getDateOfBirth()<<endl;
    }    
};
/*
P1.getBirth* khi p1 ở dạng đối tượng
P1->getBirth* khi p1 ở dạng con trỏ đối tượng
*/
int main() {
   //declare objects
   Person p1;
   //display
   p1.display();
}
