#include <string>
#include <iostream>
#include <list>
#include <vector>
#include <map>

using namespace std;

class Hospital;
class Faculty;
class Employee;
class Doctor;
class Group;
class Patient;

class Hospital
{
    private:
        string name;
        vector<Faculty*> faculties;
    public:
        void setName(string name){
            this->name=name;
        }
        void setFaculties(vector<Faculty*> faculties){
            this->faculties=faculties;
        }
        string getName(){
            return this->name;
        }
        vector<Faculty*> getFaculties(){
            return this->faculties;
        }
        Hospital(string name, vector<Faculty*> faculties){
            this->setName(name);
            this->setFaculties(faculties);
        }
};


class Faculty
{
    private:
        string name;
    public:
        void setName(string name){
            this->name=name;
        }
        string getName(){
            return this->name;
        }
        Faculty(string name){
            this->setName(name);
        }
};


class Employee
{
    private:
        string name, dateOfBirth;
    public:
        void setName(string name){
            this->name=name;
        }
        void setDateOfBirth(string dateOfBirth){
            this->dateOfBirth=dateOfBirth;
        }
        string getName(){
            return this->name;
        }
        string getDateOfBirth(){
            return this->dateOfBirth;
        }
        Employee(string name, string dateOfBirth){
            this->setName(name);
            this->setDateOfBirth(dateOfBirth);
        }
};


class Doctor
{
    private:
        Employee* employee;
        string GoupID;
        bool laCoVan;
    public:
        void setEmployee(Employee* employee){
            this->employee=employee;
        }
        void setGoupID(string GoupID){
            this->GoupID=GoupID;
        }
        void setLaCoVan(bool laCoVan){
            this->laCoVan=laCoVan;
        }
        Employee* getEmployee(){
            return this->employee;
        }
        string getGoupID(){
            return this->GoupID;
        }
        bool getLaCoVan(){
            return this->laCoVan;
        }
        Doctor(Employee* employee, string GoupID, bool laCoVan){
            this->setEmployee(employee);
            this->setGoupID(GoupID);
            this->setLaCoVan(laCoVan);
        }
};

//////////////////////////////////////
//fix + thiếu hàm registration
class Adminstrator
{
    private:
        Employee* employee;
        string GoupID;
    public:
        void setEmployee(Employee* employee){
            this->employee=employee;
        }
        void setGoupID(string GoupID){
            this->GoupID=GoupID;
        }
        Employee* getEmployee(){
            return this->employee;
        }
        string getGoupID(){
            return this->GoupID;
        }
        Adminstrator(Employee* employee, string GoupID){
            this->setEmployee(employee);
            this->setGoupID(GoupID);
        }
};

class Group
{
    private:
        string GoupID;
        Doctor* coVan;
        vector<Doctor*> doctors;
    public:
        void setGoupID(string GoupID){
            this->GoupID=GoupID;
        }
        void setCoVan(Doctor* coVan){
            this->coVan=coVan;
        }
        void setDoctors(vector<Doctor*> doctors){
            this->doctors=doctors;
        }
        string getGoupID(){
            return this->GoupID;
        }
        Doctor* getCoVan(){
            return this->coVan;
        }
        vector<Doctor*> getDoctors(){
            return this->doctors;
        }
        Group(string GoupID, Doctor* coVan, vector<Doctor*> doctors){
            this->setGoupID(GoupID);
            this->setCoVan(coVan);
            this->setDoctors(doctors);
        }
};

class Patient
{
    private:
        string name,dateOfBirth; //thiếu roomID
        Faculty* faculty;
        Group* group;
    public:
        void setName(string name){
            this->name=name;
        }
        void setDateOfBirth(string dateOfBirth){
            this->dateOfBirth=dateOfBirth;
        }
        void setFaculty(Faculty* faculty){
            this->faculty=faculty;
        }
        void setGroup(Group* group){
            this->group=group;
        }
        string getName(){
            return this->name;
        }
        string getDateOfBirth(){
            return this->dateOfBirth;
        }
        Faculty* getFaculty(){
            return this->faculty;
        }
        Group* getGroup(){
            return this->group;
        }
        Patient(string name, string dateOfBirth, Faculty* faculty, Group* group){
            this->setName(name);
            this->setDateOfBirth(dateOfBirth);
            this->setFaculty(faculty);
            this->setGroup(group);
        }
        // void regitrition()
        void display(){
            cout << "Name: " << this->getName() << endl;
            cout << "Date of Birth: " << this->getDateOfBirth() << endl;
            cout << "Faculty: " << this->getFaculty()->getName() << endl;
            cout << "Group ID: " << this->getGroup()->getGoupID() << endl;
            cout << "Adminstrator: " << this->getGroup()->getCoVan()->getEmployee()->getName() << endl;
        }  
};

int main(){
    Hospital* h1 = new Hospital("BMT, Hospital", {});

    Faculty* f1 = new Faculty("Dental Faculty");

    Employee* e1 = new Employee("Nguyen Van A", "01/01/2000");
    Employee* e2 = new Employee("Nguyen Van B", "01/01/2000");
    Employee* e3 = new Employee("Nguyen Van C", "01/01/2000");

    Doctor* d1 = new Doctor(e1,"Goup A", true);
    Doctor* d2 = new Doctor(e2,"Goup A", false);
    Doctor* d3 = new Doctor(e3,"Goup A", false);

    vector<Doctor*> doctors = {d1, d2, d3};

    Group* g1 = new Group("Goup A", d1, doctors);

    Patient* p1 = new Patient("John Doe", "01/01/2000", f1, g1);

    p1->display();

    return 0;
}