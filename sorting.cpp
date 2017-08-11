// sorting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class ObjectArrey
{
private:
	int *mas;
	int Flg, FlgSpc, n, k;
	
public:
	/*ObjectArrey(int *mas, char *CharMas)
	{	
		setDate(mas,CharMas);
	}*/
	int *masNumber;
	int SIZE = 1;
	void setDate(int *mas, char *CharMas) // convert a string to a number
	{
		Flg = 0;
		FlgSpc=0;
		k = 0;
		for (int i = 0; i < (int)strlen(CharMas); i++)
		{
				if (CharMas[i] != ' ')
				{
					FlgSpc = 0;
					n = NULL;
					n = CharMas[i] & 0x0F;
					if (Flg <= 0)
					{
						mas[i - k] = n;
					}
					if (Flg > 0)
					{
						mas[i - k - Flg] = mas[i - k - Flg] * 10 + n;
					}
					Flg++;
				}
				else
				{
					if (i <= 0 || FlgSpc > 0) { k++; }
					if (i > 0 && FlgSpc <= 0) { k = k + Flg; Flg = 0; SIZE++; }
					FlgSpc++;
				}
		}
		masNumber = new int[SIZE];
		for (int i = 0; i < SIZE; i++)
		{
			masNumber[i] = mas[i];
		}
	}
	void BubbleSort() // Bubble Sort
	{
		int i,buff;
		bool exit = false;
		while (!exit) 
		{
			exit = true;
			for (i = 0; i < SIZE-1; i++)
			{
				if (masNumber[i] > masNumber[i + 1])
				{
					buff = masNumber[i];
					masNumber[i] = masNumber[i + 1];
					masNumber[i + 1] = buff;
					exit = false;
				}
			}
		}
	}
	void getDate() // Print result
	{
		for (int i = 0; i < SIZE; i++)
		{
				std::cout << masNumber[i] << " ";
		}
		std::cout << "\nPress any key to continue..." << std::endl;
		std::cin.get();
	}
};


int main()
{
	system("cls");
	int jSIZE = 256;
	char *CharMas;
	int *mas;
	CharMas = new char[jSIZE];
	mas = new int[jSIZE];
	ObjectArrey Obj;
	std::cout << "Please input elements of array (separated by spaces): " << std::endl;
	 //cin.ignore();
	std::cin.getline(CharMas, jSIZE);
	
	bool error;
	for (int i = 0; i < (int)strlen(CharMas); i++)
	{
		if ((CharMas[i] >= '0' && CharMas[i] <= '9') || CharMas[i]==' ') //checking numbers or letters
		{
			error = false;
		}
		else 
		{
			std::cout << "\nERROR:not all elements are numbers" << std::endl;
			std::cout << "\nPress any key to continue..." << std::endl;
			std::cin.get();
			error = true;
			break;
		}
	}
	if (!error)
	{
		Obj.setDate(mas, CharMas);
		Obj.BubbleSort();
		Obj.getDate();
	}
	delete[] CharMas; delete[] mas;
	return 0;
}

