#include <string>
#include <iostream>
#include <list>
using namespace std;

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
int main() {
    cout <<"The Library Application\n" << endl;
    
    Book* first = new Book("000","Aso Haro","Alice in Borderland");
    first->display();
    
    Book second("001","Ha Van Thao","Co so lap trinh huong doi tuong");
    second.display();
    
    delete(first);

    Library secondLib("SecondLib");
    secondLib.display();
    secondLib.addOneBook(first);
    secondLib.addOneBook(&second);

    return 0;
}