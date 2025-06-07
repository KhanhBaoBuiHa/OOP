#include <vector>
#include <string>

using namespace std;

class DaiHoc;
class ToChuc;
class Phong;
class Khoa;

class ToChuc{
    protected:
        string name;
        int employeeNumber;
    public:
        Tochuc(string name, int employeeNumber){
            this->name = name;
            this->employeeNumber = employeeNumber;
        }
        virtual void display() const = 0; 
        virtual int getEmployeeNumber() const {
            return employeeNumber;
        }
        virtual ~ToChuc(){}
};

class Khoa : public ToChuc{
    public:
        Khoa(string name, int employeeNumber) : ToChuc(name, employeeNumber) {}
        void display() override {
            cout << "Khoa: " << name << ", So nhan vien: " << employeeNumber << endl;
        }
};

class Phong : public ToChuc{
    public:
        Phong(string name, int employeeNumber) : ToChuc(name, employeeNumber) {}
        void display() const override {
            cout << "Phong: " << name << ", So nhan vien: " << employeeNumber << endl;
        }
};

class DaiHoc{
    private:
        string name;
        vector<ToChuc*> dsToChuc;
    public:
        DaiHoc(string name){
            this->name = name;
        }
        void display{
            cout << "Dai Hoc: " << name << endl;
            for (const auto& toChuc : dsToChuc) {
                toChuc->display();
            }
        }
        int getTotalEmployees() const {
            int total = 0;
            for (const auto& toChuc : dsToChuc) {
                total += toChuc->getEmployeeNumber();
            }
            return total;
        }
        void addToChuc(ToChuc* toChuc) {
            dsToChuc.push_back(toChuc);
        }
        ~DaiHoc() {
            for (auto& toChuc : dsToChuc) {
                delete toChuc;
            }
        }
};
int main{
    DaiHoc dh("HCMUS");
    dh.addToChuc(new Khoa("Khoa CNTT", 50));
    dh.addToChuc(new Khoa("Khoa Toan", 30));

    dh.addToChuc(new Phong("Phong Khao Thi", 5));
    dh.addToChuc(new Phong("Phong Hanh Chinh", 10));

    dh.display();
    cout << "Tong so nhan vien: " << dh.getTotalEmployees() << endl;
    return 0;
}