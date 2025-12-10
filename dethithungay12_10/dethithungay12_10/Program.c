// CConsoleApplication.c : file nay chua 'main' function. 
// Chuong trinh phan mem Bat dau thuc thi & Ket thuc o day.

#include <stdio.h>
struct MonHoc {
	char ten[50];
	char maMon[50];
	int soTin;
};
void thongTinMonHoc(){
	struct MonHoc mh[100];
	int n;
	int hocPhi = 500000;
	printf("Moi ban nhap so luong mon hoc: ");
	scanf("%d", &n);
	
	
	for (int i = 0; i < n; i++) {
		printf("Moi nhap ten mon hoc: \n");
		while (getchar() != '\n');
		fgets(mh[i].ten, sizeof(mh[i].ten), stdin);
		printf("Moi ban nhap ma mon\n");
		//while (getchar() != '\n');
		fgets(mh[i].maMon, sizeof(mh[i].maMon), stdin);
		printf("Moi ban nhap so tin chi: \n");
		scanf("%d", &mh[i].soTin);
	}
	for (int i = 0; i < n; i++) {
		printf("Ten mon hoc: %s\n", mh[i].ten);
		printf("Ma mon hoc: %s\n", mh[i].maMon);
		printf("So tin chi: %d\n", mh[i].soTin);
		printf("Hoc phi cua mon hoc: %d\n", mh[i].soTin * hocPhi);
		
	}
	return 0;
}
void tinhTongSoLe(){
	int n;
	int tong = 0;
	printf("Moi ban nhap so n: \n");
	scanf("%d", &n);
	for (int i = 0; i <=n ; i++)
	{
		tong += i;
	}
	printf("Tong cac so tu 1 den %d la: %d\n", n, tong);
	if (n % 2 == 0) {
		printf("%d la so chan\n", n);
	}
	else {
		printf("%d la so le\n", n);
	}
}
struct SinhVien {
	char ten[50];
	int diem[3];
};
void thongTinDiemLab(){
	int soSV;
	struct SinhVien sv[100];
	printf("Moi ban nhap so sinh vien:\n");
	scanf("%d", &soSV);
	for (int i = 0; i < soSV; i++)
	{
		printf("Moi ban nhap ten sinh vien: \n");
		while (getchar() != '\n');
		fgets(sv[i].ten, sizeof(sv[i].ten), stdin);
		printf("Moi ban nhap diem: \n");
		scanf("%d", &sv[i].diem);
	}
	for (int i = 0; i < soSV; i++)
	{
		printf("Sinh vien thu: %d\n", i + 1);
		printf("Ten sinh vien thu %d: %s\n",i+1, sv[i].ten);
		printf("Diem sinh vien thu %d: %d\n", i + 1, sv[i].diem);
	}
};
int main()
{
	int choice, tiepTuc;
	do {
		printf("Menu:\n");
		printf("1. Thong tin mon hoc \n");
		printf("2. Tinh tong so le\n");
		printf("3. Thong tin diem lab\n");
		printf("0. Thoat\n");
		printf("Moi ban chon: \n");
		scanf("%d", &choice);
		tiepTuc = 1;
		while (tiepTuc == 1) {
		switch (choice) {
		case 1:thongTinMonHoc();
			break;
		case 2:tinhTongSoLe(); break;
		case 3:thongTinDiemLab(); break;
		case 0:break;
		default:
			printf("Moi nhap lai!\n");
			break;
		}
	}
	} while (choice != 1);
}

