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
	void num(int nmr);

	int den();
	void den(int dnmr);

private:
	void inline update(fraction newRational) {
		rational = newRational;

		int gcf = commonFactor(rational.NMR, rational.DNMR);
		rational.NMR = rational.NMR / gcf;
		rational.DNMR = rational.DNMR / gcf;
	}
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