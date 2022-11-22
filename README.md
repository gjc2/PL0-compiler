# yffx
语法分析


## rule类 规则
读取一个规则，转化成规则(eg.A->B: A->.B & A->B.)

## item类 项
自动机的每一个状态

## DFA

## LR(0) 分析表

## 中间代码生成？还要加静态语义检查

每个规则增加属性


##
A:<程序>
B:<分程序>
C :<常量说明部分>
D :<变量说明部分>
E :<过程说明部分>

F :[<常量说明部分>]
0 :{,<常量定义>}		//数字0
G :<常量定义>
1 :{,<标识符>}		//数字1
I :[<变量说明部分>]
J :{<过程说明部分>}
K :[<过程说明部分>]
L :<过程首部>
2 :{;<语句>}		//数字2
M :<语句>
N :<赋值语句>
O :<条件语句>
P :<当型循环语句>
Q :<过程调用语句>
R :<读语句>
S :<写语句>
T :<复合语句>
U :{<加减运算符><项>}
V :<表达式>
W :<条件>
X :{<乘除运算符><因子>}
Y :<项>
Z :<因子>
3 :[q] 

##
a: const 关键字
b: var   关键字
c: procedure 关键字
d: :=	关键字(看做关键字吧，词法分析改一下)
e: begin 关键字
f: end 关键字
g: odd 关键字
h: if 关键字
i: then 关键字
j: call 关键字
k: while
l: do
m: read
n: write
o: <无符号整数>
p: <标识符>
q: <加减运算符>
r: <乘除运算符>
s: <关系运算符>

##
5,7可以不考虑，词法分析已经读出
17，18，19也是
25,26也用不上
##
1.<程序> -> <分程序>
	A->B
2.<分程序> -> [<常量说明部分>][<变量说明部分>][<过程说明部分>]<语句>
	B->FIKM
	F->C
	F->NULL
	I->D
	I->NULL
	K->E
	K->NULL
### 常量说明部分：
3.<常量说明部分> -> const<常量定义>{,<常量定义>};
	C->aG0;
	0->,G0
	0->NULL
4.<常量定义> -> <标识符>=<无符号整数>
	G->p=o
//5.<无符号整数> -> <数字>{<数字>}
//	//I->JJ'
//	//J'=JJ'
//	//J'=NULL
### 变量说明部分：
6.<变量说明部分>->var<标识符>{,<标识符>};
	D->bH1;
	1->,H1
	1->NULL
//7.<标识符> -> <字母>{<字母>|<数字>}
//	//H->KK'
//	//K'->JK'
//	//K'->KK'
//	//K'->NULL
### 过程说明部分：
8.<过程说明部分> -> <过程首部><分程序>;{<过程说明部分>}
	E->LB;J
	J->EJ
	J->NULL
9.<过程首部>->procedure<标识符>
	L->cp
### 语句
10.<语句> -> <赋值语句>|<条件语句>|<当型循环语句>
	|<过程调用语句>|<读语句>|<写语句>|<复合语句>|<空>
	M->N
	M->O
	M->P
	M->Q
	M->R
	M->S
	M->T
	M->NULL
11.<赋值语句>-><标识符>:=<表达式>
	N->pdV
12.<复合语句>->begin<语句>{;<语句>}end
	T->eM2f
	2->;M2
	2->NULL
13.<条件> -> <表达式><关系运算符><表达式>|odd<表达式>
	W->VsV
	W->gV
14.<表达式>->[<加减运算符>]<项>{<加减运算符><项>}
	V->3YU
	3->q
	3->NULL
	U->qYU
	U->NULL
15.<项>-><因子>{<乘除运算符><因子>}
	Y->ZX
	X->rZX
	X->NULL
16.<因子>-><标识符>|<无符号整数>|(<表达式>)
	Z->p
	Z->o
	Z->(V)
//17.<加减运算符>->+|-
//	//Z->+|-
//18.<乘除运算符>->*|/
//	//F->*|/
//19.<关系运算符>->=|#|<|<=|>|>=
//	//X->=|#|<|<=|>|>=
20.<条件语句>-> if<条件>then<语句>
	O->hWiM
21.<过程调用语句>->call<标识符>
	Q->jp
22.<当型循环语句>->while<条件>do<语句>
	P->kWlM
23.<读语句>->read(<标识符>{,<标识符>})
	R->m(p1)
24.<写语句>->write(<标识符>{,<标识符>})
	S->n(p1)
//25.<字母>->a|...|z
//	//K->a|...|z
//26.<数字>->0|...|9
//	//J->0|...|1


x.push_back(new rule("&", "A"));
x.push_back(new rule("A", "B"));
x.push_back(new rule("B", "FIKM"));
x.push_back(new rule("F", "C"));
x.push_back(new rule("F", "@"));
x.push_back(new rule("I", "D"));
x.push_back(new rule("I", "@"));
x.push_back(new rule("K", "E"));
x.push_back(new rule("K", "@"));
x.push_back(new rule("C", "aG0;"));
x.push_back(new rule("0", ",G0"));
x.push_back(new rule("0", "@"));
x.push_back(new rule("G", "p=o"));
x.push_back(new rule("D", "bH1;"));
x.push_back(new rule("1", ",H1"));
x.push_back(new rule("1", "@"));
x.push_back(new rule("E", "LB;J"));
x.push_back(new rule("J", "EJ"));
x.push_back(new rule("J", "@"));
x.push_back(new rule("L", "cp"));
x.push_back(new rule("M", "N"));
x.push_back(new rule("M", "O"));
x.push_back(new rule("M", "P"));
x.push_back(new rule("M", "Q"));
x.push_back(new rule("M", "R"));
x.push_back(new rule("M", "S"));
x.push_back(new rule("M", "T"));
x.push_back(new rule("M", "@"));
x.push_back(new rule("N", "pdV"));
x.push_back(new rule("T", "eM2f"));
x.push_back(new rule("2", ";M2"));
x.push_back(new rule("2", "@"));
x.push_back(new rule("W", "VsV"));
x.push_back(new rule("W", "gV"));
x.push_back(new rule("V", "3YU"));
x.push_back(new rule("3", "q"));
x.push_back(new rule("3", "@"));
x.push_back(new rule("U", "qYU"));
x.push_back(new rule("U", "@"));
x.push_back(new rule("Z", "p"));
x.push_back(new rule("Z", "o"));
x.push_back(new rule("Z", "(V)"));
x.push_back(new rule("O", "hWiM"));
x.push_back(new rule("Q", "jp"));
x.push_back(new rule("P", "kWlM"));
x.push_back(new rule("R", "m(p1)"));
x.push_back(new rule("S", "n(p1)"));