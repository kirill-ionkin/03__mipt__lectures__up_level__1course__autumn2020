// C++ 11. Полиморфизм и виртуальные функции.
// ссылка на лекцию: https://www.youtube.com/watch?v=E92ra2sPdgM&list=PL4_hYwCyhAvazfCDGyS0wx_hvBmnAAf4h&index=14&ab_channel=%D0%9B%D0%B5%D0%BA%D1%82%D0%BE%D1%80%D0%B8%D0%B9%D0%A4%D0%9F%D0%9C%D0%98


#include <iostream>


struct Base
{
    virtual void f() // создание виртуальной фукнции f()
    {
        std::cout << "Base::f()\n";
    }

    void f(int) // non-virtual f(int)
    {
        std::cout << "Base::f(int) non-virtual \n";
    }
};

struct Derived: public Base
{
    int a = 0;
    virtual void f() // здесь virtual писать не обязательно, но лучше писать
    {
        std::cout << "Derived::f()\n";
        std::cout << "Derived::a = " << a << '\n';
    }


};


int main()
{
    // V. Полиморфизм и виртуальные функции
    // 5.1 Идея виртуальной функции

    Derived d;
    Base& b = d;

    d.f();
    b.f();


    // 5.2 Virtual and non-virtual functions combined


}