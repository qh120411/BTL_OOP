#include "../../include/models/Taikhoan.h"
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;

TaiKhoan::TaiKhoan(string tk, string mk, string quyen, string tt, string maLienKet)
    : taikhoan(tk), matkhau(mk), role(quyen), maLienKet(maLienKet), trangthai(tt) {}

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

void TaiKhoan::setMaLienKet(const string& ma) {
    maLienKet = ma;
}

string TaiKhoan::getMaLienKet() const {
    return maLienKet;
}

string TaiKhoan::getDinhDanhNguoiDung() const {
    return maLienKet.empty() ? taikhoan : maLienKet;
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
        if (line.empty()) {
            continue;
        }

        stringstream ss(line);
        vector<string> fields;
        string field;

        while (getline(ss, field, ',')) {
            fields.push_back(field);
        }

        if (fields.size() < 4 || fields[0] == "TaiKhoan") {
            continue;
        }

        string tk = fields[0];
        string mk = fields[1];
        string quyen = fields[2];
        string maLienKet = fields.size() >= 5 ? fields[3] : "";
        string tt = fields.size() >= 5 ? fields[4] : fields[3];

        if ( tk == tkinput && mk == mkinput ) {
            if (tt == "locked") {
                cout << "Tai khoan da bi khoa\n";
                return false;
            }
            this->taikhoan = tk;
            this->matkhau = mk;
            this->role = quyen;
            this->maLienKet = maLienKet;
            this->trangthai = tt;

            return true;
        }
    }
    cout << "Sai tai khoan or mat khau\n";
    return false;
}
