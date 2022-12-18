#include "interpreter.h"
using namespace std;

interpreter::interpreter(vector<pcode*>c) {
	code = c;
	s.push(0);
	s.push(0);
	s.push(0);
	while (1) {
		instruction = *code[p];
		if (instruction.op == "LIT") {
			s.push(stoi(instruction.a));
			t++;
			p++;
		}
		else if (instruction.op == "LOD") {

		}
		else if (instruction.op == "STO") {

		}
		else if (instruction.op == "CAL") {

		}
		else if (instruction.op == "INT") {

		}
		else if (instruction.op == "JMP") {

		}
		else if (instruction.op == "JPC") {

		}
		else if (instruction.op == "OPR") {

		}
	}
}
