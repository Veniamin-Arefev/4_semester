//
// Created by Veniamin_Arefev on 22.03.2021.
//
template<typename T, typename Predict> T myfilter(const T &t, Predict predict) {
    T answer = T();
    auto iter = t.begin();
    while (iter != t.end()) {
        if (predict(*iter)) {
            answer.insert(answer.end(), *iter);
        }
        ++iter;
    }
    return answer;
}
