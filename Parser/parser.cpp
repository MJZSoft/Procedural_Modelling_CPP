#include "parser.h"
extern vector<string> startParsing(FILE*);

Parser::Parser(string filePath){
	// open a file handle to a particular file:
	this->myfile = fopen(filePath.c_str(), "r");
	// make sure it's valid:
	if (!this->myfile) {
		cout << "I can't open the urbanmodel.zoo file!" << endl;
	}
};

vector<string> Parser::parse(){
	if(this->myfile)
		this->tokens = startParsing(myfile);
	return this->tokens;
};

void Parser::printTokens(){
	int size = this->tokens.size();
	for(int i=0;i<size;i++)
		cout<<this->tokens[i];
	cout<<std::endl;
};
