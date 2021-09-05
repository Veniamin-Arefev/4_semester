//
// Created by Veniamin_Arefev on 29.03.2021.
//
#include <iostream>

template<typename T1, typename T2>
class Default_Mul_func {
public:
    T1
    operator()(T1 t1, T2 t2)
    {
        return t1 * t2;
    }
};

template<typename T1, typename T2>
class Default_Add_func {
public:
    T1
    operator()(T1 t1, T2 t2)
    {
        return t1 + t2;
    }
};

template<typename Iter1, typename Iter2,
        typename Mul_func = Default_Mul_func<typename std::iterator_traits<Iter1>::value_type,
                typename std::iterator_traits<Iter2>::value_type>,
        typename Add_func  = Default_Add_func<typename std::iterator_traits<Iter1>::value_type ,
                typename std::iterator_traits<Iter2>::value_type>>
typename std::iterator_traits<Iter1>::value_type
scalar_mul(Iter1 Ibeg, Iter1 Iend, Iter2 I2,
        typename std::iterator_traits<Iter1>::value_type init = typename std::iterator_traits<Iter1>::value_type(),
        Mul_func MulF = Default_Mul_func<typename std::iterator_traits<Iter1>::value_type,
                typename std::iterator_traits<Iter2>::value_type>(),
        Add_func AddF = Default_Add_func<typename std::iterator_traits<Iter1>::value_type ,
                typename std::iterator_traits<Iter2>::value_type>())
{
    for (; Ibeg != Iend; ++Ibeg) {
        init = AddF(init, MulF(*Ibeg, *I2));
        ++I2;
    }
    return init;
}

