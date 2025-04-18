#include <iostream>
#include<string>
#include<map>

using namespace std;

int main() {
	map <string, int> counters;
	string s;


	cout << "Enter words (CTRL +Z to stop): " << endl;

	while (cin >> s)
		++counters[s];

	//�ܾ�� �󵵸� ���
	cout << "Word count:" << endl;
	for (map<string, int>::const_iterator it = counters.begin();
	it != counters.end(); ++it) {
		cout << it->first << "\t" << it->second << endl;
	
	}
	return 0;
}