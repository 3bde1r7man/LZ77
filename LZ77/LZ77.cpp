// Author : Abderlhman Mostafa
// v1.0
// FCAI - CU dept CS
// multimedia course

#include "LZ77.h"
LZ77C::LZ77C()
{
	cout << "Please enter the text to compresse : ";
	cin.ignore();
	getline(cin, originalStream, '\n');
	search = "";
	buffer = "";
	compression();
}

LZ77C::~LZ77C()
{
	printToFile();
}

void LZ77C::compression()
{
	tag t;
	// a loop that go thorught the original Stream
	for (int i = 0; i < originalStream.size(); i++)
	{
		// to make sure that the  search buffer window stay in 15 length
		while (search.size() < 15)
		{
			search += originalStream[i]; // add the new char to the search buffer
			int position = buffer.find(search); // to check if the search string is found in the buffer  if found return the position else return -1
			if (position == -1) { // if not found 
				t.setPosition(buffer.size() - buffer.find(search.substr(0 ,search.size()-1))); 
				t.setLength(search.size() - 1);
				if (t.getLength() == 0) {
					t.setPosition(0);
				}
				t.setNextChar(originalStream[i]);
				tags.push_back(t);
				// add the search to the buffer
				if (buffer.size() < 15 && buffer.size() + search.size()  <= 15) {
					buffer += search;
				}
				else // remove n char from the front off the buffer without lose any additional char  then add the search to the buffer
				{
					buffer = buffer.substr((search.size()- (15 - buffer.size())));
					buffer += search;
				}
				break;
			}
			// check if the hall buffer equal the search string and break to not  skip the next char
			else if (position != -1 && buffer.size() == search.size() && buffer.size() == 15) { 
				t.setPosition(15);
				t.setLength(15);
				t.setNextChar(originalStream[i + 1]);
				tags.push_back(t);
				break;
			}
			i++;
		}
		search = "";
		
	}

}


// print tags in form < P , L , N >
void LZ77C::printCs()
{
	for (int i = 0; i < tags.size(); i++)
	{
		cout << "< " << tags[i].getPosition() << " , " << tags[i].getLength() << " , " << tags[i].getNextChar() << " > ";
	}
	cout << '\n';
}

void LZ77C::printToFile()
{
	fstream myFile;
	myFile.open("Tags.txt", ios::out);
	for (int i = 0; i < tags.size(); i++) {
		myFile << tags[i].getPosition() << " " << tags[i].getLength() << " " << tags[i].getNextChar() << "\n";
	}
	myFile.close();
}

LZ77D::LZ77D()
{
	readFile();
	originalStream = "";
	decompress();
}

LZ77D::~LZ77D() 
{
	printToFile();
}
// read the Tags from the file
void LZ77D::readFile()
{
	fstream myFile;
	myFile.open("Tags.txt", ios::in);
	string temp;
	tag t;
	while (getline(myFile, temp))
	{
		stringstream tagLine(temp);
		string index;
		tagLine >> index;
		t.setPosition(stoi(index));
		tagLine >> index;
		t.setLength(stoi(index));
		tagLine >> index;
		t.setNextChar(index[0]);
		tags.push_back(t);
	}
	myFile.close();
}

void LZ77D::decompress()
{
	
	for (int i = 0; i < tags.size(); i++)
	{
		int P = tags[i].getPosition();
		int L = tags[i].getLength();
		char N = tags[i].getNextChar();
		// to not put a trash in the file
		if (N == '\0')
		{
			originalStream += originalStream.substr(originalStream.size() - P, L);
		}
		else
		{
			originalStream += originalStream.substr(originalStream.size() - P, L) + N;
		}
	}

}
// print in terminal
void LZ77D::printOs()
{
	cout << originalStream << '\n';
}
// print in file
void LZ77D::printToFile()
{
	fstream myFile;
	myFile.open("Text.txt", ios::out);
	myFile << originalStream << '\n';
	myFile.close();
}
