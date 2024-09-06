#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>


using namespace std;

struct STUDENT_DATA {
	string firstName;
	string lastName;

};


void readFromFile(std::string filename, vector<STUDENT_DATA>& myvector)
{

	//Opens file and will send contents to Server character by character
	std::ifstream fin(filename);
	if (!fin.is_open())  //file is not open
	{
		std::cout << "Error: unable to open file for reading" << std::endl; //error checking, file could not be opened
	}
	else //file was sucessfully opened
	{
		string line;
		while (getline(fin, line))
		{ //while loop continues t)o read character by character through entire file and sends each byte to server until the end of the file is reached
			STUDENT_DATA student;
			istringstream issLine(line);
			string firstname, lastname; 
			
			getline(issLine, firstname, ','); 
			getline(issLine, lastname); 

			student.firstName = firstname;
			student.lastName = lastname;

			myvector.push_back(student);
		}

	}
	fin.close(); //closes the file
}


int main()
{
	std::vector<STUDENT_DATA> myvector;
	readFromFile("StudentData.txt", myvector);

}

