#ifndef TPL_STRING_HPP_INCLUDED
#define TPL_STRING_HPP_INCLUDED

#include "tpl/types.hpp"

namespace tpl
{
    //String
    template <char... Text>
    struct String
    {
        const static char value[sizeof...(Text)];

        using type = decltype(value);
        using result = String<Text...>;
    };


    template <char... Text>
    const char String<Text...>::value[sizeof...(Text)] = {Text...};

    //Append
    template <typename T, typename U>
    struct Append;

    template <char... A, char... B>
    struct Append<String<A...>, String<B...>>
    {
        using result = String<A..., B...>;
    };

    //Get
    template <typename T, typename Index>
    struct Get;

    template <char C, char... Text, size_t Index>
    struct Get<String<C, Text...>, SizeT<Index>>
    {
        using result = typename Get<String<Text...>, SizeT<Index-1>>::result;
    };

    template <char C, char... Text>
    struct Get<String<C, Text...>, SizeT<0>>
    {
        using result = Char<C>;
    };

    //Set
    template <typename T, typename Index, typename NewValue>
    struct Set;

    template <char C, char... Text, size_t index, char NewValue>
    struct Set<String<C, Text...>, SizeT<index>, Char<NewValue>>
    {
        using result = typename Append<String<C>, typename Set<String<Text...>, SizeT<index-1>, Char<NewValue>>::result>::result;
    };

    template <char C, char... Text, char NewValue>
    struct Set<String<C, Text...>, SizeT<0>, Char<NewValue>>
    {
        using result = typename Append<String<NewValue>, String<Text...>>::result;
    };

    //Transform
    template <typename T, template <typename> typename Func>
    struct Transform;

    template <char C, char... Text, template <typename> typename Func>
    struct Transform<String<C, Text...>, Func>
    {
        using result = typename Append<String<Func<Char<C>>::result::value>, typename Transform<String<Text...>, Func>::result>::result;
    };

    template <char C, template <typename> typename Func>
    struct Transform<String<C>, Func>
    {
        using result = String<Func<Char<C>>::result::value>;
    };

    //Size
    template <typename T>
    struct Size;

    template<char... Text>
    struct Size<String<Text...>>
    {
        using result = SizeT<sizeof...(Text)>;
    };
}

#endif // TPL_STRING_HPP_INCLUDED
