#ifndef TAIKHOAN_H
#define TAIKHOAN_H

#include<iostream>
#include<string>

using namespace std;

class TaiKhoan {
    protected :
        string taikhoan, matkhau, role;
    public :
        TaiKhoan(string taikhoan = " ", string matkhau = " ", string role = " ");
        
        virtual ~TaiKhoan();

        void settk(const string& taikhoan);
        string gettk() const;

        void setmk(const string& matkhau);
        string getmk() const;

        void setrole(const string& role);
        string getrole() const;

        bool checklog(const string& filename);

};

#endif