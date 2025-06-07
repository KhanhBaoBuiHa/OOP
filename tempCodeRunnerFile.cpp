#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class product {
protected:
    string name;
    double price;
public:
    product(string name, double price) : name(name), price(price) {}

    virtual double getPrice() {
        return price;
    }

    virtual string getName() {
        return name;
    }

    virtual ~product() {}
};

class electronicItem : public product {
public:
    electronicItem(string name, double price) : product(name, price) {}
};

class fashionItem : public product {
private:
    float discount; // 20 means 20%
public:
    fashionItem(string name, double price, float discount)
        : product(name, price), discount(discount) {}

    double getPrice() override {
        return price * (1 - discount); // 0.2 means 20% discount
    }
};

class cart {
private:
    vector<product*> products;
public:
    void addProduct(product* item) {
        products.push_back(item);
    }

    void removeProduct(product* item) {
        auto it = find(products.begin(), products.end(), item);
        if (it != products.end()) {
            products.erase(it);
        }
    }

    double totalPrice() {
        double total = 0.0;
        for (auto item : products) {
            total += item->getPrice();
        }
        return total;
    }

    void displayCart() {
        cout << "Cart contains:\n";
        for (auto item : products) {
            cout << "- " << item->getName() << ": $" << item->getPrice() << endl;
        }
        cout << "Total Price: $" << totalPrice() << endl;
    }
};

class user {
private:
    string username;
    string id;
    cart* userCart;
public:
    user(string username, string id, cart* userCart)
        : username(username), id(id), userCart(userCart) {}

    void display() {
        cout << "User ID: " << id << ", Username: " << username << endl;
        userCart->displayCart();
    }
};

int main() {
    // Tạo sản phẩm
    electronicItem* laptop = new electronicItem("Laptop", 1000.00);
    fashionItem* aoThun = new fashionItem("Ao Thun", 50.00, 0.2f); // 20% discount

    // Tạo giỏ hàng và thêm sản phẩm
    cart* userCart = new cart();
    userCart->addProduct(laptop);
    userCart->addProduct(aoThun);
    userCart->addProduct(aoThun);

    // Tạo người dùng với đúng giỏ hàng
    user* user1 = new user("Alice", "001", userCart);

    // Hiển thị
    user1->display();

    // Giải phóng bộ nhớ
    delete laptop;
    delete aoThun;
    delete userCart;
    delete user1;

    return 0;
}
