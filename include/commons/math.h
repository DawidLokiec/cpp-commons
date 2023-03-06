#ifndef CPP_COMMONS_MATH_H
#define CPP_COMMONS_MATH_H

/**
 * @brief Namespace for math-related functions and classes.
 */
namespace commons::math {

	/**
	 * @brief Calculates the square of the given double-precision floating-point number.
	 * @param x the double-precision floating-point number to calculate the square of.
	 * @return the square of the input number.
	 */
	inline double pow2(const double x) {
		return x * x;
	}

	/**
	  * @brief Calculates the square of the given single-precision floating-point.
	  * @param x the single-precision floating-point number to calculate the square of.
	  * @return the square of the input number.
	  */
	inline float pow2(const float x) {
		return x * x;
	}
}

#endif //CPP_COMMONS_MATH_H
