#ifndef MONHOC_H
#define MONHOC_H

#include <string>

class MonHoc {
    private:
        std::string maMonHoc;
        std::string tenMonHoc;
        int soTinChi;
        int soTiet;
        std::string monTienQuyet;
        std::string khoaPhuTrach;

    public:
       MonHoc() {
            this->maMonHoc = "";
            this->tenMonHoc = "";
            this->soTinChi = 0;
            this->soTiet = 0;
            this->monTienQuyet = "";
            this->khoaPhuTrach = "";
        }
        MonHoc(std::string maMonHoc, std::string tenMonHoc, int soTinChi, int soTiet, std::string monTienQuyet, std::string khoaPhuTrach) {
            this->maMonHoc = maMonHoc;
            this->tenMonHoc = tenMonHoc;
            this->soTinChi = soTinChi;
            this->soTiet = soTiet;
            this->monTienQuyet = monTienQuyet;
            this->khoaPhuTrach = khoaPhuTrach;
        }

        std::string getMaMonHoc() const;
        std::string getTenMonHoc() const;
        int getSoTinChi() const;
        int getSoTiet() const;
        std::string getMonTienQuyet() const;
        std::string getKhoaPhuTrach() const;

        void setMaMonHoc(const std::string&);
        void setTenMonHoc(const std::string&);
        void setSoTinChi(int);
        void setSoTiet(int);
        void setMonTienQuyet(const std::string&);
        void setKhoaPhuTrach(const std::string&);

        void nhap();
        void xuat() const;
};

#endif