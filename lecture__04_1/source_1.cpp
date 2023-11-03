// С++ 4.1. Ссылки и константы.
// ссылка на лекцию: https://www.youtube.com/watch?v=9Vt9SUHNKuE&list=PL4_hYwCyhAvazfCDGyS0wx_hvBmnAAf4h&index=4


#include <iostream>


void swap(int x, int y)
{
    int tmp = x;
    x = y;
    y = tmp;
}


void swap_v2(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void swap_v3(int &x, int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}


// ф-я, возвращающая ссылку на локальный обьект (ОПАСНО!)
int& f(int x)
{
    int y = x*2;
    return y;
}


int main()
{
    // 2.4 References
    int x = 1;
    int y = 2;
    swap(x, y);
    // swap не меняет x, y потому что мы передали аргументы по значению, а не по ссылке
    std::cout << x << " " << y << '\n';    

    // передача по указателю 
    swap_v2(&x, &y);
    std::cout << x << " " << y << '\n';

    // Использование ссылок!
    swap_v3(x, y);
    std::cout << x << " " << y << '\n';


    // b, c ссылаются на a
    int a = 10;
    int &b = a;
    int &c = b; // c является ещё одной ссылкой на а, а не ссылкой на ссылку
    std::cout << a << " " << b << " " << c << '\n';


    int d = 0;
    c = d; // теперь a = 0;
    std::cout << a << " " << b << " " << c << '\n';


    // Можно создавать ссылку на указатель, но нельзя создавать указатель на ссылку
    int *p = &x;
    int *&pp = p;
    std::cout << p << " " << pp << '\n';


    // ПРОБЛЕМА! возвращаем ссылку на локальный обьект, который будет уничтожен - UB or seg. fault
    // dangling reference - проблема "подвешенной" ссылки
    // {
    //     int x = f(0); 
    //     std::cout << x << '\n';
    // }


}