#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
class tag {
public:
	void setPosition(int p) { position = p; }
	void setLength(int l) { length = l; }
	void setNextChar(char c) { nextChar = c; }
	int getPosition() { return position; }
	int getLength() { return length; }
	char getNextChar() { return nextChar; }
private:
	int position, length;
	char nextChar;
};

class LZ77C
{
public:
	LZ77C();
	~LZ77C();
	void compression();
	void printCs();
	void printToFile();
private:
	string buffer, search, originalStream;
	vector<tag> tags;
	
};

class LZ77D
{
public:
	LZ77D();
	

private:
	string originalStream;
	vector<tag> tags;
};




