#ifndef TPL_MAP_HPP_INCLUDED
#define TPL_MAP_HPP_INCLUDED

#include "tpl/types.hpp"
#include "tpl/compare.hpp"
#include "tpl/if.hpp"
#include "tpl/arith.hpp"

namespace tpl
{
    template <typename Key, typename Value>
    struct MapEntry
    {
        using key = Key;
        using value = Value;

        using result = MapEntry<Key, Value>;
    };

    template <typename Current, typename Next>
    struct Map
    {
        using current = Current;
        using next = Next;

        using result = Map<Current, Next>;
    };

    //Get
    template <typename Map, typename Key>
    struct Get;

    template <typename Key, typename Value, typename Next>
    struct Get<Map<MapEntry<Key, Value>, Next>, Key>
    {
        using result = Value;
    };

    template <typename Entry, typename Next, typename Key>
    struct Get<Map<Entry, Next>, Key>
    {
        using result = typename Get<Next, Key>::result;
    };

    template <typename Key>
    struct Get<Void, Key>
    {

    };

    //MakeMap
    template <typename... Entries>
    struct MakeMap;

    template <typename Entry, typename... Entries>
    struct MakeMap<Entry, Entries...>
    {
        using result = Map<Entry, typename MakeMap<Entries...>::result>;
    };

    template<>
    struct MakeMap<>
    {
        using result = Void;
    };

    //Set
    template <typename Map, typename Key, typename NewValue>
    struct Set;

    template <typename Key, typename OldValue, typename NewValue, typename Next>
    struct Set<Map<MapEntry<Key, OldValue>, Next>, Key, NewValue>
    {
        using result = Map<MapEntry<Key, NewValue>, Next>;
    };

    template <typename Key, typename NewValue, typename Entry, typename Next>
    struct Set<Map<Entry, Next>, Key, NewValue>
    {
        using result = Map<Entry, typename Set<Next, Key, NewValue>::result>;
    };

    template <typename Key, typename NewValue>
    struct Set<Void, Key, NewValue>
    {
        using result = Map<MapEntry<Key, NewValue>, Void>;
    };

    //Contains
    template <typename Map, typename Key>
    struct Contains;

    template <typename Key, typename Value, typename Next>
    struct Contains<Map<MapEntry<Key, Value>, Next>, Key>
    {
        using result = True;
    };

    template <typename Key, typename Entry, typename Next>
    struct Contains<Map<Entry, Next>, Key>
    {
        using result = typename Contains<Next, Key>::result;
    };

    template <typename Key>
    struct Contains<Void, Key>
    {
        using result = False;
    };

    //Size
    template <typename Map>
    struct Size;

    template <typename Entry, typename Next>
    struct Size<Map<Entry, Next>>
    {
        using result = typename Add<typename Size<Next>::result, SizeT<1>>::result;
    };

    template<>
    struct Size<Void>
    {
        using result = SizeT<0>;
    };

    //Apply
    template <typename Map, template <typename...> typename Func>
    struct Apply;

    template <typename Key, typename Value, typename Next, template <typename, typename> typename Func>
    struct Apply<Map<MapEntry<Key, Value>, Next>, Func>
    {
        using result = Map<typename Func<Key, Value>::result, typename Apply<Next, Func>::result>;
    };

    template <template <typename, typename> typename Func>
    struct Apply<Void, Func>
    {
        using result = Void;
    };

}

#endif // TPL_MAP_HPP_INCLUDED
