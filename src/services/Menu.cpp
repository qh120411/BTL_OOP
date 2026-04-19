#include "../../include/services/Menu.h"
#include "../../include/managers/MonHocManager.h"
#include "../../include/managers/SinhVienManager.h"
#include "../../include/managers/GiangVienManager.h"
#include "../../include/services/DiemService.h"
#include "../../include/models/LopHocPhan.h"
#include "../../include/models/DangKyHoc.h"
#include "../../include/utils/InputHelper.h"

#include <algorithm>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const string FILE_TAI_KHOAN = "data/Taikhoan.csv";
const string FILE_SINH_VIEN = "data/Sinhvien.csv";
const string FILE_GIANG_VIEN = "data/Giangvien.csv";
const string FILE_MON_HOC = "data/MonHoc.csv";
const string FILE_DANG_KY = "data/DangKyHoc.csv";
const string FILE_LOP_HOC_PHAN = "data/LopHocPhan.csv";

struct TaiKhoanRecord
{
    string taiKhoan;
    string matKhau;
    string role;
    string maLienKet;
    string trangThai;
};

void menuQuanLyMonHoc();
void menuQuanLySinhVien();
void menuQuanLyGiangVien();
void menuQuanLyTaiKhoan();
void phanCongGiangVienDayMon();
void xemThoiKhoaBieuGiangVien(const string &maGV);
void xemDanhSachSinhVienTheoLopHocPhan(const string &maGV);
void suaDiemSinhVienTheoGiangVien(const string &maGV);
void xemLichHocSinhVien(const string &maSV);
void xemGiangVienDayMonSinhVien(const string &maSV);

vector<TaiKhoanRecord> docTaiKhoan()
{
    vector<TaiKhoanRecord> ds;
    ifstream fin(FILE_TAI_KHOAN);
    string line;

    while (getline(fin, line))
    {
        if (line.empty())
            continue;

        vector<string> fields = InputHelper::splitCsvLine(line);
        if (fields.empty() || fields[0] == "TaiKhoan")
            continue;
        if (fields.size() == 4)
            ds.push_back({fields[0], fields[1], fields[2], "", fields[3]});
        else if (fields.size() >= 5)
            ds.push_back({fields[0], fields[1], fields[2], fields[3], fields[4]});
    }

    return ds;
}

bool ghiTaiKhoan(const vector<TaiKhoanRecord> &ds)
{
    ofstream fout(FILE_TAI_KHOAN);
    if (!fout.is_open())
    {
        cout << "Khong the mo file tai khoan de ghi\n";
        return false;
    }

    for (const auto &tk : ds)
    {
        fout << tk.taiKhoan << "," << tk.matKhau << "," << tk.role << ","
             << tk.maLienKet << "," << tk.trangThai << "\n";
    }
    return true;
}

vector<LopHocPhan> docLopHocPhan()
{
    vector<LopHocPhan> ds;
    ifstream fin(FILE_LOP_HOC_PHAN);
    if (!fin.is_open())
        return ds;

    string line;
    bool boHeader = true;
    while (getline(fin, line))
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
            ds.push_back(LopHocPhan::fromCsvRow(InputHelper::splitCsvLine(line)));
        }
        catch (const exception &e)
        {
            cout << "Bo qua dong lop hoc phan loi: " << line << " - " << e.what() << "\n";
        }
    }
    return ds;
}

bool ghiLopHocPhan(const vector<LopHocPhan> &ds)
{
    ofstream fout(FILE_LOP_HOC_PHAN);
    if (!fout.is_open())
    {
        cout << "Khong the mo file lop hoc phan de ghi\n";
        return false;
    }

    fout << LopHocPhan::csvHeader() << "\n";
    for (const auto &lhp : ds)
        fout << lhp.toCsvRow() << "\n";
    return true;
}

vector<DangKyHoc> docDangKyHoc()
{
    vector<DangKyHoc> ds;
    ifstream fin(FILE_DANG_KY);
    if (!fin.is_open())
    {
        cout << "Khong the mo file DangKyHoc.csv\n";
        return ds;
    }

    string line;
    bool boHeader = true;
    while (getline(fin, line))
    {
        if (line.empty())
            continue;
        if (boHeader)
        {
            boHeader = false;
            continue;
        }

        vector<string> fields = InputHelper::splitCsvLine(line);
        if (fields.size() != 6)
            continue;

        DangKyHoc dk;
        dk.setMaDangKy(fields[0]);
        dk.setMaSV(fields[1]);
        dk.setMaLHP(fields[2]);
        dk.setNgayDangKy(fields[3]);
        dk.setTrangThai(fields[4]);
        dk.setDiem(stod(fields[5]));
        ds.push_back(dk);
    }
    return ds;
}

bool ghiDangKyHoc(const vector<DangKyHoc> &ds)
{
    ofstream fout(FILE_DANG_KY);
    if (!fout.is_open())
    {
        cout << "Khong the mo file DangKyHoc.csv de ghi\n";
        return false;
    }

    fout << "MaDangKy,MaSV,MaLHP,NgayDangKy,TrangThai,Diem\n";
    for (const auto &dk : ds)
    {
        fout << dk.getMaDangKy() << "," << dk.getMaSV() << "," << dk.getMaLHP() << ","
             << dk.getNgayDangKy() << "," << dk.getTrangThai() << "," << dk.getDiem() << "\n";
    }
    return true;
}

const LopHocPhan *timLopHocPhan(const vector<LopHocPhan> &ds, const string &maLHP)
{
    for (const auto &lhp : ds)
        if (lhp.getMaLHP() == maLHP)
            return &lhp;
    return nullptr;
}

string taoMaLopHocPhan(const vector<LopHocPhan> &ds)
{
    int maxId = 0;
    for (const auto &lhp : ds)
    {
        string ma = lhp.getMaLHP();
        if (ma.rfind("LHP", 0) == 0)
        {
            try
            {
                maxId = max(maxId, stoi(ma.substr(3)));
            }
            catch (...)
            {
            }
        }
    }

    stringstream ss;
    ss << "LHP";
    if (maxId + 1 < 10)
        ss << "00";
    else if (maxId + 1 < 100)
        ss << "0";
    ss << (maxId + 1);
    return ss.str();
}

string taoMaDangKy(const vector<DangKyHoc> &ds)
{
    int maxId = 0;
    for (const auto &dk : ds)
    {
        string ma = dk.getMaDangKy();
        if (ma.rfind("DK", 0) == 0)
        {
            try
            {
                maxId = max(maxId, stoi(ma.substr(2)));
            }
            catch (...)
            {
            }
        }
    }

    stringstream ss;
    ss << "DK";
    if (maxId + 1 < 10)
        ss << "00";
    else if (maxId + 1 < 100)
        ss << "0";
    ss << (maxId + 1);
    return ss.str();
}

bool giangVienDayLop(const vector<LopHocPhan> &dsLHP, const string &maGV, const string &maLHP)
{
    for (const auto &lhp : dsLHP)
        if (lhp.getMaGV() == maGV && lhp.getMaLHP() == maLHP)
            return true;
    return false;
}

void hienThiLopHocPhanCoTheDangKy()
{
    vector<LopHocPhan> ds = docLopHocPhan();
    cout << "\nDanh sach lop hoc phan dang mo:\n";
    bool found = false;
    for (const auto &lhp : ds)
    {
        if (lhp.getSiSoHienTai() < lhp.getSiSoToiDa())
        {
            lhp.xuat();
            found = true;
        }
    }
    if (!found)
        cout << "Hien khong co lop hoc phan con cho trong\n";
}

void menuAdmin()
{
    int chon;
    do
    {
        cout << "\n========== MENU ADMIN ==========\n";
        cout << "1. Quan ly sinh vien\n";
        cout << "2. Quan ly giang vien\n";
        cout << "3. Quan ly mon hoc\n";
        cout << "4. Quan ly tai khoan\n";
        cout << "5. Phan cong giang vien day mon\n";
        cout << "0. Dang xuat\n";
        cout << "Nhap lua chon: ";
        cin >> chon;
        cin.ignore();

        switch (chon)
        {
        case 1:
            menuQuanLySinhVien();
            break;
        case 2:
            menuQuanLyGiangVien();
            break;
        case 3:
            menuQuanLyMonHoc();
            break;
        case 4:
            menuQuanLyTaiKhoan();
            break;
        case 5:
            phanCongGiangVienDayMon();
            break;
        case 0:
            cout << "Thoat menu Admin\n";
            return;
        default:
            cout << "Lua chon khong hop le\n";
        }
    } while (chon != 0);
}

void menuGiangVien(const string &maGiangVienDangNhap)
{
    int chon;
    do
    {
        cout << "\n===== MENU GIANG VIEN =====\n";
        cout << "1. Xem thong tin ca nhan\n";
        cout << "2. Xem thoi khoa bieu\n";
        cout << "3. Xem danh sach sinh vien theo mon\n";
        cout << "4. Nhap / sua diem sinh vien\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> chon;
        cin.ignore();

        switch (chon)
        {
        case 1:
        {
            GiangVienManager gvm;
            gvm.docTuFileCsv(FILE_GIANG_VIEN);
            gvm.hienThiTheoMa(maGiangVienDangNhap);
            break;
        }
        case 2:
            xemThoiKhoaBieuGiangVien(maGiangVienDangNhap);
            break;
        case 3:
            xemDanhSachSinhVienTheoLopHocPhan(maGiangVienDangNhap);
            break;
        case 4:
            suaDiemSinhVienTheoGiangVien(maGiangVienDangNhap);
            break;
        case 0:
            cout << "Thoat menu\n";
            return;
        default:
            cout << "Lua chon khong hop le\n";
        }
    } while (chon != 0);
}

void menuSinhVien(const string &maSinhVienDangNhap)
{
    int chon;
    do
    {
        cout << "\n===== MENU SINH VIEN =====\n";
        cout << "1. Xem thong tin ca nhan\n";
        cout << "2. Xem diem cac mon\n";
        cout << "3. Dang ky mon hoc\n";
        cout << "4. Xem lich hoc\n";
        cout << "5. Xem giang vien day mon\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> chon;
        cin.ignore();

        switch (chon)
        {
        case 1:
        {
            SinhVienManager svm;
            svm.docTuFileCsv(FILE_SINH_VIEN);
            svm.hienThiTheoMa(maSinhVienDangNhap);
            break;
        }
        case 2:
        {
            DiemService ds;
            ds.docTuFileCsv(FILE_DANG_KY);
            ds.hienThiTheoMaSV(maSinhVienDangNhap);
            break;
        }
        case 3:
        {
            vector<DangKyHoc> dsDangKy = docDangKyHoc();
            vector<LopHocPhan> dsLHP = docLopHocPhan();

            hienThiLopHocPhanCoTheDangKy();

            DangKyHoc dk;
            dk.setMaDangKy(taoMaDangKy(dsDangKy));
            dk.setMaSV(maSinhVienDangNhap);
            dk.setMaLHP(InputHelper::inputLine("Nhap ma lop hoc phan: "));

            bool trungMa = false;
            bool trungLop = false;
            for (const auto &item : dsDangKy)
            {
                if (item.getMaDangKy() == dk.getMaDangKy())
                    trungMa = true;
                if (item.getMaSV() == dk.getMaSV() && item.getMaLHP() == dk.getMaLHP())
                    trungLop = true;
            }

            LopHocPhan *lhp = nullptr;
            for (auto &item : dsLHP)
            {
                if (item.getMaLHP() == dk.getMaLHP())
                    lhp = &item;
            }

            if (trungMa)
            {
                cout << "Ma dang ky da ton tai\n";
                break;
            }
            if (trungLop)
            {
                cout << "Sinh vien da dang ky lop hoc phan nay\n";
                break;
            }
            if (!lhp)
            {
                cout << "Lop hoc phan khong ton tai\n";
                break;
            }
            if (lhp->getSiSoHienTai() >= lhp->getSiSoToiDa())
            {
                cout << "Lop hoc phan da du si so\n";
                break;
            }

            dk.setNgayDangKy(InputHelper::inputDate("Nhap ngay dang ky: "));
            dk.setTrangThai("Dang ky");
            dk.setDiem(0.0);
            dsDangKy.push_back(dk);
            lhp->setSiSoHienTai(lhp->getSiSoHienTai() + 1);

            if (ghiDangKyHoc(dsDangKy) && ghiLopHocPhan(dsLHP))
                cout << "Dang ky thanh cong. Ma dang ky: " << dk.getMaDangKy() << "\n";
            break;
        }
        case 4:
            xemLichHocSinhVien(maSinhVienDangNhap);
            break;
        case 5:
            xemGiangVienDayMonSinhVien(maSinhVienDangNhap);
            break;
        case 0:
            cout << "Thoat menu\n";
            return;
        default:
            cout << "Lua chon khong hop le\n";
        }
    } while (chon != 0);
}

void menuQuanLyMonHoc()
{
    MonHocManager mhm;
    mhm.docTuFileCsv(FILE_MON_HOC);
    int chon;
    do
    {
        cout << "\n--- Quan ly Mon Hoc ---\n";
        cout << "1. Them mon hoc\n";
        cout << "2. Hien thi danh sach\n";
        cout << "3. Tim mon hoc\n";
        cout << "4. Sua mon hoc\n";
        cout << "5. Xoa mon hoc\n";
        cout << "0. Quay lai\n";
        cout << "Nhap lua chon: ";
        cin >> chon;
        cin.ignore();

        switch (chon)
        {
        case 1:
            mhm.themMonHoc();
            mhm.ghiRaFileCsv(FILE_MON_HOC);
            break;
        case 2:
            mhm.hienThiDanhSach();
            break;
        case 3:
            mhm.hienThiTheoMa(InputHelper::inputLine("Nhap ma mon: "));
            break;
        case 4:
            if (mhm.suaMonHoc(InputHelper::inputLine("Nhap ma mon can sua: ")))
                mhm.ghiRaFileCsv(FILE_MON_HOC);
            else
                cout << "Khong tim thay mon hoc\n";
            break;
        case 5:
            if (mhm.xoaMonHoc(InputHelper::inputLine("Nhap ma mon can xoa: ")))
                mhm.ghiRaFileCsv(FILE_MON_HOC);
            else
                cout << "Khong tim thay mon hoc\n";
            break;
        case 0:
            return;
        default:
            cout << "Lua chon khong hop le\n";
        }
    } while (chon != 0);
}

void menuQuanLySinhVien()
{
    SinhVienManager svm;
    svm.docTuFileCsv(FILE_SINH_VIEN);
    int chon;
    do
    {
        cout << "\n--- Quan ly Sinh Vien ---\n";
        cout << "1. Them sinh vien\n";
        cout << "2. Hien thi danh sach\n";
        cout << "3. Tim sinh vien\n";
        cout << "4. Sua sinh vien\n";
        cout << "5. Xoa sinh vien\n";
        cout << "0. Quay lai\n";
        cout << "Nhap lua chon: ";
        cin >> chon;
        cin.ignore();

        switch (chon)
        {
        case 1:
            svm.themSinhVien();
            svm.ghiRaFileCsv(FILE_SINH_VIEN);
            break;
        case 2:
            svm.hienThiDanhSach();
            break;
        case 3:
            svm.hienThiTheoMa(InputHelper::inputLine("Nhap ma sinh vien: "));
            break;
        case 4:
            if (svm.suaSinhVien(InputHelper::inputLine("Nhap ma sinh vien can sua: ")))
                svm.ghiRaFileCsv(FILE_SINH_VIEN);
            break;
        case 5:
            if (svm.xoaSinhVien(InputHelper::inputLine("Nhap ma sinh vien can xoa: ")))
                svm.ghiRaFileCsv(FILE_SINH_VIEN);
            break;
        case 0:
            return;
        default:
            cout << "Lua chon khong hop le\n";
        }
    } while (chon != 0);
}

void menuQuanLyGiangVien()
{
    GiangVienManager gvm;
    gvm.docTuFileCsv(FILE_GIANG_VIEN);
    int chon;
    do
    {
        cout << "\n--- Quan ly Giang Vien ---\n";
        cout << "1. Them giang vien\n";
        cout << "2. Hien thi danh sach\n";
        cout << "3. Tim giang vien\n";
        cout << "4. Sua giang vien\n";
        cout << "5. Xoa giang vien\n";
        cout << "0. Quay lai\n";
        cout << "Nhap lua chon: ";
        cin >> chon;
        cin.ignore();

        switch (chon)
        {
        case 1:
            gvm.themGiangVien();
            gvm.ghiRaFileCsv(FILE_GIANG_VIEN);
            break;
        case 2:
            gvm.hienThiDanhSach();
            break;
        case 3:
            gvm.hienThiTheoMa(InputHelper::inputLine("Nhap ma giang vien: "));
            break;
        case 4:
            if (gvm.suaGiangVien(InputHelper::inputLine("Nhap ma giang vien can sua: ")))
                gvm.ghiRaFileCsv(FILE_GIANG_VIEN);
            break;
        case 5:
            if (gvm.xoaGiangVien(InputHelper::inputLine("Nhap ma giang vien can xoa: ")))
                gvm.ghiRaFileCsv(FILE_GIANG_VIEN);
            break;
        case 0:
            return;
        default:
            cout << "Lua chon khong hop le\n";
        }
    } while (chon != 0);
}

void menuQuanLyTaiKhoan()
{
    int chon;
    do
    {
        vector<TaiKhoanRecord> ds = docTaiKhoan();
        cout << "\n--- Quan ly Tai Khoan ---\n";
        cout << "1. Hien thi danh sach\n";
        cout << "2. Them tai khoan\n";
        cout << "3. Sua tai khoan\n";
        cout << "4. Xoa tai khoan\n";
        cout << "5. Khoa / mo khoa tai khoan\n";
        cout << "0. Quay lai\n";
        cout << "Nhap lua chon: ";
        cin >> chon;
        cin.ignore();

        switch (chon)
        {
        case 1:
            for (const auto &tk : ds)
            {
                cout << "Tai khoan: " << tk.taiKhoan << " | Role: " << tk.role
                     << " | Ma lien ket: " << tk.maLienKet
                     << " | Trang thai: " << tk.trangThai << "\n";
            }
            if (ds.empty())
                cout << "Danh sach tai khoan rong\n";
            break;
        case 2:
        {
            TaiKhoanRecord tk;
            tk.taiKhoan = InputHelper::inputLine("Nhap tai khoan: ");
            tk.matKhau = InputHelper::inputLine("Nhap mat khau: ");
            tk.role = InputHelper::inputLine("Nhap role (admin/gv/sv): ");
            tk.maLienKet = InputHelper::inputLine("Nhap ma lien ket (bo trong neu admin): ");
            tk.trangThai = InputHelper::inputLine("Nhap trang thai (open/locked): ");

            bool tonTai = false;
            for (const auto &item : ds)
                if (item.taiKhoan == tk.taiKhoan)
                    tonTai = true;

            if (tonTai)
                cout << "Tai khoan da ton tai\n";
            else
            {
                ds.push_back(tk);
                ghiTaiKhoan(ds);
                cout << "Them tai khoan thanh cong\n";
            }
            break;
        }
        case 3:
        {
            string ten = InputHelper::inputLine("Nhap tai khoan can sua: ");
            bool found = false;
            for (auto &tk : ds)
            {
                if (tk.taiKhoan == ten)
                {
                    tk.matKhau = InputHelper::inputLine("Nhap mat khau moi: ");
                    tk.role = InputHelper::inputLine("Nhap role moi (admin/gv/sv): ");
                    tk.maLienKet = InputHelper::inputLine("Nhap ma lien ket moi: ");
                    tk.trangThai = InputHelper::inputLine("Nhap trang thai moi (open/locked): ");
                    found = true;
                    break;
                }
            }
            if (found)
            {
                ghiTaiKhoan(ds);
                cout << "Sua tai khoan thanh cong\n";
            }
            else
                cout << "Khong tim thay tai khoan\n";
            break;
        }
        case 4:
        {
            string ten = InputHelper::inputLine("Nhap tai khoan can xoa: ");
            size_t before = ds.size();
            ds.erase(remove_if(ds.begin(), ds.end(), [&](const TaiKhoanRecord &tk)
                               { return tk.taiKhoan == ten; }),
                     ds.end());
            if (ds.size() != before)
            {
                ghiTaiKhoan(ds);
                cout << "Xoa tai khoan thanh cong\n";
            }
            else
                cout << "Khong tim thay tai khoan\n";
            break;
        }
        case 5:
        {
            string ten = InputHelper::inputLine("Nhap tai khoan can khoa/mo khoa: ");
            bool found = false;
            for (auto &tk : ds)
            {
                if (tk.taiKhoan == ten)
                {
                    tk.trangThai = (tk.trangThai == "locked") ? "open" : "locked";
                    found = true;
                    cout << "Trang thai moi: " << tk.trangThai << "\n";
                    break;
                }
            }
            if (found)
                ghiTaiKhoan(ds);
            else
                cout << "Khong tim thay tai khoan\n";
            break;
        }
        case 0:
            return;
        default:
            cout << "Lua chon khong hop le\n";
        }
    } while (chon != 0);
}

void phanCongGiangVienDayMon()
{
    MonHocManager mhm;
    GiangVienManager gvm;
    mhm.docTuFileCsv(FILE_MON_HOC);
    gvm.docTuFileCsv(FILE_GIANG_VIEN);

    string maMon = InputHelper::inputLine("Nhap ma mon: ");
    if (!mhm.tonTaiMaMon(maMon))
    {
        cout << "Ma mon khong ton tai\n";
        return;
    }

    string maGV = InputHelper::inputLine("Nhap ma giang vien: ");
    if (!gvm.tonTaiMaGiangVien(maGV))
    {
        cout << "Ma giang vien khong ton tai\n";
        return;
    }

    string hocKy = InputHelper::inputLine("Nhap hoc ky: ");
    string namHoc = InputHelper::inputLine("Nhap nam hoc: ");
    string phongHoc = InputHelper::inputLine("Nhap phong hoc: ");
    string lichHoc = InputHelper::inputLine("Nhap lich hoc: ");
    int siSoToiDa = InputHelper::inputInt("Nhap si so toi da: ", 1, 300);

    vector<LopHocPhan> ds = docLopHocPhan();
    string maLHP = taoMaLopHocPhan(ds);
    ds.push_back(LopHocPhan(maLHP, maMon, maGV, hocKy, namHoc, phongHoc, lichHoc, siSoToiDa, 0));
    if (ghiLopHocPhan(ds))
        cout << "Da phan cong giang vien " << maGV << " day mon " << maMon << " voi ma LHP: " << maLHP << endl;
}

void xemThoiKhoaBieuGiangVien(const string &maGV)
{
    vector<LopHocPhan> ds = docLopHocPhan();
    bool found = false;

    for (const auto &lhp : ds)
    {
        if (lhp.getMaGV() == maGV)
        {
            lhp.xuat();
            found = true;
        }
    }

    if (!found)
        cout << "Khong co lich day cho giang vien nay\n";
}

void xemDanhSachSinhVienTheoLopHocPhan(const string &maGV)
{
    string maLHP = InputHelper::inputLine("Nhap ma lop hoc phan: ");
    vector<LopHocPhan> dsLHP = docLopHocPhan();
    if (!giangVienDayLop(dsLHP, maGV, maLHP))
    {
        cout << "Ban khong phu trach lop hoc phan nay\n";
        return;
    }

    vector<DangKyHoc> dsDangKy = docDangKyHoc();
    SinhVienManager svm;
    svm.docTuFileCsv(FILE_SINH_VIEN);
    bool found = false;

    cout << left
         << setw(10) << "Ma DK"
         << setw(12) << "MSV"
         << setw(26) << "Ho ten"
         << "Diem" << endl;
    cout << string(58, '-') << endl;

    for (const auto &dk : dsDangKy)
    {
        if (dk.getMaLHP() == maLHP)
        {
            const Sinhvien *sv = svm.timSinhVienTheoMa(dk.getMaSV());
            cout << left
                 << setw(10) << dk.getMaDangKy()
                 << setw(12) << dk.getMaSV()
                 << setw(26) << (sv ? sv->gethoten() : "Khong tim thay")
                 << fixed << setprecision(1) << dk.getDiem() << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Chua co sinh vien dang ky lop hoc phan nay\n";
}

void suaDiemSinhVienTheoGiangVien(const string &maGV)
{
    vector<DangKyHoc> dsDangKy = docDangKyHoc();
    vector<LopHocPhan> dsLHP = docLopHocPhan();

    string maDK = InputHelper::inputLine("Nhap ma dang ky: ");
    bool found = false;
    for (auto &dk : dsDangKy)
    {
        if (dk.getMaDangKy() == maDK)
        {
            found = true;
            if (!giangVienDayLop(dsLHP, maGV, dk.getMaLHP()))
            {
                cout << "Ban khong co quyen sua diem dang ky nay\n";
                return;
            }

            double diem = InputHelper::inputDouble("Nhap diem moi: ", 0.0, 10.0);
            dk.setDiem(diem);
            if (ghiDangKyHoc(dsDangKy))
                cout << "Cap nhat diem thanh cong\n";
            return;
        }
    }

    if (!found)
        cout << "Khong tim thay ma dang ky\n";
}

void xemLichHocSinhVien(const string &maSV)
{
    vector<DangKyHoc> dsDangKy = docDangKyHoc();
    vector<LopHocPhan> dsLHP = docLopHocPhan();
    bool found = false;

    for (const auto &dk : dsDangKy)
    {
        if (dk.getMaSV() == maSV)
        {
            const LopHocPhan *lhp = timLopHocPhan(dsLHP, dk.getMaLHP());
            if (lhp)
            {
                lhp->xuat();
                found = true;
            }
        }
    }

    if (!found)
        cout << "Khong co lich hoc cho sinh vien nay\n";
}

void xemGiangVienDayMonSinhVien(const string &maSV)
{
    vector<DangKyHoc> dsDangKy = docDangKyHoc();
    vector<LopHocPhan> dsLHP = docLopHocPhan();
    GiangVienManager gvm;
    gvm.docTuFileCsv(FILE_GIANG_VIEN);
    bool found = false;

    for (const auto &dk : dsDangKy)
    {
        if (dk.getMaSV() == maSV)
        {
            const LopHocPhan *lhp = timLopHocPhan(dsLHP, dk.getMaLHP());
            if (lhp)
            {
                cout << "Lop hoc phan: " << lhp->getMaLHP() << " | Mon: " << lhp->getMaMon() << "\n";
                gvm.hienThiTheoMa(lhp->getMaGV());
                found = true;
            }
        }
    }

    if (!found)
        cout << "Khong tim thay giang vien day mon cho sinh vien nay\n";
}
