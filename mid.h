#include<vector>
#include "quadruple.h"
#include "entry.h" 
#include "4s.h"
class mid {
public:
	static vector<void(mid::*)()>func;//50个
	vector<quad*>code;//四元组
	vector<entry*>m;//符号表
	vector<s4>sta;
	int type = 0;
	int l = 0;
	int dx = 0;
	int newtemp = 0;
	void f_0();
	void f_1();
	void f_2();
	void f_3();
	void f_4();
	void f_5();
	void f_6();
	void f_7();
	void f_8();
	void f_9();
	void f_10();

	void f_11();
	void f_12();
	void f_13();
	void f_14();
	void f_15();
	void f_16();
	void f_17();
	void f_18();
	void f_19();
	void f_20();

	void f_21();
	void f_22();
	void f_23();
	void f_24();
	void f_25();
	void f_26();
	void f_27();
	void f_28();
	void f_29();
	void f_30();

	void f_31();
	void f_32();
	void f_33();
	void f_34();
	void f_35();
	void f_36();
	void f_37();
	void f_38();
	void f_39();
	void f_40();

	void f_41();
	void f_42();
	void f_43();
	void f_44();
	void f_45();
	void f_46();
	void f_47();
	void f_48();
	void f_49();
	void f_50();
	void f_51();
	void f_52();
	void f_53();
	
	void show();
	void insert(string name,string kind,string var,int level,int addr);
	void gen_quad(string q[4]);
	mid();
	int lookup(string name);
	void backpatch(string t, string q);
	string merge(string p1, string p2);
};