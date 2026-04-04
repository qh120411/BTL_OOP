#include "QuanLySinhVien.h"

// ================= TAI KHOAN =================
TaiKhoan::TaiKhoan(string u, string p, string r) {
    user = u; pass = p; role = r;
}

bool TaiKhoan::login(string u, string p) {
    return (u == user && p == pass);
}

string TaiKhoan::getRole() {
    return role;
}

// ================= NGUOI =================
void Nguoi::nhap() {
    cout << "Ma: "; cin >> ma;
    cin.ignore();
    cout << "Ten: "; getline(cin, ten);
    cout << "Tuoi: "; cin >> tuoi;
}

void Nguoi::xuat() {
    cout << left << setw(10) << ma
         << setw(20) << ten
         << setw(10) << tuoi << endl;
}

string Nguoi::getMa() { return ma; }
string Nguoi::getTen() { return ten; }

// ================= SINH VIEN =================
void SinhVien::nhap() {
    Nguoi::nhap();
    cin.ignore();
    cout << "Lop: "; getline(cin, lop);

    string u,p;
    cout << "Username: "; cin >> u;
    cout << "Password: "; cin >> p;
    tk = TaiKhoan(u,p,"sv");
}

void SinhVien::xuat() {
    cout << left << setw(10) << ma
         << setw(20) << ten
         << setw(10) << tuoi
         << setw(10) << lop << endl;
}

TaiKhoan SinhVien::getTK() { return tk; }

// ================= MON HOC =================
void MonHoc::nhap() {
    cout << "Ma MH: "; cin >> maMH;
    cin.ignore();
    cout << "Ten MH: "; getline(cin, tenMH);
    cout << "Tin chi: "; cin >> tinChi;
}

string MonHoc::getTen() { return tenMH; }
int MonHoc::getTC() { return tinChi; }

// ================= LOP HOC PHAN =================
void LopHocPhan::nhap() {
    cout << "Ma LHP: "; cin >> maLHP;
    cout << "--- Nhap mon hoc ---\n";
    mh.nhap();
}

string LopHocPhan::getMa() { return maLHP; }
string LopHocPhan::getTenMH() { return mh.getTen(); }
int LopHocPhan::getTC() { return mh.getTC(); }

void LopHocPhan::xuat() {
    cout << left << setw(10) << maLHP
         << setw(25) << getTenMH()
         << setw(10) << getTC() << endl;
}

// ================= DANG KY =================
DangKy::DangKy(string sv, string lhp) {
    maSV = sv; maLHP = lhp; diem = -1;
}

string DangKy::getSV(){ return maSV; }
string DangKy::getLHP(){ return maLHP; }

void DangKy::nhapDiem() {
    do {
        cout << "Nhap diem (0-10): ";
        cin >> diem;
    } while(diem<0 || diem>10);
}

float DangKy::getDiem(){ return diem; }

// ================= QUAN LY =================
void QuanLy::themSV() {
    SinhVien sv;
    sv.nhap();

    for(auto &x: dsSV)
        if(x.getMa()==sv.getMa()) {
            cout << "Trung ma!\n";
            return;
        }

    dsSV.push_back(sv);
    dsTK.push_back(sv.getTK());
    cout << "Them SV thanh cong!\n";
}

void QuanLy::hienSV() {
    cout << left << setw(10) << "Ma"
         << setw(20) << "Ten"
         << setw(10) << "Tuoi"
         << setw(10) << "Lop" << endl;

    for(auto &x: dsSV) x.xuat();
}

void QuanLy::sapXep() {
    sort(dsSV.begin(), dsSV.end(), [](SinhVien a, SinhVien b){
        return a.getTen()<b.getTen();
    });
    cout << "Da sap xep!\n";
}

void QuanLy::thongKe() {
    cout << "So SV: " << dsSV.size() << endl;
    cout << "So LHP: " << dsLHP.size() << endl;
    cout << "So DK: " << dsDK.size() << endl;
}

void QuanLy::themLHP() {
    LopHocPhan l;
    l.nhap();

    for (auto &x : dsLHP)
        if (x.getMa() == l.getMa()) {
            cout << "Trung ma!\n";
            return;
        }

    dsLHP.push_back(l);
    cout << "Them thanh cong!\n";
}

void QuanLy::dangKy() {
    string sv, lhp;
    cout << "Ma SV: "; cin >> sv;

    for (auto &l : dsLHP) l.xuat();

    cout << "Ma LHP: "; cin >> lhp;

    for(auto &dk: dsDK)
        if(dk.getSV()==sv && dk.getLHP()==lhp){
            cout << "Da dang ky!\n";
            return;
        }

    dsDK.push_back(DangKy(sv,lhp));
    cout << "Dang ky thanh cong!\n";
}

void QuanLy::nhapDiem() {
    string ma;
    cout << "Ma SV: "; cin >> ma;

    for(auto &dk: dsDK)
        if(dk.getSV()==ma)
            dk.nhapDiem();
}

void QuanLy::xemDiem() {
    string ma;
    cout << "Nhap ma SV: "; cin >> ma;

    for(auto &dk: dsDK)
        if(dk.getSV()==ma){
            cout << dk.getLHP() << " -> ";
            if(dk.getDiem()<0) cout << "Chua co diem\n";
            else cout << dk.getDiem() << endl;
        }
}

string QuanLy::login() {
    string u,p;
    cout << "User: "; cin >> u;
    cout << "Pass: "; cin >> p;

    if(u=="admin" && p=="admin") return "admin";

    for(auto &tk: dsTK)
        if(tk.login(u,p)) return tk.getRole();

    return "fail";
}