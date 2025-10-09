#pragma once

class Rational {
		struct fraction {
		int NMR;
		int DNMR;
	};
public:
	Rational();
	Rational(int NMR, int DNMR);

	int num();
	void num(int NMR);

	int den();
	void den(int DNMR);

private:
	int inline commonFactor(int a, int b) {
		if (a % b == 0) {
			return b;
		}
		else {
			return commonFactor(b, a % b);
		}
	}	
	void inline validate(fraction newRational);

	fraction rational;
};