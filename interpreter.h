#include<iostream>
#include<stack>
#include<vector>
#include "object.h"
using namespace std;

class interpreter {
public:
	//���ݽṹ
	static const int stacksize = 10000;
	static const int codesize = 10000;
	vector<int>s;//����ջ
	pcode instruction;//ָ��Ĵ���
	int p=0;//ָ���ַ�Ĵ���
	int b=0;//��ַ�Ĵ���
	int t=0;//ջ���Ĵ���
	vector<pcode*>code;
	//
	interpreter(vector<pcode*>c);
};