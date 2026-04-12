#include <../include/models/DangKyHoc.h>
#include <../include/utils/InputHelper.h>

#include <string>

std::string DangKyHoc::getMaDangKy() const { return this->maDangKy; }

std::string DangKyHoc::getMaSV() const { return this->maSV; }

std::string DangKyHoc::getMaLHP() const { return this->maLHP; }

std::string DangKyHoc::getNgayDangKy() const { return this->ngayDangKy; }

std::string DangKyHoc::getTrangThai() const { return this->trangThai; }



void DangKyHoc::setMaDangKy(const std::string& maDangKy) { this->maDangKy = maDangKy; }

void DangKyHoc::setMaSV(const std::string& maSV) { this->maSV = maSV; }

void DangKyHoc::setMaLHP(const std::string& maLHP) { this->maLHP = maLHP; }

void DangKyHoc::setNgayDangKy(const std::string& ngayDangKy) { this->ngayDangKy = ngayDangKy; }

void DangKyHoc::setTrangThai(const std::string& trangThai) { this->trangThai = trangThai; }



void DangKyHoc::nhap() {
    this->maDangKy = InputHelper::inputLine("Nhap ma dang ky: ");

    this->maSV = InputHelper::inputLine("Nhap ma sinh vien: ");

    this->maLHP = InputHelper::inputLine("Nhap ma lop hoc phan: ");

    this->ngayDangKy = InputHelper::inputDate("Nhap ngay dang ky: ");

    this->trangThai = InputHelper::inputLine("Nhap trang thai: ");
}

void DangKyHoc::xuat() const {

}