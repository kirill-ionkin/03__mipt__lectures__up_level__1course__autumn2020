// С++ 6. Перегрузка операторов.
// ссылка на лекцию: https://www.youtube.com/watch?v=el8ZSs-Lf1A&ab_channel=%D0%9B%D0%B5%D0%BA%D1%82%D0%BE%D1%80%D0%B8%D0%B9%D0%A4%D0%9F%D0%9C%D0%98


#include <iostream>


// +, +=, ++
// В 1ую очередь определяется +=
class Complex
{
public:
    double re;
    double im;

public:
    Complex(double x) : re{x}, im{0.0} {}
    Complex(double re, double im): re{re}, im{im} {}
    Complex(const Complex&)
    {
        std::cout << "Copy constructor" << '\n';
    }


    // Реализация операторов
    // +=
    Complex& operator+=(const Complex& c)
    {
        this->re += c.re;
        this->im += c.im;

        return *this;
    }

    // +
    // return value optimization
    Complex operator+(const Complex& c)
    {
        Complex sum = *this; // создаём копию с помощью конструктора копирования
        return sum += c;
    }

    // ++ prefix
    Complex& operator++()
    {
        ++(this->re);
        return *this;
    }
    // ++ postfix
    Complex operator++(int)
    {
        Complex tmp = *this;

        ++*this; // call ++ prefix
        return tmp;
    }
};

// Оператор + надо реализовать вне класса,
// чтобы можно было складывать - 5.0 + Complex(1, 2)
Complex operator+(const Complex& a, const Complex& c)
{
    Complex sum = a;
    sum += c;
    return sum;
}


int main()
{
    // 3.5 Arithmetic operators overloading
    Complex c = {1.0, 2.0};
    // copy elision
    Complex cc = c + c;

    // реализация + вне класса повзволяет писать
    Complex c5 = 5.0 + c;

    // 3.6 Constant methods and operator [] overloading
    // реализацию см. в source1.cpp, class String

    // 3.7 Stream input/output overloading
    // реализацию см. в source1.cpp, class String
}