//xref.cpp
#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "split.h"

using namespace std;

//입력에서 각 단어가 등장한 모든 행을 찾음
map<string, vector<int> > xref(
	istream& in,
	vector<string> find_words(const string&) = split
) {
	string line;
	int line_num = 0;
	map<string, vector<int> >ret;

	//다음행을 읽음
	while (getline(in, line)) {
		++line_num;

		vector<string>words = find_words(line);

		for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it) {
			ret[*it].push_back(line_num);
		}
		
	}

	return ret;
}

//연습문제 :xref.cpp에서 7-7, 7-8 추가 그리고 한 줄에 단어가 두번 이상 나타나면
//줄 번호를 여러 번 출력하지 않고 한 번만 출력하세요.

int main() {
	//기본 인수인 split 함수를 사용하여 xref 함수르 호출
	map<string, vector<int> > ret = xref(cin);

	//결과를 출력
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