#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct KhachHang {
    string maKH;
    int chiSoDienThangTruoc;
    int chiSoDienThangSau;
};

double tinhTienDien(int soKw) {
    if (soKw <= 50) return soKw * 1.7284;
    else if (soKw <= 100) return 50 * 1.7284 + (soKw - 50) * 1.786;
    else if (soKw <= 200) return 50 * 1.7284 + 50 * 1.786 + (soKw - 100) * 2.0740;
    else if (soKw <= 300) return 50 * 1.7284 + 50 * 1.786 + 100 * 2.0740 + (soKw - 200) * 2.612;
    else if (soKw <= 400) return 50 * 1.7284 + 50 * 1.786 + 100 * 2.0740 + 100 * 2.612 + (soKw - 300) * 2.9194;
    else return 50 * 1.7284 + 50 * 1.786 + 100 * 2.0740 + 100 * 2.612 + 100 * 2.9194 + (soKw - 400) * 3.015;
}

vector<KhachHang> docDuLieu() {
    ifstream file("khachhang.dat");
    int n;
    file >> n;
    vector<KhachHang> khachHangs(n);
    for (int i = 0; i < n; i++) {
        file >> khachHangs[i].maKH >> khachHangs[i].chiSoDienThangTruoc >> khachHangs[i].chiSoDienThangSau;
    }
    file.close();
    return khachHangs;
}

void ghiDuLieu(vector<KhachHang> khachHangs) {
    ofstream file("tiendien.dat");
    file << khachHangs.size() << endl;
    for (KhachHang kh : khachHangs) {
        int soKw = kh.chiSoDienThangSau - kh.chiSoDienThangTruoc;
        double tienDien = tinhTienDien(soKw);
        file << kh.maKH << " " << tienDien << endl;
    }
    file.close();
}

int main() {
    vector<KhachHang> khachHangs = docDuLieu();
    ghiDuLieu(khachHangs);
    return 0;
}

// Giải thích: file chứa dữ liệu của 3 khách hàng, khách hàng thứ nhất có mà A01, chỉ số điện tháng trước 159, chỉ số điện tháng sau 345.
// Trong file dữ liệu, mỗi dòng sau dòng đầu tiên sẽ chứa thông tin về một khách hàng. Thông tin này bao gồm mã khách hàng, chỉ số điện tháng trước và chỉ số điện tháng sau, mỗi giá trị được phân tách bằng ít nhất một khoảng trắng.

// Ví dụ, nếu file chứa dữ liệu của 3 khách hàng, nó có thể trông như sau :


// 3
// A01 159 345
// A02 200 400
// A03 300 600

// Trong đó :
// Dòng đầu tiên là số 3, cho biết có 3 khách hàng.
// Dòng thứ hai là A01 159 345, cho biết khách hàng có mã A01 có chỉ số điện tháng trước là 159 và chỉ số điện tháng sau là 345.
// Tương tự, dòng thứ ba và thứ tư cho biết thông tin về khách hàng thứ hai và thứ ba.
