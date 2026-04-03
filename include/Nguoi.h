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

        void setten( const string& hoten);
        string getten() const;

        void setgt(const string& gioitinh);
        string getgt() const;

        void setnsinh(const string& namsinh);
        string getnsinh() const;

        void setquequan(const string& quequan);
        string getquequan() const;

        void setsdt(const string& sodienthoai);
        string getsdt() const;

        void setemail(const string& email);
        string getemail() const;

        void setdiachi(const string& diachi);
        string getdiachi() const;

        void setcccd(const string& socccd);
        string getcccd() const;

};
#endif