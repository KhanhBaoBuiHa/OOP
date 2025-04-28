#include <string>
#include <iostream>
#include <list>

using namespace std;

class BorrowerRecord;
class Library;
//Class Book
class Book {
    // attributes: number, author, title
    string number, author, title;
    BorrowerRecord* borrower;
    //default constructor
public:
    Book() {
        this->number = "Unknown";
        this->author = "Unknown";
        this->title = "Unknown";
    }
    // constructors
    Book(string number, string author, string title){
        this->setNumber(number);
        this->setAuthor(author);
        this->setTitle(title);
    }
    // getters & setters
    //setters
    void setNumber(string number){
        this->number=number;
    }
    void setAuthor(string author){
        this->author=author;
    }
    void setTitle(string title){
        this->title=title;
    }
    //getters
    string getNumber(){
        return this->number;
    }
    string getAuthor(){
        return this->author;
    }
    string getTitle(){
        return this->title;
    }
    // display book
    void display(){
        cout<<"number: "<<this->getNumber()<<endl;
        cout<<"author: "<<this->getAuthor()<<endl;
        cout<<"title: "<<this->getTitle()<<endl;
    }
    BorrowerRecord* getBorrower() { 
        return borrower; 
    }
    void attachBorrower(BorrowerRecord* br) { 
        borrower = br; 
    }
    void detachBorrower() { 
        borrower = nullptr;
    }
};
//Class Library
class Library {
    string name;
    list<Book*> stock;
public:
    // Constructor
    Library(string name){
        this->setName(name);
    }
    // Access Methods
    void setName(string name){
        this->name=name;
    }
    string getName(){
        return this->name;
    }
    // Add one book
    void addOneBook(Book* book){
        this->stock.push_back(book);
    }
    list <Book*> getBooks(){
        return stock;
    }
    // Display
    void display(){
        cout<<"name: "<<this->getName()<<endl;
    }
    // Destructor
    ~Library(){}
};

class BorrowerRecord {
    string theName;
    list<Book*> books;
public:
    //constructor
    BorrowerRecord(string name){
        this->setName(name);
    }
    //Access Method
    void setName(string name){
        this->theName=name;
    }
    string getName(){
        return this->theName;
    }

    void attachBook(Book* book) {
        books.push_back(book);
        book->attachBorrower(this);
    }
    void detachBorrower() {
        for (Book* book : books) {
            book->detachBorrower();
        }
        books.clear();
    }
    list<Book*> getBooks() { 
        return books; 
    }
    //display
    void display(){
        cout<<"borrowed name: "<<this->getName()<<endl;
        cout<<"books borrowed: "<<endl;
        for (Book* book : books) {
            cout << " - " << book->getTitle() << endl;
        }
    }
};
/*
//BorrowerRecord::attachBorrower()
void BorrowerRecord::attachBook(Book* book) {
    this->books.push_back(book);
    book->attachBorrower(this);
}
//BorrowerRecord::detachBorrower()
void BorrowerRecord::detachBorrower() {
    this->books.clear();
}
//getBorrower()
Book* Book::getBorrower() {
    return this->borrower;
}

//attachBook()
void Book::attachBorrower(BorrowerRecord* br) {
    this->borrower = br;
}
//detachBook()
void Book::detachBorrower() {
    this->borrower = nullptr;
}
//getsBook()
list<Book*> BorrowerRecord::getBooks() {
    return this->books;
}
*/
int main(){
    cout <<"The Library Application\n" << endl;
    
    Book* first = new Book("000","Aso Haro","Alice in Borderland");
    first->display();
    Book second("001","Ha Van Thao","Co so lap trinh huong doi tuong");
    second.display();

    Library secondLib("SecondLib");
    secondLib.display();
    secondLib.addOneBook(first);
    secondLib.addOneBook(&second);

    BorrowerRecord* firstBorrow = new BorrowerRecord("Nguyen Van A");
    firstBorrow->display();

    firstBorrow->attachBook(first);
    firstBorrow->attachBook(&second);
    firstBorrow->display();

    delete(first);
    delete(firstBorrow);

    return 0;
}