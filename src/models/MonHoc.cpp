#include <../include/models/MonHoc.h>
#include <string>
#include <iostream>

std::string MonHoc::getMaMonHoc() const { return this->maMonHoc; }

std::string MonHoc::getTenMonHoc() const { return this->tenMonHoc; }

int MonHoc::getSoTinChi() const { return this->soTinChi; }

int MonHoc::getSoTiet() const { return this->soTiet; }

std::string MonHoc::getMonTienQuyet() const { return this->monTienQuyet; }

std::string MonHoc::getKhoaPhuTrach() const { return this->khoaPhuTrach; }



void MonHoc::setMaMonHoc(const std::string& maMonHoc) { this->maMonHoc = maMonHoc; }

void MonHoc::setTenMonHoc(const std::string& tenMonHoc) { this->tenMonHoc = tenMonHoc; }

void MonHoc::setSoTinChi(int soTinChi) { this->soTinChi = soTinChi; }

void MonHoc::setSoTiet(int soTiet) { this->soTiet = soTiet; }

void MonHoc::setMonTienQuyet(const std::string& monTienQuyet) { this->monTienQuyet = monTienQuyet; }

void MonHoc::setKhoaPhuTrach(const std::string& khoaPhuTrach) { this->khoaPhuTrach = khoaPhuTrach; }



void MonHoc::nhap() {
    std::cout << "Nhap ma mon hoc: ";
    std::cin.ignore();
    getline(std::cin, this->maMonHoc);

    std::cout << "Nhap ten mon hoc: ";
    getline(std::cin, this->tenMonHoc);

    std::cout << "Nhap so tin chi: ";
    std::cin >> this->soTinChi;

    std::cout << "Nhap so tiet: ";
    std::cin >> this->soTiet;

    std::cout << "Nhap mon tien quyet: ";
    std::cin.ignore();
    getline(std::cin, this->monTienQuyet);

    std::cout << "Nhap khoa phu trach: ";
    getline(std::cin, this->khoaPhuTrach);
}

void MonHoc::xuat() const {
    
}