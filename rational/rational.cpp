#include "rational.hpp"
#include <stdexcept>

Rational::Rational() : Rational(0,1){
}
Rational::Rational(int NMR, int DNMR) {
	fraction newRational = { NMR, DNMR };

	validate(newRational);

	update(newRational);
}

int Rational::num() {
	return rational.NMR;
}
void Rational::num(int nmr) {
	fraction newRational = { nmr, rational.DNMR };

	validate(newRational);
	update(newRational);
}

int Rational::den() {
	return rational.DNMR;
}
void Rational::den(int dnmr) {
	fraction newRational = { rational.NMR, dnmr };

	validate(newRational);
	update(newRational);
}

void Rational::validate(fraction newRational) {
	if (newRational.DNMR == 0) {
		throw std::domain_error("Denominator initialized to 0");
	}
}