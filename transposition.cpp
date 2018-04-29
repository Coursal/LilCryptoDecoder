#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void transposition()
{
	ifstream crypted_file("encr_transposition.txt", ios::in);		//file with the encrypted text
	ofstream output_file("output.txt", ios::out);					//file with the key pairs' generated decrypted text

	string file_line;
	string buffer;
	string message;

	int flag=0;
	int inverted_a=0;
	

    if(crypted_file.good())				//if the file opening returns no errors...
    {	
    	while(!crypted_file.eof())				//scan the file to the end
    	{
    		getline(crypted_file, file_line);	//copy each line of the file

    		message+=file_line;					//and add it to the message
		}	
	}
	
	crypted_file.close();
	
	for(int i = 0; i < message.length(); i++)	//turn message text from lower to uppercase
       message[i] = toupper(message[i]);


	char letter_table[message.length()/4+1][4];		//table to have the encrypted text divided to four columns
	
	buffer=message;

	
	for(int a=0; a<4; a++)							//generate 4-number key
		for(int b=0; b<4; b++)
			for(int c=0; c<4; c++)
				for(int d=0; d<4; d++)
					if(!(a==b || a==c || a==d || b==c || b==d || c==d))		//key must have 4 unique numbers 0-3
					{
						output_file<<a+1<<" "<<b+1<<" "<<c+1<<" "<<d+1<<endl;
		
						/*
						because the encrypted message is irregular for columnar transposition,
						(170 characters that do not completely fill 4 columns for 2 letters)
						the next if's insert two spaces to the two last columns based on the
						generated key {abcd}
						*/
		
						if(a>1 && b>1)														
						{																
							buffer.insert(buffer.begin()+(1*buffer.length()/4),' ');
							buffer.insert(buffer.begin()+(2*buffer.length()/4),' ');
						}
						else if(a>1 && c>1)
						{
							buffer.insert(buffer.begin()+(1*buffer.length()/4),' ');
							buffer.insert(buffer.begin()+(3*buffer.length()/4),' ');

						}
						else if(a>1 && d>1)
						{
							buffer.insert(buffer.begin()+(1*buffer.length()/4),' ');
							buffer.insert(buffer.begin()+(4*buffer.length()/4),' ');

						}
						else if(b>1 && c>1)
						{
							buffer.insert(buffer.begin()+(2*buffer.length()/4),' ');
							buffer.insert(buffer.begin()+(3*buffer.length()/4),' ');

						}
						else if(b>1 && d>1)
						{
							buffer.insert(buffer.begin()+(2*buffer.length()/4),' ');
							buffer.insert(buffer.begin()+(4*buffer.length()/4),' ');

						}
						else if(c>1 && d>1)
						{
							buffer.insert(buffer.begin()+(3*buffer.length()/4),' ');
							buffer.insert(buffer.begin()+(4*buffer.length()/4),' ');
						}


						for(int j=0, k=0;j<4;j++)						//divide the message by columns
						{
							for(int i=0;i<message.length()/4+1;i++)
							{
								letter_table[i][j]=buffer[k];
								k++;
							}	
						}

						for(int i=0;i<message.length()/4+1;i++)			//print the message decrypted by the generated key on the output file, one character by column at a time
						{
							output_file<<letter_table[i][a]<<letter_table[i][b]<<letter_table[i][c]<<letter_table[i][d];
						}
						
						output_file<<endl;

						
						buffer=message;									//clean the buffer from the previous spaces based on the generated key
					}
	

	output_file.close();	
}
