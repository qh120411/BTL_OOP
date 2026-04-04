#pragma once
#include <bits/stdc++.h>
using namespace std;

// ===== TAI KHOAN =====
class TaiKhoan {
    string user, pass, role;
public:
    TaiKhoan() {}
    TaiKhoan(string u, string p, string r);
    bool login(string u, string p);
    string getRole();
};

// ===== NGUOI =====
class Nguoi {
protected:
    string ma, ten;
    int tuoi;
public:
    virtual void nhap();
    virtual void xuat();
    string getMa();
    string getTen();
};

// ===== SINH VIEN =====
class SinhVien : public Nguoi {
    string lop;
    TaiKhoan tk;
public:
    void nhap() override;
    void xuat() override;
    TaiKhoan getTK();
};

// ===== MON HOC =====
class MonHoc {
    string maMH, tenMH;
    int tinChi;
public:
    void nhap();
    string getTen();
    int getTC();
};

// ===== LHP =====
class LopHocPhan {
    string maLHP;
    MonHoc mh;
public:
    void nhap();
    string getMa();
    string getTenMH();
    int getTC();
    void xuat();
};

// ===== DANG KY =====
class DangKy {
    string maSV, maLHP;
    float diem;
public:
    DangKy(string sv, string lhp);
    string getSV();
    string getLHP();
    void nhapDiem();
    float getDiem();
};

// ===== QUAN LY =====
class QuanLy {
    vector<SinhVien> dsSV;
    vector<LopHocPhan> dsLHP;
    vector<DangKy> dsDK;
    vector<TaiKhoan> dsTK;

public:
    void themSV();
    void hienSV();
    void sapXep();
    void thongKe();
    void themLHP();
    void dangKy();
    void nhapDiem();
    void xemDiem();
    string login();
};