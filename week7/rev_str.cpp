//rev_str.cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void rev_str(string& s, int start, int end) {
	if (start >= end)
		return;

	char temp = s[start];
	s[start] = s[end];
	s[end] = temp;

	//����� �ܰ�
	rev_str(s, start + 1, end - 1);
}

int main() {
	string s;
	cout << " Enter a string: ";
	cin >> s;

	rev_str(s, 0, s.length() - 1);

	cout << "Reversed string: " << s << endl;
	
	
	return 0;

}