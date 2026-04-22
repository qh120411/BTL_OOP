#include <../include/models/Nguoi.h>
#include <bits/stdc++.h>
#include <../include/utils/InputHelper.h>

using namespace std;

Nguoi::Nguoi(string ten, string gt, string nsinh, string que, string sdt, string mail, string dch, string cccd) : hoten(ten),
                                                                                                                  gioitinh(gt), namsinh(nsinh), quequan(que), sodienthoai(sdt), email(mail), diachi(dch), socccd(cccd) {};

Nguoi::~Nguoi() {}

void Nguoi::luufile(ostream &ou)
{
    ou << hoten << "," << gioitinh << "," << namsinh << "," << quequan << "," << sodienthoai << ","
       << email << "," << diachi << "," << socccd << ",";
}

void Nguoi::docfile(istream &is)
{
    getline(is, hoten, ',');
    getline(is, gioitinh, ',');
    getline(is, namsinh, ',');
    getline(is, quequan, ',');
    getline(is, sodienthoai, ',');
    getline(is, email, ',');
    getline(is, diachi, ',');
    getline(is, socccd, ',');
}

void Nguoi::nhap()
{
    this->hoten = InputHelper::inputLine("Nhap vao ho ten: ");
    this->gioitinh = InputHelper::inputLine("Nhap vao gioi tinh (nam/nu): ");
    this->namsinh = InputHelper::inputDate("Nhap vao ngay/thang/nam sinh: ");
    this->quequan = InputHelper::inputLine("Nhap vao que quan: ");
    this->sodienthoai = InputHelper::inputLine("Nhap vao so dien thoai: ");
    this->email = InputHelper::inputLine("Nhap vao email: ");
    this->diachi = InputHelper::inputLine("Nhap vao dia chi noi o: ");
    this->socccd = InputHelper::inputLine("Nhap vao so cccd: ");
}

void Nguoi::xuat() const
{
    cout << "----------------------------------------\n";
    cout << "Ho ten: " << hoten << "\n";
    cout << "Gioi tinh: " << gioitinh << "\n";
    cout << "Nam sinh: " << namsinh << "\n";
    cout << "Que quan: " << quequan << "\n";
    cout << "So dien thoai: " << sodienthoai << "\n";
    cout << "Email: " << email << "\n";
    cout << "Dia chi: " << diachi << "\n";
}

void Nguoi::hienthithongtin()
{
    xuat();
}

void Nguoi::sethoten(const string &ten)
{
    hoten = ten;
}
string Nguoi::gethoten() const
{
    return hoten;
}

void Nguoi::setgioitinh(const string &gt)
{
    gioitinh = gt;
}
string Nguoi::getgioitinh() const
{
    return gioitinh;
}

void Nguoi::setnamsinh(const string &nsinh)
{
    namsinh = nsinh;
}
string Nguoi::getnamsinh() const
{
    return namsinh;
}

void Nguoi::setquequan(const string &que)
{
    quequan = que;
}
string Nguoi::getquequan() const
{
    return quequan;
}

void Nguoi::setsodienthoai(const string &sdt)
{
    sodienthoai = sdt;
}
string Nguoi::getsodienthoai() const
{
    return sodienthoai;
}

void Nguoi::setemail(const string &mail)
{
    email = mail;
}
string Nguoi::getemail() const
{
    return email;
}

void Nguoi::setdiachi(const string &dch)
{
    diachi = dch;
}
string Nguoi::getdiachi() const
{
    return diachi;
}

void Nguoi::setsocccd(const string &cccd)
{
    socccd = cccd;
}
string Nguoi::getsocccd() const
{
    return socccd;
}
