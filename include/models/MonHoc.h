#ifndef MONHOC_H
#define MONHOC_H

#include <string>

class MonHoc {
    private:
        std::string maMonHoc;
        std::string tenMonHoc;
        int soTinChi;
        int soTiet;

    public:
       MonHoc() {
            this->maMonHoc = "";
            this->tenMonHoc = "";
            this->soTinChi = 0;
            this->soTiet = 0;

        }
        
        MonHoc(std::string maMonHoc, std::string tenMonHoc, int soTinChi, int soTiet) {
            this->maMonHoc = maMonHoc;
            this->tenMonHoc = tenMonHoc;
            this->soTinChi = soTinChi;
            this->soTiet = soTiet;
        }

        std::string getMaMonHoc() const;
        std::string getTenMonHoc() const;
        int getSoTinChi() const;
        int getSoTiet() const;

        void setMaMonHoc(const std::string&);
        void setTenMonHoc(const std::string&);
        void setSoTinChi(int);
        void setSoTiet(int);

        void nhap();
        void xuat() const;
};

#endif