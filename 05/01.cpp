//
// Created by Veniamin_Arefev on 22.03.2021.
//
template<typename T> typename T::value_type process(const T &t) {
    typename T::value_type sum = typename T::value_type();
    if (t.empty()) {
        return sum;
    }
    auto it = t.rbegin();
    int i = 0;
    while (it != t.rend() && (i <= 5)) {
        if (i % 2 == 0) {
            sum += *it;
        }
        ++i;
        ++it;
    }
    return sum;
}