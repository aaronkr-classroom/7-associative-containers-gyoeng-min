//xref.cpp
#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "split.h"

using namespace std;

//�Է¿��� �� �ܾ ������ ��� ���� ã��
map<string, vector<int> > xref(
	istream& in,
	vector<string> find_words(const string&) = split
) {
	string line;
	int line_num = 0;
	map<string, vector<int> >ret;

	//�������� ����
	while (getline(in, line)) {
		++line_num;

		vector<string>words = find_words(line);

		for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it) {
			ret[*it].push_back(line_num);
		}
		
	}

	return ret;
}

//�������� :xref.cpp���� 7-7, 7-8 �߰� �׸��� �� �ٿ� �ܾ �ι� �̻� ��Ÿ����
//�� ��ȣ�� ���� �� ������� �ʰ� �� ���� ����ϼ���.

int main() {
	//�⺻ �μ��� split �Լ��� ����Ͽ� xref �Լ��� ȣ��
	map<string, vector<int> > ret = xref(cin);

	//����� ���
	for (map<string, vector<int> >::const_iterator it = ret.begin(); it != ret.end(); ++it) {
		cout << "\"" << it->first << "\" is on line(s): ";

		vector<int>::const_iterator line_it = it->second.begin();


		cout << *line_it;
		++line_it;

		while (line_it != it->second.end()) {
			cout << ", " << *line_it;
			++line_it;
		}

		cout << endl;
	}


	return 0;
}