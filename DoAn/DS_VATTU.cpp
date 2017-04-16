#include "VATTU.h"
#include "DS_VATTU.h"

//tra ve vi tri cua 1 vat tu
int DS_VATTU::Search(string mavt)
{
	int i;
	for (i = 0; i < n; i++) {
		if(mavt == node[i].getMAVT())
			return i;
	}
	return -1;
}

int DS_VATTU::Full() {
	if (n == MaxSize) {
		return 0; //danh sach day
	}
	else {
		return 1; //danh sach chua day
	}
}

void DS_VATTU::Them() {
	if (n < MaxSize) {
		node[n].Nhap();
		n++;
	}
	else {
		cout << "\nDanh Sach Day";
	}
}

void DS_VATTU::Them(string mavt, string tenvt, int slt, string dvt)
{
	if (n < MaxSize) {
		node[n].setTENVT(tenvt);
		node[n].setMAVT(mavt);
		node[n].setDVT(dvt);
		node[n].setSLT(slt);
		n++;
	}
	else {
		cout << "\nDanh Sach Day";
	}
}

void DS_VATTU::XoaVT(string mavt) {
	for (int i = 0; i < n; i++) {
		if (node[i].getMAVT() != mavt) {
			cout << "\nKhong co ma vat tu " << mavt;
		}
		else {
			for (int j = i; j < n - 1; j++) {
				node[j] = node[j + 1];
			}
			n--;
		}
	}
}

void DS_VATTU::SuaVT(string ma_vt) {
	char LuaChon;
	string tenvt, mavt;
	for (int i = 0; i < n; i++) {
		if (node[i].getMAVT() == ma_vt) {
			bool KiemTraNhap = true;
			while (KiemTraNhap) {
				cout << "\n1. Sua MVT";
				cout << "\n2. Sua TENVT";
				cout << "\n0. Thoat";
				cout << "\nNhap vao lua chon: ";
				do {
					LuaChon = _getch();
					cout << LuaChon;
					if (LuaChon == '0' || LuaChon == '1' || LuaChon == '2') {
						switch (LuaChon) {
							case '1':
								cout << "\nNhap vao Ma Vat Tu moi: "; fflush(stdin); getline(cin, mavt); node[i].setMAVT(mavt); break;
							case '2':
								cout << "\nNhap vao Ten Vat Tu moi: "; fflush(stdin); getline(cin, tenvt); node[i].setTENVT(tenvt); break;
							case '0': KiemTraNhap = false;
						}
						break;
					}
				} while (true);
					
			}
		}
		else {
			cout << "\nKo co Vat tu do";
		}
	}
}

int DS_VATTU::SoLuongVT()
{
	return n;
}

void DS_VATTU::Xuat() {
	for (int i = 0; i < n; i++) {
		node[i].Xuat();
		//cout << "\n";
	}
}
DS_VATTU::DS_VATTU()
{

}


DS_VATTU::~DS_VATTU()
{

}
