#include "DS_HOADON.h"
#include <iostream>
#include<stdlib.h>
using namespace std;
PTR DS_HOADON::newnode() {
	PTR p = new NODES_DSHOADON;
	return p;
}

void DS_HOADON::InsertLast() {
	PTR p = newnode();
	p->next = NULL; //danh sach chua co gi nen phai tro p->next = null, vi tri cuoi.
	if (contro == NULL) {
		p->info.Nhap();
		contro = p; //neu first mà bang null thi gan p vao;
	}
	else
	{
		PTR last;
		for (last = contro; last->next != NULL; last = last->next);
		p->info.Nhap();
		last->next = p;
	}
	XuLyHOADON();
}

void DS_HOADON::XuatDSHOADON()
{
	PTR p = contro;
	if (p == NULL) {
		cout << "\nKo co phan tu nao.";
	}
	while (p != NULL) {
		p->info.Xuat();
		cout<< "\n";
		p = p->next;
		//thuc hien toi khi nao gap gia tri null
	}
}

void DS_HOADON::XuLyHOADON()
{
	PTR p = contro;
	if (p == NULL) {
		cout << "\nHien tai khong co hoa don de xu ly: \n";
	}
	else
	{
		while (p->next != NULL)
			p = p->next;
		if (p->info.Loai == 'N')
		{
			int i = 0;
			while (i < p->info.DsCon.SoLuongVT()) // duyet tung VT trong DS con cua Hoa don
			{
				int ViTriTrongKho = KhoXuLy->Search(p->info.DsCon.node[i].getMAVT());
				if (ViTriTrongKho >= 0)
				{
					int SltMoi = KhoXuLy->node[ViTriTrongKho].getSLT() + p->info.DsCon.node[i].getSLT();
					KhoXuLy->node[ViTriTrongKho].setSLT(SltMoi);
				}
				else
				{
					string DVT = p->info.DsCon.node[i].getDVT();
					string TenVT = p->info.DsCon.node[i].getTENVT();
					string MaVT = p->info.DsCon.node[i].getMAVT();
					int SoLuongTon = p->info.DsCon.node[i].getSLT();
					KhoXuLy->Them(TenVT, MaVT, SoLuongTon, DVT);
				}
				i++;
			}
		}
		else
		{
			int i = 0;
			while (i < p->info.DsCon.SoLuongVT())
			{
				int ViTriTrongKho = KhoXuLy->Search(p->info.DsCon.node[i].getMAVT());
				if (ViTriTrongKho >= 0)
				{
					int SltMoi = KhoXuLy->node[ViTriTrongKho].getSLT() - p->info.DsCon.node[i].getSLT();
					if (SltMoi >= 0)
						KhoXuLy->node[ViTriTrongKho].setSLT(SltMoi);
					else
					{
						cout << "So luong ton kho hien tai co ma: ";
						cout << KhoXuLy->node[ViTriTrongKho].getMAVT();
						cout << "(" << KhoXuLy->node[ViTriTrongKho].getSLT() << ") ";
						cout<<"thap hon so luong ban can cua ma("<< p->info.DsCon.node[i].getMAVT()<<" )"<<endl;
						cout << "Ban co muon xuat lay vat tu nay khong? (Y/N): ";
						while (true)
						{
							char BatChu = _getch();
							if (BatChu == 'y' || BatChu == 'Y')
							{
								int SoLuongMuonLay = 0;
								string tempSLML; //khai bao bien tam luu c;
								do {
									cout << "\bBan nhap so luong muon lay <= " << KhoXuLy->node[ViTriTrongKho].getSLT() << ": ";
									while (true) {
										char biendem = _getch();
										if (biendem >= '0' && biendem <= '9') {
											cout << biendem;
											tempSLML += biendem;
										}
										else {
											if (biendem == 13) {
												break;
											}
										}
									}
									SoLuongMuonLay = atoi(tempSLML.c_str()); //chuyen tu string to number

									//thông báo cho người dùng biết là lấy ra số lượng trong kho
									if (SoLuongMuonLay > SoLuongMuonLay > KhoXuLy->node[ViTriTrongKho].getSLT()) {
										cout << "\nBan lay vuot qua so luong trong kho";
									}

								} while (SoLuongMuonLay > KhoXuLy->node[ViTriTrongKho].getSLT() || SoLuongMuonLay == 0); //kiem tra SoLUongMuonLay nhap vao co be hon hoac bang so luong co trong kho khong
								
								p->info.DsCon.node[i].setSLT(SoLuongMuonLay); //set so luong muon lay khi so luong muon lay ban dau lon hon kho
								KhoXuLy->node[ViTriTrongKho].setSLT(KhoXuLy->node[ViTriTrongKho].getSLT() - SoLuongMuonLay);
								break;
							}
							if (BatChu == 'n' || BatChu == 'N')
							{
								string mavt_temp = p->info.DsCon.node[i].getMAVT();
								p->info.DsCon.XoaVT(mavt_temp);
								i--;
								break;
							}
						}
					}
				}
				else
				{
					string mavt_temp = p->info.DsCon.node[i].getMAVT();
					p->info.DsCon.XoaVT(mavt_temp);
					cout << "Khong tim thay ma vat tu '" << mavt_temp << "' can xuat ra" << endl;
					continue;
				}
				i++;
			}
		}
	}
}


DS_HOADON::DS_HOADON(DS_VATTU &kho) {
	contro = NULL;
	KhoXuLy = &kho;
}

DS_HOADON::~DS_HOADON() {
	if (contro == NULL) {
		delete contro;
	}
}
