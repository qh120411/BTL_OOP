#include <../include/MonHoc.h>
#include <string>
#include <iostream>

MonHoc::MonHoc() {
    this->maMonHoc = "";
    this->tenMonHoc = "";
    this->soTinChi = 0;
    this->soTiet = 0;
    this->monTienQuyet = "";
    this->khoaPhuTrach = "";
}

MonHoc::MonHoc(string maMonHoc, string tenMonHoc, int soTinChi, int soTiet, string monTienQuyet, string khoaPhuTrach) {
    this->maMonHoc = maMonHoc;
    this->tenMonHoc = tenMonHoc;
    this->soTinChi = soTinChi;
    this->soTiet = soTiet;
    this->monTienQuyet = monTienQuyet;
    this->khoaPhuTrach = khoaPhuTrach;
}



string MonHoc::getMaMonHoc() { return this->maMonHoc; }

string MonHoc::getTenMonHoc() { return this->tenMonHoc; }

int MonHoc::getSoTinChi() { return this->soTinChi; }

int MonHoc::getSoTiet() { return this->soTiet; }

string MonHoc::getMonTienQuyet() { return this->monTienQuyet; }

string MonHoc::getKhoaPhuTrach() { return this->khoaPhuTrach; }



void MonHoc::setMaMonHoc(string maMonHoc) { this->maMonHoc = maMonHoc; }

void MonHoc::setTenMonHoc(string tenMonHoc) { this->tenMonHoc = tenMonHoc; }

void MonHoc::setSoTinChi(int soTinChi) { this->soTinChi = soTinChi; }

void MonHoc::setSoTiet(int soTiet) { this->soTiet = soTiet; }

void MonHoc::setMonTienQuyet(string monTienQuyet) { this->monTienQuyet = monTienQuyet; }

void MonHoc::setKhoaPhuTrach(string khoaPhuTrach) { this->khoaPhuTrach = khoaPhuTrach; }



void MonHoc::nhap() {
    cout << "Nhap ma mon hoc: ";
    cin.ignore();
    getline(cin, this->maMonHoc);

    cout << "Nhap ten mon hoc: ";
    getline(cin, this->tenMonHoc);

    cout << "Nhap so tin chi: ";
    cin >> this->soTinChi;

    cout << "Nhap so tiet: ";
    cin >> this->soTiet;

    cout << "Nhap mon tien quyet: ";
    cin.ignore();
    getline(cin, this->monTienQuyet);

    cout << "Nhap khoa phu trach: ";
    getline(cin, this->khoaPhuTrach);
}

void xuat() {
    
}