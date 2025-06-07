#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Lớp trừu tượng: ToChuc
class ToChuc {
protected:
    string ten;
    int soNhanVien;

public:
    ToChuc(string ten, int soNhanVien) {
        this->ten = ten;
        this->soNhanVien = soNhanVien;
    }

    virtual void hienThi() = 0; // Hàm ảo thuần túy

    virtual int laySoNhanVien() {
        return soNhanVien;
    }

    virtual ~ToChuc() {} // Destructor ảo để tránh rò rỉ bộ nhớ
};

// Lớp Phong kế thừa từ ToChuc
class Phong : public ToChuc {
public:
    Phong(string ten, int soNhanVien) : ToChuc(ten, soNhanVien) {}

    void hienThi() override {
        cout << "Phong: " << ten << " | So nhan vien: " << soNhanVien << endl;
    }
};

// Lớp Khoa kế thừa từ ToChuc
class Khoa : public ToChuc {
public:
    Khoa(string ten, int soNhanVien) : ToChuc(ten, soNhanVien) {}

    void hienThi() override {
        cout << "Khoa: " << ten << " | So nhan vien: " << soNhanVien << endl;
    }
};

// Lớp Đại học quản lý các tổ chức
class DaiHoc {
private:
    string ten;
    vector<ToChuc*> danhSachToChuc;

public:
    DaiHoc(string ten) {
        this->ten = ten;
    }

    void themToChuc(ToChuc* tc) {
        danhSachToChuc.push_back(tc);
    }

    void hienThiDanhSach() {
        cout << "\nDai hoc: " << ten << endl;
        cout << "Danh sach cac to chuc:\n";
        for (auto tc : danhSachToChuc) {
            tc->hienThi();
        }
    }

    int tinhTongNhanVien() {
        int tong = 0;
        for (auto tc : danhSachToChuc) {
            tong += tc->laySoNhanVien();
        }
        return tong;
    }

    ~DaiHoc() {
        for (auto tc : danhSachToChuc) {
            delete tc;
        }
    }
};

int main() {
    DaiHoc dh("Dai hoc BKHN");

    // Tạo 2 phòng
    dh.themToChuc(new Phong("Phong Dao tao", 10));
    dh.themToChuc(new Phong("Phong Khao thi", 8));

    // Tạo 2 khoa
    dh.themToChuc(new Khoa("Khoa Cong nghe thong tin", 25));
    dh.themToChuc(new Khoa("Khoa Toan", 15));

    // In danh sách tổ chức
    dh.hienThiDanhSach();

    // In tổng số nhân viên
    cout << "\nTong so nhan vien: " << dh.tinhTongNhanVien() << endl;

    return 0;
}
