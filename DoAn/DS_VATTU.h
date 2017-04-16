#pragma once
#include "VATTU.h"
class DS_VATTU
{
private:
	int n = 0;//soluong
	VATTU node[MaxSize];
public:
	int Search(string mavt); //tim vat tu
	int Full();
	void Them();
	void Them(string mavt, string tenvt, int slt, string dvt);
	void Xuat();
	void XoaVT(string mavt);
	void SuaVT(string mavt);
	int SoLuongVT();
	DS_VATTU();
	~DS_VATTU();
	friend class DS_HOADON;
};

