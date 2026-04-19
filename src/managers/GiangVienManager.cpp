#include "../include/managers/GiangVienManager.h"
#include "../include/utils/InputHelper.h"

#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <exception>

static std::string tinhTrangGiangVienText(tinhtrangGV tinhtrang)
{
    switch (tinhtrang)
    {
    case DANG_GIANG_DAY:
        return "DANG_GIANG_DAY";
    case TAM_NGHI:
        return "TAM_NGHI";
    case NGHI_THAI_SAN:
        return "NGHI_THAI_SAN";
    case NGHI_HUU:
        return "NGHI_HUU";
    case THOI_VIEC:
        return "THOI_VIEC";
    }
    return "DANG_GIANG_DAY";
}

void GiangVienManager::themGiangVien()
{
    Giangvien gv;
    gv.nhap();

    if (tonTaiMaGiangVien(gv.getmgv()))
    {
        std::cout << "Ma giang vien da ton tai. Khong the them." << std::endl;
        return;
    }

    dsGiangVien.push_back(gv);
    std::cout << "Them giang vien thanh cong." << std::endl;
}

bool GiangVienManager::themGiangVien(const Giangvien &gv)
{
    if (tonTaiMaGiangVien(gv.getmgv()))
    {
        return false;
    }

    dsGiangVien.push_back(gv);
    return true;
}

void GiangVienManager::hienThiDanhSach() const
{
    if (dsGiangVien.empty())
    {
        std::cout << "Danh sach giang vien rong." << std::endl;
        return;
    }

    std::cout << std::left
              << std::setw(10) << "MGV"
              << std::setw(24) << "Ho ten"
              << std::setw(24) << "Bo mon"
              << std::setw(12) << "Khoa"
              << std::setw(12) << "Hoc vi"
              << "Tinh trang" << std::endl;
    std::cout << std::string(100, '-') << std::endl;

    for (const auto &gv : dsGiangVien)
    {
        std::cout << std::left
                  << std::setw(10) << gv.getmgv()
                  << std::setw(24) << gv.gethoten()
                  << std::setw(24) << gv.getbomon()
                  << std::setw(12) << gv.getkhoa()
                  << std::setw(12) << gv.gethocvi()
                  << tinhTrangGiangVienText(gv.gettinhtranggv()) << std::endl;
    }
}

void GiangVienManager::hienThiTheoMa(const std::string &ma) const
{
    const Giangvien *gv = timGiangVienTheoMa(ma);
    if (gv)
    {
        gv->xuat();
    }
    else
    {
        std::cout << "Khong tim thay giang vien voi ma: " << ma << std::endl;
    }
}

int GiangVienManager::timViTriTheoMa(const std::string &ma) const
{
    for (size_t i = 0; i < dsGiangVien.size(); ++i)
    {
        if (dsGiangVien[i].getmgv() == ma)
        {
            return i;
        }
    }
    return -1;
}

Giangvien *GiangVienManager::timGiangVienTheoMa(const std::string &ma)
{
    int pos = timViTriTheoMa(ma);
    return pos != -1 ? &dsGiangVien[pos] : nullptr;
}

const Giangvien *GiangVienManager::timGiangVienTheoMa(const std::string &ma) const
{
    int pos = timViTriTheoMa(ma);
    return pos != -1 ? &dsGiangVien[pos] : nullptr;
}

bool GiangVienManager::suaGiangVien(const std::string &ma)
{
    Giangvien *gv = timGiangVienTheoMa(ma);
    if (!gv)
    {
        std::cout << "Khong tim thay giang vien de sua." << std::endl;
        return false;
    }

    std::cout << "Nhap thong tin moi cho giang vien:" << std::endl;
    gv->nhap();
    return true;
}

bool GiangVienManager::xoaGiangVien(const std::string &ma)
{
    int pos = timViTriTheoMa(ma);
    if (pos == -1)
    {
        std::cout << "Khong tim thay giang vien de xoa." << std::endl;
        return false;
    }

    dsGiangVien.erase(dsGiangVien.begin() + pos);
    std::cout << "Xoa giang vien thanh cong." << std::endl;
    return true;
}

bool GiangVienManager::tonTaiMaGiangVien(const std::string &ma) const
{
    return timViTriTheoMa(ma) != -1;
}

void GiangVienManager::sapXepTheoTen()
{
    std::sort(dsGiangVien.begin(), dsGiangVien.end(), [](const Giangvien &a, const Giangvien &b)
              { return a.gethoten() < b.gethoten(); });
}

void GiangVienManager::sapXepTheoKhoa()
{
    std::sort(dsGiangVien.begin(), dsGiangVien.end(), [](const Giangvien &a, const Giangvien &b)
              { return a.getkhoa() < b.getkhoa(); });
}

bool GiangVienManager::docTuFileCsv(const std::string &filename)
{
    std::ifstream fin(filename);
    if (!fin.is_open())
    {
        std::cout << "Khong the mo file: " << filename << std::endl;
        return false;
    }

    dsGiangVien.clear();

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
            Giangvien gv = Giangvien::fromCsvRow(fields);

            if (!tonTaiMaGiangVien(gv.getmgv()))
            {
                dsGiangVien.push_back(gv);
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

bool GiangVienManager::ghiRaFileCsv(const std::string &filename) const
{
    std::ofstream fout(filename);
    if (!fout.is_open())
    {
        std::cout << "Khong the mo file de ghi: " << filename << std::endl;
        return false;
    }

    fout << Giangvien::csvHeader() << std::endl;

    for (const auto &gv : dsGiangVien)
    {
        fout << gv.toCsvRow() << std::endl;
    }

    fout.close();
    return true;
}
