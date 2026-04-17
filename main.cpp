#include <iostream>
#include "include/models/Taikhoan.h"

using namespace std;

int main() {
    TaiKhoan tk;

    if (tk.checklog("C:/Users/Admin/Desktop/BTL_OOP/data/Taikhoan.csv")) {
        cout << "Dang nhap thanh cong\n";
        string role = tk.getrole();

        if (role == "admin") {
            cout << "Dang vao he thong admin\n";
        }
        else if (role == "gv") {
            cout << "Dang vao he thong giang vien\n";
        }
        else if (role == "sv") {
            cout << "Dang vao he thong sinh vien\n";
        }
    }
    else {
        cout << "Sai tai khoan hoac mat khau\n";
    }

    return 0;
}