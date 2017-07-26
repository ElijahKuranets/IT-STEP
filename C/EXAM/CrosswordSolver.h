#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <locale>
#include "windows.h"

class CrosswordSolver
{
	
public:
	CrosswordSolver();
	~CrosswordSolver();
	void getAllwithLen();
	void getAllWithInit();	
	void findByMask();
	//void findByBigMask(std::string);
	void getAnagrams();
	bool match(std::string pat, std::string w);

	

}; 
