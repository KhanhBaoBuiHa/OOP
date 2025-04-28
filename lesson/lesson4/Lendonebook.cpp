#include <string>
#include <iostream>
#include <list>

using namespace std;

class BorrowerRecord;
class Library;
class Book;

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
class BorrowerRecord {
    string borrowerName;
    list<Book*> borrowedBooks;

public:
    BorrowerRecord(string name) : borrowerName(name) {}

    string getName() { 
        return borrowerName; 
    }

    void attachBook(Book* book) {
        borrowedBooks.push_back(book);
        book->attachBorrower(this);
    }

    void detachBook(Book* book) {
        borrowedBooks.remove(book);
        book->detachBorrower();
    }

    void display() {
        cout << "Borrower: " << this->getName() << endl;
        cout << "Books Borrowed: " << endl;
        for (Book* book : borrowedBooks) {
            cout << " - " << book->getTitle() << endl;
        }
    }
};

//Class Library
class Library {
    string name;
    list<Book*> stock;
    list<BorrowerRecord*> borrowerList;
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

    void registerOneBorrower(string name) {
        borrowerList.push_back(new BorrowerRecord(name));
    }

    /*
    list <Book*> getBooks(){
        return stock;
    }
    */

    // Display

    //displayBookAvailableForLoan()
    void displayBookAvailableForLoan(){
        cout<<"Books available for loan: "<<endl;
        for (Book* book : stock) {
            cout << " - " << book->getTitle() << endl;
        }
    }
    //displayBookOnLoan()
    void displayBookOnLoan(){
        cout<<"Books on loan: "<<endl;
        for (Book* book : stock) {
            if (book->getBorrower() != nullptr) {
                cout << " - " << book->getTitle() << endl;
            }
        }
    }
    //void lendOneBook (string catalougeNumber, string borrowerName){}
    void lenOneBook(string catalogueNumber, string borrowerName) {
        for (Book* book : stock) {
            if (book->getNumber() == catalogueNumber) {
                if (book->getBorrower() == nullptr) {
                    book->attachBorrower(new BorrowerRecord(borrowerName));
                    cout << "Book lent to " << borrowerName << endl;
                } else {
                    cout << "Book is already on loan." << endl;
                }
                return;
            }
        }
        cout << "Book not found." << endl;
    }

    void returnOneBook(string catalougeNumber){
        for (Book* book : stock){
            if (book->getNumber() == catalougeNumber) {
                if (book->getBorrower() != nullptr) {
                    book->detachBorrower();
                    cout << "Book returned." << endl;
                } else {
                    cout << "Book is not on loan." << endl;
                }
                return;
            }
        }
    }

    ~Library() {
        for (Book* b : stock) delete b;
        for (BorrowerRecord* br : borrowerList) delete br;
    }
};

int main(){
    Library lib("My Library");
    cout <<"The Library Application\n" << endl;
    Book* first = new Book("000","Aso Haro", "Alice in Borderland");
    Book *second = new Book("001","Ha Van Thao" , "co so lap trinh huong doi tuong");
    Book *third = new Book("002", "Author", "Ky thuat lap trinh");
    
    lib.addOneBook(first);
    lib.addOneBook(second);
    lib.addOneBook(third);

    lib.registerOneBorrower("Alice");
    lib.registerOneBorrower("Bob");

    lib.displayBookAvailableForLoan();
    cout<<endl;
    lib.displayBookOnLoan();

    lib.lenOneBook("002","Bob");
    lib.displayBookAvailableForLoan();
    lib.displayBookOnLoan();

    lib.returnOneBook("002");
    delete first, second, third;
    return 0;
}