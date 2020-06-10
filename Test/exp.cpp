#include "exp.h"

int Exp::getValue() {
	int cnt(1);

	for (int i(0); i < exp; i++)
	{
		cnt *= base;
	}

	return cnt;
}

bool Exp::equals(Exp b) {

	if (getValue() == b.getValue())
		return true;

	else
		return false;
}