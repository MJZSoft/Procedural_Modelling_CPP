#include <iostream>
#include <vector>
#include <cstdio>
#include "scanner.h"
using namespace std;

class Parser{
	private:
	FILE* myfile;
	vector<string> tokens;
	public:
		Parser(string filePath);
		vector<string> parse();
		void printTokens();
};
