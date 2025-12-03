// CConsoleApplication.c : file nay chua 'main' function. 
// Chuong trinh phan mem Bat dau thuc thi & Ket thuc o day.

#include <stdio.h>
#include <string.h>
void kiemTraSoNguyen() {
    menuPhu(1);
};
void uocChungBoiChung() {
    menuPhu(2);
};
void tinhTienKaraoke() {
    menuPhu(3);
};
void tinhTienDien() {
    menuPhu(4);
};
void doiTien() {
    menuPhu(5);
};
void tinhLaiNganHang() {
    menuPhu(6);
};
void vayTienMuaXe() {
    menuPhu(7);
};
void sapXepThongTinSV() {
    menuPhu(8);
};
void gameFPOLYLOTT() {
    menuPhu(9);
};
void tinhPhanSo() {
    menuPhu(10);
};
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
void tongMang() {
    int n;
    printf("Nhap so luong phan tu n: \n");
    scanf("%d", &n);
    int mang[100];
    for (int i = 0; i < n; i++) {
        printf("Moi ban nhap phan tu thu %d cua mang: \n", i);
        scanf("%d", &mang[i]);
    }
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += mang[i];
    }
    printf("Tong cac phan tu cua mang: %d \n", tong);
}
void nhapChuoi() {
    char ten[50];
    printf("Nhap ten cua ban: ");
    scanf("%s", &ten);
    getchar();
    //puts(ten);
    fgets(ten, sizeof(ten), stdin);
    ten[strcspn(ten, "\n")] = '\0';
    printf("Ten cua ban la: %s\n", ten);
    //gets(ten);
    //printf("Ten cua ban: %s", ten);
}
void demoMang() {
    int arr[2][3];
    for (int i = 0; i <2; i++)
    {
        for (int j = 0; j < 3; j++) {
            printf("Mang[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i <2; i++)
    {
        for (int j = 0; j < 3; j++) {
            printf("%d, ", arr[i][j]);
        }
        printf("\n");
    }
    
}
int main()
{
    int choice;
    do {
        printf("\n---------- MENU ----------\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. Uoc chung || Boi chung\n");
        printf("3. Tinh tien Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Doi tien\n");
        printf("6. Tinh lai ngan hang\n");
        printf("7. Vay tien mua xe\n");
        printf("8. Sap xep thong tin sinh vien\n");
        printf("9. Game FPOLY-LOTT\n");
        printf("10. tinh phan so\n");
        printf("11. tinh tong cac so trong mang\n");
        printf("0. Thoat chuong trinh\n");
        printf("--------------------------\n");
        printf("\nMoi ban chon chuc nang: \n");
        scanf("%d", &choice);
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
        case 11: nhapChuoi();
            break;
        case 12: demoMang();
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