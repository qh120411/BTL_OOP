#include <../include/models/Giangvien.h>
#include <bits/stdc++.h>
#include <../include/utils/InputHelper.h>

using namespace std;

static string tinhTrangGVToString(tinhtrangGV tinhtrang)
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

Giangvien::Giangvien(string ten, string gt, string nsinh,
                     string que, string sdt, string mail,
                     string dch, string cccd, string magv,
                     string gvbomon, string khoadaot, string hcvi,
                     string chuc, string chuyenngh, tinhtrangGV tinhtranggv)
    : Nguoi(ten, gt, nsinh, que, sdt, mail, dch, cccd),
      mgv(magv), bomon(gvbomon), khoa(khoadaot), hocvi(hcvi), chucvu(chuc), chuyennganh(chuyenngh), tinhtrang(tinhtranggv) {}

Giangvien::~Giangvien() {}

void Giangvien::luufile(ostream &ou)
{
    Nguoi::luufile(ou);
    ou << mgv << "," << bomon << "," << khoa << "," << hocvi << "," << chucvu << "," << chuyennganh << ","
       << tinhTrangGVToString(tinhtrang) << endl;
}

void Giangvien::docfile(istream &is)
{
    Nguoi::docfile(is);
    getline(is, mgv, ',');
    getline(is, bomon, ',');
    getline(is, khoa, ',');
    getline(is, hocvi, ',');
    getline(is, chucvu, ',');
    getline(is, chuyennganh, ',');
    string tmp;
    getline(is, tmp, ',');
    if (tmp == "DANG_GIANG_DAY")
        tinhtrang = DANG_GIANG_DAY;
    else if (tmp == "TAM_NGHI")
        tinhtrang = TAM_NGHI;
    else if (tmp == "NGHI_THAI_SAN")
        tinhtrang = NGHI_THAI_SAN;
    else if (tmp == "NGHI_HUU")
        tinhtrang = NGHI_HUU;
    else if (tmp == "THOI_VIEC")
        tinhtrang = THOI_VIEC;
}

void Giangvien::nhap()
{
    Nguoi::nhap();
    this->mgv = InputHelper::inputLine("Nhap vao ma giang vien: ");
    this->bomon = InputHelper::inputLine("Nhap vao bo mon: ");
    this->khoa = InputHelper::inputLine("Nhap vao khoa: ");
    this->hocvi = InputHelper::inputLine("Nhap vao hoc vi cua giang vien: ");
    this->chucvu = InputHelper::inputLine("Nhap vao chuc vu cua giang vien: ");
    this->chuyennganh = InputHelper::inputLine("Nhap vao chuyen nganh cua giang vien: ");
    cout << "Chon tinh trang giang vien:\n";
    cout << "1. Dang giang day\n";
    cout << "2. Tam nghi\n";
    cout << "3. Nghi thai san\n";
    cout << "4. Da nghi huu\n";
    cout << "5. Da thoi viec\n";

    int luaChon = InputHelper::inputInt("Nhap lua chon: ", 1, 5);

    switch (luaChon)
    {
    case 1:
        this->tinhtrang = DANG_GIANG_DAY;
        break;
    case 2:
        this->tinhtrang = TAM_NGHI;
        break;
    case 3:
        this->tinhtrang = NGHI_THAI_SAN;
        break;
    case 4:
        this->tinhtrang = NGHI_HUU;
        break;
    case 5:
        this->tinhtrang = THOI_VIEC;
        break;
    }
}

void Giangvien::xuat() const
{
    Nguoi::xuat();
    cout << "Ma giang vien: " << mgv << "\n";
    cout << "Bo mon: " << bomon << "\n";
    cout << "Khoa: " << khoa << "\n";
    cout << "Hoc vi: " << hocvi << "\n";
    cout << "Chuc vu: " << chucvu << "\n";
    cout << "Chuyen nganh: " << chuyennganh << "\n";
    cout << "Tinh trang: " << tinhTrangGVToString(tinhtrang) << "\n";
    cout << "----------------------------------------\n";
}

void Giangvien::hienthithongtin()
{
    xuat();
}

void Giangvien::setmgv(const string &magv)
{
    mgv = magv;
}
string Giangvien::getmgv() const
{
    return mgv;
}

void Giangvien::setbomon(const string &gvbomon)
{
    bomon = gvbomon;
}
string Giangvien::getbomon() const
{
    return bomon;
}

void Giangvien::setkhoa(const string &khoadaot)
{
    khoa = khoadaot;
}
string Giangvien::getkhoa() const
{
    return khoa;
}

void Giangvien::sethocvi(const string &hcvi)
{
    hocvi = hcvi;
}
string Giangvien::gethocvi() const
{
    return hocvi;
}

void Giangvien::setchucvu(const string &chuc)
{
    chucvu = chuc;
}
string Giangvien::getchucvu() const
{
    return chucvu;
}

std::string Giangvien::csvHeader()
{
    return "HoTen,GioiTinh,NamSinh,QueQuan,SoDienThoai,Email,DiaChi,SoCCCD,MGV,BoMon,Khoa,HocVi,ChucVu,ChuyenNganh,TinhTrang";
}

std::string Giangvien::toCsvRow() const
{
    std::stringstream ss;
    ss << gethoten() << "," << getgioitinh() << "," << getnamsinh() << "," << getquequan() << ","
       << getsodienthoai() << "," << getemail() << "," << getdiachi() << "," << getsocccd() << ","
       << mgv << "," << bomon << "," << khoa << "," << hocvi << "," << chucvu << "," << chuyennganh << "," << tinhTrangGVToString(tinhtrang);
    return ss.str();
}

Giangvien Giangvien::fromCsvRow(const std::vector<std::string> &fields)
{
    if (fields.size() != 15)
    {
        throw std::invalid_argument("Invalid CSV row for Giangvien");
    }
    tinhtrangGV tt;
    if (fields[14] == "DANG_GIANG_DAY" || fields[14] == "0") tt = DANG_GIANG_DAY;
    else if (fields[14] == "TAM_NGHI" || fields[14] == "1") tt = TAM_NGHI;
    else if (fields[14] == "NGHI_THAI_SAN" || fields[14] == "2") tt = NGHI_THAI_SAN;
    else if (fields[14] == "NGHI_HUU" || fields[14] == "3") tt = NGHI_HUU;
    else if (fields[14] == "THOI_VIEC" || fields[14] == "4") tt = THOI_VIEC;
    else throw std::invalid_argument("Invalid tinhtrangGV value");
    return Giangvien(fields[0], fields[1], fields[2], fields[3], fields[4], fields[5], fields[6], fields[7],
                     fields[8], fields[9], fields[10], fields[11], fields[12], fields[13], tt);
}

void Giangvien::setchuyennganh(const string &chuyenngh)
{
    chuyennganh = chuyenngh;
}
string Giangvien::getchuyennganh() const
{
    return chuyennganh;
}

void Giangvien::settinhtranggv(tinhtrangGV tinhtranggv)
{
    tinhtrang = tinhtranggv;
}
tinhtrangGV Giangvien::gettinhtranggv() const
{
    return tinhtrang;
}
