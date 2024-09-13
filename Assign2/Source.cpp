#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>


using namespace std;
//#define PRE_RELEASE


struct STUDENT_DATA {
	std::string firstName;
	std::string lastName;
#ifdef PRE_RELEASE
	std::string email;
#endif
};


void readFromFile(std::string filename, std::vector<STUDENT_DATA>& myvector)
{

	//Opens file and will send contents to Server character by character
	std::ifstream fin(filename);
	if (!fin.is_open())  //file is not open
	{
		std::cout << "Error: unable to open file for reading" << std::endl; //error checking, file could not be opened
	}
	else //file was sucessfully opened
	{
		std::string line;
		while (getline(fin, line))
		{ //while loop continues t)o read character by character through entire file and sends each byte to server until the end of the file is reached
			STUDENT_DATA student;
			std::istringstream issLine(line);
			std::string firstname, lastname;
			
			getline(issLine, firstname, ','); 
#ifdef PRE_RELEASE
			std::string email;
			getline(issLine, lastname, ',');
			getline(issLine, email);
			student.email = email;
#else
			getline(issLine, lastname); 
#endif

			student.firstName = firstname;
			student.lastName = lastname;

			myvector.push_back(student);
		}

	}
	fin.close(); //closes the file
}


int main()
{
#ifdef PRE_RELEASE
	std::cout << "Application is running Pre-release source code" << std::endl;
#else
	std::cout << "Application is running standard source code" << std::endl;
#endif


	std::vector<STUDENT_DATA> myvector;
	std::string filename;
#ifdef PRE_RELEASE
	filename = "StudentData_Emails.txt";
#else
	filename = "StudentData.txt";
#endif
	readFromFile(filename, myvector);


	for (int i = 0; i < myvector.size(); i++)
	{
		#ifdef _DEBUG
		std::cout << myvector[i].firstName << myvector[i].lastName << std::endl;
		#endif

	}

}

