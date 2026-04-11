#include<../include/models/Sinhvien.h>
#include<bits/stdc++.h>

using namespace std;

Sinhvien::Sinhvien(string ten, string gt, string nsinh,
                   string que, string sdt, string mail,
                   string dch, string cccd,
                   string masv, string cnganh, string Khoadt,
                   string lophc, int nkhoa, Tinhtrang tinhtrangg)
    : Nguoi(hoten, gioitinh, namsinh, quequan, sodienthoai, email, diachi, socccd),
      msv(masv), nganh(cnganh), Khoa(Khoadt), lop(lophc), khoahoc(nkhoa), tinhtrang(tinhtrangg) {}

Sinhvien::~Sinhvien(){}

void Sinhvien::luufile(ostream &ou) {
    Nguoi::luufile(ou);
    ou << msv << "," << nganh << "," << Khoa << "," << lop << "," << khoahoc << "," << tinhtrang <<endl;
}

void Sinhvien::docfile(istream &is) {
    Nguoi::docfile(is);
    getline(is,msv,',');
    getline(is,nganh, ',');
    getline(is,Khoa, ',');
    getline(is,lop, ',');
    string tmp;
    getline(is, tmp, ',');
    khoahoc = stoi(tmp);
    getline(is, tmp, ',');
    if (tmp == "DANG_HOC") tinhtrang = DANG_HOC;
    else if (tmp == "BAO_LUU") tinhtrang = BAO_LUU;
    else if (tmp == "TOT_NGHIEP") tinhtrang = TOT_NGHIEP;
    else if (tmp == "THOI_HOC") tinhtrang = THOI_HOC;

}

void Sinhvien::setmsv(const string &masv) {
    msv = masv;
} 
string Sinhvien::getmsv() const {
    return msv;
}

void Sinhvien::setnganh(const string &cnganh) {
    nganh = cnganh;
} 
string Sinhvien::getnganh() const {
    return nganh;
}

void Sinhvien::setKhoa(const string &Khoadt) {
    Khoa = Khoadt;
} 
string Sinhvien::getKhoa() const {
    return Khoa;
}

void Sinhvien::setlop(const string &lophc) {
    lop = lophc;
} 
string Sinhvien::getlop() const {
    return lop;
}

void Sinhvien::setkhoahoc(const int &nkhoa) {
    khoahoc = nkhoa;
} 
int Sinhvien::getkhoahoc() const {
    return khoahoc;
}

void Sinhvien::settinhtrang(Tinhtrang tinhtrangg) {
    tinhtrang = tinhtrangg;
} 
Tinhtrang Sinhvien::gettinhtrang() const {
    return tinhtrang;
}





