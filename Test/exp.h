#ifndef EXP_H
#define EXP_H

class Exp {
	int exp; // ������
	int base; // ���̽�

public:
	Exp(int b, int e) {
		exp = e, base = b;
	}

	Exp(int b) :Exp(b, 1) {
	}

	Exp() :Exp(1) {
	}

	int getExp() {
		return exp;
	}

	int getBase() {
		return base;
	}

	int getValue();
	bool equals(Exp b);
};

#endif