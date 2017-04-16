#pragma once
#include "VATTU.h"
#include "DS_VATTU.h"
class HOADON
{
private:
	int NgHienTai();
	void SetBGColor_HOADON(WORD color);
	void gotoxy_HOADON(short x, short y);
	void VeMau();
	void coutChar(int code);
	void SetColor_HOADON(WORD color);
public:
	int SoHD, NgLapHD;
	char Loai;
	DS_VATTU DsCon;
	int static AutoNumber;
	void Nhap(); //truyen vao ds kho, kho 
	void Xuat(); //xuat to hoa don ra
	HOADON();
	~HOADON();
};

