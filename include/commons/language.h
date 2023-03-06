#ifndef CPP_COMMONS_LANGUAGE_H
#define CPP_COMMONS_LANGUAGE_H

/**
 * @brief Namespace for C++ language-related functions and classes.
 */
namespace commons {
	/**
	 * @brief Returns true if the given pointer of type A can be cast to a pointer of type B.
	 * @details This function is the implementation of the <code>instanceof</code>-operator in <strong>Java</strong>.
	 * @tparam A The type A.
	 * @tparam B The type B.
	 * @param pointer the pointer of type A to be checked if it can be cast to a pointer of type B.
	 * @return true if the given pointer of type A can be cast to a pointer of type B.
	 */
	template<typename A, typename B>
	[[maybe_unused]] [[nodiscard]] inline bool isInstanceOf(const A *pointer) {
		return (nullptr != dynamic_cast<const B *>(pointer));
	}
}

#endif //CPP_COMMONS_LANGUAGE_H
