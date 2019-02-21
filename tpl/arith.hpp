#ifndef TPL_ARITH_HPP_INCLUDED
#define TPL_ARITH_HPP_INCLUDED

#include "tpl/types.hpp"

namespace tpl
{
    template <typename T, typename U>
    struct Add
    {
        private:
            const static auto arith = T::result::value + U::result::value;
        public:
            using result = Constant<decltype(arith), arith>;
    };

    template <typename T, typename U>
    struct Sub
    {
        private:
            const static auto arith = T::result::value - U::result::value;
        public:
            using result = Constant<decltype(arith), arith>;
    };

    template <typename T, typename U>
    struct Mul
    {
        private:
            const static auto arith = T::result::value * U::result::value;
        public:
            using result = Constant<decltype(arith), arith>;
    };

    template <typename T, typename U>
    struct Div
    {
        private:
            const static auto arith = T::result::value / U::result::value;
        public:
            using result = Constant<decltype(arith), arith>;
    };

    template <typename T, typename U>
    struct Mod
    {
        private:
            const static auto arith = T::result::value % U::result::value;
        public:
            using result = Constant<decltype(arith), arith>;
    };

    template <typename T, typename U>
    struct LShift
    {
        private:
            const static auto arith = T::result::value << U::result::value;
        public:
            using result = Constant<decltype(arith), arith>;
    };

    template <typename T, typename U>
    struct RShift
    {
        private:
            const static auto arith = T::result::value >> U::result::value;
        public:
            using result = Constant<decltype(arith), arith>;
    };

    template <typename T, typename U>
    struct BitAnd
    {
        private:
            const static auto arith = T::result::value & U::result::value;
        public:
            using result = Constant<decltype(arith), arith>;
    };

    template <typename T, typename U>
    struct BitOr
    {
        private:
            const static auto arith = T::result::value | U::result::value;
        public:
            using result = Constant<decltype(arith), arith>;
    };

    template <typename T, typename U>
    struct BitXor
    {
        private:
            const static auto arith = T::result::value ^ U::result::value;
        public:
            using result = Constant<decltype(arith), arith>;
    };

    template <typename T>
    struct Compl
    {
        private:
            const static auto arith = ~T::result::value;
        public:
            using result = Constant<decltype(arith), arith>;
    };

    template <typename T>
    struct Neg
    {
        private:
            const static auto arith = -T::result::value;
        public:
            using result = Constant<decltype(arith), arith>;
    };
}

#endif // TPL_ARITH_HPP_INCLUDED
