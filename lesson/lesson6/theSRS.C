//note cần có course *getcourse()
/*
thuộc tính liên kết khác lớp liên kết

*/
#include <string>
#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Course;
class Section;
class SectionOfClasses;
class Person;
class Professor;
class Student;
class Transcript;
class TranscriptEntry;

class Course
{
    private:
        string courseNo;
        string courseName;
        int credits;
        list<Course*> prerequisites;
        list<Section*> sections;
    public:
        void setCourseNo(string courseNo){
            this->courseNo=courseNo;
        }
        void setCourseName(string courseName){
            this->courseName=courseName;
        }
        void setCredits(int credits){
            this->credits=credits;
        }

        string getCourseNo(){
            return this->courseNo;
        }
        string getCourseName(){
            return this->courseName;
        }
        int getCredits(){
            return this->credits;
        }
        Course(string courseNo, string courseName, int credits){
            this->setCourseNo(courseNo);
            this->setCourseName(courseName);
            this->setCredits(credits);
        }
        void display(){
            cout<<"Course No: "<<this->getCourseNo()<<endl;
            cout<<"Course Name: "<<this->getCourseName()<<endl;
            cout<<"Credits: "<<this->getCredits()<<endl;
        }

        void scheduleSection();
        void addPrerequisite();
        void hasPrerequisite();

        Section* scheduleSection(string sectionNo, string dayOfWeek, string timeOfDay, string room, int seatingCapacity);
        void addPrerequisites(Course* course);
        list<Course*>  getPrerequisites();
};

class Section
{
    private:
        string sectionNo;
        string dayOfWeek;
        string timeOfDay;
        string room;
        int seatingCapacity;
        Course* cousrse;
    public:
        void setSectionNo(string sectionNo){
            this->sectionNo=sectionNo;
        }
        void setDayOfWeek(string dayOfWeek){
            this->dayOfWeek=dayOfWeek;
        }
        void setTimeOfDay(string timeOfDay){
            this->timeOfDay=timeOfDay;
        }
        void setRoom(string room){
            this->room=room;
        }
        void setSeatingCapacity(string seatingCapacity){
            this->seatingCapacity=seatingCapacity;
        }

        string getSectionNo(){
            return this->sectionNo;
        }
        string getDayOfWeek(){
            return this->dayOfWeek;
        }
        string getTimeOfDay(){
            return this->timeOfDay;
        }
        string getRoom(){
            return this->room;
        }
        int getSeatingCapacity(){
            return this->seatingCapacity;
        }
        Section(string sectionNo, string dayOfWeek, string timeOfDay, string room, int seatingCapacity){
            this->setSectionNo(sectionNo);
            this->setDayOfWeek(dayOfWeek);
            this->setTimeOfDay(timeOfDay);
            this->setRoom(room);
            this->setSeatingCapacity(seatingCapacity);
        }

        void enroll();
        void drop();
        int postGrade();
        void confirmSeatAbility();
};

class SectionOfClasses
{
    private:
        string semester;
        unordered_map<string, Section*> sections; // key: sectionNo
    public:
        void setSemester(string semester){
            this->semester=semester;
        }
        string getSemester(){
            return this->semester;
        }
        SectionOfClasses(string semester){
            this->setSemester(semester);
        }

        void addSection(Section* section){
            sections[section->getSectionNo()] = section;
        }
        Section* getSection(string sectionNo){
            return sections[sectionNo];
        }
        ~ ScheduleOfClasses();
};

class Person
{
    protected:
        string ssn;
        string name;
    public:
        void setSsn(string ssn){
            this->ssn=ssn;
        }
        void setName(string name){
            this->name=name;
        }
        string getSsn(){
            return this->ssn;
        }
        string getName(){
            return this->name;
        }
        Person(string ssn, string name){
            this->setSsn(ssn);
            this->setName(name);
        }
        virtual void display() = 0; // Pure virtual function
};

class Professor : public Person
{
    private:
        string department;
        string title;
        vector<Section*> sections;
    public:
        void setDepartment(string department){
            this->department=department;
        }
        void setTitle(string title){
            this->title=title;
        }
        void addSection(Section* section){
            sections.push_back(section);
        }

        string getDepartment(){
            return this->department;
        }
        string getTitle(){
            return this->title;
        }
        vector<Section*> getSections(){
            return this->sections;
        }

        Professor(string ssn, string name, string department, string title) : Person(ssn, name) {
            this->setDepartment(department);
            this->setTitle(title);
        }

        void display() override {
            cout << "Professor: " << this->getName() << ", Department: " << this->getDepartment() << endl;
        }
};

class Student : public Person
{
    private:
        string major;
        string degree;
        vector<Section*> sections;
        Transcript* transcript;
    public:
        void setMajor(string major){
            this->major=major;
        }
        void setDegree(string degree){
            this->degree=degree;
        }
        void addSection(Section* section){
            sections.push_back(section);
        }
        void setTranscript(Transcript* transcript){
            this->transcript=transcript;
        }

        string getMajor(){
            return this->major;
        }
        string getDegree(){
            return this->degree;
        }
        vector<Section*> getSections(){
            return this->sections;
        }
        Transcript* getTranscript(){
            return this->transcript;
        }

        Student(string ssn, string name, string major, string degree) : Person(ssn, name) {
            this->setMajor(major);
            this->setDegree(degree);
        }

        void display() override {
            cout << "Student: " << this->getName() << ", Major: " << this->getMajor() << endl;
        }
        ~Student();
};

class 

int main(){

    return 0;
}