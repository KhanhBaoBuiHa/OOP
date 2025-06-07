#include <string>
#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class user;
class cart;
class product;
class electronicItem;
class fashionItem;

class product
{
    protected:
        string name;
        double price;
    public:
        void setName(string name){
            this->name = name;
        }
        virtual void setPrice(double price){
            this->price = price;
        }
        virtual string getName(){
            return this->name;
        }
        virtual double getPrice(){
            return this->price;
        }
        product(string name, double price){
            this->setName(name);
            this->setPrice(price);
        }
        virtual ~product() {}
};

class electronicItem : public product
{
    public:
        electronicItem(string name, double price) : product(name, price) {}
};

class fashionItem : public product
{
    private:
        float discount;
    public:
        void setDiscount(float discount){
            this->discount = discount;
        }
        float getDiscount(){
            return this->discount;
        }
        fashionItem(string name, double price, float discount) : product(name, price) {
            this->setDiscount(discount);
        }
        double getPrice() override {
            return price * (1 - discount);
        }
};

class cart
{
    private:
        vector<product*> products;
    public:
        void addProduct(product* item, int quantity ){
            if(quantity <= 0 ) return;
            if(items.cout(item
        }
        void removeProduct(product* item){
            auto it = find(products.begin(), products.end(), item);
            if (it != products.end()) {
                products.erase(it);
            }
        }
        vector<product*> getProducts(){
            return this->products;
        }
        double totalPrice(){
            double total = 0.0;
            for(auto item : products) {
                total += item->getPrice();
            }
            return total;
        }
        void displayCart(){
            cout << "Cart contains:" << endl;
            for(auto item : products) {
                cout << "- " << item->getName() << ": $" << item->getPrice() << endl;
            }
        }
};

class user
{
    private:
        string username;
        string id;
        cart* userCart;
    public:
        void setUsername(string username){
            this->username = username;
        }
        void setId(string id){
            this->id = id;
        }
        void setCart(cart* userCart){
            this->userCart = userCart;
        }
        string getUsername(){
            return this->username;
        }
        string getId(){
            return this->id;
        }
        cart* getCart(){
            return this->userCart;
        }
        
        user(string username, string id, cart* userCart) {
            this->setUsername(username);
            this->setId(id);
            this->setCart(userCart);
        }
        void display() {
            cout << "User ID: " << this->id << endl;
            cout << "Username: " << this->username << endl;
            userCart->displayCart();
            cout << "Cart Total Price: $" << userCart->totalPrice() << endl;
        }
};

int main(){
    electronicItem* laptop = new electronicItem("Laptop", 10000.00);
    fashionItem* aoThun = new fashionItem("AoThun", 50.00, 0.2);

    cart* userCart = new cart();
    userCart->addProduct(laptop,1);
    userCart->addProduct(aoThun,2);

    user* user1 = new user("Alice","001", userCart);

    user1->display();
    delete laptop;
    delete aoThun;
    delete userCart;
    delete user1;
    return 0;
}