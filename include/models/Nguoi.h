#ifndef NGUOI_H
#define NGUOI_H

#include<bits/stdc++.h>

using namespace std;

class Nguoi {
    protected: 
        string hoten, gioitinh, namsinh, quequan, sodienthoai, email, diachi, socccd;
    public :
        Nguoi(string hoten = " ", string gioitinh = " ", string namsinh = " ", string quequan = " ", string sodienthoai = " ",
             string email = " ", string diachi = " ", string socccd = " ");
        
        virtual ~Nguoi();

        virtual void hienthithongtin();
        virtual void docfile(istream &is);
        virtual void luufile(ostream &ou);

        void sethoten( const string& hoten);
        string gethoten() const;

        void setgioitinh(const string& gioitinh);
        string getgioitinh() const;

        void setnamsinh(const string& namsinh);
        string getnamsinh() const;

        void setquequan(const string& quequan);
        string getquequan() const;

        void setsodienthoai(const string& sodienthoai);
        string getsodienthoai() const;

        void setemail(const string& email);
        string getemail() const;

        void setdiachi(const string& diachi);
        string getdiachi() const;

        void setsocccd(const string& socccd);
        string getsocccd() const;

};
#endif