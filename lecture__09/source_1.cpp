// С++ 9. Приведения типов при наследовании.
// ссылка на лекцию: https://www.youtube.com/watch?v=KjHPIXXngEY&list=PL4_hYwCyhAvazfCDGyS0wx_hvBmnAAf4h&index=9


#include <iostream>


struct A
{
    A() {std::cout << "A\n";}
    ~A() {std::cout << "~A\n";}
};

struct B
{
    B() {std::cout << "B\n";}
    ~B() {std::cout << "~B\n";}
};


struct Granny
{
    int x = 0;

    Granny()
    {
        std::cout << "Granny constructor\n";
    }
    ~Granny()
    {
        std::cout << "Granny destructor\n";
    }

    
    Granny(int x)
    {
        std::cout << "Granny constructor, x = " << x << '\n';
    }
};

struct Mom : private Granny
{
    A a;

    Mom()
    {
        std::cout << "Mom constructor\n";
    }
    ~Mom()
    {
        std::cout << "Mom destructor\n";
    }

    
    Mom(int x)
    {
        std::cout << "Mom constructor, x = " << x << '\n';
    }
};

struct Son : public Mom
{
    B b;

    Son()
    {
        std::cout << "Son constructor\n";
    }

    ~Son()
    {
        std::cout << "Son destructor\n";
    }

    Son(int x) : Mom(x) // создание Mom с помощью определённого конструктора класса Mom
    {
        std::cout << "Son constructor, x = " << x << '\n';
    }

    // since c++11
    // using Mom::Mom; // объявление конструктора класса Mom - это нужно для того, 
    // чтобы Son можно было создать используя конструктор класса Mom
};


int main()
{
    // 4.3 Order of constructors and destructors
    {
        Son s;
    }
    

    std::cout << '\n';
    {
        Son s1(1);
    }
    
}
