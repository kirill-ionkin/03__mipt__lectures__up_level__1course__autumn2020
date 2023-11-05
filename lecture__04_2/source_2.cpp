// С++ 4.2. Приведение типов. ООП: Классы и структуры.
// ссылка на лекцию: https://www.youtube.com/watch?v=fgNQAfo4MuM&list=PL4_hYwCyhAvazfCDGyS0wx_hvBmnAAf4h&index=4


#include <iostream>
#include <vector>


class MyClass
{
private:
    //fields
    int x = 0;
    char *p = nullptr;
    std::vector<int> v = {};

public:
    //methods
    void print(int a)
    {
        std::cout << x + a << '\n';
    }
};


class MyClass2
{
private:
    //fields
    int x = 0;
    char *p = nullptr;
    std::vector<int> v = {};

public:
    // constructor
    MyClass2(int n)
    {
        v.reserve(n);
    }

    //methods
    void print(int a)
    {
        std::cout << x + a << '\n';
    }
};

int main()
{
    // III. OOP basics: classes and structures
    // 3.1 Concepts of class and struct, incapsulateions

    MyClass obj;
    obj.print(10);

    // 3.2 Constructors, destructors(начало)
    MyClass2 obj2(10);
}