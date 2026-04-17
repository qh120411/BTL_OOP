#include <../include/models/MonHoc.h>
#include <../include/utils/InputHelper.h>
#include <string>

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
    this->maMonHoc = InputHelper::inputLine("Nhap ma mon hoc: ");

    this->tenMonHoc = InputHelper::inputLine("Nhap ten mon hoc: ");

    this->soTinChi = InputHelper::inputInt("Nhap so tin chi: ", 1, 10);

    this->soTiet = InputHelper::inputInt("Nhap so tiet: ", 1, 50);

    this->monTienQuyet = InputHelper::inputLine("Nhap mon tien quyet: ");

    this->khoaPhuTrach = InputHelper::inputLine("Nhap khoa phu trach: ");
}

void MonHoc::xuat() const {
    
}