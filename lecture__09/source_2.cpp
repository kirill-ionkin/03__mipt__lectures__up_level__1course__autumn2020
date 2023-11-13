// С++ 9. Приведения типов при наследовании.
// ссылка на лекцию: https://www.youtube.com/watch?v=KjHPIXXngEY&list=PL4_hYwCyhAvazfCDGyS0wx_hvBmnAAf4h&index=9


#include <iostream>


struct Base
{
    int a = 0;

    Base() {};

    Base(const Base& b)
    {
        std::cout << "Base copy constructor\n";
    }
};

struct Derived : public Base
{
    int a = 1;
    Derived() {};
};


void f(const Base& b) // хочется мочь передавать также наследника по такому аргументу
{
    std::cout << b.a << '\n';
}

void g(Base* b)
{
    std::cout << b->a << '\n';
}


int main()
{
    // 4.4 Casts between base and derived classes
    Derived d;

    f(d); // происходит неявный cast ссылки наследника на ссылку базового класса
    g(&d); // также неявный cast
    
    // как можно заметить, обращение к полю базового класса происходит
    
    Base& b = d; // b указывает на базовую часть обьекта d Derived
    std::cout << b.a << '\n';
    std::cout << sizeof(b) << '\n';

    std::cout << d.a << '\n';
    std::cout << sizeof(d) << '\n';
    
    std::cout << *(&b.a + 1) << '\n';

    std::cout << &b.a << '\n';
    std::cout << &d.a << '\n';


    // А что, если мы хотим сделать cast в обратную сторону?
    // Derived dd = b; // Compile Error т.к. нужен конструктор Deriver от Base

    // Derived& dd = b; // в эту сторону так делать нельзя
    
    
    // Если мы очень хотим, то нам поможет static_cast
    Derived& dd = static_cast<Derived&>(b);
    std::cout << dd.a << '\n';


    // НО static_case не позволяет кастовать
    // между классами, не связанными иерархией наследования
    

}