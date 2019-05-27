//#include "pch.h"
#include <iostream>
#include <stdio.h>     
#include <stdlib.h>
#include <conio.h>
#include <sstream>
#include <random>
#include <Windows.h>

using namespace std;

int main()
{
x:
	using namespace std;

	string matrixSizeString;
	double c;
	bool flag = false;
	int tryb = 0;
	int lower = 0, upper = 0;
	double lower_bound = 0, upper_bound = 0;
	cout << "Prosz\251 poda\206 ilo\230\206 rowna\344\n";

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
		//relokowanie pamięci na tablice
		double** tab = new double* [matrixSize];
		double** tab2 = new double* [matrixSize];
		double* wekt = new double[matrixSize];
		double* wekt2 = new double[matrixSize];
		if (flag == false)
		{
			for (int i = 0; i < matrixSize; i++)
			{
				tab[i] = new double[matrixSize + 1];
				tab2[i] = new double[matrixSize + 1];
			}

			cout << "Prawid\210owo. Teraz  prosz\251 podawa\206 kolejne elementy r\242wna\344:\n\n";

			cout << "Prosz\251 wybra\206 tryb wprowadzania" << endl;
			cout << "1 - liczby dziesi\251tne" << endl;
			cout << "2 - u\210amki zwyk\210e" << endl;
			cout << "3 - warto\230ci losowe" << endl;
			cout << "4 - warto\230ci losowe ca\210kowite" << endl;

			cin >> tryb;

			if (tryb == 3)
			{
				cout << "Prosz\251 wprowadzi\206 zakres losowania liczb" << endl;
				cin >> lower_bound >> upper_bound;
				system("cls");
			}
			else if (tryb == 4)
			{
				cout << "Prosz\251 wprowadzić\206 zakres losowania liczb" << endl;
				cin >> lower >> upper;
				system("cls");
			}

			for (int i = 0; i < matrixSize; i++)
			{
				cout << "\n\n";
				for (int j = 0; j < matrixSize + 1; j++)
				{
					tab[i][j] = 0;
					wekt[i] = 0;
					cout << tab[i][j] << "  ";
				}
			}
			for (int i = 0; i < matrixSize; i++)
			{
				cout << "\n";
				for (int j = 0; j < matrixSize + 1; j++)
				{
					cout << i + 1 << "x" << j + 1 << ":" << endl;

					if (tryb == 1)
					{
					y:						double a;
						cin >> a;

						if (cin.fail())
						{
							cin.clear();
							cin.ignore();
							//goto y;
						}
						else
						{
							tab[i][j] = a;
						}

					}
					else if (tryb == 2)
					{
						double a, b;
						cin >> a;
						cout << endl;
						cin >> b;
						tab[i][j] = a / b;
					}
					else if (tryb == 3)
					{
						uniform_real_distribution<double> unif(lower_bound, upper_bound);
						random_device rand_dev;
						mt19937 rand_engine(rand_dev());

						double x = unif(rand_engine);
						std::cout << x << std::endl;
						int a = 5;
						tab[i][j] = unif(rand_engine);
					}
					else if (tryb == 4)
					{
						tab[i][j] = rand() % upper + lower;
					}

					system("cls");
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
			//tworzenie kopii macierzy początkowej
			//tab2 = tab;

			cout << endl;
			flag = true;
		}


		for (int k = 0; k < matrixSize; k++)
		{
			cout << "\n\n";
			for (int l = 0; l < matrixSize + 1; l++)
			{
				cout << tab[k][l] << "  ";
			}
		}

		for (int k = 0; k < matrixSize; k++)
		{
			for (int l = 0; l < matrixSize + 1; l++)
			{
				tab2[k][l] = tab[k][l];
			}
		}
		cout << endl;

		//obliczanie macierzy
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
						cout << "\n\n";
						for (int jj = 0; jj < matrixSize + 1; jj++)
						{
							cout << tab[ii][jj] << "  ";
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
						cout << "\n\n";
						for (int jj = 0; jj < matrixSize + 1; jj++)
						{
							cout << tab[ii][jj] << "  ";
						}
					}
					cout << endl;
				}
			}
		}

		cout << "\n\n" << "nowa macierz:";
		for (int k = 0; k < matrixSize; k++)
		{
			//b wejściowe
			cout << "\n\n";
			for (int l = 0; l < matrixSize + 1; l++)
			{


				if (l != matrixSize)
				{
					cout << tab[k][l] << "  ";
				}
				else
				{
					HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
					WORD wOldColorAttrs;
					CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
					GetConsoleScreenBufferInfo(h, &csbiInfo);
					wOldColorAttrs = csbiInfo.wAttributes;
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
					cout << tab[k][l] << "  ";
					SetConsoleTextAttribute(h, wOldColorAttrs);
				}

			}
		}
		for (int k = 0; k < matrixSize; k++)
		{
			//b wejściowe
			cout << "\n\n";
			for (int l = 0; l < matrixSize + 1; l++)
			{


				if (l != matrixSize)
				{
					cout << tab2[k][l] << "  ";
				}
				else
				{
					HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
					WORD wOldColorAttrs;
					CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
					GetConsoleScreenBufferInfo(h, &csbiInfo);
					wOldColorAttrs = csbiInfo.wAttributes;
					SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					cout << tab2[k][l] << "  ";
					SetConsoleTextAttribute(h, wOldColorAttrs);
				}

			}
		}

		cout << "Błędy" << endl;

		for (int k = 0; k < matrixSize; k++)
		{
			wekt2[k] = tab[k][matrixSize];
		}

		for (int k = 0; k < matrixSize; k++)
		{
			for (int l = 0; l < matrixSize; l++)
			{
				wekt[k] += tab2[k][l] * wekt2[l];
			}

			cout << wekt[k] << endl;
		}
		delete[] tab;
		delete[] tab2;
	}
	else
	{
		//cout << matrixSize << endl;
		cout << "Podano zly zakres\n";
		//goto x;


	}


	_getch();

	return 0;
}


