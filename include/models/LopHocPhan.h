#ifndef LOPHOCPHAN_H
#define LOPHOCPHAN_H

#include <string>
#include <vector>

class LopHocPhan {
    private:
        std::string maLHP;
        std::string maMon;
        std::string maGV;
        std::string hocKy;
        std::string namHoc;
        std::string phongHoc;
        std::string lichHoc;
        int siSoToiDa;
        int siSoHienTai;
    
    public:
        LopHocPhan() {
            this->maLHP = "";
            this->maMon = "";
            this->maGV = "";
            this->hocKy = "";
            this->namHoc = "";
            this->phongHoc = "";
            this->lichHoc = "";
            this->siSoToiDa = 0;
            this->siSoHienTai = 0;
        }
        LopHocPhan(std::string maLHP, std::string maMon, std::string maGV, std::string hocKy, std::string namHoc, std::string phongHoc, std::string lichHoc, int siSoToiDa, int siSoHienTai) {
            this->maLHP = maLHP;
            this->maMon = maMon;
            this->maGV = maGV;
            this->hocKy = hocKy;
            this->namHoc = namHoc;
            this->phongHoc = phongHoc;
            this->lichHoc = lichHoc;
            this->siSoToiDa = siSoToiDa;
            this->siSoHienTai = siSoHienTai;
        }

        std::string getMaLHP() const;
        std::string getMaMon() const;
        std::string getMaGV() const;
        std::string getHocKy() const;
        std::string getNamHoc() const;
        std::string getPhongHoc() const;
        std::string getLichHoc() const;
        int getSiSoToiDa() const;
        int getSiSoHienTai() const;

        void setMaLHP(const std::string&);
        void setMaMon(const std::string&);
        void setMaGV(const std::string&);
        void setHocKy(const std::string&);
        void setNamHoc(const std::string&);
        void setPhongHoc(const std::string&);
        void setLichHoc(const std::string&);
        void setSiSoToiDa(int);
        void setSiSoHienTai(int);

        void tangSiSo();
        void giamSiSo();

        void nhap();
        void xuat() const;

        static std::string csvHeader();
        std::string toCsvRow() const;
        static LopHocPhan fromCsvRow(const std::vector<std::string>&);
};

#endif
