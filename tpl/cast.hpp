#ifndef TPL_CAST_HPP_INCLUDED
#define TPL_CAST_HPP_INCLUDED

#include "tpl/types.hpp"

namespace tpl
{
    template <typename To, typename From>
    struct Cast
    {
        using result = Constant<To, (To)From::result::value>;
    };
}

#endif // TPL_CAST_HPP_INCLUDED
