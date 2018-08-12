#include <iostream>
#include <conio.h>
using namespace std;

struct CauThu
{
	char HoTen[50];
	char ViTri[50];
	int SoAo;
};

void Input(CauThu a[])
{
	for (int i = 0; i < 11; i++)
	{
		cout << "\nCAU THU THU " << i + 1;
		cout << "\n   Ho va ten: ";
		cin.ignore(1);
		gets_s(a[i].HoTen);
		cout << "   Vi tri: ";
		cin.ignore(1);
		gets_s(a[i].ViTri);
		cout << "   So ao: ";
		cin >> a[i].SoAo;
		int key = 0;
		do {
			for (int j = i - 1; j >= 0; j--)
				if (a[j].SoAo == a[i].SoAo)
				{
					cout << "So ao bi trung. Vui long nhap lai: ";
					cin >> a[i].SoAo;
					key = 0;
				}
			for (int j = i - 1; j >= 0; j--)
				if (a[j].SoAo == a[i].SoAo)
					key = 1;
		} while (key == 1);
	}
}

void Output(CauThu a[])
{
	for (int i = 0; i < 11; i++)
	{
		cout << "\nCAU THU THU " << i + 1;
		cout << "\n   Ho ve ten: ";
		puts(a[i].HoTen);
		cout << "   Vi tri: ";
		puts(a[i].ViTri);
		cout << "   So ao: " << a[i].SoAo;
		cout << endl;
	}
}

void Swap(CauThu &a, CauThu &b)
{
	CauThu t = a;
	a = b;
	b = t;
}

void InterchangeSort(CauThu a[])
{
	int i, j;
	for (i = 0; i < 10; i++)
		for (j = i + 1; j < 11; j++)
			if (a[i].SoAo > a[j].SoAo)
				Swap(a[i], a[j]);
}

int LinearSearch(CauThu a[])
{
	int i = 0;
	while ((i < 11) && (a[i].SoAo != 15) && (a[i].SoAo != 20)) i++;
	if (i == 11)
		return -1;
	return i;
}

void Menu()
{
	cout << "\n=======================   MENU   ======================\n";
	cout << "1.  Nhap, xuat thong tin cua 11 cau thu trong doi bong.\n";
	cout << "2.  Sap xep thu tu tang dan cac cau thu theo so ao.\n";
	cout << "3.  Tim nhung cau thu co so ao 15 hoac 20.\n";
	cout << "0.  Thoat\n";
	cout << "=======================================================\n";
}

int ChooseMenu(int &key)
{
	int menu;
	cout << "\nChon cong viec: ";
	cin >> menu;
	if (menu >= 0 && menu <= 3)
		if (menu != 1 && key == 0)
		{
			cout << "Chua co du lieu. Vui long thuc hien (1) truoc.\n\n";
			key++;
			system("pause");
			return 1;
		}
		else
		{
			key++;
			return menu;
		}
	else
	{
		do {
			cout << "Nhap sai. Vui long nhap lai: ";
			cin >> menu;
		} while (menu < 0 || menu > 3);
		if (menu != 1 && key == 0)
		{
			cout << "Chua co du lieu. Vui long thuc hien (1) truoc.\n\n";
			key++;
			system("pause");
			return 1;
		}
		else
		{
			key++;
			return menu;
		}
	}
}

void Process(CauThu a[], int &key)
{
	int choose = ChooseMenu(key);
	switch (choose)
	{
	case 1:
		system("cls");
		cout << "\nNHAP CAC THONG TIN CAU THU\n";
		Input(a);
		cout << "\nCAC THONG TIN CAU THU VUA NHAP\n";
		Output(a);
		cout << endl;
		system("pause");
		break;
	case 2:
		system("cls");
		cout << "\nSAP XEP CAC CAU THU THEO SO AO TANG DAN\n";
		InterchangeSort(a);
		Output(a);
		cout << endl;
		system("pause");
		break;
	case 3:
	{
		system("cls");
		cout << "\nTIM KIEM CAU THU CO SO AO 15 HOAC 20\n";
		int t = LinearSearch(a);
		if (t == -1) cout << "\nKhong tim thay.\n";
		else
		{
			cout << "\nCAU THU THU " << t + 1;
			cout << "\n   Ho ve ten: ";
			puts(a[t].HoTen);
			cout << "   Vi tri: ";
			puts(a[t].ViTri);
			cout << "   So ao: " << a[t].SoAo;
			cout << endl;
		}
		cout << "\n";
		system("pause");
		break;
	}
	case 0:
		exit(1);
	}
}

void main()
{
	CauThu a[10];
	int key = 0;
	while (1)
	{
		system("cls");
		Menu();
		Process(a, key);
	}
}