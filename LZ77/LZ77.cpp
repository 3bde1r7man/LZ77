// Author : Abderlhman Mostafa
// v1.0
// FCAI - CU dept CS
// multimedia course

#include "LZ77.h"
LZ77C::LZ77C()
{
	cout << "Please enter the text to compresse : ";
	getline(cin, originalStream);
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
		myFile << "< " << tags[i].getPosition() << " , " << tags[i].getLength() << " , " << tags[i].getNextChar() << " >\n";
	}
	myFile.close();
}

LZ77D::LZ77D()
{
}