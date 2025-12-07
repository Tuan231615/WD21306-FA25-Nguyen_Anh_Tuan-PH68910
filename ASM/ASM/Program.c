// CConsoleApplication.c : file nay chua 'main' function. 
// Chuong trinh phan mem Bat dau thuc thi & Ket thuc o day.

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int flag = 1;
bool laSoNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}
bool laSoChinhPhuong(int n) {
    if (n < 0) return false;
    int can = sqrt(n);
    return can * can == n;
}
void kiemTraSoNguyen() {
    float soNhap;
    int flag = 1;
    while (flag) {
        printf("\nMoi ban nhap so: \n");
        scanf("%f", &soNhap);
        if (soNhap - (int)soNhap == 0) {
            if (laSoNguyenTo(soNhap)) {
                printf(" %.2f la so nguyen to. \n ", soNhap);
            }
            else if (laSoChinhPhuong(soNhap)) {
                printf(" %.2f la so chinh phuong. \n", soNhap);
            }
            else {
                printf("So vua nhap la so nguyen.\n");
            }
        }
        else {
            printf("So vua nhap khong phai la so nguyen.\n");
        }
        /*do{
            printf("\n------------------\n");
            printf(" Ban co muon tiep tuc khong?\n");
            printf("1. Co\n");
            printf("2. Khong[Hay bam phim 0]\n");
            printf("------------------\n");
            printf("\nMoi ban chon: \n");
            scanf("%d", &flag);

            switch (flag) {
            case 1: kiemTraSoNguyen();
                break;
            case 0: flag = 0;
                break;
            default:
                printf("Ban nhap loi[Vui long chon 1 hoac 0] \n");
                break;
            }
        } while (flag);*/
        menuPhu(1);
        flag = 0;
    }
}
int UCLN(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int BCNN(int a, int b) {
    return (a * b) / UCLN(a, b);
}
void uocChungBoiChung() {
    int choice = 1;
    float a, b;
    int flag = 1, flag1 = 1;
    int flag2 = 1;
    while (flag2) {
        printf("\nMoi nhap so a: \n");
        scanf("%f", &a);
        if (a - (int)a != 0) {
            printf("So a khong phai la so nguyen. Vui long nhap lai!\n");
            printf("--------------------------------\n");
        }
        else {
            while (flag) {
                printf("\nMoi nhap so b: \n");
                scanf("%f", &b);
                while (flag1) {
                    if (b - (int)b != 0) {
                        printf("So b khong phai la so nguyen. Vui long nhap lai!\n");
                        printf("--------------------------------\n");
                        break;
                    }
                    else {
                        printf("Uoc chung lon nhat cua %d va %d la: %d\n", a, b, UCLN(a, b));
                        printf("Boi chung nho nhat cua %d va %d la: %d\n", a, b, BCNN(a, b));
                        menuPhu(2);
                        flag = 0; flag1 = 0; flag2 = 0;
                    }
                }
            }
        }
    }
}
float tienHat(int gioVao, int gioRa) {
    int soGio;
    int flag = 1;
    float tienThanhToan;
    const int giaHat = 150000;
    soGio = gioRa - gioVao;
    if (soGio <= 3) {
        if (gioVao >= 14 && gioVao <= 17) {
            return tienThanhToan = soGio * giaHat * 0.9;
        }
        return  tienThanhToan = soGio * giaHat;
    }
    else {
        if (gioVao >= 14 && gioVao <= 17) {
            return tienThanhToan = (3 * giaHat + (soGio - 3) * giaHat * 0.7) * 0.9;
        }
        return tienThanhToan = 3 * giaHat + (soGio - 3) * giaHat * 0.7;
    }
}
void tinhTienKaraoke() {
    int gioVao, gioRa;
    int choice = 1;
    int flag = 1;
    while (choice) {
        printf("\nMoi ban nhap gio vao [12-23]: \n");
        scanf("%d", &gioVao);
        while (flag) {
            if (gioVao < 12 || gioVao > 23) {
                printf("Nhap khong hop le! Quan chi hoat dong tu 12 - 23h. Vui long nhap lai gio vao: \n");
                printf("--------------------------------\n");
                break;
            }
            else {
                printf("\nMoi ban nhap gio ra [12-23]: \n");
                scanf("%d", &gioRa);
                for (int i = 1; i > 0; i++) {
                    if (gioRa > 24) {
                        printf("Nhap khong hop le! Quan chi hoat dong tu 12 - 23h. \n");
                        printf("--------------------------------\n");
                        break;
                    }
                    else if (gioRa <= gioVao) {
                        printf("Nhap khong hop le! Gio ra > gio vao[Gio vao ban dang nhap la: %d h] \n", gioVao);
                        printf("--------------------------------\n");
                        break;
                    }
                    else {
                        printf("So gio hat: %d\n", gioRa - gioVao);
                        printf("Tien thanh toan: %.2f VND\n", tienHat(gioVao, gioRa));
                        /*while(1){
                            printf("\n------------------\n");
                            printf("Ban co muon tiep tuc tinh tien hat khong? \n");
                            printf("Co.[bam phim 1] \n");
                            printf("Khong.[bam phim 0] \n");
                            printf("-------------------\n");
                            printf("\nMoi ban chon: \n");
                            scanf("%d", &flag1);
                            switch (flag1) {
                            case 1: TinhTienKaraoke();
                                break;
                            case 0:
                                flag1 = 0;flag = 0;
                                choice = 0; i = 0;
                                break;
                            default: printf("Ban nhap loi![Vui long chon 1 hoac 0] \n");
                                continue;
                            }
                            break;
                        }*/
                        menuPhu(3);
                        flag = 0;
                        choice = 0;
                        break;
                    }
                }

            }

        }

    }
}
void tinhTienDien() {
    double kWh;
    int flag = 1;
    float tienDien;
    while (flag) {
        printf("\nMoi ban nhap so kWh tieu thu trong thang: \n");
        scanf("%lf", &kWh);
        if (kWh <= 0) {
            printf("So kWh khong hop le. Vui long nhap lai: \n");
            printf("--------------------------------\n");
        }
        else {
            if (kWh <= 50) {
                tienDien = kWh * 1678;

            }
            else if (kWh <= 100) {
                tienDien = 50 * 1678 + (kWh - 50) * 1734;

            }
            else if (kWh <= 200) {
                tienDien = 50 * 1678 + 50 * 1734 + (kWh - 100) * 2014;

            }
            else if (kWh <= 300) {
                tienDien = 50 * 1678 + 50 * 1734 + 100 * 2014 + (kWh - 200) * 2536;

            }
            else if (kWh <= 400) {
                tienDien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (kWh - 300) * 2834;
            }
            else {
                tienDien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (kWh - 400) * 2927; 
            }
            printf("Gia dien cua 50 so dau:     1678 VND\n");
            printf("Gia dien tu so 51 den 100:  1734 VND\n");
            printf("Gia dien tu so 101 den 200: 2014 VND\n");
            printf("Gia dien tu so 201 den 300: 2536 VND\n");
            printf("Gia dien tu so 301 den 400: 2834 VND\n");
            printf("Gia dien tu so 401 tro di:  2927 VND\n");
            printf("So tien dien phai tra trong thang la: %.0f VND\n", tienDien);
            /*while(1){
                printf("\n------------------\n");
                printf("Ban co muon tinh tien dien nua khong? \n");
                printf("1. Co \n");
                printf("2. Khong[Bam phim 0] \n");
                printf("--------------------\n");
                printf("\nMoi ban chon: \n");
                scanf("%d", &flag1);
                switch (flag1) {
                case 1: tinhTienDien();
                    break;
                case 0:
                    flag1 = 0;
                    flag = 0;
                    break;
                default: printf("Ban nhap loi![Vui long chon 1 hoac 0] \n");
                    continue;
                }
                break;
            }*/
            menuPhu(4);
            flag = 0;
        }
    }
}
void doiTien() {
    int flag = 1;
    int soTien;
    int menhGia[] = { 500, 200, 100, 50, 20, 10, 5, 2, 1 };
    int soLuong[9] = { 0 };
    while (flag) {
        printf("\nNhap so tien can doi: \n");
        scanf("%d", &soTien);
        if (soTien <= 0) {
            printf("So tien khong hop le. Vui long nhap lai!\n");
            printf("--------------------------------\n");
        }
        else {
            int soTienConLai = soTien;
            for (int j = 0; j < 9; j++) {
                if (menhGia[j] == 500 && soTien < 1000) {
                    continue;
                }
                if (menhGia[j] == 200 && soTien < 400) {
                    continue;
                }
                if (menhGia[j] == 100 && soTien < 200) {
                    continue;
                }
                if (menhGia[j] == 50 && soTien < 100) {
                    continue;
                }
                if (menhGia[j] == 20 && soTien < 40) {
                    continue;
                }
                if (menhGia[j] == 10 && soTien < 20) {
                    continue;
                }
                if (menhGia[j] == 5 && soTien < 10) {
                    continue;
                }
                if (menhGia[j] == 2 && soTien < 4) {
                    continue;
                }
                soLuong[j] = soTienConLai / menhGia[j];
                soTienConLai %= menhGia[j];
            }
            printf("Cac menh gia tien[500, 200, 100, 50, 20, 10, 5, 2, 1] \n");
            printf("----------------------------------------------------- \n");
            printf("Ket qua doi tien:\n");
            for (int i = 0; i < 9; i++) {
                if (soLuong[i] > 0) {
                    printf("%d to %d VND\n", soLuong[i], menhGia[i]);
                }
            }
            menuPhu(5);
            flag = 0;
        }
    }
}
void tinhLaiNganHang() {
    int flag = 1;
    float soTienVay, tienLai, tongTienPhaiTra, gocHangThang, GocConLai, laiSuat = 0.05;
    while (flag) {
        printf("Lai suat co dinh 5%%/thang va ky han 12 thang \n");
        printf("-------------------------------------------- \n");
        printf("\nNhap so tien muon vay: \n");
        scanf("%f", &soTienVay);
        if (soTienVay <= 0) {
            printf("So tien vay khong hop le. Vui long nhap lai: \n");
            printf("-------------------------------------------\n");
        }
        else {
            gocHangThang = soTienVay / 12;
            printf("Bang tra gop 12 thang: \n");

            for (int thang = 1; thang <= 12; thang++) {
                tienLai = soTienVay * laiSuat;
                tongTienPhaiTra = gocHangThang + tienLai;
                soTienVay -= gocHangThang;
                printf("Thang %d: Tien goc hang thang: %.0f VND, Tien lai: %.0f VND, Tong tien phai tra: %.0f VND, So tien con lai: %.0f\n", thang, gocHangThang, tienLai, tongTienPhaiTra, soTienVay);
            }
            /*while (1) {
                printf("\n------------------\n");
                printf("Ban co muon tinh lai ngan hang nua khong? \n");
                printf("1. Co \n");
                printf("2. Khong[Bam phim 0] \n");
                printf("-------------------\n");
                printf("\nMoi ban chon: \n");
                scanf("%d", &flag1);
                switch (flag1) {
                case 1: TinhLaiNganHang();
                    break;
                case 0:
                    flag = 0;
                    flag1 = 0;
                    break;
                default: printf("Ban nhap loi![Vui long chon 1 hoac 0] \n");
                    continue;
                }
                break;
            }*/
            menuPhu(6);
            flag = 0;
        }
    }
}
void vayTienMuaXe() {
    int flag = 1;
    float giaXe = 500000000;
    float phanTramVay, traTruoc, tienVay, phanTramTraTruoc;
    float laiSuatThang = 0.072 / 12;
    int soThang = 24 * 12;
    float tienTraHangThang;
    while (flag) {
        printf("Tien duoc vay co dinh: 500 tr(VND) \n");
        printf("Thoi han vay: 24 nam \n");
        printf("Lai suat co dinh nam: 7.2%%\n");
        printf("--------------------------------\n");
        printf("\nNhap phan tram vay: \n");
        scanf("%f", &phanTramVay);
        if (phanTramVay <= 0 || phanTramVay > 100) {
            printf("Phan tram vay khong hop le. Vui long nhap lai! \n");
            printf("\n--------------------------------\n");
        }
        else {
            phanTramTraTruoc = 100 - phanTramVay;
            traTruoc = giaXe * (100 - phanTramVay) / 100;
            tienVay = giaXe - traTruoc;
            tienTraHangThang = (tienVay * laiSuatThang * pow(1 + laiSuatThang, soThang)) / (pow(1 + laiSuatThang, soThang) - 1);
            printf("\n-----Ket qua-----\n");
            printf("Gia xe: %.0f VND\n", giaXe);
            printf("So tien tra lan dau: %.0f VND(Tra truoc %.0f%%)\n", traTruoc, phanTramTraTruoc);
            printf("So tien vay: %.2f VND(Vay %.0f%%)\n", tienVay, phanTramVay);
            printf("So tien phai tra hang thang: %.0f VND/thang\n", tienTraHangThang);
            printf("So nam vay: 24 nam\n");
            printf("Lai suat vay co dinh: 7.2%%/nam \n");
            /*while (1) {
                printf("\n------------------\n");
                printf("Ban co muon tinh lai vay xe nua khong? \n");
                printf("1. Co \n");
                printf("2. Khong[Bam phim 0] \n");
                printf("-------------------\n");
                printf("\nMoi ban chon: \n");
                scanf("%d", &flag1);
                switch (flag1) {
                case 1: VayTienMuaXe();
                    break;
                case 0: flag = 0;
                    flag1 = 0;
                    break;
                default: printf("Ban nhap loi![Vui long chon 1 hoac 0] \n");
                    continue;
                }
                break;
            }*/
            menuPhu(7);
            break;
        }
    }
}
struct SinhVien {
    char hoTen[50];
    float diem;
    char hocLuc[20];
};
void xepLoai(float diem, char* hocLuc) {
    if (diem < 0 || diem > 10) {
        printf("Diem khong lop le\n");
    }
    else {
        if (diem >= 9)
            strcpy(hocLuc, "Xuat sac");
        else if (diem >= 8)
            strcpy(hocLuc, "Gioi");
        else if (diem >= 7)
            strcpy(hocLuc, "Kha");
        else if (diem >= 5)
            strcpy(hocLuc, "Trung binh");
        else
            strcpy(hocLuc, "Yeu");
    }
}
void sapXepGiam(struct SinhVien sv[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sv[i].diem < sv[j].diem) {
                struct SinhVien temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
}
void sapXepThongTinSV() {
    struct SinhVien sv[100];
    int n = 0;
    int flag = 1;
    while (flag) {
        printf("\nNhap thong tin sinh vien thu %d:\n", n + 1);
        printf("--------------------------------\n");
        printf("Nhap ho ten sinh vien: \n");
        getchar();
        fgets(sv[n].hoTen, sizeof(sv[n].hoTen), stdin);
        sv[n].hoTen[strcspn(sv[n].hoTen, "\n")] = '\0';
        while (1) {
            printf("Nhap diem so cua sinh vien: \n");
            scanf("%f", &sv[n].diem);
            if (sv[n].diem < 0 || sv[n].diem > 10) {
                printf("Diem so khong hop le. Vui long nhap lai diem!\n");
                continue;
            }
            break;
        }
        xepLoai(sv[n].diem, sv[n].hocLuc);
        n++;
        sapXepGiam(sv, n);
        printf("\n-----Danh sach sinh vien sau khi sap xep-----\n");
        for (int i = 0; i < n; i++) {
            printf("Ho ten: %-20s | Diem: %.2f | Hoc luc: %-12s\n", sv[i].hoTen, sv[i].diem, sv[i].hocLuc);
        }
        /*int choice;
        while (1) {
            printf("Ban co muon nhap them sinh vien khong? [1: Co, 0: Khong]: ");
            scanf("%d", &choice);
            if (choice == 1) {
                break;
            }
            else if (choice == 0) {
                printf("Thoat chuong trinh.\n");
                return;
            }
            else {
                printf("Lua chon khong hop le. Vui long chon 1 hoac 0!\n");
            }
        }*/
        menuPhu(8);
        flag = 0;
    }
}
void gameFPOLYLOTT() {
    srand(time(NULL));
    int soNgauNhien = rand() % 15 + 1;
    int input;
    while (flag) {
        printf("\nNhap 1 so co 2 chu so[01-15]: \n");
        scanf("%d", &input);
        if (input < 0 || input > 15) {
            printf("So nhap khong dung! Vui long nhap lai[01-15] \n");
            printf("--------------------------------\n");
        }
        else {
            printf("So ngau nhien: %02d\n", soNgauNhien);
            int hangChucRanDom = soNgauNhien / 10;
            int hangDonViRanDom = soNgauNhien % 10;
            int hangChucInput = input / 10;
            int hangDonViInput = input % 10;
            int count = 0;
            if (hangChucRanDom == hangChucInput) count++;
            if (hangDonViRanDom == hangChucInput) count++;
            if (count == 2) printf("Chuc mung ban da trung giai nhat! \n");
            else if (count == 1) printf("Chuc mung ban da trung giai nhi! \n");
            else printf("Chuc ban may man lan sau! \n");
            menuPhu(9);
            flag = 0;
        }
    }
}
typedef struct {
    int tuSo;
    int mauSo;
} PhanSo;
PhanSo rutGonPhanSo(PhanSo ps) {
    int ucln = UCLN(ps.tuSo, ps.mauSo);
    ps.tuSo /= ucln;
    ps.mauSo /= ucln;
    if (ps.mauSo < 0) {
        ps.tuSo = -ps.tuSo;
        ps.mauSo = -ps.mauSo;
    }
    return ps;
}
//PhanSo congPhanSo(PhanSo ps1, PhanSo ps2) {
//    PhanSo kq;
//    kq.tuSo = ps1.tuSo * ps2.mauSo + ps2.tuSo * ps1.mauSo;
//    kq.mauSo = ps1.mauSo * ps2.mauSo;
//    return rutGonPhanSo(kq);
//}
//PhanSo truPhanSo(PhanSo ps1, PhanSo ps2) {
//    PhanSo kq;
//
//    kq.tuSo = ps1.tuSo * ps2.mauSo - ps2.tuSo * ps1.mauSo;
//    kq.mauSo = ps1.mauSo * ps2.mauSo;
//    return rutGonPhanSo(kq);
//}
//PhanSo nhanPhanSo(PhanSo ps1, PhanSo ps2) {
//    PhanSo kq;
//    kq.tuSo = ps1.tuSo * ps2.tuSo;
//    kq.mauSo = ps1.mauSo * ps2.mauSo;
//    return rutGonPhanSo(kq);
//}
//PhanSo chiaPhanSo(PhanSo ps1, PhanSo ps2) {
//    PhanSo kq;
//    kq.tuSo = ps1.tuSo * ps2.mauSo;
//    kq.mauSo = ps1.mauSo * ps2.tuSo;
//    return rutGonPhanSo(kq);
//}
PhanSo phepTinhCoBanPhanSo(PhanSo ps1, PhanSo ps2, char toanTu) {
    PhanSo kq;
    if (toanTu == '+') {
        kq.tuSo = ps1.tuSo * ps2.mauSo + ps2.tuSo * ps1.mauSo;
        kq.mauSo = ps1.mauSo * ps2.mauSo;
        return rutGonPhanSo(kq);
    }
    else if (toanTu == '-') {
        kq.tuSo = ps1.tuSo * ps2.mauSo - ps2.tuSo * ps1.mauSo;
        kq.mauSo = ps1.mauSo * ps2.mauSo;
        return rutGonPhanSo(kq);
    }
    else if (toanTu == '*') {
        kq.tuSo = ps1.tuSo * ps2.tuSo;
        kq.mauSo = ps1.mauSo * ps2.mauSo;
        return rutGonPhanSo(kq);
    }
    else if (toanTu == '/') {
        kq.tuSo = ps1.tuSo * ps2.mauSo;
        kq.mauSo = ps1.mauSo * ps2.tuSo;
        return rutGonPhanSo(kq);
    }
}
void inPhanSo(PhanSo ps, char* chuoi) {
    printf("%s", chuoi);
    if (ps.tuSo == ps.mauSo) {
        printf("1\n");
    }
    else if ("ps.mauSo == 1") {
        printf("%d\n", ps.tuSo);
    }
    else {
        printf("%d/%d\n", ps.tuSo, ps.mauSo);
    }
}
void tinhPhanSo() {
    PhanSo ps1, ps2, kq;
    int flag = 1;
    while (flag) {
        printf("\nNhap phan so thu nhat(tu so va mau so): \n");
        scanf("%d %d", &ps1.tuSo, &ps1.mauSo);
        if (ps1.mauSo == 0) {
            printf("Mau so khong the bang 0. Vui long nhap lai!\n");
            continue;
        }
        else {
            if (ps1.tuSo == 0) {
                ps1.mauSo == 0;
            }
            printf("\nNhap phan so thu hai(tu so va mau so): \n");
            scanf("%d %d", &ps2.tuSo, &ps2.mauSo);
            if (ps2.mauSo == 0) {
                printf("Mau so khong the bang 0. Vui long nhap lai!\n");
                continue;
            }
            else {
                kq = phepTinhCoBanPhanSo(ps1, ps2, '+');
                inPhanSo(kq, "Ket qua phep cong: ");
                kq = phepTinhCoBanPhanSo(ps1, ps2, '-');
                inPhanSo(kq, "Ket qua phep tru: ");
                kq = phepTinhCoBanPhanSo(ps1, ps2, '*');
                inPhanSo(kq, "Ket qua phep nhan: ");
                kq = phepTinhCoBanPhanSo(ps1, ps2, '/');
                inPhanSo(kq, "Ket qua phep chia: ");
                menuPhu(10);
                flag = 0;
            }
        }
    }
}
int menuPhu(int cacChucNang) {
    int flag = 1;
    int flag1 = 1;
    while (flag1) {
        printf("\n-----------Menu Phu-------------\n");
        printf("Ban co muon tiep tuc khong \n");
        printf("Co[Chon 1] \n");
        printf("Khong[Chon 0] \n");
        printf("--------------------------------\n");
        printf("\nMoi ban chon: \n");
        scanf("%d", &flag);
        switch (flag) {
        case 1:
            if (cacChucNang == 1) {
                kiemTraSoNguyen();
                break;
            }
            else if (cacChucNang == 2) {
                uocChungBoiChung();
                break;
            }
            else if (cacChucNang == 3) {
                tinhTienKaraoke();
                break;
            }
            else if (cacChucNang == 4) {
                tinhTienDien();
                break;
            }
            else if (cacChucNang == 5) {
                doiTien();
                break;
            }
            else if (cacChucNang == 6) {
                tinhLaiNganHang();
                break;
            }
            else if (cacChucNang == 7) {
                vayTienMuaXe();
                break;
            }
            else if (cacChucNang == 8) {
                sapXepThongTinSV();
                break;
            }
            else if (cacChucNang == 9) {
                gameFPOLYLOTT();
                break;
            }
            else if (cacChucNang == 10) {
                tinhPhanSo();
                break;
            }
            break;
        case 0:
            printf("Tro ve menu chinh. \n");
            break;
        default:
            printf("Lua chon khong hop le! Vui long chon 1 hoac 0. \n");
            continue;
        }
        flag1 = 0;
    }
}
int main()
{
    int choice;
    do {
        printf("\n------------- MENU -------------\n");
        printf("1. Kiem tra so nguyen\n");//Done
        printf("2. Uoc chung || Boi chung\n");//Done
        printf("3. Tinh tien Karaoke\n");//Done
        printf("4. Tinh tien dien\n");//Done
        printf("5. Doi tien\n");//Done
        printf("6. Tinh lai ngan hang\n");//Done
        printf("7. Vay tien mua xe\n");//Done
        printf("8. Sap xep thong tin sinh vien\n");//Done
        printf("9. Game FPOLY-LOTT\n");//Done
        printf("10. tinh phan so\n");//Done
        printf("0. Thoat chuong trinh\n");
        printf("--------------------------------\n");
        printf("\nMoi ban chon chuc nang: \n");
        scanf("%d", &choice);
        printf("--------------------------------\n");
        switch (choice) {
        case 1: kiemTraSoNguyen();
            break;
        case 2: uocChungBoiChung();
            break;
        case 3: tinhTienKaraoke();
            break;
        case 4: tinhTienDien();
            break;
        case 5: doiTien();
            break;
        case 6: tinhLaiNganHang();
            break;
        case 7: vayTienMuaXe();
            break;
        case 8: sapXepThongTinSV();
            break;
        case 9: gameFPOLYLOTT();
            break;
        case 10: tinhPhanSo();
            break;
        case 0: printf("Thoat chuong trinh.\n");
            break;
        default: printf("Lua chon khong hop le. Vui long chon lai [1-10] hoac 0 de thoat.\n");
            break;
        }
    } while (choice != 0);
}

// Debug/Run chuong trinh: bam "F5" hoac "Debug > Start Debugging" tren menu

// Danh cho nguoi moi bat dau:
//   1. Mo "View" > "Solution Explorer"
//          de them/quan ly cac files
//   2. Mo "View" > "Output"
//          de kiem tra "build output" va "cac thong bao khac"
//   3. Mo "View" > "Error List"
//          de xem loi
//   4. Chon Project > "Add" > "New Item"
//          de tao moi file code,
//      hoac Project > "Add" > "Existing Item"
//          de them file da ton tai vao project nay.
//   5. Sau nay, de mo lai project nay,
//          chon "File > Open > Project" va chon file *.sln
//      Co the xem thu muc project, noi luu file *.sln bang cach
//          trong cua so "Solution Explorer"
//          bam chuot phai vao "Solution"
//          chon "Open Folder in File Explorer"

// GV: AnhTT184