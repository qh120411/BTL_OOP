#include <../include/models/LopHocPhan.h>
#include <../include/utils/InputHelper.h>
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
    this->maLHP = InputHelper::inputLine("Nhap ma lop hoc phan: ");

    this->maMon = InputHelper::inputLine("Nhap ma mon hoc: ");

    this->maGV = InputHelper::inputLine("Nhap ma giang vien: ");

    this->hocKy = InputHelper::inputLine("Nhap hoc ky: ");

    this->namHoc = InputHelper::inputLine("Nhap nam hoc: ");

    this->phongHoc = InputHelper::inputLine("Nhap phong hoc: ");

    this->lichHoc = InputHelper::inputLine("Nhap lich hoc: ");

    this->siSoToiDa = InputHelper::inputInt("Nhap si so toi da: ", 1, 100);

    this->siSoHienTai = 0;
}

void LopHocPhan::xuat() const {
    
}