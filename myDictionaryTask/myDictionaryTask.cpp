// myDictionaryTask.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <map>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

using std::ifstream;
using std::exception;
using std::runtime_error;
using std::string;
using std::map;
using std::cout;
using std::endl;

long long calculateWordWeight(const string& word)
{
	long long wordWeigth = 0;
	for (int i = 0; i < word.length(); ++i)
	{
		wordWeigth += (word[i] - 'A') + 1;
	}
	return wordWeigth;
}

void parseFile(ifstream& fin, map<string, long long>& wordsWeigths)
{
	char delimeter = ',';
	string tempStr = "";
	while (getline(fin, tempStr, delimeter))
	{
		tempStr.erase(remove(tempStr.begin(), tempStr.end(), '"'), tempStr.end());
		cout << tempStr << endl << endl;
		wordsWeigths[tempStr] = calculateWordWeight(tempStr);
		tempStr = "";
	}
	for (auto i = wordsWeigths.begin(); i != wordsWeigths.end(); ++i) 
	{
		cout << i->first << ":" << i->second << endl;
	}
}

void openStream(ifstream& fInput, const string& fileName)
{
	ifstream fin(fileName);
	if (!fin.is_open())
	{
		throw runtime_error("Could not open the file!");
	}
}

void calculateTotalSumOfWords(const string& fileName)
{
	ifstream fin;
	try {
		openStream(fin, fileName);
	}
	catch (exception &ex)
	{
		std::cout << "Ouch! That hurts, because: "
			<< ex.what() << "!\n";
	}
	map<string, long long> wordsWeigths;
	parseFile(fin, wordsWeigths);
}

int main(int argc, char* argv[])
{
	const string filename = "../names.txt";
	calculateTotalSumOfWords(filename);

	getchar();
    return 0;
}

