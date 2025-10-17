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

	operator int() const;
	operator double()const;

	int num() const;
	void num(int nmr);

	int den() const;
	void den(int dnmr);

	void print(std::ostream& out) const;

private:
	void inline update(fraction newRational) {
		rational = newRational;

		int gcf = commonFactor(rational.NMR, rational.DNMR);
		rational.NMR = rational.NMR / gcf;
		rational.DNMR = rational.DNMR / gcf;
	}
	int inline commonFactor(int a, int b) {
		a = abs(a);
		b = abs(b);
		if (a % b == 0) {
			return b;
		}
		else {
			return commonFactor(b, a % b);
		}
	}	
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

Rational operator +=(Rational& dst, Rational const& src);
Rational operator -=(Rational& dst, Rational const& src);
Rational operator *=(Rational& dst, Rational const& src);
Rational operator /=(Rational& dst, Rational const& src);

Rational& operator++(Rational& dst);
Rational& operator--(Rational& dst);
Rational operator++(Rational& dst, int);
Rational operator--(Rational& dst, int);

std::ostream& operator<<(std::ostream& out, Rational const& rhs );
std::istream& operator>>(std::istream& in, Rational& rhs);