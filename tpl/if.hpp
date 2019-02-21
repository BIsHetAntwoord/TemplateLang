#ifndef TPL_IF_HPP_INCLUDED
#define TPL_IF_HPP_INCLUDED

namespace tpl
{
    template <typename Cond, typename Stat, typename... Rest>
    struct If;

    template <typename Stat, typename... Rest>
    struct If<True, Stat, Rest...>
    {
        using result = typename Stat::result;
    };

    template <typename Stat, typename... Rest>
    struct If<False, Stat, Rest...>
    {
        using result = typename If<Rest...>::result;
    };

    template <typename Stat, typename Else>
    struct If<True, Stat, Else>
    {
        using result = typename Stat::result;
    };

    template <typename Stat, typename Else>
    struct If<False, Stat, Else>
    {
        using result = typename Else::result;
    };

    template <typename Stat>
    struct If<True, Stat>
    {
        using result = typename Stat::result;
    };

    template <typename Stat>
    struct If<False, Stat>
    {
    };
}

#endif // TPL_IF_HPP_INCLUDED
