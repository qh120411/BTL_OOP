#include "../../include/models/Taikhoan.h"
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

TaiKhoan::TaiKhoan(string tk, string mk, string quyen, string tt) : taikhoan(tk), matkhau(mk), role(quyen), trangthai(tt) {}

TaiKhoan::~TaiKhoan(){}

void TaiKhoan::settk(const string& tk) {
    taikhoan = tk;
}
string TaiKhoan::gettk() const{
    return taikhoan;
}

void TaiKhoan::setmk(const string& mk) {
    matkhau = mk;
}
string TaiKhoan::getmk() const{
    return matkhau;
}

void TaiKhoan::setrole(const string& quyen) {
    role = quyen;
}

string TaiKhoan::getrole() const{
    return role;
}

void TaiKhoan::settrangthai(const string& tt) {
    trangthai = tt;
}

string TaiKhoan::gettrangthai() const{
    return trangthai;
}

bool TaiKhoan::checklog(const string& ten_file) {
    string tkinput, mkinput;
    cout << "Nhap vao tai khoan: ";
    getline(cin,tkinput);
    cout << "Nhap vao mat khau: ";
    getline(cin,mkinput);

    ifstream file(ten_file);
    string line;
    while(getline(file, line)){
        stringstream ss(line);
        string tk, mk, quyen, tt;

        getline(ss,tk,',');
        getline(ss, mk, ',');
        getline(ss, quyen, ',');
        getline(ss,tt, ',');

        if ( tk == tkinput && mk == mkinput ) {
            if (tt == "locked") {
                cout << "Tai khoan da bi khoa\n";
                return false;
            }
            this->taikhoan = tk;
            this->matkhau = mk;
            this->role = quyen;
            this->trangthai = tt;

            return true;
        }
    }
    cout << "Sai tai khoan or mat khau\n";
    return false;
}
