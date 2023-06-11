#ifndef CPP_COMMONS_DATA_LAYOUTS_HPP
#define CPP_COMMONS_DATA_LAYOUTS_HPP

#include <tuple>
#include <vector>

/**
 * @brief Namespace for data layout-related functions and classes.
 */
namespace commons::layout {

    /**
     * @brief Array of structures data layout.
     *
     * @details This data structure represents an array of structures (AoS) layout, which stores multiple structures
     * as elements of a vector. Each structure in the vector corresponds to a tuple of types specified as template
     * parameters.
     *
     * @tparam TS Variadic template parameter pack for the types of elements in each structure.
     */
    template<typename... TS>
    struct [[maybe_unused]] ArrayOfStructures : std::vector<std::tuple<TS...>> {

        /**
         * @brief Default constructor.
         *
         * @details Constructs an empty ArrayOfStructures object.
         */
        ArrayOfStructures() : std::vector<std::tuple<TS...>>() {

        }

        /**
         * @brief Size constructor.
         *
         * @details Constructs an ArrayOfStructures object with a specified size.
         *
         * @param size The size of the ArrayOfStructures.
         */
        explicit ArrayOfStructures(const size_t size) : std::vector<std::tuple<TS...>>(size) {

        }

        /**
         * @brief Field access operator.
         *
         * @details Retrieves the value of a field at a specific element index.
         *
         * @tparam Index The index of the field to retrieve.
         * @param elementIndex The index of the element in the ArrayOfStructures.
         * @param fieldIndex The index of the field in the tuple.
         * @return The value of the specified field at the specified element index.
         */
        template<size_t Index>
        auto operator()(const size_t elementIndex, const std::integral_constant<std::size_t, Index> fieldIndex) {
            return std::get<fieldIndex.value>((*this)[elementIndex]);
        }
    };

    /**
     * @brief Structure of arrays data layout.
     *
     * @details This data structure represents a structure of arrays (SoA) layout, which stores multiple arrays of
     * different types as members of a tuple. Each array in the tuple corresponds to a specific type specified as a
     * template parameter.
     *
     * @tparam TS Variadic template parameter pack for the types of arrays.
     */
    template<typename... TS>
    struct [[maybe_unused]] StructureOfArrays : std::tuple<std::vector<TS>...> {

        /**
         * @brief Field access operator.
         *
         * @details Retrieves the value of a field at a specific element index.
         *
         * @tparam Index The index of the field to retrieve.
         * @param elementIndex The index of the element in the StructureOfArrays.
         * @param fieldIndex The index of the field in the tuple.
         * @return The value of the specified field at the specified element index.
         */
        template<size_t Index>
        auto operator()(const size_t elementIndex, const std::integral_constant<std::size_t, Index> fieldIndex) {
            const auto &element = std::get<fieldIndex.value>(*this);
            return element[elementIndex];
        }
    };
}

#endif //CPP_COMMONS_DATA_LAYOUTS_HPP
