#include <../include/models/LopHocPhan.h>
#include <../include/utils/InputHelper.h>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>

std::string LopHocPhan::getMaLHP() const { return this->maLHP; }

std::string LopHocPhan::getMaMon() const { return this->maMon; }

std::string LopHocPhan::getMaGV() const { return this->maGV; }

std::string LopHocPhan::getHocKy() const { return this->hocKy; }

std::string LopHocPhan::getNamHoc() const { return this->namHoc; }

std::string LopHocPhan::getPhongHoc() const { return this->phongHoc; }

std::string LopHocPhan::getLichHoc() const { return this->lichHoc; }

int LopHocPhan::getSiSoToiDa() const { return this->siSoToiDa; }

int LopHocPhan::getSiSoHienTai() const { return this->siSoHienTai; }

void LopHocPhan::setMaLHP(const std::string &maLHP) { this->maLHP = maLHP; }

void LopHocPhan::setMaMon(const std::string &maMon) { this->maMon = maMon; }

void LopHocPhan::setMaGV(const std::string &maGV) { this->maGV = maGV; }

void LopHocPhan::setHocKy(const std::string &hocKy) { this->hocKy = hocKy; }

void LopHocPhan::setNamHoc(const std::string &namHoc) { this->namHoc = namHoc; }

void LopHocPhan::setPhongHoc(const std::string &phongHoc) { this->phongHoc = phongHoc; }

void LopHocPhan::setLichHoc(const std::string &lichHoc) { this->lichHoc = lichHoc; }

void LopHocPhan::setSiSoToiDa(int siSoToiDa) { this->siSoToiDa = siSoToiDa; }

void LopHocPhan::setSiSoHienTai(int siSoHienTai) { this->siSoHienTai = siSoHienTai; }

void LopHocPhan::tangSiSo()
{
    if (this->siSoHienTai < this->siSoToiDa)
        this->siSoHienTai++;
    else
        std::cout << "Lop da du si so!" << std::endl;
}

void LopHocPhan::giamSiSo()
{
    if (this->siSoHienTai > 0)
        this->siSoHienTai--;
    else
        std::cout << "Si so lop hien tai la 0!" << std::endl;
}

void LopHocPhan::nhap()
{
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

void LopHocPhan::xuat() const
{
    std::cout << "Ma LHP       : " << maLHP << std::endl;
    std::cout << "Ma mon       : " << maMon << std::endl;
    std::cout << "Ma giang vien: " << maGV << std::endl;
    std::cout << "Hoc ky       : " << hocKy << std::endl;
    std::cout << "Nam hoc      : " << namHoc << std::endl;
    std::cout << "Phong hoc    : " << phongHoc << std::endl;
    std::cout << "Lich hoc     : " << lichHoc << std::endl;
    std::cout << "Si so        : " << siSoHienTai << "/" << siSoToiDa << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}

std::string LopHocPhan::csvHeader()
{
    return "MaLHP,MaMon,MaGV,HocKy,NamHoc,PhongHoc,LichHoc,SiSoToiDa,SiSoHienTai";
}

std::string LopHocPhan::toCsvRow() const
{
    std::stringstream ss;
    ss << maLHP << "," << maMon << "," << maGV << "," << hocKy << "," << namHoc << ","
       << phongHoc << "," << lichHoc << "," << siSoToiDa << "," << siSoHienTai;
    return ss.str();
}

LopHocPhan LopHocPhan::fromCsvRow(const std::vector<std::string> &fields)
{
    if (fields.size() != 9)
    {
        throw std::invalid_argument("Invalid CSV row for LopHocPhan");
    }

    return LopHocPhan(fields[0], fields[1], fields[2], fields[3], fields[4],
                      fields[5], fields[6], std::stoi(fields[7]), std::stoi(fields[8]));
}
