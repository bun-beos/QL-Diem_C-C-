#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

struct hocSinh
{
    int id;
	char ten[30];
	int tuoi;
	char gioiTinh[5];
	float diemToan;
	float diemVan;
	float diemAnh;
	float diemKHTN;
	float diemKHXH;
	float diemTB = 0;
	char hocLuc[10] = "-";
};
typedef hocSinh HS;

void themHS (HS a[], int m, int n);
void hienThiDS (HS a[], int n);
int xoaHS (HS a[], int id, int n);
void capNhapDiemHS (HS a[], int id);
void timKiemHS (HS a[], char ten[]);
void sapXepTheoTen (HS a[], int n);
void sapXepTheoDiemTB (HS a[], int n);
void ghiFile (HS a[], int n);
int docFile (HS a[]);
void tiepTuc ();

int main() {
	HS a[50];
	int k;
	int soLuong = docFile(a);
	while (true) {
		cout << "*********** Quan ly diem hoc sinh ***********\n";
		cout << "* 1. Them hoc sinh moi                      *\n";
		cout << "* 2. Hien thi danh sach hoc sinh            *\n";
		cout << "* 3. Cap nhap diem cho hoc sinh             *\n";
		cout << "* 4. Xoa hoc sinh khoi danh sach            *\n";
		cout << "* 5. Tim kiem thong tin hoc sinh theo ten   *\n";
		cout << "* 6. Sap xep danh sach theo diem TB         *\n";
		cout << "* 7. Ghi danh sach hoc sinh vao file        *\n";
		cout << "* 0. Thoat                                  *\n";
		cout << "*********************************************\n";
		cout << "Chon chuc nang: ";
		cin >> k;
		switch(k) {
			case 1:
				cout << "Them hoc sinh.\n";
				int n;
				cout << "Nhap so luong hoc sinh muon them: "; cin >> n;
				themHS(a, soLuong, n);
				soLuong += n;
				tiepTuc();
				break;
			case 2:
				if (soLuong > 0) {
					cout << "Danh sach hoc sinh:\n";
					hienThiDS(a, soLuong);
				}
				else cout << "Danh sach trong!\n" ;
				tiepTuc();
				break;
			case 3:
				if (soLuong > 0) {
					cout << "Cap nhap diem.\n";
					int id;
					cout << "Nhap id: "; cin >> id;
					capNhapDiemHS(a, id);
				}
				else 
					cout << "Danh sach trong!\n" ;
				tiepTuc();
				break;
			case 4:
				if (soLuong > 0) {
					cout << "Xoa hoc sinh.\n";
					int id;
					cout << "Nhap id: "; cin >> id;
					if (xoaHS(a, id, soLuong))
						soLuong--;
					ghiFile(a, soLuong);
				}
				else 
					cout << "Danh sach trong!\n" ;
				tiepTuc();
				break;
			case 5:
				if (soLuong > 0) {
					cout << "Tim kiem hoc sinh.\n";
					char ten[30];
					cout << "Nhap ten: "; 
					fflush(stdin);
					gets(ten);
					timKiemHS(a, ten);
				}
				else 
					cout << "Danh sach trong!\n" ;
				tiepTuc();
				break;
			case 6:
				if (soLuong > 0) {
					cout << "Sap xep danh sach theo diem trung binh.\n";
					cout << "Thanh cong!\n";
					sapXepTheoDiemTB(a, soLuong);
				}
				else 
					cout << "Danh sach trong!\n" ;
				tiepTuc();
				break;
			case 7:
				if (soLuong > 0) {
					cout << "Ghi danh sach vao file.\n";
					sapXepTheoTen(a, soLuong);
					ghiFile(a, soLuong);
					cout << "Thanh cong!\n";
				}
				else {
					cout << "Danh sach trong!\n" ;
				}
				tiepTuc();
				break;
			case 0:
				cout << "Nhan phim bat ky de thoat.\n";
				getch();
				return 0;
				break;
			default:
				cout << "Khong hop le. Vui long chon lai.\n";
				tiepTuc();
				break;
		}
	}
}

inline float tinhDiemTB (HS &hs) {
	return hs.diemTB = (hs.diemToan + hs.diemVan + hs.diemAnh + hs.diemKHTN + hs.diemKHXH) / 5.0;
}

void xepLoaiHS (HS &hs) {
	if (hs.diemTB >= 8.0) strcpy(hs.hocLuc, "Gioi");
	else if (hs.diemTB >= 6.5 && hs.diemTB < 8.0) strcpy(hs.hocLuc, "Kha");
	else if (hs.diemTB >= 5.0 && hs.diemTB < 6.5) strcpy(hs.hocLuc, "T.Binh");
	else strcpy(hs.hocLuc, "Yeu");
}

void themHS (HS a[], int m, int n) {
	for (int i = 0; i < n; i++) {
		printf("\nNhap thong tin hoc sinh thu %d:\n", i + 1);
		cout << "Nhap id hoc sinh: "; cin >> a[i + m].id;
		cout << "Nhap ten: "; fflush(stdin); gets(a[i + m].ten);
		cout << "Nhap tuoi: "; cin >> a[i + m].tuoi;
		cout << "Nhap gioi tinh: "; cin >> a[i + m].gioiTinh;
		cout << "Nhap diem Toan: "; cin >> a[i + m].diemToan;
		cout << "Nhap diem Van: "; cin >> a[i + m].diemVan;
		cout << "Nhap diem Anh: "; cin >> a[i + m].diemAnh;
		cout << "Nhap diem KHTN: "; cin >> a[i + m].diemKHTN;
		cout << "Nhap diem KHXH: "; cin >> a[i + m].diemKHXH;
		tinhDiemTB(a[i + m]);
		xepLoaiHS(a[i + m]);
	}
}

inline void inDong () {
	for (int i = 0; i < 21; i++) cout << "--------";
	cout << endl;
}

inline void inTieuDe () {
	inDong();
	cout << setw(5) << left << "|STT" << setw(11) << left << "|ID" 
		 << setw(25) << left << "|Ho va ten" << setw(10) << left << "|Tuoi" << setw(15) << left << "|Gioi tinh"
		 << setw(15) << left << "|Diem Toan" << setw(15) << left << "|Diem Van" << setw(15) << left << "|Diem Anh"
		 << setw(15) << left << "|Diem KHTN" << setw(15) << left << "|Diem KHXH" << setw(15) << left << "|Diem TB" << setw(10) << left << "|Hoc luc   |" << endl;
}

void hienThiDS (HS a[], int n) {
	inTieuDe();
	for(int i = 0; i < n; i++) {
		inDong();
		cout << "|"  << setw(4) << left << i + 1  << "|" << setw(10) << left << a[i].id  << "|" << setw(24) << left << a[i].ten
			 << "|" << setw(9) << left << a[i].tuoi  << "|" << setw(14) << left << a[i].gioiTinh;
		cout << "|" << setw(14) << left << setprecision(1) << fixed << a[i].diemToan;
		cout << "|" << setw(14) << left << setprecision(1) << fixed << a[i].diemVan;
		cout << "|" << setw(14) << left << setprecision(1) << fixed << a[i].diemAnh;
		cout << "|" << setw(14) << left << setprecision(1) << fixed << a[i].diemKHTN;
		cout << "|" << setw(14) << left << setprecision(1) << fixed << a[i].diemKHXH
			 << "|" << setw(14) << left << a[i].diemTB  << "|" << setw(9) << left << a[i].hocLuc << " |" << endl;
	}
	inDong();
}

int xoaHS (HS a[], int id, int n) {
	int check = 0;
	for(int i = 0; i < n; i++) {
		if(a[i].id == id) {
			check = 1;
			for(int j = i; j < 50; j++)
				a[j] = a[j + 1];
			cout << "Da xoa xong!\n";
			break;
		}
	}
	if (check == 0) cout << "Hoc sinh khong co trong danh sach!\n";
	return check;
}

void capNhapDiemHS (HS a[], int id) {
	int check = 0;
	for(int i = 0; i < 50; i++) {
		if(a[i].id == id) {
			check = 1;
			cout << "Cap nhap diem hoc sinh:\n";
			cout << "Nhap diem Toan: "; cin >> a[i].diemToan;
			cout << "Nhap diem Van: "; cin >> a[i].diemVan;
			cout << "Nhap diem Anh: "; cin >> a[i].diemAnh;
			cout << "Nhap diem KHTN: "; cin >> a[i].diemKHTN;
			cout << "Nhap diem KHXH: "; cin >> a[i].diemKHXH;
			tinhDiemTB(a[i]);
			xepLoaiHS(a[i]);
			cout << "Cap nhap thanh cong!\n";
			break;
		}
	}
	if(check == 0) cout << "Hoc sinh khong co trong danh sach!\n";
}

void timKiemHS (HS a[], char ten[]) {
	HS ds[50];
	int dem = 0;
	for(int i = 0; i < 50; i++) {
		char ten1[30];
		strcpy(ten1, a[i].ten);
		if(strstr(strupr(ten1), strupr(ten))) {
			ds[dem] = a[i];
			dem++;
		}
	}
	if (dem == 0) cout << "Khong tim thay hoc sinh.\n";
    else hienThiDS(ds, dem);
}

void tachTen (char x[], char ten[]) {
	for (int i = strlen(x) - 1; i >= 0; i--) 
		if (x[i] == ' ') {
			strcpy(ten, x + i + 1);
			break;
		}
}

void tachHo (char x[], char ho[]) {
	for (int i = 0; i < strlen(x); i++)
		if (x[i] == ' ') {
			for (int j = 0; j < i; j++)
				ho[j] = x[j];
			break;
		}
}

void sapXepTheoTen (HS a[], int n) {
	int m = n - 1;
	for (int i = 0; i < m; i++) 
		for (int j = i + 1; j < n; j++) {
			char ten1[10] = "", ten2[10] = "";
			tachTen(a[i].ten, ten1);
			tachTen(a[j].ten, ten2);
			if (strcmp(ten1, ten2) > 0) 
				swap(a[i], a[j]);
			else if (strcmp(ten1, ten2) == 0) {
				char ho1[10] = "", ho2[10] = "";
				tachHo(a[i].ten, ho1);
				tachHo(a[j].ten, ho2);
				if (strcmp(ho1, ho2) > 0) 
					swap(a[i], a[j]);
			}
	}
}

void sapXepTheoDiemTB (HS a[], int n) {
	int m = n - 1;
	for (int i = 0; i < m; i++) 
		for (int j = i + 1; j < n; j++) {
			if (a[j].diemTB < a[i].diemTB) 
				swap(a[i], a[j]);
	}
}

void ghiFile (HS a[], int n) {
	FILE *fptr;
	fptr = fopen("QL_Diem.txt", "w");
	for (int i = 0; i < n; i++) {
		fprintf(fptr, "%s\n", a[i].ten);
		fprintf(fptr, "%10d%5d%10s%10f%10f%10f%10f%10f%10f%10s\n\n", a[i].id, a[i].tuoi, a[i].gioiTinh, 
				a[i].diemToan, a[i].diemVan, a[i].diemAnh, a[i].diemKHTN, a[i].diemKHXH, a[i].diemTB, a[i].hocLuc); 
	}
	fclose(fptr);
}

int docFile (HS a[]) {
	FILE *fptr;
	int i = 0;
	fptr = fopen("QL_Diem.txt", "r");
	while (fscanf(fptr, "%[^\n]", a[i].ten)) {
		if (fscanf(fptr,"%10d%5d%10s%10f%10f%10f%10f%10f%10f%10s\n", &a[i].id, &a[i].tuoi, &a[i].gioiTinh, 
	 			&a[i].diemToan, &a[i].diemVan, &a[i].diemAnh, &a[i].diemKHTN, &a[i].diemKHXH, &a[i].diemTB, &a[i].hocLuc) != EOF)
			i++;
		else break; 
	}
	cout << "\nSo luong hoc sinh trong file la: " << i << endl;
	cout << endl;
	fclose(fptr);
	return i;
}

void tiepTuc () {
	cout << "Nhan phim bat ky de tiep tuc!\n";
	getch();
	system("cls"); 
}