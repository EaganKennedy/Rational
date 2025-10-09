#include "rational.hpp"
#include <stdexcept>

Rational::Rational() : Rational(0,1){
}

Rational::Rational(int NMR, int DNMR) {
	fraction newRational = { NMR, DNMR };

	validate(newRational);

	rational = newRational;
}

void Rational::validate(fraction newRational) {
	if (newRational.DNMR == 0) {
		throw std::domain_error("Denominator initialized to 0");
	}
}