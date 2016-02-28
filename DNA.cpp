// Homework 7
// Due 10/24
// Yash Parekh
// Analyzing Mouse or Human DNA

#include <iostream>
#include <fstream>

using namespace std;
int main(int argc, char*argv[])
{
	char* humanfile = (argv[2]);
	char* mousefile = (argv[1]);
	char* unknownfile = (argv[3]);
	string mousestring;
	string humanstring;
	string unknownstring;
	ifstream in;
	
	in.open(humanfile);
	if (in.is_open()) // Ensures file was opened properly
	{
		getline(in,humanstring);
		in.close();
	}

	in.open(mousefile);
	if (in.is_open())
	{
		getline(in,mousestring);
		//int mousestringlength= mousestring.length();
		in.close();
	}
	in.close();
	
	in.open(unknownfile);
	if (in.is_open())
	{
		getline(in, unknownstring);
		//int unknownstringlength = unknownstring.length();
		in.close();
	}
	in.close();
	double hammingdistancem;
	double hammingdistanceh;
	int hlength = humanstring.length();
	
	for(int i=0; i < hlength ; i++)
	{
		if (mousestring[i] != unknownstring[i])
		{
		//hammingdistance = mousestring.length+1;
		hammingdistancem++;
		}
		//else --- Don't need this else, have to check both!) 
		if (humanstring[i] != unknownstring[i])
		{
		//hammingdistance = humanstring.length+1;
		hammingdistanceh += 1;
		}
	}
	
	//human
	double similarity_scoreh = (humanstring.length() - hammingdistanceh) / humanstring.length();
	//cout << humanstring.length();
	//mouse
	double similarity_scorem = (mousestring.length() - hammingdistancem) / mousestring.length();
	
	//Read in data from the files
	//Find matches and mismatches, set to Hamming distance
	
	//Calculate Similarity score
	
	cout << "MouseCompare = " << similarity_scorem << endl;
	cout << "HumanCompare = " << similarity_scoreh << endl;
		if (similarity_scoreh == similarity_scorem)
		cout<<"identity cannot be determined"<<endl;
		else if (similarity_scoreh > similarity_scorem)
		cout<<"human"<<endl;
		else if (similarity_scoreh < similarity_scorem)
		cout<<"mouse"<<endl;
	
	return 0;
	
}
