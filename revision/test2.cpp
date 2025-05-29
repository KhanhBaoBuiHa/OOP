#include <string>
#include <iostream>
#include <list>
#include <vector>
#include <map>

using namespace std;

class Hotel;
class Floor;
class Room;
class restRoom;
class conferenceRoom;
class studyRoom;
class Guest;

class Hotel
{
    private:
        int number;
        string name;
        vector<Floor*> floors;
    public:
        void setNumber(int number){
            this->number=number;
        }
        void setName(string name){
            this->name=name;
        }
        void setFloors(vector<Floor*> floors){
            this->floors=floors;
        }
        int getNumber(){
            return this->number;
        }
        string getName(){
            return this->name;
        }
        vector<Floor*> getFloors(){
            return this->floors;
        }
        Hotel(string name, vector<Floor*> floors){
            this->setName(name);
            this->setFloors(floors);
        }
};

class Floor
{
    private:
        int number;
        vector<Room*> rooms;
    public:
        void setNumber(int number){
            this->number=number;
        }
        void setRooms(vector<Room*> rooms){
            this->rooms=rooms;
        }
        int getNumber(){
            return this->number;
        }
        vector<Room*> getRooms(){
            return this->rooms;
        }
        Floor(int number, vector<Room*> rooms){
            this->setNumber(number);
            this->setRooms(rooms);
        }
};

class Room
{
    private:
        int number;
        string type;
        bool isAvailable;
        vector<Guest*> guests; // Assuming Guest is another class that needs to be defined
    public:
        
        if(type != "restRoom" && type != "conferenceRoom" && type != "studyRoom"){
            throw invalid_argument("Invalid room type");
            return 0;
        }

        void setNumber(int number){
            this->number=number;
        }
        void setType(string type){
            this->type=type;
        }
        void setIsAvailable(bool isAvailable){
            this->isAvailable=isAvailable;
        }
        int getNumber(){
            return this->number;
        }
        string getType(){
            return this->type;
        }
        bool getIsAvailable(){
            return this->isAvailable;
        }
        Room(int number, string type, bool isAvailable){
            this->setNumber(number);
            this->setType(type);
            this->setIsAvailable(isAvailable);
        }
};

class restRoom
{
    private:
        Room* room;
    public:
        void setRoom(Room* room){
            this->room=room;
        }
        Room* getRoom(){
            return this->room;
        }
        restRoom(Room* room){
            this->setRoom(room);
        }

}

class studyRoom
{
    private:
        Room* room;
    public:
        void setRoom(Room* room){
            this->room=room;
        }
        Room* getRoom(){
            return this->room;
        }
        studyRoom(Room* room){
            this->setRoom(room);
        }
}

class conferenceRoom
{
    private:
        string name;
        Room* room;
        bool haveStudyRoom;
        if(haveStudyRoom == 1){
            int numberOfStudyRoom;
            while(numberOfStudyRoom > 0){
                studyRoom* studyroom = new studyRoom(room);
                this->studyroom.push_back(studyroom);
            }
        }
    public:
        void setName(string name){
            this->name=name;
        }
        void setHaveStudyRoom(bool haveStudyRoom){
            this->haveStudyRoom=haveStudyRoom;
        }
        void setRoom(Room* room){
            this->room=room;
        }
        string getName(){
            return this->name;
        }
        bool getHaveStudyRoom(){
            return this->haveStudyRoom;
        }
        Room* getRoom(){
            return this->room;
        }
        conferenceRoom(string name, bool haveStudyRoom, Room* room){
            this->setName(name);
            this->setHaveStudyRoom(haveStudyRoom);
            this->setRoom(room);
        }

};

class Guest
{
    private:
        string name;
        int age;
        string idCard;
    public:
        void setName(string name){
            this->name=name;
        }
        void setAge(int age){
            this->age=age;
        }
        void setIdCard(string idCard){
            this->idCard=idCard;
        }
        string getName(){
            return this->name;
        }
        int getAge(){
            return this->age;
        }
        string getIdCard(){
            return this->idCard;
        }
        Guest(string name, int age, string idCard){
            this->setName(name);
            this->setAge(age);
            this->setIdCard(idCard);
        }
}; 

int main(){
    
    return 0;
}