#ifndef DIEMSERVICE_H
#define DIEMSERVICE_H

#include <../include/models/DangKyHoc.h>
#include <vector>
#include <string>

class DiemService
{
private:
    std::vector<DangKyHoc> dsDangKy;

public:
    void themDangKy();
    bool themDangKy(const DangKyHoc &);

    void hienThiDanhSach() const;
    void hienThiTheoMaSV(const std::string &) const;

    int timViTriTheoMa(const std::string &) const;
    DangKyHoc *timDangKyTheoMa(const std::string &);
    const DangKyHoc *timDangKyTheoMa(const std::string &) const;

    bool suaDiem(const std::string &, double);
    bool xoaDangKy(const std::string &);

    bool tonTaiMaDangKy(const std::string &) const;

    void sapXepTheoDiemGiamDan();

    bool docTuFileCsv(const std::string &);
    bool ghiRaFileCsv(const std::string &) const;
};

#endif