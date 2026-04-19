#include <../include/models/MonHoc.h>
#include <../include/utils/InputHelper.h>
#include <string>
#include <iostream>
#include <vector>

std::string MonHoc::getMaMonHoc() const { return this->maMonHoc; }

std::string MonHoc::getTenMonHoc() const { return this->tenMonHoc; }

int MonHoc::getSoTinChi() const { return this->soTinChi; }

int MonHoc::getSoTiet() const { return this->soTiet; }



void MonHoc::setMaMonHoc(const std::string& maMonHoc) { this->maMonHoc = maMonHoc; }

void MonHoc::setTenMonHoc(const std::string& tenMonHoc) { this->tenMonHoc = tenMonHoc; }

void MonHoc::setSoTinChi(int soTinChi) { this->soTinChi = soTinChi; }

void MonHoc::setSoTiet(int soTiet) { this->soTiet = soTiet; }



void MonHoc::nhap() {
    this->maMonHoc = InputHelper::inputLine("Nhap ma mon hoc: ");

    this->tenMonHoc = InputHelper::inputLine("Nhap ten mon hoc: ");

    this->soTinChi = InputHelper::inputInt("Nhap so tin chi: ", 1, 10);

    this->soTiet = InputHelper::inputInt("Nhap so tiet: ", 1, 50);
}

void MonHoc::xuat() const {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Ma mon hoc : " << maMonHoc << std::endl;
    std::cout << "Ten mon hoc: " << tenMonHoc << std::endl;
    std::cout << "So tin chi : " << soTinChi << std::endl;
    std::cout << "So tiet    : " << soTiet << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}

std::string MonHoc::csvHeader() {
    return "MaMonHoc,TenMonHoc,SoTinChi,SoTiet";
}

std::string MonHoc::toCsvRow() const {
    return maMonHoc + "," + tenMonHoc + "," + std::to_string(soTinChi) + "," + std::to_string(soTiet);
}

MonHoc MonHoc::fromCsvRow(const std::vector<std::string>& fields) {
    MonHoc mh;
    if (fields.size() < 4) {
        throw std::runtime_error("Khong du cot du lieu");
    }

    mh.setMaMonHoc(fields[0]);
    mh.setTenMonHoc(fields[1]);
    mh.setSoTinChi(std::stoi(fields[2]));
    mh.setSoTiet(std::stoi(fields[3]));

    return mh;
}
