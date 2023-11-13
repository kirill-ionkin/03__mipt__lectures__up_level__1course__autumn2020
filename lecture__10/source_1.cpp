// С++ 10. Множественное и виртуальное наследование.
// ссылка на лекцию: https://www.youtube.com/watch?v=zZzwTXOqEvM&list=PL4_hYwCyhAvazfCDGyS0wx_hvBmnAAf4h&index=10&ab_channel=%D0%9B%D0%B5%D0%BA%D1%82%D0%BE%D1%80%D0%B8%D0%B9%D0%A4%D0%9F%D0%9C%D0%98


#include <iostream>


struct Mom
{
    void f()
    {
        std::cout << "Mom::f()\n";
    }
    int m = 1;
};

struct Dad 
{
    void f()
    {
        std::cout << "Dad::f()\n";
    }
    int d = 2;
};

// [ Mom::m ][ Dad::d ][ Son::s ]
struct Son : public Mom, public Dad
{
    int s = 3;
};


int main()
{
    // 4.5 Multiple Inheritance
    Son s;
    std::cout << sizeof(s) << '\n';

    std::cout << "&s.m = " << &s.m << '\n';
    std::cout << "&s.d = " << &s.d << '\n';
    std::cout << "&s.s = " << &s.s << '\n';

    // s.f(); // CE - Compile Error - 2 кандидата равноправных для компилятора
    s.Mom::f(); // вызов конкретной функции у родителя
}