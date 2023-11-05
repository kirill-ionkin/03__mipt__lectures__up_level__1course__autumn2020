// С++ 4.2. Приведение типов. ООП: Классы и структуры.
// ссылка на лекцию: https://www.youtube.com/watch?v=fgNQAfo4MuM&list=PL4_hYwCyhAvazfCDGyS0wx_hvBmnAAf4h&index=4


#include <iostream>
#include <vector>


void f(int x)
{
    std::cout << x << '\n';
    std::cout << "int" << '\n';
}


void f(double x)
{
    std::cout << x << '\n';
    std::cout << "double" << '\n';
}


void g(int&) {std::cout << "int&" << '\n';}
void g(const int&) {std::cout << "const int&" << '\n';}


int main()
{
    // 2.6 Casts

    // C-style cast
    double d = 0.0;
    int x = (int) d;


    // C++ style cast

    // 1. static_cast
    {
        int x = 2;
        double d = static_cast<double>(x);
        f(x);
        f(d);

        std::vector xv = static_cast<std::vector<int>>(x);
        for (auto elem: xv)
            std::cout << elem << ' ';
        std::cout << '\n';
    }

    std::cout << '\n';
    // 2. reinterpret_cast
    {
        double d = 3.14;
        std::cout << reinterpret_cast<int&>(d) << '\n';
        // вывод первых 4х байт double, и интерпретации их int
        // но всё это UB, поэтому это ОПАСНО!

        int x = 1;
        int *p = &x;
        
        // можно скастовать указатель одного типа к указателю на другой тип\
        // это UB, это ОПАСНО!
        double* pd = reinterpret_cast<double*>(p);
    }

    std::cout << '\n';
    // 3. const_cast
    {   
        // лёгкая версия - неконстантный обьект к константному
        int n = 10;
        g(n); // вызов g(int&)
        g(const_cast<const int&>(n)); // вызов g(const int&)


        // жёсткая версия - наоборот - ОПАСНО
        const int& cn = n;
        g(const_cast<int&>(cn)); // снятие константности - ОПАСНО!

    }

    std::cout << '\n';
    // 4. C-style cast - комбинация предыдущих cast-ов - ОПАСНО!
    {
    }


    // 5. dynamic_cast - пока рано изучать

}