//
// Created by Veniamin_Arefev on 19.04.2021.
//
//#include <iostream>
//
//class Holder
//{
//    int value = 0;
//
//public:
//    Holder()
//    {
//        std::cin >> value;
//    }
//
//    ~Holder()
//    {
//        std::cout << value << std::endl;
//    }
//
//    void swap(Holder &other)
//    {
//        int tmp = value;
//        value = other.value;
//        other.value = tmp;
//    }
//};

int main()
{
    int count;
    std::cin >> count;
    Holder *mas[count];
    for (int i = 0; i < count;i++) {
        mas[i] = new Holder;
    }

    for (int i = 0; i < count;i++) {
        delete mas[i];
    }
}
