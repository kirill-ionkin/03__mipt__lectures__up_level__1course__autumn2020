// С++ 4.1. Ссылки и константы.
// ссылка на лекцию: https://www.youtube.com/watch?v=9Vt9SUHNKuE&list=PL4_hYwCyhAvazfCDGyS0wx_hvBmnAAf4h&index=4


#include <iostream>
#include <string>


size_t find(const std::string& text, const std::string& word)
{
    // Если не собираемся менять текст, то используем const ссылки
    return 0;
}


int main()
{
    // 2.5 Constants

    // ссылки
    const int x = 1;
    const std::string s = "abc";


    // int& x1 = 1; // так делать нельзя
    const int& x2 = 1; // а вот так делать можно




    // указатели
    {
        int a = 1;
        
        // указатель на константу
        const int *p = &a; // так делать можно, но при этом изменить значение нельзя
        p++; // так делать можно 
        // (*p)++; // так делать нельзя

        // константный указатель
        int* const p2 = &a;
        // p2++; // так делать нельзя
        (*p2)++; // так делать можно


        // константный указатель на константу
        const int* const p3 = &a;
        // p3++; // так делать нельзя
        // (*p3)++; // так делать нельзя
    }

    {
        int x = 0;
        const int& y = x;
        int& z = y; // Compile Error


        // при этом 
        x++; // можно
        y++; // нельзя
    }
}