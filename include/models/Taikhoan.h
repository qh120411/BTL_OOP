#ifndef TAIKHOAN_H
#define TAIKHOAN_H

#include<iostream>
#include<string>

using namespace std;

class TaiKhoan {
    protected :
        string taikhoan, matkhau, role, maLienKet, trangthai;
    public :
        TaiKhoan(string taikhoan = " ", string matkhau = " ", string role = " ", string trangthai = " ", string maLienKet = " ");
        
        virtual ~TaiKhoan();

        void settk(const string& taikhoan);
        string gettk() const;

        void setmk(const string& matkhau);
        string getmk() const;

        void setrole(const string& role);
        string getrole() const;

        void settrangthai(const string& trangthai);
        string gettrangthai() const;

        void setMaLienKet(const string& maLienKet);
        string getMaLienKet() const;
        string getDinhDanhNguoiDung() const;

        bool checklog(const string& filename);

};

#endif
