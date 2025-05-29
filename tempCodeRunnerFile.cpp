#include <string>
#include <iostream>
#include <list>
#include <map>
using namespace std;

class Course;
class Section;
class ScheduleOfClasses;

class Course {
    string CourseNo;
    string CourseName;
    int credits;
    list<Section*> sections;
    list<Course*> prerequisites;
public:
    //Constructor
    Course(string CourseNo, string CourseName, int credits);
    //Getters & setters
    void setNo(string theNo);
    void setName(string theName);
    void setCredits(int credits);
    string getNo();
    string getName();
    int getCredits();
    //functions
    void attachSection(Section* s);
    void detachSection(Section* s);
    void scheduleSection(Section* s);
    list<Section*> getSections();
    void displaySections();
    /*void attachCourse(Course* c);
    void detachCourse(Course* c);
    void addPrerequisite(Course* c);
    list<Course*> getPrerequisites();
    void hasPrerequisites(); //display prerequisites
    void display();*/
};

class Section{
    string sectionNo;
    string dayOfWeek;
    string timeOfDay;
    string room;
    int seatingCapacity;
    Course* course;
public:
    //Constructor
    Section(string sectionNo, string dayOfWeek, string timeOfDay, string room, int seatingCapacity);
    //Getters & setters
    void setNo(string theNo);
    void setDay(string theDay);
    void setTime(string theTime);
    void setRoom(string theRoom);
    void setCap(int theCap);
    string getNo();
    string getDay();
    string getTime();
    string getRoom();
    int getCap();
    //functions
    void attachCourse(Course* c);
    void detachCourse();
    void setCourse(Course* c);
    Course* getCourse();
    void display();
    /* void enroll();
    void drop();
    void postGrade();
    void confirmSeatAvailabilyty();*/
};

class ScheduleOfClasses {
    string semester;
    list<Section*> sections;
public:
    //Constructor
    ScheduleOfClasses(string semester);
    //Getter & Setter
    void setSemester(string semester);
    string getSemester();
    //functions
    void attachSection(Section* s);
    void detachSection(Section* s);
    void addSection(Section* s);
    void removeSection(Section* s);
    list<Section*> getSections();
    void displaySections();
};

Course::Course(string CourseNo, string CourseName, int credits) {
    this->setNo(CourseNo);
    this->setName(CourseName);
    this->setCredits(credits);
}
void Course::setNo(string theNo) {
    this->CourseNo = theNo;
}
void Course::setName(string theName) {
    this->CourseName = theName;
}
void Course::setCredits(int credits) {
    this->credits = credits;
}
string Course::getNo() {
    return this->CourseNo;
}
string Course::getName() {
    return this->CourseName;
}
int Course::getCredits() {
    return this->credits;
}
void Course::attachSection(Section* s) {
    this->sections.push_back(s);
}
void Course::detachSection(Section* s) {
    this->sections.remove(s);
}
void Course::scheduleSection(Section* s) {
    if (!s) {
        cout << "Section not found!" << endl;
        return;
    }
    if (s->getCourse() != NULL) {
        cout << "Section is scheduled!" << endl;
        return;
    }
    s->attachCourse(this);
}
list<Section*> Course::getSections() {
    return this->sections;
}
void Course::displaySections() {
    for (auto i : sections) {
        i->display();
    }
}
/*void Course::attachCourse(Course* c);
void Course::detachCourse(Course* c);
void Course::addPrerequisite(Course* c);
list<Course*> Course::getPrerequisites();
void Course::hasPrerequisites(); //display prerequisites
void Course::display();*/

Section::Section(string sectionNo, string dayOfWeek, string timeOfDay, string room, int seatingCapacity) {
    this->setNo(sectionNo);
    this->setDay(dayOfWeek);
    this->setTime(timeOfDay);
    this->setRoom(room);
    this->setCap(seatingCapacity);
}
void Section::setNo(string theNo) {
    this->sectionNo = theNo;
}
void Section::setDay(string theDay) {
    this->dayOfWeek = theDay;
}
void Section::setTime(string theTime) {
    this->timeOfDay = theTime;
}
void Section::setRoom(string theRoom) {
    this->room = theRoom;
}
void Section::setCap(int theCap) {
    this->seatingCapacity = theCap;
}
string Section::getNo() {
    return this->sectionNo;
}
string Section::getDay() {
    return this->dayOfWeek;
}
string Section::getTime() {
    return this->timeOfDay;
}
string Section::getRoom() {
    return this->room;
}
int Section::getCap() {
    return this->seatingCapacity;
}
void Section::attachCourse(Course* c) {
    this->setCourse(c);
    c->attachSection(this);
}
void Section::detachCourse() {
    Course* c = this->getCourse();
    this->setCourse(NULL);
    c->detachSection(this);
}
void Section::setCourse(Course* c) {
    this->course = c;
}
Course* Section::getCourse() {
    return this->course;
}
void Section::display() {
    cout << "Section: " << endl;
    cout << "Section Number: " << this->getNo() << endl;
    cout << "Day of week: " << this->getDay() << endl;
    cout << "Time of day: " << this->getTime() << endl;
    cout << "Room: " << this->getRoom() << endl;
    cout << "Course: " << this->getCourse() << endl;
}

ScheduleOfClasses::ScheduleOfClasses(string semester) {
    this->setSemester(semester);
}
void ScheduleOfClasses::setSemester(string semester) {
    this->semester = semester;
}
string ScheduleOfClasses::getSemester() {
    return this->semester;
}
void ScheduleOfClasses::attachSection(Section* s) {
    this->sections.push_back(s);
}
void ScheduleOfClasses::detachSection(Section* s) {
    this->sections.remove(s);
}
void ScheduleOfClasses::addSection(Section* s) {
    if (!s) {
        cout << "Section not found!" << endl;
        return;
    }
    this->attachSection(s);
}
void ScheduleOfClasses::removeSection(Section* s) {
    if (!s) {
        cout << "Section not found!" << endl;
        return;
    }
    for (auto i : sections) {
        if (i->getNo() == s->getNo()) {
            continue;
        }
        cout << "Section not in this Schedule!" << endl;
        return;
    }
    this->detachSection(s);
}
list<Section*> ScheduleOfClasses::getSections() {
    return this->sections;
}
void ScheduleOfClasses::displaySections() {
    for (auto i:sections) {
        i->display();
    }
}

int main() {
    Course a("001", "OOP", 4);
    Section b("00001", "Mon", "9AM", "C204", 80);
    ScheduleOfClasses c("A");
    a.scheduleSection(&b);
    a.displaySections();
    c.addSection(&b);
    c.displaySections();
    return 0;
}