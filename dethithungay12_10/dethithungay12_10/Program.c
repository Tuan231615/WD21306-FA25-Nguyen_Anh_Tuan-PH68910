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

void thongTinDiemLab(){
	int soSV;
	float diem[100];
	float tong = 0;
	float tbc;

	printf("Moi ban nhap so sinh vien:\n");
	scanf("%d", &soSV);
	if (soSV>0)
	{
		for (int i = 0; i < soSV; i++)
		{
			printf("Moi ban nhap diem lab cua sinh vien: %d\n", i + 1);
			scanf("%f", &diem[i]);
		}
		printf("Danh sach diem lab cua sinh vien: \n");
		for (int i = 0; i < soSV; i++)
		{
			printf("Diem lab cua sinh vien %d la: %.2lf\n", i + 1, diem[i]);
		}
		for (int i = 0; i < soSV; i++)
		{
			tong += diem[i];
		}
		tbc = tong / soSV;
		printf("Diem trung binh cua lop la: %.2f\n", tbc);
		float max;
		for (int i = 0; i < soSV; i++)
		{
			max = diem[0];
				if (diem[i]> max) {
					max = diem[i];
			}
		}
		printf("Diem lab cao nhat cua lop la: %.2f\n", max);
		int flag = 0;
		for (int i = 0; i < soSV; i++)
		{
			if (diem[i] >= 5) {
				flag++;
			}
		}
		printf("So sinh vien dat diem lon hon 5: %d\n", flag);
	}
	else {
		printf("So sinh vien khong hop le!\n");
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
			case 2:tinhTongSoLe(); 
				break;
			case 3:thongTinDiemLab();
				break;
			case 0:
				printf("Thoat chuong trinh!\n");
				return 0;
			default:
				printf("Moi nhap lai!\n");
				break;
			}
			printf("Ban co muon tiep tuc khong? (1: Co, 0: Khong)");
			scanf("%d", &tiepTuc);
			if (tiepTuc != 1) {
				break;
			}
		}
	} while (choice != 0);
}

