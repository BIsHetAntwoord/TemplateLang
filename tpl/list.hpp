#ifndef TPL_LIST_HPP_INCLUDED
#define TPL_LIST_HPP_INCLUDED

#include "tpl/types.hpp"

namespace tpl
{
    template <typename Current, typename Next>
    struct List
    {
        using current = Current;
        using next = Next;

        using result = List<Current, Next>;
    };

    //MakeList
    template <typename... Elems>
    struct MakeList;

    template <typename Elem, typename... Elems>
    struct MakeList<Elem, Elems...>
    {
        using result = List<Elem, typename MakeList<Elems...>::result>;
    };

    template <>
    struct MakeList<>
    {
        using result = Void;
    };

    //Get
    template <typename List, typename Index>
    struct Get;

    template <typename Current, typename Next>
    struct Get<List<Current, Next>, SizeT<0>>
    {
        using result = Current;
    };

    template <typename Current, typename Next, size_t index>
    struct Get<List<Current, Next>, SizeT<index>>
    {
        using result = typename Get<Next, SizeT<index - 1>>::result;
    };

    //Set
    template <typename List, typename Index, typename Value>
    struct Set;

    template <typename Current, typename Next, size_t index, typename Value>
    struct Set<List<Current, Next>, SizeT<index>, Value>
    {
        using result = List<Current, typename Set<Next, SizeT<index - 1>, Value>::result>;
    };

    template <typename Current, typename Next, typename Value>
    struct Set<List<Current, Next>, SizeT<0>, Value>
    {
        using result = List<Value, Next>;
    };

    //Apply
    template <typename List, template <typename...> typename Func>
    struct Apply;

    template <typename Current, typename Next, template <typename> typename Func>
    struct Apply<List<Current, Next>, Func>
    {
        using result = List<typename Func<Current>::result, typename Apply<Next, Func>::result>;
    };

    template <template <typename> typename Func>
    struct Apply<Void, Func>
    {
        using result = Void;
    };
}

#endif // TPL_LIST_HPP_INCLUDED
