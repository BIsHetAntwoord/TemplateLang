#ifndef TPL_COMPARE_HPP_INCLUDED
#define TPL_COMPARE_HPP_INCLUDED

#include "tpl/types.hpp"

namespace tpl
{
    //Not
    template <typename T>
    struct Not
    {
        using result = typename Not<typename T::result>::result;
    };

    template <bool Value>
    struct Not<Bool<Value>>
    {
        using result = Bool<!Value>;
    };

    //Equals
    template <typename T, typename U>
    struct Equals
    {
        using result = Bool<false>;
    };

    template <typename T>
    struct Equals<T, T>
    {
        using result = Bool<true>;
    };

    //Not Equals
    template <typename T, typename U>
    struct NotEquals
    {
        using result = typename Not<Equals<T, U>>::result;
    };

    //Less
    template <typename T, typename U>
    struct Less
    {
        using result = Bool<T::result::value < U::result::value>;
    };

    //Greater
    template <typename T, typename U>
    struct Greater
    {
        using result = Bool<(T::result::value > U::result::value)>;
    };

    //LessEqual
    template <typename T, typename U>
    struct LessEquals
    {
        using result = Bool<T::result::value <= U::result::value>;
    };

    //GreaterEqual
    template <typename T, typename U>
    struct GreaterEquals
    {
        using result = Bool<T::result::value >= U::result::value>;
    };

}

#endif // TPL_COMPARE_HPP_INCLUDED
