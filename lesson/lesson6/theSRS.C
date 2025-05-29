//note cần có course *getcourse()
#include <string>
#include <iostream>
#include <list>
#include <vector>
#include <map>

using namespace std;

class Course;
class Section;
class SectionOfClasses;

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
}

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
}
int main(){

    return 0;
}