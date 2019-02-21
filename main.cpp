#include "tpl.hpp"

using namespace tpl;

#include <iostream>
#include <typeinfo>
#include <cxxabi.h>

using L = MakeMap<MapEntry<Int<2>, Int<5>>, MapEntry<Int<4>, Int<8>>>::result;

template <typename Key, typename Value>
using Func = MapEntry<Value, Key>;

using Result = Apply<L, Func>::result;

int main()
{
    int stat;
    char* data = abi::__cxa_demangle(typeid(Result::result).name(), 0, 0, &stat);
    std::cout << data << std::endl;
    std::free(data);

    return 0;
}
