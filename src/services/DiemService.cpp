#include "../include/services/DiemService.h"
#include "../include/utils/InputHelper.h"

#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <exception>

void DiemService::themDangKy()
{
    DangKyHoc dk;
    dk.nhap();

    if (tonTaiMaDangKy(dk.getMaDangKy()))
    {
        std::cout << "Ma dang ky da ton tai. Khong the them." << std::endl;
        return;
    }

    dsDangKy.push_back(dk);
    std::cout << "Them dang ky thanh cong." << std::endl;
}

bool DiemService::themDangKy(const DangKyHoc &dk)
{
    if (tonTaiMaDangKy(dk.getMaDangKy()))
    {
        return false;
    }

    dsDangKy.push_back(dk);
    return true;
}

void DiemService::hienThiDanhSach() const
{
    if (dsDangKy.empty())
    {
        std::cout << "Danh sach dang ky rong." << std::endl;
        return;
    }

    std::cout << std::left
              << std::setw(10) << "Ma DK"
              << std::setw(12) << "Ma SV"
              << std::setw(10) << "Ma LHP"
              << std::setw(14) << "Ngay DK"
              << std::setw(14) << "Trang thai"
              << "Diem" << std::endl;
    std::cout << std::string(75, '-') << std::endl;

    for (const auto &dk : dsDangKy)
    {
        std::cout << std::left
                  << std::setw(10) << dk.getMaDangKy()
                  << std::setw(12) << dk.getMaSV()
                  << std::setw(10) << dk.getMaLHP()
                  << std::setw(14) << dk.getNgayDangKy()
                  << std::setw(14) << dk.getTrangThai()
                  << std::fixed << std::setprecision(1) << dk.getDiem() << std::endl;
    }
}

void DiemService::hienThiTheoMaSV(const std::string &maSV) const
{
    bool found = false;
    std::cout << std::left
              << std::setw(10) << "Ma DK"
              << std::setw(10) << "Ma LHP"
              << std::setw(14) << "Ngay DK"
              << std::setw(14) << "Trang thai"
              << "Diem" << std::endl;
    std::cout << std::string(62, '-') << std::endl;
    for (const auto &dk : dsDangKy)
    {
        if (dk.getMaSV() == maSV)
        {
            std::cout << std::left
                      << std::setw(10) << dk.getMaDangKy()
                      << std::setw(10) << dk.getMaLHP()
                      << std::setw(14) << dk.getNgayDangKy()
                      << std::setw(14) << dk.getTrangThai()
                      << std::fixed << std::setprecision(1) << dk.getDiem() << std::endl;
            found = true;
        }
    }
    if (!found)
    {
        std::cout << "Khong tim thay dang ky cho sinh vien: " << maSV << std::endl;
    }
}

int DiemService::timViTriTheoMa(const std::string &ma) const
{
    for (size_t i = 0; i < dsDangKy.size(); ++i)
    {
        if (dsDangKy[i].getMaDangKy() == ma)
        {
            return i;
        }
    }
    return -1;
}

DangKyHoc *DiemService::timDangKyTheoMa(const std::string &ma)
{
    int pos = timViTriTheoMa(ma);
    return pos != -1 ? &dsDangKy[pos] : nullptr;
}

const DangKyHoc *DiemService::timDangKyTheoMa(const std::string &ma) const
{
    int pos = timViTriTheoMa(ma);
    return pos != -1 ? &dsDangKy[pos] : nullptr;
}

bool DiemService::suaDiem(const std::string &ma, double diemMoi)
{
    DangKyHoc *dk = timDangKyTheoMa(ma);
    if (!dk)
    {
        std::cout << "Khong tim thay dang ky de sua diem." << std::endl;
        return false;
    }

    dk->setDiem(diemMoi);
    return true;
}

bool DiemService::xoaDangKy(const std::string &ma)
{
    int pos = timViTriTheoMa(ma);
    if (pos == -1)
    {
        std::cout << "Khong tim thay dang ky de xoa." << std::endl;
        return false;
    }

    dsDangKy.erase(dsDangKy.begin() + pos);
    std::cout << "Xoa dang ky thanh cong." << std::endl;
    return true;
}

bool DiemService::tonTaiMaDangKy(const std::string &ma) const
{
    return timViTriTheoMa(ma) != -1;
}

void DiemService::sapXepTheoDiemGiamDan()
{
    std::sort(dsDangKy.begin(), dsDangKy.end(), [](const DangKyHoc &a, const DangKyHoc &b)
              { return a.getDiem() > b.getDiem(); });
}

bool DiemService::docTuFileCsv(const std::string &filename)
{
    std::ifstream fin(filename);
    if (!fin.is_open())
    {
        std::cout << "Khong the mo file: " << filename << std::endl;
        return false;
    }

    dsDangKy.clear();

    std::string line;
    bool boHeader = true;

    while (std::getline(fin, line))
    {
        if (line.empty())
            continue;

        if (boHeader)
        {
            boHeader = false;
            continue;
        }

        try
        {
            std::vector<std::string> fields = InputHelper::splitCsvLine(line);
            // Assume CSV: maDangKy,maSV,maLHP,ngayDangKy,trangThai,diem
            if (fields.size() != 6)
            {
                throw std::invalid_argument("Invalid CSV row for DangKyHoc");
            }
            DangKyHoc dk;
            dk.setMaDangKy(fields[0]);
            dk.setMaSV(fields[1]);
            dk.setMaLHP(fields[2]);
            dk.setNgayDangKy(fields[3]);
            dk.setTrangThai(fields[4]);
            dk.setDiem(std::stod(fields[5]));
            dsDangKy.push_back(dk);
        }
        catch (const std::exception &e)
        {
            std::cout << "Loi doc dong: " << line << " - " << e.what() << std::endl;
        }
    }

    fin.close();
    return true;
}

bool DiemService::ghiRaFileCsv(const std::string &filename) const
{
    std::ofstream fout(filename);
    if (!fout.is_open())
    {
        std::cout << "Khong the mo file de ghi: " << filename << std::endl;
        return false;
    }

    fout << "MaDangKy,MaSV,MaLHP,NgayDangKy,TrangThai,Diem" << std::endl;

    for (const auto &dk : dsDangKy)
    {
        fout << dk.getMaDangKy() << "," << dk.getMaSV() << "," << dk.getMaLHP() << ","
             << dk.getNgayDangKy() << "," << dk.getTrangThai() << "," << dk.getDiem() << std::endl;
    }

    fout.close();
    return true;
}
