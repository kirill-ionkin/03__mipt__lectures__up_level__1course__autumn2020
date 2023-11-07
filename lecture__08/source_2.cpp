// C++ 8. Наследование, видимость и доступность при наследовании.
// ссылка на лекцию: https://www.youtube.com/watch?v=Jw2hP7fAqXg&list=PL4_hYwCyhAvazfCDGyS0wx_hvBmnAAf4h&index=8


#include <iostream>


struct Mom
{
    int a = 0;
    void f()
    {
        std::cout << "Mom" << '\n';
    }
};

struct Son : Mom
{
    int a = 1;
    void f()
    {
        std::cout << "Son" << '\n';
    }
};


int main()
{
    // IV. Inheritance(наследование)

    // 4.2 Visibility and accessibility
    Son s;
    s.f(); // вызов Son::f()
    s.Mom::f(); // вызов именно функцию родительского класса Mom::f()

    std::cout << s.a << '\n'; // вызов Son::a
    std::cout << s.Mom::a << '\n'; // вызов именно функцию родительского класса Mom::a
} 