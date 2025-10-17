#pragma once
#include <iostream>
#include <compare>

class Rational {
		struct fraction {
		int NMR;
		int DNMR;
	};
public:
	Rational();
	Rational(int NMR, int DNMR);
	Rational(int i);
	Rational(double d);

	explicit operator int() const;
	explicit operator double()const;

	int num() const;
	void num(int nmr);

	int den() const;
	void den(int dnmr);

	void print(std::ostream& out) const;

private:
	void inline update(fraction newRational);
	int inline commonFactor(int a, int b);
	void inline validate(fraction newRational);

	fraction rational;

	static int doubleBase;
};

bool operator ==(Rational const& lhs, Rational const& rhs);
bool operator !=(Rational const& lhs, Rational const& rhs);
std::strong_ordering operator<=>(Rational const& lhs, Rational const& rhs);

Rational operator +(Rational const& lhs, Rational const& rhs);
Rational operator -(Rational const& lhs, Rational const& rhs);
Rational operator *(Rational const& lhs, Rational const& rhs);
Rational operator /(Rational const& lhs, Rational const& rhs);
Rational operator -(Rational const& lhs);

Rational& operator +=(Rational& dst, Rational const& src);
Rational& operator -=(Rational& dst, Rational const& src);
Rational& operator *=(Rational& dst, Rational const& src);
Rational& operator /=(Rational& dst, Rational const& src);

Rational& operator++(Rational& dst);
Rational& operator--(Rational& dst);
Rational operator++(Rational& dst, int);
Rational operator--(Rational& dst, int);

std::ostream& operator<<(std::ostream& out, Rational const& rhs );
std::istream& operator>>(std::istream& in, Rational& rhs);