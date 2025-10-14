#include "gtest/gtest.h"
#include "rational.hpp"

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
}

TEST(Setters, Getting) {
	Rational r;

	ASSERT_NO_THROW(r.num(3));
	ASSERT_NO_THROW(r.den(9));

	ASSERT_EQ(r.num(), 1);
	ASSERT_EQ(r.den(), 3);
}

TEST(ValueCtor, Init) {
	Rational r{ 1,2 };

	ASSERT_EQ(r.num(), 1);
	ASSERT_EQ(r.den(), 2);

	ASSERT_THROW(r = Rational(1, 0), std::domain_error);
}