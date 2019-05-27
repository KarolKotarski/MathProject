#include "pch.h"
#include <iostream>
#include <stdio.h>     
#include <stdlib.h>
#include <conio.h>
#include <sstream>
#include <random>
#include <Windows.h>
#include <iomanip>


int main()
{
x:
	using namespace std;
	string matrixSizeString;
	long double c;
	bool flag = false, q1 = false, q2 = false;
	int tryb = 0, lower = 0, upper = 0, response = 0;
	long double lower_bound = 0, upper_bound = 0;
	cout << "Prosz\251 poda\206 ilo\230\206 r\242wna\344\n";

	try
	{
		cin >> matrixSizeString;
	}
	catch (int e)
	{
		cout << e;
	}

	system("cls");
	int matrixSize = atoi(matrixSizeString.c_str());
	if (matrixSize >= 1)
	{
		//alokacja pamięci na tablice
		long double** tab = new long double*[matrixSize];
		long double** tab2 = new long double*[matrixSize];
		long double* wekt = new long double[matrixSize];
		long double* wekt2 = new long double[matrixSize];
		long double* wektEW = new long double[matrixSize];
		long double* wektEB = new long double[matrixSize];

		if (flag == false)
		{
			for (int i = 0; i < matrixSize; i++)
			{
				tab[i] = new long double[matrixSize + 1];
				tab2[i] = new long double[matrixSize + 1];
			}

			cout << "Prosz\251 wybra\206 tryb wprowadzania" << endl;
			cout << "1 - liczby dziesi\251tne" << endl;
			cout << "2 - u\210amki zwyk\210e" << endl;
			cout << "3 - warto\230ci losowe rzeczywiste" << endl;
			cout << "4 - warto\230ci losowe ca\210kowite" << endl;

			cin >> tryb;

			if (tryb == 1 || tryb == 2)
			{
				cout << "Teraz  prosz\251 podawa\206 kolejne elementy r\242wna\344:\n\n";

			}
			else if (tryb == 3)
			{
				cout << "Prosz\251 wprowadzi\206 zakres losowania liczb" << endl;
				cin >> lower_bound >> upper_bound;
				system("cls");
			}
			else if (tryb == 4)
			{
				cout << "Prosz\251 wprowadzi\206 zakres losowania liczb" << endl;
				cin >> lower >> upper;
				system("cls");
			}

			cout << "Czy wy\230wietli\206 macierze? tak - 1, nie - 0" << endl;
			cin >> response;
			if (response == 1) q1 = true;

			cout << "Czy wy\230wietli\206 wizualizacj\251 przekszta\210cania macierzy?  tak - 1, nie - 0" << endl;
			cin >> response;
			if (response == 1) q2 = true;

			//inicjalizacja zerami
			for (int i = 0; i < matrixSize; i++)
			{
				for (int j = 0; j < matrixSize + 1; j++)
				{
					tab[i][j] = 0;
					wekt[i] = 0;
				}
			}

			for (int i = 0; i < matrixSize; i++)
			{
				cout << "\n";
				for (int j = 0; j < matrixSize + 1; j++)
				{
					if (tryb == 1)
					{
					y:	
						cout << i + 1 << "x" << j + 1 << ":" << endl;
						long double a;
						cin >> a;

						if (cin.fail())
						{
							cin.clear();
							cin.ignore();
							goto y;
						}
						else
						{
							tab[i][j] = a;
						}

					}
					else if (tryb == 2)
					{
						cout << i + 1 << "x" << j + 1 << ":" << endl;
						long double a, b;
						cin >> a;
						cin >> b;
						tab[i][j] = a / b;
					}
					else if (tryb == 3)
					{
						uniform_real_distribution<long double> unif(lower_bound, upper_bound);
						random_device rand_dev;
						mt19937 rand_engine(rand_dev());
						long double x = unif(rand_engine);
						tab[i][j] = unif(rand_engine);
					}
					else if (tryb == 4)
					{
						tab[i][j] = rand() % upper + lower;
					}

					system("cls");

					if (q1 == true)
					{
						for (int k = 0; k < matrixSize; k++)
						{
							cout << "\n\n";
							for (int l = 0; l < matrixSize + 1; l++)
							{
								cout << tab[k][l] << "  ";
							}
						}
					}

				}
			}

			cout << endl;
			flag = true;
		}

		//zapamiętanie macierzy przed rozpoczęciem przekształcania
		for (int k = 0; k < matrixSize; k++)
		{
			for (int l = 0; l < matrixSize + 1; l++)
			{
				tab2[k][l] = tab[k][l];
			}
		}

		//przekształcanie macierzy
		for (int j = 0; j < matrixSize; j++)
		{
			for (int i = 0; i < matrixSize; i++)
			{
				if (i != j)
				{
					c = tab[i][j] / tab[j][j];

					for (int k = 0; k < matrixSize + 1; k++)
					{
						tab[i][k] = tab[i][k] - c * tab[j][k];

					}
					for (int ii = 0; ii < matrixSize; ii++)
					{
						if (q2 == true) cout << "\n\n";
						for (int jj = 0; jj < matrixSize + 1; jj++)
						{
							if (q2 == true) cout << tab[ii][jj] << "  ";
						}
					}
					cout << endl;
				}

			}
		}

		for (int j = 0; j < matrixSize; j++)
		{
			for (int i = 0; i < matrixSize; i++)
			{
				if (i == j)
				{
					tab[i][matrixSize] /= tab[i][j];
					tab[i][j] = 1;
					for (int ii = 0; ii < matrixSize; ii++)
					{
						if (q2 == true) cout << "\n\n";
						for (int jj = 0; jj < matrixSize + 1; jj++)
						{
							if (q2 == true) cout << tab[ii][jj] << "  ";
						}
					}
				}
			}
		}

		if (q2 == true) cout << "\n\n" << "nowa macierz:";
		for (int k = 0; k < matrixSize; k++)
		{
			if (q2 == true) cout << "\n\n";
			for (int l = 0; l < matrixSize + 1; l++)
			{
				if (l != matrixSize)
				{
					if (q2 == true) cout << tab[k][l] << "  ";
				}
				else
				{
					HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
					WORD wOldColorAttrs;
					CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
					GetConsoleScreenBufferInfo(h, &csbiInfo);
					wOldColorAttrs = csbiInfo.wAttributes;
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
					if (q2 == true) cout << tab[k][l] << "  ";
					SetConsoleTextAttribute(h, wOldColorAttrs);
				}
			}
		}

		//b wejściowe
		for (int k = 0; k < matrixSize; k++)
		{
			wekt2[k] = tab[k][matrixSize];
		}

		//b obliczone
		for (int k = 0; k < matrixSize; k++)
		{
			for (int l = 0; l < matrixSize; l++)
			{
				wekt[k] += tab2[k][l] * wekt2[l];
			}
		}

		//błąd bezwzględny
		for (int k = 0; k < matrixSize; k++)
		{
			wektEB[k] = abs(tab2[k][matrixSize] - wekt[k]);
		}

		long double maxB = wektEB[0];

		for (int k = 0; k < matrixSize; k++)
		{
			if (wektEB[k] > maxB) maxB = wektEB[k];
		}

		//błąd względny
		for (int k = 0; k < matrixSize; k++)
		{
			wektEW[k] = abs(wektEB[k] / tab2[k][matrixSize]);
		}

		long double maxW = wektEW[0];

		for (int k = 0; k < matrixSize; k++)
		{
			if (wektEW[k] > maxW) maxW = wektEW[k];
		}

		cout << endl << "B\210\251dy" << endl << endl;
		cout << "B\210\245d bezwzgl\251dny: " << scientific << maxB << endl;
		cout << "B\210\245d wzgl\251dny: " << scientific << maxW << endl;

		//
		for (int i = 0; i < matrixSize;i++)
		{
			delete tab[i];
			delete tab2[i];
		}

		delete[] tab;
		delete[] tab2;
		delete[] wekt;
		delete[] wekt2;
		delete[] wektEB;
		delete[] wektEW;
	}
	else
	{
		cout << "Podano z\210y zakres\n" << endl;
		goto x;
	}

	_getch();

	return 0;
}


