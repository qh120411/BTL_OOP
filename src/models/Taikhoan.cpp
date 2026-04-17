#include "../../include/models/Taikhoan.h"
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

TaiKhoan::TaiKhoan(string tk, string mk, string quyen) : taikhoan(tk), matkhau(mk), role(quyen) {};

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
        string tk, mk, quyen;

        getline(ss,tk,',');
        getline(ss, mk, ',');
        getline(ss, quyen, ',');

        if ( tk == tkinput && mk == mkinput ) {
            this->taikhoan = tk;
            this->matkhau = mk;
            this->role = quyen;
            return true;
        }
    }
    return false;
}
