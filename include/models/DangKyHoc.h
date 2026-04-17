#ifndef DANGKYHOC_H
#define DANGKYHOC_H

#include <string>

class DangKyHoc {
    private:
        std::string maDangKy;
        std::string maSV;
        std::string maLHP;
        std::string ngayDangKy;
        std::string trangThai;

    public:
        DangKyHoc() {
            this->maDangKy = "";
            this->maSV = "";
            this->maLHP = "";
            this->ngayDangKy = "";
            this->trangThai = "";
        }
        DangKyHoc(std::string maDangKy, std::string maSV, std::string maLHP, std::string ngayDangKy, std::string trangThai) {
            this->maDangKy = maDangKy;
            this->maSV = maSV;
            this->maLHP = maLHP;
            this->ngayDangKy = ngayDangKy;
            this->trangThai = trangThai;
        }

        std::string getMaDangKy() const;
        std::string getMaSV() const;
        std::string getMaLHP() const;
        std::string getNgayDangKy() const;
        std::string getTrangThai() const;

        void setMaDangKy(const std::string&);
        void setMaSV(const std::string&);
        void setMaLHP(const std::string&);
        void setNgayDangKy(const std::string&);
        void setTrangThai(const std::string&);

        void nhap();
        void xuat() const;
};

#endif