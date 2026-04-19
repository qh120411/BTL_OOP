#include <../include/models/Sinhvien.h>
#include <../include/utils/InputHelper.h>
#include <bits/stdc++.h>

using namespace std;

static string tinhTrangToString(Tinhtrang tinhtrang)
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

Sinhvien::Sinhvien(string ten, string gt, string nsinh,
                   string que, string sdt, string mail,
                   string dch, string cccd,
                   string masv, string cnganh, string Khoadt,
                   string lophc, int nkhoa, Tinhtrang tinhtrangg)
    : Nguoi(ten, gt, nsinh, que, sdt, mail, dch, cccd),
      msv(masv), nganh(cnganh), Khoa(Khoadt), lop(lophc), khoahoc(nkhoa), tinhtrang(tinhtrangg) {}

Sinhvien::~Sinhvien() {}

void Sinhvien::luufile(ostream &ou)
{
    Nguoi::luufile(ou);
    ou << msv << "," << nganh << "," << Khoa << "," << lop << "," << khoahoc << "," << tinhTrangToString(tinhtrang) << endl;
}

void Sinhvien::docfile(istream &is)
{
    Nguoi::docfile(is);
    getline(is, msv, ',');
    getline(is, nganh, ',');
    getline(is, Khoa, ',');
    getline(is, lop, ',');
    string tmp;
    getline(is, tmp, ',');
    khoahoc = stoi(tmp);
    getline(is, tmp, ',');
    if (tmp == "DANG_HOC")
        tinhtrang = DANG_HOC;
    else if (tmp == "BAO_LUU")
        tinhtrang = BAO_LUU;
    else if (tmp == "TOT_NGHIEP")
        tinhtrang = TOT_NGHIEP;
    else if (tmp == "THOI_HOC")
        tinhtrang = THOI_HOC;
}

void Sinhvien::nhap()
{
    Nguoi::nhap();
    this->msv = InputHelper::inputLine("Nhap vao ma sinh vien: ");
    this->nganh = InputHelper::inputLine("Nhap vao nganh: ");
    this->Khoa = InputHelper::inputLine("Nhap vao khoa: ");
    this->lop = InputHelper::inputLine("Nhap vao lop cua sinh vien: ");
    this->khoahoc = InputHelper::inputInt("Nhap vao khoa hoc cua sinh vien: ", 1, 66);
    cout << "Chon tinh trang sinh vien:\n";
    cout << "1. Dang hoc\n";
    cout << "2. Bao luu\n";
    cout << "3. Tot nghiep\n";
    cout << "4. Thoi hoc\n";

    int luaChon = InputHelper::inputInt("Nhap lua chon: ", 1, 4);

    switch (luaChon)
    {
    case 1:
        this->tinhtrang = DANG_HOC;
        break;
    case 2:
        this->tinhtrang = BAO_LUU;
        break;
    case 3:
        this->tinhtrang = TOT_NGHIEP;
        break;
    case 4:
        this->tinhtrang = THOI_HOC;
        break;
    }
}

void Sinhvien::xuat() const
{
    Nguoi::xuat();
    cout << "Ma sinh vien: " << msv << "\n";
    cout << "Nganh: " << nganh << "\n";
    cout << "Khoa: " << Khoa << "\n";
    cout << "Lop: " << lop << "\n";
    cout << "Khoa hoc: " << khoahoc << "\n";
    cout << "Tinh trang: " << tinhTrangToString(tinhtrang) << "\n";
    cout << "----------------------------------------\n";
}

void Sinhvien::hienthithongtin()
{
    xuat();
}

void Sinhvien::setmsv(const string &masv)
{
    msv = masv;
}
string Sinhvien::getmsv() const
{
    return msv;
}

void Sinhvien::setnganh(const string &cnganh)
{
    nganh = cnganh;
}
string Sinhvien::getnganh() const
{
    return nganh;
}

void Sinhvien::setKhoa(const string &Khoadt)
{
    Khoa = Khoadt;
}
string Sinhvien::getKhoa() const
{
    return Khoa;
}

void Sinhvien::setlop(const string &lophc)
{
    lop = lophc;
}
string Sinhvien::getlop() const
{
    return lop;
}

void Sinhvien::setkhoahoc(const int &nkhoa)
{
    khoahoc = nkhoa;
}
int Sinhvien::getkhoahoc() const
{
    return khoahoc;
}

void Sinhvien::settinhtrang(Tinhtrang tinhtrangg)
{
    tinhtrang = tinhtrangg;
}
Tinhtrang Sinhvien::gettinhtrang() const
{
    return tinhtrang;
}

std::string Sinhvien::csvHeader()
{
    return "HoTen,GioiTinh,NamSinh,QueQuan,SoDienThoai,Email,DiaChi,SoCCCD,MSV,Nganh,Khoa,Lop,KhoaHoc,TinhTrang";
}

std::string Sinhvien::toCsvRow() const
{
    std::stringstream ss;
    ss << gethoten() << "," << getgioitinh() << "," << getnamsinh() << "," << getquequan() << ","
       << getsodienthoai() << "," << getemail() << "," << getdiachi() << "," << getsocccd() << ","
       << msv << "," << nganh << "," << Khoa << "," << lop << "," << khoahoc << "," << tinhTrangToString(tinhtrang);
    return ss.str();
}

Sinhvien Sinhvien::fromCsvRow(const std::vector<std::string> &fields)
{
    if (fields.size() != 14)
    {
        throw std::invalid_argument("Invalid CSV row for Sinhvien");
    }
    Tinhtrang tt;
    if (fields[13] == "DANG_HOC" || fields[13] == "0") tt = DANG_HOC;
    else if (fields[13] == "BAO_LUU" || fields[13] == "1") tt = BAO_LUU;
    else if (fields[13] == "TOT_NGHIEP" || fields[13] == "2") tt = TOT_NGHIEP;
    else if (fields[13] == "THOI_HOC" || fields[13] == "3") tt = THOI_HOC;
    else throw std::invalid_argument("Invalid Tinhtrang value");
    return Sinhvien(fields[0], fields[1], fields[2], fields[3], fields[4], fields[5], fields[6], fields[7],
                    fields[8], fields[9], fields[10], fields[11], std::stoi(fields[12]), tt);
}
