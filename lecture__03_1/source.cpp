// C++ 3.1. Указатели, массивы, функции, константы...
// ссылка на лекцию: https://www.youtube.com/watch?v=njfH8PHghWo&list=PL4_hYwCyhAvazfCDGyS0wx_hvBmnAAf4h&index=2



#include <iostream>


void f()
{
    std::cout << "inside f()\n";

    int x = 2;
    std::cout << "&x: " << &x << '\n';
    
    int *p = &x;
    std::cout << "*(p - 1): " << *(p - 1) << '\n';
    std::cout << "*(p + 1): " << *(p + 1) << '\n';

    std::cout << "*(p - 2): " << *(p - 2) << '\n';
    std::cout << "*(p + 2): " << *(p + 2) << '\n';
}

int main()
{
    int x = 2;
    std::cout << "&x in main: " << &x << '\n';
    f();
}