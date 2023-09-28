#include <iostream>

using namespace std;

#define MIN_N 1
#define MAX_N 100

int main()
{
	int n;

	cout << "n = "; cin >> n;

	if (n < MIN_N || n > MAX_N)
	{
		cout << "Eroare valoare n\n";
		return 1;
	}
	
	int i, j, a[n][n];

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	}

	// Verificati daca matricea este inferior triunghiulara
	// (toate elementele de deasupra diagonalei principale sunt nule)

	bool ok = 1;
	int k;
	
	for (k = 1, i = 0; i < n && ok; i++, k++)
	{
		for (j = k; j < n && ok; j++)
		{
			if (a[i][j])
			{
				ok = 0;
			}
		}
	}

	if (ok)
	{
		cout << "matricea este inferior triunghiulara\n";
	}
	else
	{
		cout << "matricea nu este inferior triunghiulara\n";
        }

	// Verificati daca matricea este simetrica fata de diagonala principala
	
	for (ok = k = 1, i = 0; i < n-1 && ok; i++)
	{
		for (j = k; j < n && ok; j++)
		{
			if (a[i][j] != a[j][i])
			{
				ok = 0;
			}
		}
	}

	if (ok)
	{
		cout << "matricea este simetrica fata de diagonala principala\n";
	}
	else
	{
		cout << "matricea nu este simetrica fata de diagonala principala\n";
	}

	// Calculati suma elementelor impare de sub diagonala secundara
	
	int suma = 0;

	for (i = 1; i < n; i++)
	{
		for (j = n-1; j >= n-i; j--)
		{
			if (a[i][j] % 2)
			{
				suma += a[i][j];
			}
		}
	}

	cout << "suma elementelor impare de sub diagonala secundara = " << suma << "\n";

	// Determinati sumele elementelor de pe chenarele concentrice ale matricei
		
	cout << "suma elementelor de pe chenarele concentrice ale matrice: ";

	int st, dr;

	for (st = 0 , dr = n-1; st <= dr; st++, dr--)
	{
		suma = 0;

		if (st == dr)
		{
			suma = a[st][dr];
		}
		else
		{
			for (i = st; i <= dr; i++)
			{
				suma += a[i][st] + a[i][dr];
			}

			for (j = st+1; j <= dr-1; j++)
			{
				suma += a[st][j] + a[dr][j];
			}
		}
		
		cout << suma << " ";
	}

	cout << "\n";

	return 0;
}
