// C++ 3.2. Указатели, массивы, функции, константы... Продолжение.
// ссылка на лекцию: https://www.youtube.com/watch?v=rJUd7YKRFXc&list=PL4_hYwCyhAvazfCDGyS0wx_hvBmnAAf4h&index=2


#include <iostream>


void f(int, int) {}


void g(int) {std::cout << "int\n";}
void g(double) {std::cout << "double\n";}


int main()
{
    void(* pf) (int, int) = &f; // определение указателя на функцию
    std::cout << pf << '\n';


    // переопределение функций
    g(1);
    g(1.0);

}