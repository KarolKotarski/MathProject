// MathsProject.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <conio.h>
#include <sstream>

using namespace std;



int main()
{
x:
	string matrixSizeString;
	double c;
	bool flag = false;
	cout << "Prosz\251 poda\206 ilo\230\206 rownan (n) od 1 do 20\n\n";
	//cout << "Proszę podać wielkość tablicy (n) od 1 do 20\n\n";
	cin >> matrixSizeString;
	system("cls");
	int matrixSize = atoi(matrixSizeString.c_str());
	if ((matrixSize <= 20) && (matrixSize >= 1))
	{
		//relokowanie pamięci na tablice
		double** tab = new double* [matrixSize];
		if (flag == false)
		{
			for (int i = 0; i < matrixSize; i++)
			{
				tab[i] = new double[matrixSize + 1];

			}

			cout << "Prawid\210owo. Teraz  prosz\251 podawa\206 kolejne elementy rownan:\n\n";

			for (int i = 0; i < matrixSize; i++)
			{
				cout << "\n\n";
				for (int j = 0; j < matrixSize + 1; j++)
				{
					tab[i][j] = 0;
					cout << tab[i][j] << "  ";
				}
			}
			for (int i = 0; i < matrixSize; i++)
			{
				cout << "\n";
				for (int j = 0; j < matrixSize + 1; j++)
				{
					cout << i + 1 << "x" << j + 1 << ":" << endl;
					cin >> tab[i][j];
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
			/*
			tab[0][0] = 3;
			tab[0][1] = 1;
			tab[0][2] = 1;
			tab[0][3] = 6;
			tab[1][0] = 2;
			tab[1][1] = -1;
			tab[1][2] = 3;
			tab[1][3] = 0;
			tab[2][0] = 1;
			tab[2][1] = 3;
			tab[2][2] = -1;
			tab[2][3] = 6;
			flag = true;
			*/
		}
		for (int k = 0; k < matrixSize; k++)
		{
			cout << "\n\n";
			for (int l = 0; l < matrixSize + 1; l++)
			{
				cout << tab[k][l] << "  ";
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
			cout << "\n\n";
			for (int l = 0; l < matrixSize + 1; l++)
			{
				cout << tab[k][l] << "  ";
			}
		}
		delete[] tab;
	}
	else
	{
		//cout << matrixSize << endl;
		cout << "Podano zly zakres\n";
		goto x;


	}
	//_getch();

	return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
