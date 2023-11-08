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


    


}