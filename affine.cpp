#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void affine()
{
	ifstream crypted_file("encr_affine.txt", ios::in);		//file with the encrypted text
	ofstream output_file("output.txt", ios::out);			//file with the key pairs' generated decrypted text

	string file_line;
	string buffer;
	string possible_message;
	
	int flag=0;
	int inverted_a=0;
	

    if(crypted_file.good())				//if the file opening returns no errors...
    {	
    	while(!crypted_file.eof())				//scan the file to the end
    	{
    		getline(crypted_file, file_line);	//copy each line of the file

    		buffer+=file_line;					//and add it to the buffer
		}	
	}
	
	crypted_file.close();
	
	for(int i = 0; i < buffer.length(); i++)	//turn buffer text from lower to uppercase
       buffer[i] = toupper(buffer[i]);

	
	for(int a=0;a<26;a++)			//searching for k1...
	{
		
        for (int i=0;i<26;i++)				//check if k1 is proper to be used as inverted a
	    {
			flag = (a*i) % 26;				//should be a*a^-1 mod m == 1 to be used as inverted a

			if (flag==1)
			{ 
			    for(int l=0;l<=a;l++)
				{
			    	inverted_a=((l*26)+1);
			    	if(inverted_a%a==0) 
						break;
				}
				
				inverted_a=inverted_a/a;
				
			    break;
			}
			
		}

		
	    if(flag==1)
		{
			for(int b=0;b<26;b++)	//searching for k2...
			{
				possible_message="";
				
			    for (int i=0;i<buffer.length();i++)		//scan the buffer
			    {
					if(buffer[i]!=' ')						//decode the buffer text with each pair of k1,k2
					    possible_message = possible_message + (char) (((inverted_a * ((buffer[i]+'A' - b)) % 26)) + 'A');
					else									//leave the spaces as they are
					    possible_message+= buffer[i]; 
			    }
			    
			    output_file<<"k1= "<<a<<", k2= "<<b<<", Output: "<<possible_message<<endl;	//print the possible message to the output file   
			}
			
			output_file<<endl;
	    }
  
	}
	
	output_file.close();	
}
