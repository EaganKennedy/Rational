#include "rational.hpp"
#include <stdexcept>
#include <iostream>
#include <string>

using std::ostream;
using std::istream;

Rational::Rational() : Rational(0,1){
}
Rational::Rational(int NMR, int DNMR) {
	fraction newRational = { NMR, DNMR };

	validate(newRational);

	update(newRational);
}
Rational::Rational(int i) : Rational(i,1){
}
Rational::Rational(double d) : Rational(d * doubleBase, doubleBase){
}

Rational::operator int() const{
	return num() / den();
}
Rational::operator double() const{
	double d = num();
	return d / den();
}

int Rational::num() const{
	return rational.NMR;
}
void Rational::num(int nmr) {
	fraction newRational = { nmr, rational.DNMR };

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

int Rational::doubleBase = 1000000;

bool operator==(Rational const& lhs, Rational const& rhs) {
	return lhs.num() == rhs.num() && lhs.den() == rhs.den();
}
bool operator!=(Rational const& lhs, Rational const& rhs){
	return !(lhs == rhs);
}
std::strong_ordering operator<=>(Rational const& lhs, Rational const& rhs)
{
	return (lhs.num() * rhs.den()) <=> (rhs.num() * lhs.den());
}
Rational operator+(Rational const& lhs, Rational const& rhs)
{
	int newNum = lhs.num() * rhs.den() + rhs.num() * lhs.den();
	int newDen = lhs.den() * rhs.den();
	return Rational(newNum, newDen);
}
Rational operator-(Rational const& lhs, Rational const& rhs){
	int newNum = lhs.num() * rhs.den() - rhs.num() * lhs.den();
	int newDen = lhs.den() * rhs.den();
	return Rational(newNum, newDen);
}
Rational operator*(Rational const& lhs, Rational const& rhs) {
	int newNum = lhs.num() * rhs.num();
	int newDen = lhs.den() * rhs.den();
	return Rational(newNum, newDen);
}
Rational operator/(Rational const& lhs, Rational const& rhs) {
	if (rhs.num() == 0) {
		throw std::domain_error("Attempted division by 0");
	}
	int newNum = lhs.num() * rhs.den();
	int newDen = lhs.den() * rhs.num();
	return Rational(newNum, newDen);
}
Rational operator-(Rational const& lhs){
	return Rational{ -lhs.num(), lhs.den() };
}

Rational operator+=(Rational& dst, Rational const& src){
	dst = dst + src;
	return dst;
}
Rational operator-=(Rational& dst, Rational const& src){
	dst = dst - src;
	return dst;
}
Rational operator*=(Rational& dst, Rational const& src){
	dst = dst * src;
	return dst;
}
Rational operator/=(Rational& dst, Rational const& src){
	dst = dst / src;
	return dst;
}

Rational& operator++(Rational& dst){
	dst.num(dst.num() + dst.den());
	return dst;
}
Rational& operator--(Rational& dst){
	dst.num(dst.num() - dst.den());
	return dst;
}
Rational operator++(Rational& dst, int){
	Rational old = dst;
	dst.num(dst.num() + dst.den());
	return old;
}
Rational operator--(Rational& dst, int){
	Rational old = dst;
	dst.num(dst.num() - dst.den());
	return old;
}

ostream& operator<<(ostream& out, Rational const& rhs){
	rhs.print(out);
	return out;
}
std::istream& operator>>(std::istream& in, Rational& rhs) {
	int NMR;
	int DNMR;
	char S;

	in >> NMR >> S >> DNMR;

	if (in && S == '/') {
		rhs = Rational(NMR, DNMR);
	}
	else {
		in.setstate(std::ios::failbit);
	}

	return in;
}
