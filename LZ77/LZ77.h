#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
class tag {
private:
	int position, length;
	char nextChar;
public:
	void setPosition(int p) { position = p;}
	void setLength(int l) { length = l;}
	void setNextChar(char c) { nextChar = c;}
	int getPosition() { return position; }
	int getLength() { return length; }
	char getNextChar() { return nextChar; }
};

class LZ77C
{
public:
	LZ77C();
	void compression();
	void printCs();
private:
	string buffer, search, originalStream;
	vector<tag> tags;

};



