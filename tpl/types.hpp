#ifndef TPL_TYPES_HPP_INCLUDED
#define TPL_TYPES_HPP_INCLUDED

#include <cstddef>

namespace tpl
{
    template <typename T, T Value>
    struct Constant
    {
        using type = T;
        const static T value = Value;

        using result = Constant<T, Value>;
    };

    struct Void
    {
        using type = void;

        using result = Void;
    };

    template <bool Value>
    using Bool = Constant<bool, Value>;

    template <int Value>
    using Int = Constant<int, Value>;

    template <unsigned Value>
    using UInt = Constant<unsigned, Value>;

    template <long long Value>
    using LongLong = Constant<long long, Value>;

    template <unsigned long long Value>
    using ULongLong = Constant<unsigned long long, Value>;

    template <size_t Value>
    using SizeT = Constant<size_t, Value>;

    template <char Value>
    using Char = Constant<char, Value>;

    using True = Bool<true>;
    using False = Bool<false>;

}

#endif // TPL_TYPES_HPP_INCLUDED
