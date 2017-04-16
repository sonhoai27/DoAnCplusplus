#include "VATTU.h"
void VATTU::gotoxy_VATTU(short x, short y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x,y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void VATTU::Nhap() {
	cin.ignore();
	cout << "\nMa Vat Tu: ";
	fflush(stdin);
	getline(cin, MaVT);
	cout << "Ten Vat Tu: ";
	fflush(stdin);
	getline(cin, TenVT);
	cout << "Don Vi Tinh: ";
	fflush(stdin);
	getline(cin, DVT);
	cout << "So Luong Ton: ";
	cin >> SoLuongTon;
	cin.ignore();

}

void VATTU::Xuat() {
	gotoxy_VATTU(61, 12);
	cout << MaVT;
	gotoxy_VATTU(75 + 2, 12);
	cout << TenVT;
	gotoxy_VATTU(60 + 90 - 1 - 10 - 10 - 1, 12);
	cout << DVT;
	gotoxy_VATTU(60 + 90 - 1 - 10, 12);
	cout << SoLuongTon;
}

//get
string VATTU::getMAVT() {
	return MaVT;
}

string VATTU::getTENVT() {
	return TenVT;
}

string VATTU::getDVT() {
	return DVT;
}

int VATTU::getSLT() {
	return SoLuongTon;
}

//set
void VATTU::setMAVT(string x) {
	MaVT = x;
}

void VATTU::setTENVT(string x) {
	TenVT = x;
}

//truyen x de thay doi, cap nhat (+, -) so luong ton, de tao thanh so luong ton moi.

void VATTU::setSLT(int x) {
	SoLuongTon = x;
}

void VATTU::setDVT(string x) {
	DVT = x;
}

VATTU::VATTU()
{
}


VATTU::~VATTU()
{

}

//them ham search de xu ly nhap vao vat tu, đối với mã vật tư
//vi du nhapp vao 5, trong luc do tim vao kho co 4, no se hien len bang thong bao, con 4, co muon lay khong.