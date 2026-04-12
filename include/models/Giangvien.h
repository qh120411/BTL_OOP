#ifndef GIANGVIEN_H
#define GIANGVIEN_H
#include<Nguoi.h>

using namespace std;

enum tinhtrangGV {
    DANG_GIANG_DAY,
    TAM_NGHI,
    NGHI_THAI_SAN,
    NGHI_HUU,
    THOI_VIEC
};

class Giangvien : public Nguoi {
    protected :
        string mgv;
        string bomon;
        string khoa;
        string hocvi;
        string chucvu;
        string chuyennganh;
        tinhtrangGV tinhtrang;
    
        public :
            Giangvien(string hoten = " ", string gioitinh = " ", string namsinh = " ", string quequan = " ", string sodienthoai = " ",
                string email = " ", string diachi = " ", string socccd = " ", string mgv = " ", string bomon = " ", string khoa = " ",
                string hocvi = " ", string chucvu = " ", string chuyennganh = " ", tinhtrangGV tinhtrang = DANG_GIANG_DAY);
            virtual ~Giangvien();

            virtual void hienthithongtin() override;
            virtual void docfile(istream &is) override;
            virtual void luufile(ostream &ou) override;

            virtual void nhap() ;
            virtual void xuat() const;

            void setmgv ( const string &mgv);
            string getmgv() const;

            void setbomon ( const string &bomon);
            string getbomon() const;

            void setkhoa ( const string &khoa);
            string getkhoa() const;

            void sethocvi ( const string &hocvi);
            string gethocvi() const;

            void setchucvu ( const string &chucvu);
            string getchucvu() const;

            void setchuyennganh ( const string &chuyennganh);
            string getchuyennganh() const;

            void settinhtranggv(tinhtrangGV tinhtrang);
            tinhtrangGV gettinhtranggv() const;


};

#endif