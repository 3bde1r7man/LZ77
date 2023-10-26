// Author : Abderlhman Mostafa
// v1.0
// FCAI - CU dept CS
// multimedia course


#include "LZ77.h"
int main() {
	while (true)
	{
		cout << "1- Comperess\n";
		cout << "2- Decompress\n";
		cout << "3- Exit\n";
		cout << ">> ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			LZ77C comp;
			comp.printCs();
			break;
		}
		case 2:
		{
			LZ77D decomp;
			decomp.printOs();
			break;
		}
		case 3:
			exit(0);
		default:
			cout << "Please enter a valid input!!\n";
			break;
		}
	}
	
	
}

// some test cases for lz77 comperation
// ababbaabbbbbabaaab : < 0 , 0 , a > < 0 , 0 , b > < 2 , 2 , b > < 5 , 1 , a > < 4 , 2 , b > < 7 , 3 , b > < 9 , 2 , a > < 14 , 1 ,  >

// abcdefghijklmnoabcdefghijklmno : < 0 , 0 , a > < 0 , 0 , b > < 0 , 0 , c > < 0 , 0 , d > < 0 , 0 , e > < 0 , 0 , f > < 0 , 0 , g > < 0 , 0 , h > < 0 , 0 , i > < 0 , 0 , j > < 0 , 0 , k > < 0 , 0 , l > < 0 , 0 , m > < 0 , 0 , n > < 0 , 0 , o > < 15 , 15 ,  >
// this is bad 
// abcdefghijklmnopabcdefghijklmnop : < 0 , 0 , a > < 0 , 0 , b > < 0 , 0 , c > < 0 , 0 , d > < 0 , 0 , e > < 0 , 0 , f > < 0 , 0 , g > < 0 , 0 , h > < 0 , 0 , i > < 0 , 0 , j > < 0 , 0 , k > < 0 , 0 , l > < 0 , 0 , m > < 0 , 0 , n > < 0 , 0 , o > < 0 , 0 , p > < 0 , 0 , a > < 0 , 0 , b > < 0 , 0 , c > < 0 , 0 , d > < 0 , 0 , e > < 0 , 0 , f > < 0 , 0 , g > < 0 , 0 , h > < 0 , 0 , i > < 0 , 0 , j > < 0 , 0 , k > < 0 , 0 , l > < 0 , 0 , m > < 0 , 0 , n > < 0 , 0 , o > < 0 , 0 , p > 
