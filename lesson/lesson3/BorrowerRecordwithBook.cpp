#include <string>
#include <iostream>
#include <list>
using namespace std;

class Book;
class BorrowerRecord;

class Book {
    string number;
    BorrowerRecord* borrower;
public:

    //Constructor
    Book(string name);

    //Access Method
    void setNumber(string number);
    string getNumber();
   
    void display();

    //Book <-> borrower
    BorrowerRecord* getBorrower();
    void attachBorrower(BorrowerRecord* br);
};


class BorrowerRecord {
    string name;
    list<Book*> books;
public:
    void setName(string name);
    string getName();
    void display();
    BorrowerRecord(string name);
   //attach a book
    void attachBook(Book* book);
};

void Book::setNumber(string number) {
    this->number = number;
}
string Book::getNumber() {
    return this->number;
}
Book::Book(string number) {
    this->setNumber(number);
    this->borrower = nullptr;
}
BorrowerRecord* Book::getBorrower() {
    return this->borrower;
}
void Book::attachBorrower(BorrowerRecord* br) {
    this->borrower = br;
}
void Book::display() {
    cout<<"number: "<<this->getNumber()<<endl;
    if (this->borrower != nullptr) {
        cout<<"borrower: "<<this->borrower->getName()<<endl;
    } else {
        cout<<"borrower: None"<<endl;
    }
}

void BorrowerRecord::setName(string name) {
    this->name = name;
}

string BorrowerRecord::getName() {
    return this->name;
}
BorrowerRecord::BorrowerRecord(string name) {
    this->setName(name);
    this->books.clear();
}
void BorrowerRecord::attachBook(Book* book) {
    this->books.push_back(book);
    book->attachBorrower(this);
}
void BorrowerRecord::display() {
    cout<<"borrower name: "<<this->getName()<<endl;
    cout<<"books borrowed: "<<endl;
    for (Book* book : this->books) {
        cout<<"- "<<book->getNumber()<<endl;
    }
}
int main() {
    // Create a book and a borrower record
    Book* book1 = new Book("12345");
    BorrowerRecord* borrower1 = new BorrowerRecord("John Doe");

    // Attach the borrower to the book
    book1->attachBorrower(borrower1);

    // Display the book and borrower information
    book1->display();
    borrower1->display();

    // Clean up memory
    delete book1;
    delete borrower1;

    return 0;
//test case
}