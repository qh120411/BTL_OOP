#ifndef GIANGVIENMANAGER_H
#define GIANGVIENMANAGER_H

#include <../include/models/Giangvien.h>
#include <vector>
#include <string>

class GiangVienManager
{
private:
    std::vector<Giangvien> dsGiangVien;

public:
    void themGiangVien();
    bool themGiangVien(const Giangvien &);

    void hienThiDanhSach() const;
    void hienThiTheoMa(const std::string &) const;

    int timViTriTheoMa(const std::string &) const;
    Giangvien *timGiangVienTheoMa(const std::string &);
    const Giangvien *timGiangVienTheoMa(const std::string &) const;

    bool suaGiangVien(const std::string &);
    bool xoaGiangVien(const std::string &);

    bool tonTaiMaGiangVien(const std::string &) const;

    void sapXepTheoTen();
    void sapXepTheoKhoa();

    bool docTuFileCsv(const std::string &);
    bool ghiRaFileCsv(const std::string &) const;
};

#endif