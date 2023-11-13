// С++ 10. Множественное и виртуальное наследование.
// ссылка на лекцию: https://www.youtube.com/watch?v=zZzwTXOqEvM&list=PL4_hYwCyhAvazfCDGyS0wx_hvBmnAAf4h&index=10&ab_channel=%D0%9B%D0%B5%D0%BA%D1%82%D0%BE%D1%80%D0%B8%D0%B9%D0%A4%D0%9F%D0%9C%D0%98


#include <iostream>


struct Granny
{
    int g = 0;
};

struct Mom : public Granny
{
    void f()
    {
        std::cout << "Mom::f()\n";
    }
    int m = 1;
};


struct Son : public Mom, public Granny
{
    int s = 3;
};


int main()
{
    // 4.6 Diamon problem and ambiguos casts
    Son s; // Опасное наследование из-за неопределённости

}