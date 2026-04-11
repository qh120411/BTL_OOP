#include <../include/models/LopHocPhan.h>
#include <string>
#include <iostream>

std::string LopHocPhan::getMaLHP() const { return this->maLHP; }

std::string LopHocPhan::getMaMon() const { return this->maMon; }

std::string LopHocPhan::getMaGV() const { return this->maGV; }

std::string LopHocPhan::getHocKy() const { return this->hocKy; }

std::string LopHocPhan::getNamHoc() const { return this->namHoc; }

std::string LopHocPhan::getPhongHoc() const { return this->phongHoc; }

std::string LopHocPhan::getLichHoc() const { return this->lichHoc; }

int LopHocPhan::getSiSoToiDa() const { return this->siSoToiDa; }

int LopHocPhan::getSiSoHienTai() const { return this->siSoHienTai; }



void LopHocPhan::setMaLHP(const std::string& maLHP) { this->maLHP = maLHP; }

void LopHocPhan::setMaMon(const std::string& maMon) { this->maMon = maMon; }

void LopHocPhan::setMaGV(const std::string& maGV) { this->maGV = maGV; }

void LopHocPhan::setHocKy(const std::string& hocKy) { this->hocKy = hocKy; }

void LopHocPhan::setNamHoc(const std::string& namHoc) { this->namHoc = namHoc; }

void LopHocPhan::setPhongHoc(const std::string& phongHoc) { this->phongHoc = phongHoc; }

void LopHocPhan::setLichHoc(const std::string& lichHoc) { this->lichHoc = lichHoc; }

void LopHocPhan::setSiSoToiDa(int siSoToiDa) { this->siSoToiDa = siSoToiDa; }



void LopHocPhan::tangSiSo() {
    if (this->siSoHienTai < this->siSoToiDa) this->siSoHienTai++;
    else std::cout << "Lop da du si so!" << std::endl;
}

void LopHocPhan::giamSiSo() {
    if (this->siSoHienTai > 0) this->siSoHienTai--;
    else std::cout << "Si so lop hien tai la 0!" << std::endl;
}



void LopHocPhan::nhap() {
    std::cout << "Nhap ma lop hoc phan: ";
    std::cin.ignore();
    getline(std::cin, this->maLHP);

    std::cout << "Nhap ma mon hoc: ";
    getline(std::cin, this->maMon);

    std::cout << "Nhap ma giang vien: ";
    getline(std::cin, this->maGV);

    std::cout << "Nhap hoc ky: ";
    getline(std::cin, this->hocKy);

    std::cout << "Nhap nam hoc: ";
    getline(std::cin, this->namHoc);

    std::cout << "Nhap phong hoc: ";
    getline(std::cin, this->phongHoc);

    std::cout << "Nhap lich hoc: ";
    getline(std::cin, this->lichHoc);

    std::cout << "Nhap si so toi da: ";
    std::cin >> this->siSoToiDa;

    this->siSoHienTai = 0;
}

void LopHocPhan::xuat() const {
    
}