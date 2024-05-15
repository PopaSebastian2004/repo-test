#include <fstream>
#include <string>
#include <map>
#include <queue>
using namespace std;

class Compare {
public:
	bool operator() (pair<string, int> p1, pair<string, int> p2) {
		if (p1.second < p2.second)
			return true;
		if (p1.second > p2.second)
			return false;
		if (p1.first < p2.first)
			return false;
		return true;
	}
};

int main() {
	string myString;
	ifstream myFile("TextFile1.txt");
	if (!myFile)
	{
		printf("error la deschiderea fisierului: TextFile1.txt");
		return 0;
	}
	//citim prima linie din fisier
	if (!getline(myFile, myString)) {
		printf("error la citirea din fisier: TextFile1.txt");
		return 0;
	}
	map<string, int> myMap;
	printf("Sirul de caractere citit este: %s\n", myString.c_str());
	
	size_t prev = 0, pos;
	string word;
	char *cuv = new char[100];
	int cnt = 0;
	cuv[0] = '\0';
	for (int i = 0; i < myString.size(); i++) {
		if (myString[i] >= 'A' && myString[i] <= 'z')
		{
			if (myString[i] <= 'Z')
			{
				myString[i] += 32;
			}
			cuv[cnt] = myString[i];
			cnt++;
		}
		else
		{
			if (cnt > 0)
			{
				cuv[cnt] = '\0';
				word = cuv;
				if (myMap.count(word) != 0) {
					myMap[word] += 1;
				}
				else {
					myMap[word] = 1;
				}
				cnt = 0;
				char* cuv = new char[100];
			}
		}
	}
	for (auto mapIterator = myMap.begin(); mapIterator != myMap.end(); mapIterator++) {
		printf("cuvantul: %s  - apare de %d ori \n", mapIterator->first.c_str(), mapIterator->second);
	}
	priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> myQueue;
	for (auto mapIterator = myMap.begin(); mapIterator != myMap.end(); mapIterator++) {
		myQueue.push(pair<string, int>(mapIterator->first, mapIterator->second));
	}
	printf("\n\nSortate\n");
	//Golim coada
	while (!myQueue.empty())
	{
		printf("%s | %d\n", myQueue.top().first.c_str(), myQueue.top().second);
		myQueue.pop();
	}
};