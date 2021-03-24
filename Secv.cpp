#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <windows.h>;

using namespace std;

void main()

{
	//FILE *f;
	int i, j, l;
	int m, n, p;
	long int a[100][100], b[100][100], c[100][100];
	SYSTEMTIME time1, time2;

	//f= fopen("intrare_matrici.txt","r");

	//fscanf(f,"%d %d",&m,&n);
	//fscanf(f,"%d %d",&n,&p);

	cout << "m="; cin >> m;
	cout << "n="; cin >> n;
	cout << "p="; cin >> p;

	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
		{
			//fscanf(f,"%d",&a[i][j]);
			a[i][j] = rand() % 10 + 1;
		}
	for (i = 0; i < n; i++)
		for (j = 0; j < p; j++)
		{
			//fscanf(f,"%d",&b[i][j]);
			b[i][j] = rand() % 10 + 1;
		}

	for (i = 0; i < m; i++)
		for (j = 0; j < p; j++)
			c[i][j] = 0;

	GetLocalTime(&time1);

	int hour1 = time1.wHour;
	int minute1 = time1.wMinute;
	int seconds1 = time1.wSecond;
	int miliseconds1 = time1.wMilliseconds;

	int dif1 = seconds1 * 1000 + miliseconds1;

	for (i = 0; i < m; i++)
		for (j = 0; j < p; j++)
		{
			for (l = 0; l < n; l++)
				c[i][j] = c[i][j] + a[i][l] * b[l][j];
		}

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < p; j++)
			cout << c[i][j] << " ";
		cout << endl;
	}

	GetLocalTime(&time2);
	int hour2 = time2.wHour;
	int minute2 = time2.wMinute;
	int seconds2 = time2.wSecond;
	int miliseconds2 = time2.wMilliseconds;

	int dif2 = seconds2 * 1000 + miliseconds2;

	cout << endl << "timpul de desfasurare este de " << dif2 - dif1 << " ";
	//fclose(f);
	system("pause");

}
