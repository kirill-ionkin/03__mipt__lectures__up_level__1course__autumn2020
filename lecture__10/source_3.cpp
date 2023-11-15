// С++ 10. Множественное и виртуальное наследование.
// ссылка на лекцию: https://www.youtube.com/watch?v=zZzwTXOqEvM&list=PL4_hYwCyhAvazfCDGyS0wx_hvBmnAAf4h&index=10&ab_channel=%D0%9B%D0%B5%D0%BA%D1%82%D0%BE%D1%80%D0%B8%D0%B9%D0%A4%D0%9F%D0%9C%D0%98


#include <iostream>


struct Granny
{
    int g = 0;
    void f()
    {
        std::cout << "Granny::f()\n";
    }
};

struct Mom : public virtual Granny
{
    int m = 1;
    void f()
    {
        std::cout << "Mom::f()\n";
    }
};

struct Dad : public virtual Granny
{
    int d = 1;
    void f()
    {
        std::cout << "Dad::f()\n";
    }
};

struct Son : public Mom, public Dad
{
    int s = 3;
};


int main()
{
    // 4.7 Virtual Inheritance
    Son s;
    std::cout << s.g;

    Dad* pd = &s;

    pd->g;


    std::cout << &s.Mom::m << ' ' << &s.Dad::d << &s.Son::s << '\n';
    std::cout << &s.Dad::g << ' ' << &s.Mom::g << '\n';
}