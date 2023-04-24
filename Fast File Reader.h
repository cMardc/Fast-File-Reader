#pragma once

//Libraries Used
#include <iostream> //Input/Output Stream For Console
#include <string>   //For String
#include <fstream>  //File Stream
#include <filesystem> //For Controling Files


using namespace std;//Standart Namespace

//Get File's Name On Given Path
string getName(const string target)
{
	size_t size = target.size(); //Size Of Given Path
	size_t lastPos = size; //Position Of Backslash(\)
	char symbol; //Char For Symbol On Given Index
	string name; //Result
	for (size_t i = 0; i < size; i++) //Loop To Get Chars
	{
		symbol = target[i]; //Get Char On Given Index Of Path
		if (symbol == '/') 
		{
			lastPos = i; //Get Position Of Backslash(\)
		}
	}
	for (size_t i = lastPos; i < size; i++) //Loop To Get Name
	{
		symbol = target[i]; //Get Char On Given Index Of Path
		if (symbol == '.') //IF Symbol Is Dot
		{
			break; //Vreak Because Format Comes After Dot
		}
		else
		{
			name += symbol; //Add It To Name
		}
	}
	return name; //Give Name
}

