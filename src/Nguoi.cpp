#include<../include/Nguoi.h>
#include<bits/stdc++.h>

using namespace std;

Nguoi::Nguoi(string ten, string gt, string nsinh, string que, string sdt, string mail, string dch, string cccd ) : hoten(ten),
             gioitinh(gt), namsinh(nsinh), quequan(que), sodienthoai(sdt), email(mail), diachi(dch), socccd(cccd) {};


Nguoi::~Nguoi(){}


void Nguoi::sethoten(const string &ten) {
    hoten = ten;
}
string Nguoi::gethoten() const {
    return hoten;
}

void Nguoi::setgioitinh(const string &gt) {
    gioitinh = gt;
}
string Nguoi::getgioitinh() const {
    return gioitinh;
}

void Nguoi::setnamsinh(const string &nsinh) {
    namsinh = nsinh;
}
string Nguoi::getnamsinh() const {
    return namsinh;
}

void Nguoi::setquequan(const string &que) {
    quequan = que;
}
string Nguoi::getquequan()const{
    return quequan;
}

void Nguoi::setsodienthoai(const string &sdt) {
    sodienthoai = sdt;
}
string Nguoi::getsodienthoai() const {
    return sodienthoai;
}

void Nguoi::setemail(const string &mail) {
    email = mail;
}
string Nguoi::getemail() const {
    return email;
}

void Nguoi::setdiachi(const string &dch) {
    diachi = dch;
}
string Nguoi::getdiachi() const {
    return diachi;
}

void Nguoi::setsocccd(const string &cccd) {
    socccd = cccd;
}
string Nguoi::getsocccd() const {
    return socccd;
}






