#include<../include/models/Giangvien.h>
#include<bits/stdc++.h>

using namespace std;

Giangvien::Giangvien(string ten, string gt, string nsinh,
                   string que, string sdt, string mail,
                   string dch, string cccd, string magv,
                   string gvbomon, string khoadaot, string hcvi,
                   string chuc, string chuyenngh, tinhtrangGV tinhtranggv )
            : Nguoi(hoten, gioitinh, namsinh, quequan, sodienthoai, email, diachi, socccd),
              mgv(magv), bomon(gvbomon), khoa(khoadaot), hocvi(hcvi), chucvu(chuc), chuyennganh(chuyenngh), tinhtrang(tinhtranggv) {}

Giangvien::~Giangvien(){}

void Giangvien::luufile(ostream &ou) {
    Nguoi::luufile(ou);
    ou << mgv << "," << bomon << "," << khoa << "," << hocvi << "," << chucvu << "," << chuyennganh << "," 
       << tinhtrang << endl;
}

void Giangvien::docfile(istream &is) {
    Nguoi::docfile(is);
    getline(is,mgv,',');
    getline(is,bomon,',');
    getline(is,khoa, ',');
    getline(is,hocvi, ',');
    getline(is,chucvu,',');
    getline(is,chuyennganh,',');
    string tmp;
    getline(is,tmp,',');
    if (tmp == "DANG_CONG_TAC") tinhtrang = DANG_CONG_TAC;
    else if ( tmp == "TAM_NGHI") tinhtrang = TAM_NGHI;
    else if (tmp == "NGHI_THAI_SAN") tinhtrang = NGHI_THAI_SAN;
    else if ( tmp == "NGHI_HUU") tinhtrang = NGHI_HUU;
    else if (tmp == "THOI_VIEC") tinhtrang = THOI_VIEC;
}

void Giangvien::setmgv(const string &magv) {
    mgv = magv;
}
string Giangvien::getmgv() const {
    return mgv;
}

void Giangvien::setbomon(const string &gvbomon) {
    bomon = gvbomon;
}
string Giangvien::getmgv() const {
    return bomon;
}

void Giangvien::setkhoa(const string &khoadaot) {
    khoa = khoadaot;
}
string Giangvien::getkhoa() const {
    return khoa;
}

void Giangvien::sethocvi(const string &hcvi) {
    hocvi = hcvi;
}
string Giangvien::getmgv() const {
    return hocvi;
}

void Giangvien::setchucvu(const string &chuc) {
    chucvu = chuc;
}
string Giangvien::getmgv() const {
    return chucvu;
}

void Giangvien::setchuyennganh(const string &chuyenngh) {
    chuyennganh = chuyenngh;
}
string Giangvien::getchuyennganh() const {
    return chuyennganh;
}

void Giangvien::settinhtranggv(tinhtrangGV tinhtranggv) {
    tinhtrang = tinhtranggv;
}
tinhtrangGV Giangvien::gettinhtranggv() const {
    return tinhtrang;
}


