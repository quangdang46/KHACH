#include <bits/stdc++.h>
using namespace std;

struct DaiLy
{
	char TenDaily[30];
	char SDT[11];
	int DoanhThu;
	DaiLy *Tiep;
};
struct ThanhPho
{
	char TenThanhPho[30];
	ThanhPho *Next;
	DaiLy *Down;
};
void NhapDanhSachThanhPho(ThanhPho *&DSThanhPho)
{
	ThanhPho *p, *q;
	char TenThanhPho[30];
	cout << "Nhap ten thanh pho: ";
	fflush(stdin);
	gets(TenThanhPho);
	while (strcmp(TenThanhPho, "0") != 0)
	{
		p = new ThanhPho;
		strcpy(p->TenThanhPho, TenThanhPho);
		p->Next = NULL;
		p->Down = NULL;
		if (DSThanhPho == NULL)
			DSThanhPho = p;
		else
			q->Next = p;
		q = p;
		cout << "Nhap ten thanh pho: ";
		fflush(stdin);
		gets(TenThanhPho);
	}
}
void NhapDanhSachDaiLy(DaiLy *&DSDaiLy)
{
	DaiLy *p, *q;
	char TenDaily[30], SDT[11];
	int DoanhThu;
	cout << "Nhap ten dai ly: ";
	fflush(stdin);
	gets(TenDaily);
	while (strcmp(TenDaily, "0") != 0)
	{
		p = new DaiLy;
		strcpy(p->TenDaily, TenDaily);
		cout << "Nhap SDT: ";
		fflush(stdin);
		gets(SDT);
		strcpy(p->SDT, SDT);
		cout << "Nhap doanh thu: ";
		cin >> DoanhThu;
		p->DoanhThu = DoanhThu;
		p->Tiep = NULL;
		if (DSDaiLy == NULL)
			DSDaiLy = p;
		else
			q->Tiep = p;
		q = p;
		cout << "Nhap ten dai ly: ";
		fflush(stdin);
		gets(TenDaily);
	}
}
void NhapDanhSach(ThanhPho *&DSThanhPho)
{
	ThanhPho *p;
	p = DSThanhPho;
	while (p != NULL)
	{
		cout << "Nhap danh sach dai ly cua thanh pho " << p->TenThanhPho << endl;
		NhapDanhSachDaiLy(p->Down);
		p = p->Next;
	}
}
void XuatDanhSachDaiLy(DaiLy *DSDaiLy)
{
	DaiLy *p;
	p = DSDaiLy;
	while (p != NULL)
	{
		cout << setw(30) << p->TenDaily << setw(11) << p->SDT << setw(11) << p->DoanhThu << endl;
		p = p->Tiep;
	}
}
void XuatDanhSachThanhPho(ThanhPho *DSThanhPho)
{
	ThanhPho *p;
	p = DSThanhPho;
	while (p != NULL)
	{
		cout << "Danh sach dai ly cua thanh pho " << p->TenThanhPho << endl;
		XuatDanhSachDaiLy(p->Down);
		p = p->Next;
	}
}
void XuatDanhSach(ThanhPho *DSThanhPho)
{
	ThanhPho *p;
	p = DSThanhPho;
	while (p != NULL)
	{
		cout << "Danh sach dai ly cua thanh pho " << p->TenThanhPho << endl;
		XuatDanhSachDaiLy(p->Down);
		p = p->Next;
	}
}

void HoanViThanhPho(ThanhPho *&p, ThanhPho *&q)
{
	ThanhPho *temp;
	temp = p;
	p = q;
	q = temp;
}
void HoanViDaiLy(DaiLy *&p, DaiLy *&q)
{
	DaiLy *temp;
	temp = p;
	p = q;
	q = temp;
}
// sap xep thanh pho
void SapXepThanhPho(ThanhPho *&DSThanhPho)
{
	ThanhPho *p, *q;
	p = DSThanhPho;
	while (p != NULL)
	{
		q = p->Next;
		while (q != NULL)
		{
			if (strcmp(p->TenThanhPho, q->TenThanhPho) > 0)
				HoanViThanhPho(p, q);
			q = q->Next;
		}
		p = p->Next;
	}
}
// sap xep dai ly
void SapXepDaiLy(DaiLy *&DSDaiLy)
{
	DaiLy *p, *q;
	p = DSDaiLy;
	while (p != NULL)
	{
		q = p->Tiep;
		while (q != NULL)
		{
			if (p->DoanhThu > q->DoanhThu)
				HoanViDaiLy(p, q);
			q = q->Tiep;
		}
		p = p->Tiep;
	}
}
// sap xep danh sach
void SapXepDanhSach(ThanhPho *&DSThanhPho)
{
	ThanhPho *p;
	p = DSThanhPho;
	while (p != NULL)
	{
		SapXepThanhPho(DSThanhPho);
		SapXepDaiLy(p->Down);
		p = p->Next;
	}
}

int main()
{
	ThanhPho *DSThanhPho = NULL;
	NhapDanhSachThanhPho(DSThanhPho);
	NhapDanhSach(DSThanhPho);
	SapXepDanhSach(DSThanhPho);
	XuatDanhSach(DSThanhPho);
	return 0;
}
