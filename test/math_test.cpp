#include <gtest/gtest.h>
#include "commons/math.h"

TEST(MathTest, ShouldCalculateTheSquareOfANumberCorrectly) {
	ASSERT_FLOAT_EQ(9.0f, commons::math::pow2(3.0f));
	ASSERT_FLOAT_EQ(9.0f, commons::math::pow2(-3.0f));
	ASSERT_FLOAT_EQ(0.0f, commons::math::pow2(0.0f));

	ASSERT_FLOAT_EQ(9.0, commons::math::pow2(static_cast<double>(3.0)));
	ASSERT_FLOAT_EQ(9.0, commons::math::pow2(static_cast<double>(-3.0)));
	ASSERT_FLOAT_EQ(0.0, commons::math::pow2(static_cast<double>(0.0)));
}
