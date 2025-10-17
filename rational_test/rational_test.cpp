#include "gtest/gtest.h"
#include "rational.hpp"
#include <string>
#include <sstream>

using std::string;
using std::ostringstream;

TEST(DefaultCtor, Init) {
	ASSERT_NO_THROW(Rational r);

	Rational r;
	ASSERT_EQ(r.num(), 0);
	ASSERT_EQ(r.den(), 1);
}

TEST(Setters, Setting) {
	Rational r;

	ASSERT_NO_THROW(r.num(3));
	ASSERT_NO_THROW(r.den(9));
	ASSERT_THROW(r.den(0), std::domain_error);
}
TEST(Setters, Getting) {
	Rational r;

	ASSERT_NO_THROW(r.num(3));
	ASSERT_NO_THROW(r.den(9));

	ASSERT_EQ(r.num(), 1);
	ASSERT_EQ(r.den(), 3);
	
	ostringstream sout;
	r.print(sout);
	ASSERT_EQ(sout.str(), "1/3");
}

TEST(ValueCtor, Init) {
	Rational r{ 1,2 };

	ASSERT_EQ(r.num(), 1);
	ASSERT_EQ(r.den(), 2);

	ASSERT_THROW(r = Rational(1, 0), std::domain_error);
}

TEST(CompareOp, Equality) {
	Rational lhs{ 1,2 };
	Rational rhs{ 1,2 };
	
	ASSERT_EQ(lhs, rhs);
}
TEST(CompareOp, NEquality) {
	Rational lhs{ 1,2 };
	Rational rhs{ 1,3 };

	ASSERT_NE(lhs, rhs);
}
TEST(CompareOp, Lesser) {
	Rational lhs(1, 3);
	Rational rhs(1, 2);

	ASSERT_LT(lhs, rhs);
}
TEST(CompareOp, Greater) {
	Rational lhs(1, 2);
	Rational rhs(1, 3);

	ASSERT_GT(lhs, rhs);
}
TEST(CompareO, LesserE) {
	Rational lhs(1, 3);
	Rational rhs(1, 3);

	ASSERT_LE(lhs, rhs);
}
TEST(CompareOp, GreaterE) {
	Rational lhs(1, 3);
	Rational rhs(1, 3);

	ASSERT_GE(lhs, rhs);
}

TEST(MathOps, Addition) {
	Rational lhs{ 1,2 };
	Rational rhs{ 1,3 };
	Rational answer{ 5 , 6 };

	ASSERT_EQ(lhs + rhs, answer);
}
TEST(MathOps, Subtraction) {
	Rational lhs{ 5 , 6 };
	Rational rhs{ 1,3 };
	Rational answer{ 1,2 };

	ASSERT_EQ(lhs - rhs, answer);
}
TEST(MathOps, Multiplication) {
	Rational lhs{ 2,3 };
	Rational rhs{ 3,4 };
	Rational answer{ 1,2 };

	ASSERT_EQ(lhs * rhs, answer);
}
TEST(MathOps, Dvision) {
	Rational lhs{ 1,2 };
	Rational rhs{ 1,3 };
	Rational answer{ 3,2 };

	ASSERT_EQ(lhs / rhs, answer);
	ASSERT_THROW(lhs / (rhs - rhs), std::domain_error);
}

TEST(MathAssignOps, Addition) {
	Rational lhs{ 1,2 };
	Rational rhs{ 1,3 };
	Rational answer{ 5 , 6 };

	lhs += rhs;
	ASSERT_EQ(lhs, answer);
}
TEST(MathAssignOps, Subtraction) {
	Rational lhs{ 5 , 6 };
	Rational rhs{ 1,3 };
	Rational answer{ 1,2 };

	lhs -= rhs;
	ASSERT_EQ(lhs, answer);
}
TEST(MathAssignOps, Multiplication) {
	Rational lhs{ 2,3 };
	Rational rhs{ 3,4 };
	Rational answer{ 1,2 };

	lhs *= rhs;
	ASSERT_EQ(lhs, answer);
}
TEST(MathAssignOps, Division) {
	Rational lhs{ 1,2 };
	Rational rhs{ 1,3 };
	Rational answer{ 3,2 };

	lhs /= rhs;
	ASSERT_EQ(lhs, answer);
	ASSERT_THROW(lhs / (rhs - rhs), std::domain_error);
}
TEST(MathAssignOps, Prefix) {
	Rational r(1, 3);
	Rational answer = r;

	++r;
	ASSERT_NE(r, answer);
	--r;
	ASSERT_EQ(r, answer);
}
TEST(MathAssignOps, Postfix) {
	Rational r(1, 3);
	Rational answer = r;

	r++;
	ASSERT_NE(r, answer);
	r--;
	ASSERT_EQ(r, answer);
}