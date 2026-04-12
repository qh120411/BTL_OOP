#include "../include/managers/MonHocManager.h"
#include "../include/utils/InputHelper.h"

#include <iostream>
#include <algorithm>

void MonHocManager::themMonHoc() {
    MonHoc mh;
    mh.nhap();

    if (tonTaiMaMon(mh.getMaMonHoc())) {
        std::cout << "Ma mon hoc da ton tai. Khong the them." << std::endl;
        return;
    }

    dsMonHoc.push_back(mh);
    std::cout << "Them mon hoc thanh cong." << std::endl;
}

bool MonHocManager::themMonHoc(const MonHoc& mh) {
    if (tonTaiMaMon(mh.getMaMonHoc())) {
        return false;
    }

    dsMonHoc.push_back(mh);
    return true;
}

void MonHocManager::hienThiDanhSach() const {
    if (dsMonHoc.empty()) {
        std::cout << "Danh sach mon hoc rong." << std::endl;
        return;
    }

    for (const auto& mh : dsMonHoc) {
        mh.xuat();
    }
}

void MonHocManager::hienThiTheoMa(const std::string& maMon) const {
    const MonHoc* mh = timMonHocTheoMa(maMon);
    if (mh == nullptr) {
        std::cout << "Khong tim thay mon hoc." << std::endl;
        return;
    }

    mh->xuat();
}

int MonHocManager::timViTriTheoMa(const std::string& maMon) const {
    for (int i = 0; i < static_cast<int>(dsMonHoc.size()); ++i) {
        if (dsMonHoc[i].getMaMonHoc() == maMon) {
            return i;
        }
    }
    return -1;
}

MonHoc* MonHocManager::timMonHocTheoMa(const std::string& maMon) {
    for (auto& mh : dsMonHoc) {
        if (mh.getMaMonHoc() == maMon) {
            return &mh;
        }
    }
    return nullptr;
}

const MonHoc* MonHocManager::timMonHocTheoMa(const std::string& maMon) const {
    for (const auto& mh : dsMonHoc) {
        if (mh.getMaMonHoc() == maMon) {
            return &mh;
        }
    }
    return nullptr;
}

bool MonHocManager::suaMonHoc(const std::string& maMon) {
    MonHoc* mh = timMonHocTheoMa(maMon);
    if (mh == nullptr) {
        return false;
    }

    std::string tenMoi;
    int soTinChiMoi, soTietMoi;

    tenMoi = InputHelper::inputLine("Nhap ten mon moi: ");

    soTinChiMoi = InputHelper::inputInt("Nhap so tin chi moi: ", 1, 10);
    soTietMoi = InputHelper::inputInt("Nhap so tiet moi: ", 1, 50);

    mh->setTenMonHoc(tenMoi);
    mh->setSoTinChi(soTinChiMoi);
    mh->setSoTiet(soTietMoi);

    return true;
}

bool MonHocManager::xoaMonHoc(const std::string& maMon) {
    int viTri = timViTriTheoMa(maMon);
    if (viTri == -1) {
        return false;
    }

    dsMonHoc.erase(dsMonHoc.begin() + viTri);
    return true;
}

bool MonHocManager::tonTaiMaMon(const std::string& maMon) const {
    return timMonHocTheoMa(maMon) != nullptr;
}

void MonHocManager::sapXepTheoTen() {
    std::sort(dsMonHoc.begin(), dsMonHoc.end(), [](const MonHoc& a, const MonHoc& b) {
            return a.getTenMonHoc() < b.getTenMonHoc();
        });
}

void MonHocManager::sapXepTheoSoTinChiTangDan() {
    std::sort(dsMonHoc.begin(), dsMonHoc.end(), [](const MonHoc& a, const MonHoc& b) {
            return a.getSoTinChi() < b.getSoTinChi();
        });
}

// bool MonHocManager::docTuFileCsv(const std::string& tenFile) {
//     std::ifstream fin(tenFile);
//     if (!fin.is_open()) {
//         std::cout << "Khong mo duoc file: " << tenFile << "\n";
//         return false;
//     }

//     dsMonHoc.clear();

//     std::string line;
//     bool boHeader = true;

//     while (std::getline(fin, line)) {
//         if (line.empty()) {
//             continue;
//         }

//         if (boHeader) {
//             boHeader = false;
//             continue;
//         }

//         try {
//             std::vector<std::string> fields = CsvService::splitCsvLine(line);
//             MonHoc mh = MonHoc::fromCsvRow(fields);

//             if (!tonTaiMaMon(mh.getMaMon())) {
//                 dsMonHoc.push_back(mh);
//             }
//         } catch (const std::exception& e) {
//             std::cout << "Bo qua dong loi: " << line << "\n";
//             std::cout << "Ly do: " << e.what() << "\n";
//         }
//     }

//     fin.close();
//     return true;
// }

// bool MonHocManager::ghiRaFileCsv(const std::string& tenFile) const {
//     std::ofstream fout(tenFile);
//     if (!fout.is_open()) {
//         std::cout << "Khong mo duoc file de ghi: " << tenFile << "\n";
//         return false;
//     }

//     fout << MonHoc::csvHeader() << "\n";
//     for (const auto& mh : dsMonHoc) {
//         fout << mh.toCsvRow() << "\n";
//     }

//     fout.close();
//     return true;
// }