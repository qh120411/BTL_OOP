#ifndef SINHVIENMANAGER_H
#define SINHVIENMANAGER_H

#include <../include/models/Sinhvien.h>
#include <vector>
#include <string>

class SinhVienManager
{
private:
    std::vector<Sinhvien> dsSinhVien;

public:
    void themSinhVien();
    bool themSinhVien(const Sinhvien &);

    void hienThiDanhSach() const;
    void hienThiTheoMa(const std::string &) const;

    int timViTriTheoMa(const std::string &) const;
    Sinhvien *timSinhVienTheoMa(const std::string &);
    const Sinhvien *timSinhVienTheoMa(const std::string &) const;

    bool suaSinhVien(const std::string &);
    bool xoaSinhVien(const std::string &);

    bool tonTaiMaSinhVien(const std::string &) const;

    void sapXepTheoTen();
    void sapXepTheoKhoaHocTangDan();

    bool docTuFileCsv(const std::string &);
    bool ghiRaFileCsv(const std::string &) const;
};

#endif