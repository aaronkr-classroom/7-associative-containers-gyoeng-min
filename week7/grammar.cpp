//grammar.cpp
#include <vector>
#include <iostream>
#include <algorithm>//find()
#include <cstdlib>//RAND_MAX����
#include <stdexcept>// domain_error
#include <fstream>//���� (������ ������..)
#include <string>
#include <map>
#include <ctime>//time()

#include "split.h"

using namespace std;

typedef vector<string> Rule;
typedef vector<Rule>Rule_collection;
typedef map<string, Rule_collection> Grammar;

//�־��� �Է� �Է� ��Ʈ������ ���� ���̺� ����
Grammar read_grammar(istream& in) {
	Grammar ret;
	string line;

	ifstream grammar_file("grammar.txt");//���� �߰�

	//�Է� �����͸� ����
	while (getline(grammar_file, line)) {
		//�Է� �����͸� �ܾ�� ����
		vector<string> entry = split(line);
		if (!entry.empty()) {
			//ī�װ� �� ������ ��Ģ�� �ʿ� ����
			ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
		}
	}
	return ret;
}

//�����ȣ �ִ��� Ȯ��
bool bracketed(const string& s) {
	return s.size() > 1
		&& s[0] == '<' && s[s.size() - 1] == '>';
}

//[0,n) �������� ���� ���� �ϳ��� ��ȯ
int nrand(int n) {
	if (n <= 0 || n > RAND_MAX)
		throw domain_error("nrand is out of range!");

	const int bucket_size = RAND_MAX / n;
	int r;
	do r = rand() / bucket_size;//������ �� �� �̻� ����
	while(r >= n);

	return r;
}

//���� ����ϰ� ���� �����ϱ�
void gen_aux(const Grammar& g, const string& word,
	vector<string>& ret) {
	
	if (!bracketed(word))
		ret.push_back(word);//�Ϲ����� �ܾ�

	else {// <..>�ִ� �ܾ� (������Ģ)
		//word�� ������ ��Ģ�� ã��
		Grammar::const_iterator it = g.find(word);
		
		if (it == g.end())// ���� ����?
			throw logic_error("Empty rule!");

		//���� ������ ��Ģ�� ��� ���� ���͸� ������
		const Rule_collection& c = it->second;

		//���Ƿ� �ϳ��� ����
		const Rule& r = c[nrand(c.size())];

		//������ ��Ģ�� ��������� Ȯ��
		for (Rule::const_iterator i = r.begin(); i != r.end(); ++i) {
			gen_aux(g, *i, ret); //����� ȣ��
		}
	}
}

//�Ϲ������� ���� �����ϱ�
vector<string>gen_sent(const Grammar& g){
	vector<string>ret;
	gen_aux(g, "<sentence>", ret);
	return ret;
}

//main
int main() {
	//seed the random number generator with current time
	srand(static_cast<unsigned int>(time(0)));

	//���� ����
	vector<string> sentence = gen_sent(read_grammar(cin));

	//ù��° �ܾ� ���
	vector<string>::const_iterator it = sentence.begin();
	if (!sentence.empty()) {
		cout << *it;
		++it;
	}

	while (it != sentence.end()) {
		cout << " " << *it;
		++it;

	}
	
	cout << endl;

	return 0;
}