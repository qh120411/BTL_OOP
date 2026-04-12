#ifndef MONHOCMANAGER_H
#define MONHOCMANAGER_H

#include <../include/models/MonHoc.h>
#include <vector>
#include <string>

class MonHocManager {
    private:
        std::vector<MonHoc> dsMonHoc;

    public:
        void themMonHoc();
        bool themMonHoc(const MonHoc&);

        void hienThiDanhSach() const;
        void hienThiTheoMa(const std::string&) const;

        int timViTriTheoMa(const std::string&) const;
        MonHoc* timMonHocTheoMa(const std::string&);
        const MonHoc* timMonHocTheoMa(const std::string&) const;

        bool suaMonHoc(const std::string&);
        bool xoaMonHoc(const std::string&);

        bool tonTaiMaMon(const std::string&) const;

        void sapXepTheoTen();
        void sapXepTheoSoTinChiTangDan();

        bool docTuFileCsv(const std::string&);
        bool ghiRaFileCsv(const std::string&) const;
};

#endif