#include "Fast File Reader.h"
using namespace std;
namespace fs = filesystem;


int main() //Run Only On Execute
{
	string target; //target Drive Path
	string path; //Text File Path
	string name; //Name OF Fıle
	string text; //Text Insıde File
	cout << "\nEnter Drive Path : ";
	getline(cin, target); 
	cout << "\nEnter TextFile Path : ";
	getline(cin, path); 
	ofstream textFile(path);
	bool open = textFile.is_open();
	if (!open)
	{
		cout << "\nWrong Path Entered!";
		return 0; //End Program Here
	}
	for (const auto& targetFS : fs::directory_iterator(target)) 
	{
		//get Path that Includes Target Path
		name = getName(targetFS.path().generic_string());
		//Get Name Of File
		ifstream targetFile(targetFS.path().generic_string());
		//Check If File Really Exsists
		if (!targetFile.is_open())
		{
			cout << "One File Failed During Upload.";
		}
		else
		{

			getline(targetFile, text);//Read Text Inside File
			textFile << name << "\n" << text << "\n"; //Include It On File
		}
	}
	textFile.close(); //Close File
	return 0; //End Program
}
