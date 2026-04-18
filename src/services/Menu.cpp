#include "../../include/services/Menu.h"
#include<iostream>
#include<string>

using namespace std;

void menuAdmin() {
    int chon;
    do {
        cout << "\n========== MENU ADMIN ==========\n";
        cout << "1. Quan ly sinh vien\n";
        cout << "2. Quan ly giang vien\n";
        cout << "3. Quan ly mon hoc\n";
        cout << "4. Quan ly tai khoan\n";
        cout << "5. Phan cong giang vien day mon\n";
        cout << "0. Dang xuat\n";
        cout << "Nhap lua chon: ";
        cin >> chon;
        cin.ignore();

        switch (chon) {
            case 1:
                cout << "Vao chuc nang quan ly sinh vien\n";
                // menuQuanLySinhVien();
                break;
            case 2:
                cout << "Vao chuc nang quan ly giang vien\n";
                // menuQuanLyGiangVien();
                break;
            case 3:
                cout << "Vao chuc nang quan ly mon hoc\n";
                // menuQuanLyMonHoc();
                break;
            case 4:
                cout << "Vao chuc nang quan ly tai khoan\n";
                // menuQuanLyTaiKhoan();
                break;
            case 5:
                cout << "Vao chuc nang phan cong giang vien day mon\n";
                // phanCongGiangVienDayMon();
                break;
            case 0:
                cout << "Thoat menu Admin\n";
                return;
            default:
                cout << "Lua chon khong hop le\n";
        }
    } while (chon != 0);
}

void menuGiangVien() {
    int chon;
    do {
        cout << "\n===== MENU GIANG VIEN =====\n";
        cout << "1. Xem thong tin ca nhan\n";
        cout << "2. Xem thoi khoa bieu\n";
        cout << "3. Xem danh sach sinh vien theo mon\n";
        cout << "4. Nhap / sua diem sinh vien\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> chon;
        cin.ignore();
        switch (chon) {
            case 1:
                // xemThongTinGiangVien();
                break;
            case 2:
                // xemTKBGiangVien();
                break;
            case 3:
                // xemDanhSachSinhVienTheoMon();
                break;
            case 4:
                // nhapHoacSuaDiem();
                break;
            case 0:
                cout << "Thoat menu\n";
                return;
            default:
                cout << "Lua chon khong hop le\n";
        }
    } while (chon != 0);
}

void menuSinhVien() {
    int chon;
    do {
        cout << "\n===== MENU SINH VIEN =====\n";
        cout << "1. Xem thong tin ca nhan\n";
        cout << "2. Xem diem cac mon\n";
        cout << "3. Dang ky mon hoc\n";
        cout << "4. Xem lich hoc\n";
        cout << "5. Xem giang vien day mon\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> chon;
        cin.ignore();
        switch (chon) {
            case 1:
                // xemThongTinSinhVien();
                break;
            case 2:
                // xemDiem();
                break;
            case 3:
                // dangKyMon();
                break;
            case 4:
                // xemLichHoc();
                break;
            case 5:
                // xemGiangVienDayMon();
                break;
            case 0:
                cout << "Thoat menu\n";
                return;
            default:
                cout << "Lua chon khong hop le\n";
        }
    } while (chon != 0);
}