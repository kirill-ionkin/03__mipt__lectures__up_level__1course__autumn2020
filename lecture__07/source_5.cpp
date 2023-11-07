// С++ 7. Перегрузка операторов (продолжение).
// ссылка на лекцию: https://www.youtube.com/watch?v=oGwNuB7uflM&ab_channel=%D0%9B%D0%B5%D0%BA%D1%82%D0%BE%D1%80%D0%B8%D0%B9%D0%A4%D0%9F%D0%9C%D0%98


#include <iostream>
#include <vector>


// можно обьявлять класс внутри класса
class A
{
public:
    class B {};

};


int main()
{
    // 3.12 Other operators overloading

    // cppreference operators overloading
    // https://en.cppreference.com/w/cpp/language/operators



    // 3.13 Local classes and inner classes
    A::B a_b; // создание обьекта внутреннего класса


    
    // классы можно создавать внутри ф-ий - локальные классы
    class Local
    {
    public:
        int x = 0;
    };

    Local l;
    std::cout << l.x << '\n';
}