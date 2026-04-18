#include <iostream>
#include "include/models/Taikhoan.h"
#include "include/services/Menu.h"

using namespace std;

int main() {
    TaiKhoan tk;
    while (true) {
        if (tk.checklog("C:/Users/Admin/Desktop/BTL_OOP/data/Taikhoan.csv")) {
            cout << "Dang nhap thanh cong\n";
            string role = tk.getrole();

            if (role == "admin") {
                menuAdmin();
            }
            else if (role == "gv") {
                menuGiangVien();
            }
            else if (role == "sv") {
                menuSinhVien();
            }
        }
    }

    return 0;
}