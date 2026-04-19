# Bài tập lớn bộ môn OOP
![Project](https://img.shields.io/badge/Project-Nhóm_9-blue)  
![Status](https://img.shields.io/badge/Status-Hoàn_thành-green)  
*Bài tập lớn của **nhóm 9** với đề tài: Quản lí **sinh viên***

## CẤU TRÚC THƯ MỤC
   ```bash
    ├── folder data
    │           └── các file .csv chứa dữ liệu 
    ├── folder include (*.h)
    ├── folder src (*.cpp)
    ├── main.cpp
    └── README.md
   ```

## CÀI ĐẶT VÀ CHẠY CHƯƠNG TRÌNH

### Yêu cầu hệ thống
- Hệ điều hành: Windows
- Compiler: g++ (MinGW hoặc tương tự)
- Thư viện: C++ Standard Library

### Hướng dẫn cài đặt
1. Clone hoặc tải source code về máy.
2. Mở terminal và điều hướng đến thư mục project.
3. Biên dịch chương trình:
   ```bash
   g++ -I include -o main main.cpp src/models/*.cpp src/managers/*.cpp src/services/*.cpp src/utils/*.cpp
   ```
4. Chạy chương trình:
   ```bash
   ./main
   ```

## TÍNH NĂNG CHÍNH

### 1. Đăng nhập hệ thống
- Hỗ trợ 3 loại tài khoản: Admin, Giảng viên, Sinh viên
- Đọc thông tin từ file `data/Taikhoan.csv`

### 2. Menu Admin
- Quản lý Sinh viên: Thêm, sửa, xóa, hiển thị danh sách
- Quản lý Giảng viên: Thêm, sửa, xóa, hiển thị danh sách
- Quản lý Môn học: Thêm, sửa, xóa, hiển thị danh sách
- Quản lý Tài khoản (chưa triển khai)
- Phân công giảng viên dạy môn (chưa triển khai)

### 3. Menu Giảng viên
- Xem thông tin cá nhân
- Xem thời khóa biểu (chưa triển khai)
- Xem danh sách sinh viên theo môn (chưa triển khai)
- Nhập/sửa điểm sinh viên

### 4. Menu Sinh viên
- Xem thông tin cá nhân
- Xem điểm các môn
- Đăng ký môn học
- Xem lịch học (chưa triển khai)
- Xem giảng viên dạy môn (chưa triển khai)

## CẤU TRÚC DỮ LIỆU

### File CSV
- `Sinhvien.csv`: Thông tin sinh viên
- `Giangvien.csv`: Thông tin giảng viên
- `MonHoc.csv`: Thông tin môn học
- `DangKyHoc.csv`: Thông tin đăng ký học và điểm số
- `Taikhoan.csv`: Thông tin tài khoản đăng nhập

### Lớp chính
- `Nguoi` (abstract): Lớp cơ sở cho Sinhvien và Giangvien
- `Sinhvien`: Quản lý thông tin sinh viên
- `Giangvien`: Quản lý thông tin giảng viên
- `MonHoc`: Thông tin môn học
- `DangKyHoc`: Thông tin đăng ký và điểm số
- `TaiKhoan`: Xử lý đăng nhập

### Managers
- `SinhVienManager`: Quản lý danh sách sinh viên
- `GiangVienManager`: Quản lý danh sách giảng viên
- `MonHocManager`: Quản lý danh sách môn học

### Services
- `Menu`: Xử lý giao diện menu
- `DiemService`: Quản lý điểm số và đăng ký học
- `InputHelper`: Hỗ trợ nhập liệu

## HƯỚNG DẪN SỬ DỤNG

1. Chạy chương trình và đăng nhập với tài khoản phù hợp.
2. Chọn menu tương ứng với vai trò của bạn.
3. Thực hiện các thao tác quản lý dữ liệu.
4. Dữ liệu sẽ được lưu tự động vào file CSV.

## NHÓM THỰC HIỆN
- **Nhóm 9**: [Tên các thành viên]

## LƯU Ý
- Chương trình sử dụng tiếng Việt trong giao diện.
- Đảm bảo các file CSV tồn tại trong thư mục `data/` trước khi chạy.
- Một số tính năng nâng cao chưa được triển khai đầy đủ.

