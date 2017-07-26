#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale>
#include "windows.h"
#include "CrosswordSolver.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	CrosswordSolver cs;
	cs.getAllwithLen();
	cs.getAllWithInit();
	cs.getAnagrams();
	cs.findByMask();
	return 0;
}
