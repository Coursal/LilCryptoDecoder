#include <iostream>

#include "affine.cpp"
#include "transposition.cpp"

using namespace std;

int main(int argc, char** argv)
{
	int choice;
	
	cout<<"==========================================================="<<endl;
	cout<<"====================Lil' Crypto Decoder===================="<<endl;
	cout<<"==========================================================="<<endl;
	cout<<"==      1. Affine Cipher Decryption                      =="<<endl;
	cout<<"==      2. Transposition Cipher Decryption               =="<<endl;
	cout<<"==========================================================="<<endl;
	
	cout<<endl;
	cout<<'\t'<<"Choice: ";
	cin>>choice;
	cout<<endl;
	cout<<"==========================================================="<<endl;
	
	switch(choice)
	{
		case 1:
				affine();
				cout<<"==          Affine Cipher's guesses @ output.txt         =="<<endl;
				break;
		case 2:
				transposition();
				cout<<"==      Transposition Cipher's guesses @ output.txt      =="<<endl;
				break;
		default:
				cout<<"==                     Wrong Choice.                     =="<<endl;
				cout<<"==              Abrupt Exit in 3...2...1...              =="<<endl;
	}
	
	cout<<"==========================================================="<<endl;

	return 0;
}
