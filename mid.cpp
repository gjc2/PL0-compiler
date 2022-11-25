#include "mid.h"
using namespace std;
mid::mid() {
	func.push_back(f_0);
	func.push_back(f_1);
	func.push_back(f_2);
	func.push_back(f_3);
	func.push_back(f_4);
	func.push_back(f_5);
	func.push_back(f_6);
	func.push_back(f_7);
	func.push_back(f_8);
	func.push_back(f_9);
	func.push_back(f_10);
	func.push_back(f_11);
	func.push_back(f_12);
	func.push_back(f_13);
	func.push_back(f_14);
	func.push_back(f_15);
	func.push_back(f_16);
	func.push_back(f_17);
	func.push_back(f_18);
	func.push_back(f_19);
	func.push_back(f_20);
	func.push_back(f_21);
	func.push_back(f_22);
	func.push_back(f_23);
	func.push_back(f_24);
	func.push_back(f_25);
	func.push_back(f_26);
	func.push_back(f_27);
	func.push_back(f_28);
	func.push_back(f_29);
	func.push_back(f_30);
	func.push_back(f_31);
	func.push_back(f_32);
	func.push_back(f_33);
	func.push_back(f_34);
	func.push_back(f_35);
	func.push_back(f_36);
	func.push_back(f_37);
	func.push_back(f_38);
	func.push_back(f_39);
	func.push_back(f_40);
	func.push_back(f_41);
	func.push_back(f_42);
	func.push_back(f_43);
	func.push_back(f_44);
	func.push_back(f_45);
	func.push_back(f_46);
	func.push_back(f_47);
	func.push_back(f_48);
	func.push_back(f_49);
}
void mid::insert(string name,string kind,int var,int level,int addr) {
	m.push_back(new entry(name, kind, var, level, addr));
}
void mid::gen_quad(string q[4]) {
	code.push_back(new quad(q));
}
void mid::f_0() {//&->A
	;
}
void mid::f_1() {//A->B!
	;
}
void mid::f_2() {
	;
}
void mid::f_3() {

}
void mid::f_4() {
	;
}
void mid::f_5() {
	;
}
void mid::f_6() {
	;
}
void mid::f_7() {
	;
}
void mid::f_8() {
	;
}
void mid::f_9() {//C->aG0
	;
}
void mid::f_10() {
	;
}
void mid::f_11() {
	;
}
void mid::f_12() {//G->p=o
	insert(p, "constant", o, l, dx);
	dx++;
}
void mid::f_13() {//D->bp1;
	insert(p, "variable", 0, l, dx);
}
void mid::f_14() {
	insert(p, "variable", 0, l, dx);
}

void mid::f_15() {
	;
}
void mid::f_16() {
	;
}
void mid::f_17() {
	;
}
void mid::f_18() {
	;
}
void mid::f_19() {
	;
}
void mid::f_20() {
	;
}
void mid::f_21() {
	;
}
void mid::f_22() {
	;
}
void mid::f_23() {
	;
}
void mid::f_24() {
	;
}
void mid::f_25() {
	;
}
void mid::f_26() {
	;
}
void mid::f_27() {
	;
}
void mid::f_28() {
	;
}
void mid::f_29() {
	;
}
void mid::f_30() {
	;
}
void mid::f_31() {
	;
}
void mid::f_32() {
	;
}
void mid::f_33() {
	;
}
void mid::f_34() {
	;
}
void mid::f_35() {
	;
}
void mid::f_36() {
	;
}
void mid::f_37() {
	;
}
void mid::f_38() {
	;
}
void mid::f_39() {
	;
}
void mid::f_40() {
	;
}
void mid::f_41() {
	;
}
void mid::f_42() {
	;
}
void mid::f_43() {
	;
}
void mid::f_44() {
	;
}
void mid::f_45() {
	;
}
void mid::f_46() {
	;
}
void mid::f_47() {
	;
}
void mid::f_48() {
	;
}
void mid::f_49() {
	;
}
