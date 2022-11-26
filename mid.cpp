#include "mid.h"
using namespace std;
std::vector<void(mid::*)()>mid::func;
mid::mid() {
	func.push_back(&mid::f_0);
	func.push_back(&mid::f_1);
	func.push_back(&mid::f_2);
	func.push_back(&mid::f_3);
	func.push_back(&mid::f_4);
	func.push_back(&mid::f_5);
	func.push_back(&mid::f_6);
	func.push_back(&mid::f_7);
	func.push_back(&mid::f_8);
	func.push_back(&mid::f_9);
	func.push_back(&mid::f_10);
	func.push_back(&mid::f_11);
	func.push_back(&mid::f_12);
	func.push_back(&mid::f_13);
	func.push_back(&mid::f_14);
	func.push_back(&mid::f_15);
	func.push_back(&mid::f_16);
	func.push_back(&mid::f_17);
	func.push_back(&mid::f_18);
	func.push_back(&mid::f_19);
	func.push_back(&mid::f_20);
	func.push_back(&mid::f_21);
	func.push_back(&mid::f_22);
	func.push_back(&mid::f_23);
	func.push_back(&mid::f_24);
	func.push_back(&mid::f_25);
	func.push_back(&mid::f_26);
	func.push_back(&mid::f_27);
	func.push_back(&mid::f_28);
	func.push_back(&mid::f_29);
	func.push_back(&mid::f_30);
	func.push_back(&mid::f_31);
	func.push_back(&mid::f_32);
	func.push_back(&mid::f_33);
	func.push_back(&mid::f_34);
	func.push_back(&mid::f_35);
	func.push_back(&mid::f_36);
	func.push_back(&mid::f_37);
	func.push_back(&mid::f_38);
	func.push_back(&mid::f_39);
	func.push_back(&mid::f_40);
	func.push_back(&mid::f_41);
	func.push_back(&mid::f_42);
	func.push_back(&mid::f_43);
	func.push_back(&mid::f_44);
	func.push_back(&mid::f_45);
	func.push_back(&mid::f_46);
	func.push_back(&mid::f_47);
	func.push_back(&mid::f_48);
	func.push_back(&mid::f_49);
}
void mid::insert(string name,string kind,string var,int level,int addr) {
	m.push_back(new entry(name, kind, var, level, addr));
}
void mid::gen_quad(string q[4]) {
	code.push_back(new quad(q));
}
void mid::f_0() {//&->A
	sta.pop_back();
}
void mid::f_1() {//A->B!
	sta.pop_back();
	sta.pop_back();
	sta.push_back({ " "," "," "," "});
}
void mid::f_2() {//B->FIKM
	sta.pop_back();
	sta.pop_back();
	sta.pop_back();
	sta.pop_back();
	sta.push_back({ " "," "," "," " });
}
void mid::f_3() {//F->C
	type++;
	sta.pop_back();
	sta.push_back({ " "," "," "," " });
}
void mid::f_4() {//F->NULL
	sta.push_back({ " "," "," "," " });
}
void mid::f_5() {//I->D
	type++;
	sta.pop_back();
	sta.push_back({ " "," "," "," " });
}
void mid::f_6() {//I->NULL
	sta.push_back({ " "," "," "," " });
}
void mid::f_7() {//K->E
	type++;
	sta.pop_back();
	sta.push_back({ " "," "," "," " });
}
void mid::f_8() {//K->NULL
	sta.push_back({ " "," "," "," " });
}
void mid::f_9() {//C->aG0;
	sta.pop_back();
	sta.pop_back();
	sta.pop_back();
	sta.pop_back();
	sta.push_back({ " "," "," "," " });
}
void mid::f_10() {//0->,G0
	sta.pop_back();
	sta.pop_back();
	sta.pop_back();
	sta.push_back({ " "," "," "," " });
}
void mid::f_11() {//0->NULL
	sta.push_back({ " "," "," "," " });
}
void mid::f_12() {//G->p=o
	//insert(p, "constant", o, l, dx);
	string o = sta[sta.size() - 1].name;
	sta.pop_back();
	sta.pop_back();
	string p = sta[sta.size() - 1].name;
	sta.pop_back();
	sta.push_back({ " "," "," "," " });
	insert(p, "constant", o, l, dx);
	dx++;
}
void mid::f_13() {//D->bp1;
	sta.pop_back();
	sta.pop_back();
	string p = sta[sta.size() - 1].name;
	sta.pop_back();
	sta.pop_back();
	sta.push_back({ " "," "," "," " });
	insert(p, "variable", "0", l, dx);
	dx++;
}
void mid::f_14() {//1->,p1
	sta.pop_back();
	string p = sta[sta.size() - 1].name;
	sta.pop_back();
	sta.pop_back();
	sta.push_back({ " "," "," "," " });
	if(type==1)
		insert(p, "variable", "0", l, dx);
	dx++;
}

void mid::f_15() {//1->NULL
	sta.push_back({ " "," "," "," " });
}
void mid::f_16() {//E->LB;J
	sta.pop_back();
	sta.pop_back();
	sta.pop_back();
	sta.pop_back();
	sta.push_back({ " "," "," "," " });
	l--;
}
void mid::f_17() {//J->EJ
	sta.pop_back();
	sta.pop_back();
	sta.push_back({ " "," "," "," " });
	
}
void mid::f_18() {//J->NULL
	sta.push_back({ " "," "," "," " });
}
void mid::f_19() {//L->cp
	sta.pop_back();
	sta.pop_back();
	sta.push_back({ " "," "," "," " });
	l++;
}
//上面的 常量说明，变量说明，过程说明不用生成四元式
void mid::f_20() {//M->N
	sta.pop_back();
	sta.push_back({ " "," "," "," " });
}
void mid::f_21() {//M->O
	sta.pop_back();
	sta.push_back({ " "," "," "," " });
}
void mid::f_22() {//M->P
	sta.pop_back();
	sta.push_back({ " "," "," "," " });
}
void mid::f_23() {//M->Q
	sta.pop_back();
	sta.push_back({ " "," "," "," " });
}
void mid::f_24() {//M->R
	sta.pop_back();
	sta.push_back({ " "," "," "," " });
}
void mid::f_25() {//M->S
	sta.pop_back();
	sta.push_back({ " "," "," "," " });
}
void mid::f_26() {//M->T
	sta.pop_back();
	sta.push_back({ " "," "," "," " });
}
void mid::f_27() {//M->NULL
	sta.push_back({ " "," "," "," " });
}
//上面的各种语句赋值给语句也不用四元式


void mid::f_28() {//N->pdV
	string vv = sta[sta.size() - 1].name;
	sta.pop_back();
	sta.pop_back();
	string p = sta[sta.size() - 1].name;
	if (lookup(p) != -1) {
		string temp[] = { "=",vv,"-",p };
		gen_quad(temp);
	}
	sta.pop_back();
	sta.push_back({ " "," "," "," " });
}
void mid::f_29() {//T->eM2f
	sta.pop_back();
	string next = sta[sta.size() - 1].next;
	sta.pop_back();
	sta.pop_back();
	sta.pop_back();
	sta.push_back({" ",next," "," "});
}
void mid::f_30() {//2->;M2
	string next = sta[sta.size() - 1].next;
	sta.pop_back();
	sta.pop_back();
	sta.pop_back();
	sta.push_back({" ",next," ", " "});
}
void mid::f_31() {//2->NULL
	string next = to_string(code.size());
	sta.push_back({" ",next," "," "});
}
void mid::f_32() {//W->VsV
	string t = to_string(code.size());
	string f = to_string(code.size());
	string id2 = sta[sta.size() - 1].name;
	sta.pop_back();
	string judge = sta[sta.size() - 1].name;
	sta.pop_back();
	string id1 = sta[sta.size() - 1].name;
	sta.pop_back();
	sta.push_back({" "," ",t,f});
	string temp[4] = { judge, id1, id2, "0" };
	gen_quad(temp);
}
void mid::f_33() {//W->gV
	string t = to_string(code.size());
	string f = to_string(code.size());
	string id1 = sta[sta.size() - 1].name;
	sta.pop_back();
	string judge = sta[sta.size() - 1].name;
	sta.pop_back();
	string id2 = "1";
	sta.push_back({ " "," ",t,f });
	string temp[4] = { judge, id1, id2, "0" };
	gen_quad(temp);
	string temp1[4] = { "j","-","-","0" };
	gen_quad(temp1);
}
void mid::f_34() {//V->3YU
	string u = sta[sta.size() - 1].name;

	sta.pop_back();

	string y = sta[sta.size() - 1].name;

	sta.pop_back();

	string judge = sta[sta.size() - 1].name;
	sta.pop_back();
	string tempvar = "n" + to_string(newtemp);
	insert(tempvar, "tempvar", "0", l, dx);
	dx++;
	newtemp++;
	string temp[4] = {judge,y,"-",tempvar};
	gen_quad(temp);

	string tempvar1 = "n" + to_string(newtemp);
	insert(tempvar1, "tempvar", "0", l, dx);
	dx++;
	newtemp++;
	string temp1[4] = { "+",tempvar,u,tempvar1 };
	gen_quad(temp1);
	sta.push_back({tempvar1," "," "," "});
}
void mid::f_35() {//3->q
	string q = sta[sta.size() - 1].name;
	sta.pop_back();
	sta.push_back({q," "," "," "});
}
void mid::f_36() {//3->NULL
	sta.push_back({ "+"," "," "," " });
}
void mid::f_37() {//U->qYU
	string u = sta[sta.size() - 1].name;

	sta.pop_back();

	string y = sta[sta.size() - 1].name;

	sta.pop_back();

	string judge = sta[sta.size() - 1].name;
	sta.pop_back();
	string tempvar = "n" + to_string(newtemp);
	insert(tempvar, "tempvar", "0", l, dx);
	dx++;
	newtemp++;
	string temp[4] = { judge,y,"-",tempvar };
	gen_quad(temp);

	string tempvar1 = "n" + to_string(newtemp);
	insert(tempvar1, "tempvar", "0", l, dx);
	dx++;
	newtemp++;
	string temp1[4] = { "+",tempvar,u,tempvar1 };
	gen_quad(temp1);
	sta.push_back({ tempvar1," "," "," " });
}
void mid::f_38() {//U->NULL
	sta.push_back({ "-"," "," "," " });
}
void mid::f_39() {//Y->ZX
	string x = sta[sta.size() - 1].name;
	string symbol = sta[sta.size() - 1].next;
	sta.pop_back();
	string z = sta[sta.size() - 1].name;
	sta.pop_back();
	string tempvar = "n" + to_string(newtemp);
	insert(tempvar, "tempvar", "0", l, dx);
	dx++;
	newtemp++;
	string temp[4] = { symbol,z,x,tempvar };
	gen_quad(temp);
	sta.push_back({tempvar," "," "," "});
}
void mid::f_40() {//X->rZX
	string xr = sta[sta.size() - 1].name;
	string xs = sta[sta.size() - 1].name;
	sta.pop_back();
	string z = sta[sta.size() - 1].name;
	sta.pop_back();
	string symbol = sta[sta.size() - 1].name;
	sta.pop_back();
	string tempvar = "n" + to_string(newtemp);
	insert(tempvar, "tempvar", "0", l, dx);
	dx++;
	string temp[4] = { xs,xr,z,tempvar };
	gen_quad(temp);

	newtemp++;

	sta.push_back({tempvar,symbol," "," "});
}
void mid::f_41() {//X->NULL	
	sta.push_back({"1","*"," "," "});
}
void mid::f_42() {//Z->p
	string p = sta[sta.size() - 1].name;
	sta.pop_back();
	sta.push_back({p," "," "," "});
}
void mid::f_43() {//Z->o
	string o = sta[sta.size() - 1].name;
	sta.pop_back();
	sta.push_back({ o," "," "," " });
}
void mid::f_44() {//Z->(V)	
	sta.pop_back();
	string v = sta[sta.size() - 1].name;
	sta.pop_back();
	sta.pop_back();
	sta.push_back({v," "," "," "});
}
void mid::f_45() {//O->hWiM //if then 语句待加
	sta.pop_back();
	sta.pop_back();
	sta.pop_back();
	sta.pop_back();
	sta.push_back({" "," "," "," "});
}
void mid::f_46() {//Q->jp //应该加跳转
	string p = sta[sta.size() - 1].name;
	sta.pop_back();
	string j = sta[sta.size() - 1].name;
	sta.pop_back();
	string tempvar = "n" + to_string(newtemp);
	insert(tempvar, "tempvar", "0", l, dx);
	dx++;
	newtemp++;
	string temp[4] = { j,p,"-","-" };
	gen_quad(temp);
	sta.push_back({" "," "," "," "});
}
void mid::f_47() {//P->kWlM	 //while 语句待加
	sta.pop_back();
	sta.pop_back();
	sta.pop_back();
	sta.pop_back();
	sta.push_back({" "," "," "," "});
}
void mid::f_48() {//R->m(p1)
	sta.pop_back();
	sta.pop_back();
	sta.pop_back();
	sta.pop_back();
	sta.pop_back();
	string temp[4] = { "read","-","-","-"};
	gen_quad(temp);
	sta.push_back({" "," "," "," "});
}
void mid::f_49() {//S->n(p1)
	sta.pop_back();
	sta.pop_back();
	sta.pop_back();
	sta.pop_back();
	sta.pop_back();
	string temp[4] = { "write","-","-","-" };
	gen_quad(temp);
	sta.push_back({ " "," "," "," " });
}
void mid::show() {
	for (int i = 0; i < m.size(); i++)
		m[i]->show();
	for (int i = 0; i < code.size(); i++)
		code[i]->show();
}

int mid::lookup(string name) {
	for (int i = 0; i < m.size(); i++) {
		if (m[i]->name == name && m[i]->level == l) {
			return i;
		}
	}
	return -1;
}