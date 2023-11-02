// C++ 3.2. Указатели, массивы, функции, константы... Продолжение.
// ссылка на лекцию: https://www.youtube.com/watch?v=rJUd7YKRFXc&list=PL4_hYwCyhAvazfCDGyS0wx_hvBmnAAf4h&index=2


#include <iostream>


int main()
{   
    // создание массива в динамической памяти и поис метаданых этого массива
    int *p = new int[100];

    std::cout << *(p - 1) << '\n';
    std::cout << *(p - 2) << '\n'; // пытаемся найти size - вот он 4 * 100 + 17
    std::cout << *(p - 3) << '\n';
    std::cout << *(p - 4) << '\n';
}