#include <string>
#include <iostream>
#include <list>

using namespace std;

//class Book
class Book {
    // attributes: number, author, title
    string number, author, title;
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
};
//class BorrowerRecord
class BorrowerRecord {
    string theName;
public:
    //constructor
    BorrowerRecord(string aName){
        this->setName(aName);
    }
    //Access Method
    void setName(string aName){
        this->theName=aName;
    }
    string getName(){
        return this->theName;
    }
    //display
    void display(){
        cout<<"borrowed name: "<<this->getName()<<endl;
    }
};

class Library {
    string aName;
    list<Book*> stock;
    list<BorrowerRecord*> borrower;
public:
    // Constructor
    Library(string aName){
        this->setName(aName);
    }
    // Access Method (modify)
    void setName(string aName){
        this->aName=aName;
    }
    string getName(){
        return this->aName;
    }
    // Add one book
    void addOneBook(Book* book){
        this->stock.push_back(book);
    }
    list <Book*> getBooks(){
        return stock;
    }
    // Register one borrower
    void registerOneBorrower(string name){
        this->borrower.push_back(new BorrowerRecord(name));
    }
    // Display all books and borrowers in the library
    void display(){
        cout<<"name: "<<this->getName()<<endl;
        cout<<"Books in the library: "<<endl;
        for (Book* book : stock) {
            book->display();
        }
        cout<<"Borrowers in the library: "<<endl;
        for (BorrowerRecord* record : borrower) {
            record->display();
        }
    }
    //destructors
    ~Library(){
        for (Book* book : stock) {
            delete book;
        }
        stock.clear();

        for (BorrowerRecord* record : borrower) {
            delete record;
        }
        borrower.clear();
    }
};
int main(){
    cout <<"The Library Application\n" << endl;
    // Create a library
    Library* library = new Library("City Library");
    // Create books
    Book* book1 = new Book("001", "Author A", "Title A");
    Book* book2 = new Book("002", "Author B", "Title B");

    library->addOneBook(book1);
    library->addOneBook(book2);

    library->registerOneBorrower("John Doe");
    library->registerOneBorrower("Jane Smith");

    library->display();

    delete library;

    return 0;
}