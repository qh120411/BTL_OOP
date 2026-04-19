#include <iostream>
#include "include/models/Taikhoan.h"
#include "include/services/Menu.h"

using namespace std;

int main()
{
    TaiKhoan tk;
    while (true)
    {
        if (tk.checklog("data/Taikhoan.csv"))
        {
            cout << "Dang nhap thanh cong\n";
            string role = tk.getrole();

            // Convert role to lowercase for comparison
            for (int i = 0; i < role.length(); i++)
            {
                role[i] = tolower(role[i]);
            }

            if (role == "admin")
            {
                menuAdmin();
            }
            else if (role == "gv")
            {
                menuGiangVien(tk.getDinhDanhNguoiDung());
            }
            else if (role == "sv")
            {
                menuSinhVien(tk.getDinhDanhNguoiDung());
            }
            break; // exit after successful login and menu
        }
        else
        {
            cout << "Dang nhap that bai. Thu lai? (y/n): ";
            char choice;
            cin >> choice;
            if (choice != 'y' && choice != 'Y')
            {
                break;
            }
        }
    }
    return 0;
}
