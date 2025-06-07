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

class Room
{
    private:
        int number;
        string type;
        bool isAvailable;
    public:
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

};

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
};

class conferenceRoom
{
    private:
        string name;
        Room* room;
        bool haveStudyRoom;
        vector<studyRoom*> studyRooms;
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
        void setStudyRooms(vector<studyRoom*> studyRooms){
            this->studyRooms=studyRooms;
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
        vector<studyRoom*> getStudyRooms(){
            return this->studyRooms;
        }
        conferenceRoom(string name, Room* room, bool haveStudyRoom, vector<studyRoom*> studyRooms){
            this->setName(name);
            this->setHaveStudyRoom(haveStudyRoom);
            this->setRoom(room);
            this->setStudyRooms(studyRooms);
        }
        
        display(){
            cout << "Conference Room Name: " << this->name << endl;
            cout << "Room Number: " << this->room->getNumber() << ", Type: " << this->room->getType() << endl;
            cout << "Has Study Room: " << (this->haveStudyRoom ? "Yes" : "No") << endl;
            if(this->haveStudyRoom) {
                cout << "Study Rooms: " << endl;
                for(auto studyRoom : this->studyRooms) {
                    cout << "Study Room Number: " << studyRoom->getRoom()->getNumber() << endl;
                }
            }
        }
    ~conferenceRoom(){
        for(auto s : studyRooms) {
            delete s; // Clean up study rooms
        }
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

class Guest
{
    private:
        string name;
        string id;
        vector<Room*> bookedRooms; // Assuming Guest can book multiple rooms
    public:
        void setName(string name){
            this->name=name;
        }
        void setId(string id){
            this->id=id;
        }
        void setBookedRooms(vector<Room*> bookedRooms){
            this->bookedRooms=bookedRooms;
        }
        string getName(){
            return this->name;
        }
        string getId(){
            return this->id;
        }
        vector<Room*> getBookedRooms(){
            return this->bookedRooms;
        }
        Guest(string name, string id, vector<Room*> bookedRooms){
            this->setName(name);
            this->setId(id);
            this->setBookedRooms(bookedRooms);
        }
    
    display(){
        cout << "Guest Name: " << this->name << endl;
        cout << "Guest ID: " << this->id << endl;
        cout << "Booked Rooms: " << endl;
        for(auto room : this->bookedRooms) {
            cout << "Room Number: " << room->getNumber() << ", Type: " << room->getType() << endl;
        }
    }    
}; 

class Hotel
{
    private:
        string name;
        vector<Floor*> floors;
    public:
        void setName(string name){
            this->name=name;
        }
        void setFloors(vector<Floor*> floors){
            this->floors=floors;
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

int main(){

    // nhap du lieu cho Hotel
    Room* room101 = new Room(101, "restRoom", true);
    Room* room102 = new Room(102, "restRoom", true);
    Room* room103 = new Room(103, "studyRoom", true);
    vector<Room*> rooms1 = {room101, room102, room103};
    
    Room* room201 = new Room(201, "conferenceRoom", true);
    conferenceRoom* confRoom1 = new conferenceRoom("Conference A", room201, true, {new studyRoom(room103)});

    Floor* floor1 = new Floor(1, rooms1);
    Floor* floor2 = new Floor(2, {room201});

    vector<Floor*> floors = {floor1};

    Hotel* hotel = new Hotel("Muong Thanh", floors);

    // nhap du lieu cho Guest
    vector<Room*> bookedRooms = {room101, room102};
    Guest* guest = new Guest("John Doe", "G123", bookedRooms);
    guest->display();

    //clean up
    delete hotel;
    delete guest;
    return 0;
}