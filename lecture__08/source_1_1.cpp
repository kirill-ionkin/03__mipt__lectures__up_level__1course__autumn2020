// C++ 8. Наследование, видимость и доступность при наследовании.
// ссылка на лекцию: https://www.youtube.com/watch?v=Jw2hP7fAqXg&list=PL4_hYwCyhAvazfCDGyS0wx_hvBmnAAf4h&index=8


#include <iostream>


class Base
{
private:
    int x = 10;
protected:
    int y = 20;

public:
    int a = 0;
    void f()
    {
        std::cout << "Base::f()" << '\n';
    }
};

class Derived: public Base
{
public:
    int b = 1;
    void g()
    {
        std::cout << "Derived::g()" << '\n';
    }
};


int main()
{
    // IV. Inheritance(наследование)
    
    // 4.1 Public, private and protected inheritance - пример public наследования

    Derived d;
    d.g();
    d.f();

    std::cout << d.a << '\n';
    std::cout << d.b << '\n';

    // d.x; // Нельзя, т.к. поля базового класса private, protected
    // d.y; //  
    
}   
