#include<../include/models/Giangvien.h>
#include<bits/stdc++.h>
#include<../include/utils/InputHelper.h>

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
    if (tmp == "DANG_GIANG_DAY") tinhtrang = DANG_GIANG_DAY;
    else if ( tmp == "TAM_NGHI") tinhtrang = TAM_NGHI;
    else if (tmp == "NGHI_THAI_SAN") tinhtrang = NGHI_THAI_SAN;
    else if ( tmp == "NGHI_HUU") tinhtrang = NGHI_HUU;
    else if (tmp == "THOI_VIEC") tinhtrang = THOI_VIEC;
}

void Giangvien::nhap() {
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

    switch (luaChon) {
        case 1: this->tinhtrang = DANG_GIANG_DAY; break;
        case 2: this->tinhtrang = TAM_NGHI; break;
        case 3: this->tinhtrang = NGHI_THAI_SAN; break;
        case 4: this->tinhtrang = NGHI_HUU; break;
        case 5: this->tinhtrang = THOI_VIEC; break;
    }
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


