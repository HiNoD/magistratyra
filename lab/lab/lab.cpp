#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

const int size1 = 6;
const int size2 = 50;
const string first = "Грека";
const string second = "рак";

int main()
{
	ifstream file;
	file.open("text.txt");
	string word;
	char x;
	word.clear();

	while (!file.eof())
	{
		string word;
		int counter = 0;
		vector<int> firstWords;
		vector<int> secondWords;
		vector<int> result;
		while (file >> word)
		{
			counter++;
			if (word == first) {
				firstWords.push_back(counter);
			}
			else if (word == second) {
				secondWords.push_back(counter);
			}
		}
		for (int i = 0; i < firstWords.size(); i++) {
			for (int j = 0; j < secondWords.size(); j++) {
				result.push_back(fabs(firstWords[i] - secondWords[j] - 1));
			}
		}
		cout << "MIN " << *std::min_element(result.begin(), result.end()) << endl;
		cout << "MAX " << *std::max_element(result.begin(), result.end()) << endl;
	}
	return 0;
}