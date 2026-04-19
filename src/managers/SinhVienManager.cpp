#include "../include/managers/SinhVienManager.h"
#include "../include/utils/InputHelper.h"

#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <exception>

static std::string tinhTrangSinhVienText(Tinhtrang tinhtrang)
{
    switch (tinhtrang)
    {
    case DANG_HOC:
        return "DANG_HOC";
    case BAO_LUU:
        return "BAO_LUU";
    case TOT_NGHIEP:
        return "TOT_NGHIEP";
    case THOI_HOC:
        return "THOI_HOC";
    }
    return "DANG_HOC";
}

void SinhVienManager::themSinhVien()
{
    Sinhvien sv;
    sv.nhap();

    if (tonTaiMaSinhVien(sv.getmsv()))
    {
        std::cout << "Ma sinh vien da ton tai. Khong the them." << std::endl;
        return;
    }

    dsSinhVien.push_back(sv);
    std::cout << "Them sinh vien thanh cong." << std::endl;
}

bool SinhVienManager::themSinhVien(const Sinhvien &sv)
{
    if (tonTaiMaSinhVien(sv.getmsv()))
    {
        return false;
    }

    dsSinhVien.push_back(sv);
    return true;
}

void SinhVienManager::hienThiDanhSach() const
{
    if (dsSinhVien.empty())
    {
        std::cout << "Danh sach sinh vien rong." << std::endl;
        return;
    }

    std::cout << std::left
              << std::setw(12) << "MSV"
              << std::setw(24) << "Ho ten"
              << std::setw(24) << "Nganh"
              << std::setw(10) << "Lop"
              << std::setw(10) << "Khoa hoc"
              << "Tinh trang" << std::endl;
    std::cout << std::string(100, '-') << std::endl;

    for (const auto &sv : dsSinhVien)
    {
        std::cout << std::left
                  << std::setw(12) << sv.getmsv()
                  << std::setw(24) << sv.gethoten()
                  << std::setw(24) << sv.getnganh()
                  << std::setw(10) << sv.getlop()
                  << std::setw(10) << sv.getkhoahoc()
                  << tinhTrangSinhVienText(sv.gettinhtrang()) << std::endl;
    }
}

void SinhVienManager::hienThiTheoMa(const std::string &ma) const
{
    const Sinhvien *sv = timSinhVienTheoMa(ma);
    if (sv)
    {
        sv->xuat();
    }
    else
    {
        std::cout << "Khong tim thay sinh vien voi ma: " << ma << std::endl;
    }
}

int SinhVienManager::timViTriTheoMa(const std::string &ma) const
{
    for (size_t i = 0; i < dsSinhVien.size(); ++i)
    {
        if (dsSinhVien[i].getmsv() == ma)
        {
            return i;
        }
    }
    return -1;
}

Sinhvien *SinhVienManager::timSinhVienTheoMa(const std::string &ma)
{
    int pos = timViTriTheoMa(ma);
    return pos != -1 ? &dsSinhVien[pos] : nullptr;
}

const Sinhvien *SinhVienManager::timSinhVienTheoMa(const std::string &ma) const
{
    int pos = timViTriTheoMa(ma);
    return pos != -1 ? &dsSinhVien[pos] : nullptr;
}

bool SinhVienManager::suaSinhVien(const std::string &ma)
{
    Sinhvien *sv = timSinhVienTheoMa(ma);
    if (!sv)
    {
        std::cout << "Khong tim thay sinh vien de sua." << std::endl;
        return false;
    }

    std::cout << "Nhap thong tin moi cho sinh vien:" << std::endl;
    sv->nhap();
    return true;
}

bool SinhVienManager::xoaSinhVien(const std::string &ma)
{
    int pos = timViTriTheoMa(ma);
    if (pos == -1)
    {
        std::cout << "Khong tim thay sinh vien de xoa." << std::endl;
        return false;
    }

    dsSinhVien.erase(dsSinhVien.begin() + pos);
    std::cout << "Xoa sinh vien thanh cong." << std::endl;
    return true;
}

bool SinhVienManager::tonTaiMaSinhVien(const std::string &ma) const
{
    return timViTriTheoMa(ma) != -1;
}

void SinhVienManager::sapXepTheoTen()
{
    std::sort(dsSinhVien.begin(), dsSinhVien.end(), [](const Sinhvien &a, const Sinhvien &b)
              { return a.gethoten() < b.gethoten(); });
}

void SinhVienManager::sapXepTheoKhoaHocTangDan()
{
    std::sort(dsSinhVien.begin(), dsSinhVien.end(), [](const Sinhvien &a, const Sinhvien &b)
              { return a.getkhoahoc() < b.getkhoahoc(); });
}

bool SinhVienManager::docTuFileCsv(const std::string &filename)
{
    std::ifstream fin(filename);
    if (!fin.is_open())
    {
        std::cout << "Khong the mo file: " << filename << std::endl;
        return false;
    }

    dsSinhVien.clear();

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
            Sinhvien sv = Sinhvien::fromCsvRow(fields);

            if (!tonTaiMaSinhVien(sv.getmsv()))
            {
                dsSinhVien.push_back(sv);
            }
        }
        catch (const std::exception &e)
        {
            std::cout << "Loi doc dong: " << line << " - " << e.what() << std::endl;
        }
    }

    fin.close();
    return true;
}

bool SinhVienManager::ghiRaFileCsv(const std::string &filename) const
{
    std::ofstream fout(filename);
    if (!fout.is_open())
    {
        std::cout << "Khong the mo file de ghi: " << filename << std::endl;
        return false;
    }

    fout << Sinhvien::csvHeader() << std::endl;

    for (const auto &sv : dsSinhVien)
    {
        fout << sv.toCsvRow() << std::endl;
    }

    fout.close();
    return true;
}
