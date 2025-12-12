// CConsoleApplication.c : file nay chua 'main' function. 
// Chuong trinh phan mem Bat dau thuc thi & Ket thuc o day.

#include <stdio.h>
struct ThuCung {
    char ma[100];
    char ten[100];
    int namSinh;

};
void thongTinThuCung(){
    struct ThuCung tc[100];
    for (int i = 0; i < 3; i++)
    {
        printf("Moi ban nhap ma thu cung thu %d: \n", i+1);
        while (getchar() != '\n');
        fgets(tc[i].ma, sizeof(tc[i].ma), stdin);
        printf("Moi ban nhap ten thu cung: \n");
        fgets(tc[i].ten, sizeof(tc[i].ten), stdin);
        printf("Moi ban nhap nam sinh thu cung: \n");
        scanf("%d", &tc[i].namSinh);
    }
    for (int i = 0; i < 3; i++)
    {
        printf("Ma thu cung thu %d: %s\n", i + 1, tc[i].ma);
        printf("Ten thu cung thu %d: %s\n", i + 1, tc[i].ten);
        printf("Nam sinh thu cung thu %d: %d\n", i + 1, tc[i].namSinh);
        printf("Tuoi cua thu cung thu %d: %d\n", i + 1, 2025 - tc[i].namSinh);
    }
    
}
void tinhTong(int n) {
    int tong = 0;
    for (int i = 0; i < n; i++)
    {if(i%2==0)
        tong += i;
    }
    printf("Tong cac so le tu 1 den %d la: %d\n", n, tong);
    
        if (n % 5 == 0) {
            printf("%d chia het cho 5\n", n);
        }
        else {
            printf("%d khong chia het cho 5\n", n);
        }
}
void thongTinCuaHang() {
    int soLuong;
    float cannang[100];
    float tongCan = 0;
    float min;
    float tbc = 0;
    int flag = 0;
    printf("Moi nhap so luong thu cung:\n");
    scanf("%d", &soLuong);
    for (int i = 0; i < soLuong; i++)
    {
        printf("Moi nhap can nang thu cung thu %d: \n", i+1);
        scanf("%f", &cannang[i]);
    }
    for (int i = 0; i < soLuong; i++)
    {
        min = cannang[0];
        printf("Can nang thu cung thu %d: %.2f\n", i + 1, cannang[i]);
        tongCan += cannang[i];
        if (min > cannang[i]) {
            min = cannang[i];
        }
    }
    tbc = (float)tongCan / soLuong;
    printf("Can nang trung binh: %.2f\n", tbc);
    printf("Can nang cua thu cung nho nhat: %.2f\n", min);
    for (int i = 0; i < soLuong; i++)
    {
        if (cannang[i] < tbc) {
            flag++;
        }
    }
    printf("So thu cung duoi can nang trung binh: %d\n", flag);
}
int main()
{
    int choice;
    int n;
    do {
        printf("Menu\n");
        printf("1. Thong tin thu cung\n");
        printf("2.Tinh tong\n");
        printf("3.Thong tin cua hang\n");
        printf("0. Thoat\n");
        printf("Moi ban chon: \n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:thongTinThuCung();
            break;
        case 2:
            printf("Moi ban nhap so: \n");
            scanf("%d", &n);
                tinhTong(n);
            break;
        case 3: thongTinCuaHang();
            break;
        case 0:
            return 0;
        defalut:
            printf("Loi nhap\n");
            break;
        }
    } while (choice != 0);
}

