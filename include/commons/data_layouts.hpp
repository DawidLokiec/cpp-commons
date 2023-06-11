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

    };
}

#endif //CPP_COMMONS_DATA_LAYOUTS_HPP
