#include "rational.hpp"
#include <stdexcept>
#include <iostream>

Rational::Rational() : Rational(0,1){
}
Rational::Rational(int NMR, int DNMR) {
	fraction newRational = { NMR, DNMR };

	validate(newRational);

	update(newRational);
}

int Rational::num() const{
	return rational.NMR;
}
void Rational::num(int nmr) {
	fraction newRational = { nmr, rational.DNMR };

	validate(newRational);
	update(newRational);
}

int Rational::den() const{
	return rational.DNMR;
}
void Rational::den(int dnmr) {
	fraction newRational = { rational.NMR, dnmr };

	validate(newRational);
	update(newRational);
}

void Rational::print(std::ostream& out) const{
	out << num() << "/" << den();
}

void Rational::validate(fraction newRational) {
	if (newRational.DNMR == 0) {
		throw std::domain_error("Denominator initialized to 0");
	}
}

bool operator==(Rational lhs, Rational rhs){
	if (lhs.num() == rhs.num() && lhs.den() == rhs.den()) {
		return true;
	}
	else {
		return false;
	}
}

Rational operator+(Rational lhs, Rational rhs)
{
	int newNum = lhs.num() * rhs.den() + rhs.num() * lhs.den();
	int newDen = lhs.den() * rhs.den();
	return Rational(newNum, newDen);
}