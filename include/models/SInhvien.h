#ifndef SINHVIEN_H
#define SINHVIEN_H
#include "Nguoi.h"

using namespace std;

enum Tinhtrang
{
    DANG_HOC,
    BAO_LUU,
    TOT_NGHIEP,
    THOI_HOC
};

class Sinhvien : public Nguoi
{
protected:
    string msv;
    string nganh;
    string Khoa;
    string lop;
    int khoahoc;
    Tinhtrang tinhtrang;

public:
    Sinhvien(string hoten = " ", string gioitinh = " ", string namsinh = " ", string quequan = " ", string sodienthoai = " ",
             string email = " ", string diachi = " ", string socccd = " ", string msv = " ", string nganh = " ", string Khoa = " ", string lop = " ", int khoahoc = 0, Tinhtrang tinhtrang = DANG_HOC);
    virtual ~Sinhvien();

    virtual void hienthithongtin() override;
    virtual void docfile(istream &is) override;
    virtual void luufile(ostream &ou) override;

    virtual void nhap();
    virtual void xuat() const;

    void setmsv(const string &msv);
    string getmsv() const;

    void setnganh(const string &nganh);
    string getnganh() const;

    void setKhoa(const string &Khoa);
    string getKhoa() const;

    void setlop(const string &lop);
    string getlop() const;

    void setkhoahoc(const int &khoahoc);
    int getkhoahoc() const;

    void settinhtrang(Tinhtrang tinhtrang);
    Tinhtrang gettinhtrang() const;

    static std::string csvHeader();
    std::string toCsvRow() const;
    static Sinhvien fromCsvRow(const std::vector<std::string> &fields);
};
#endif