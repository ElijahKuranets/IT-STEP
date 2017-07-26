#include "CrosswordSolver.h"

std::vector<std::string> dict;
std::unordered_map<std::string, std::string> map;

//std::ifstream in;
void CrosswordSolver::getAllwithLen() {
	int number;

	std::cout << "Введите чиселко: ";
	std::cin >> number;

	std::ofstream out("NEW_Lopatin_dictionary.txt");
	std::string line;
	for (auto& el : dict) {
		if (el.length() == number) {
			//std::cout  << el << std::endl;

			out << el << std::endl;
		}
	}
}
void CrosswordSolver::getAllWithInit() {
	char letter;

	std::cout << "Введите буковку: ";
	std::cin >> letter;

	for (auto& el : dict) {
		if (el[0] == letter) {
			std::cout << el << std::endl;

			//out << el << std::endl;
		}

	}
}
void CrosswordSolver::findByMask() {
	setlocale(LC_ALL, "Russian ");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::string word;
	std::vector<std::string> dictionary;
	std::string pattern;
	std::ifstream dictInput;
	dictInput.open("Lopatin_dictionary.txt");
	std::ofstream out("NEW_Lopatin_dictionary.txt");
	if (!dictInput) {
		std::cerr << "Unable to open file" << std::endl;
		exit(1);
	}


	int n = 0;
	while (dictInput >> word) {
		dictionary.push_back(word);
		if (n++ % 10000 == 0) {
			//std::cout << '.';
		}
		//std::cout<<std::endl;
	}
	//std::cout << std::endl << "Dictionary size = " << n << std::endl;
	std::cout << "Введите словечко с вопросами, например с?д: " << std::endl;
	while (std::cin >> pattern) {
		int numberOfMatches = 0;
		for (int i = 1; i<n; i++) {
			if (match(pattern, dictionary[i])) {
				std::cout << "Найдено: " << dictionary[i] << std::endl;
				numberOfMatches++;
			}
		}
		std::cout << "Введите другое слово с опросами, например д?н?р " << std::endl;
	}
}
void CrosswordSolver::getAnagrams() {
	std::string tmp;
	std::cout << "Введите словечко для анаграммы ";
	std::ifstream in("Lopatin_dictionary.txt");
	while (in >> tmp) {
		std::string sort_tmp = tmp;
		sort(sort_tmp.begin(), sort_tmp.end());
		map[tmp] = sort_tmp;
	}
	std::string word;
	std::cin >> word;
	sort(word.begin(), word.end());
	for (auto& el : map) {
		if (word == el.second) { std::cout << el.first << std::endl; }
	}



};

CrosswordSolver::CrosswordSolver()
{
	std::ifstream in("Lopatin_dictionary.txt");
	if (!in.is_open()) 	std::cout << "error";
	//std::ofstream out("NEW_Lopatin_dictionary.txt");

	std::string line;
	while (in >> line) {
		dict.push_back(line);
	}
	in.close();
}
CrosswordSolver::~CrosswordSolver() {}


bool CrosswordSolver::match(std::string pat, std::string w) {
	int len = pat.size();
	if (w.size() != len)  return false;

	for (int i = 0; i<len; i++) {
		if (pat[i] != '?') {
			if (pat[i] != w[i]) {
				return false;
			}
		}
	}
	return true;
}

//void CrosswordSolver::findByBigMask(std::string word)
//{
//	std::vector<std::string> words;
//	std::string woord = "";
//	std::vector<std::string> answer;
//	for (int i = 0; i < word.size() - 1; ++i)
//		woord += word[i];
//	std::ifstream in("Lopatin_dictionary.txt");
//	std::string temp;
//	while (in >> temp)
//	{
//		if (temp.length() >= woord.length())
//			words.push_back(temp);
//	}
//	in.close();
//	for (int i = 0; i < words.size(); ++i)
//	{
//		bool flag = true;
//		for (int j = 0; j < woord.size(); ++j)
//		{
//			if (woord[j] != words[i][j])
//				flag = false;
//		}
//		if (flag)
//			answer.push_back(words[i]);
//	}
//	for (int x = 0; x < answer.size(); ++x)
//		std::cout << answer[x] << std::endl;
//}

