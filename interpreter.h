#include<iostream>
#include<stack>
#include<vector>
#include "pcode.h"
using namespace std;

class interpreter {
public:
	//数据结构
	static const int stacksize = 10000;
	static const int codesize = 10000;
	stack<int>s;//运行栈
	pcode instruction;//指令寄存器
	int p=0;//指令地址寄存器
	int b=0;//基址寄存器
	int t=0;//栈顶寄存器
	vector<pcode*>code;
	//
	interpreter(vector<pcode*>c);
};