#ifndef MONHOC_H
#define MONHOC_H

#include <string>

class MonHoc {
    private:
        string maMonHoc;
        string tenMonHoc;
        int soTinChi;
        int soTiet;
        string monTienQuyet;
        string khoaPhuTrach;

    public:
        MonHoc();
        MonHoc(string maMonHoc, string tenMonHoc, int soTinChi, int soTiet, string monTienQuyet, string khoaPhuTrach);

        string getMaMonHoc();
        string getTenMonHoc();
        int getSoTinChi();
        int getSoTiet();
        string getMonTienQuyet();
        string getKhoaPhuTrach();

        void setMaMonHoc(string maMonHoc);
        void setTenMonHoc(string tenMonHoc);
        void setSoTinChi(int soTinChi);
        void setSoTiet(int soTiet);
        void setMonTienQuyet(string monTienQuyet);
        void setKhoaPhuTrach(string khoaPhuTrach);

        void nhap();
        void xuat();
};

#endif