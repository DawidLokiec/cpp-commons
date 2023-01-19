#ifndef SIMULATION_ENGINE_LANGUAGE_H
#define SIMULATION_ENGINE_LANGUAGE_H

/**
 * The namespace of the current library.
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
	[[maybe_unused]] inline bool isInstanceOf(const A *pointer) {
		return (nullptr != dynamic_cast<const B *>(pointer));
	}
}

#endif //SIMULATION_ENGINE_LANGUAGE_H
