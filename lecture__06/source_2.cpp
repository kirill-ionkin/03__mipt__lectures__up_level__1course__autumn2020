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

    // ++
    Complex& operator++(int notused)
    {
        
    }

};


int main()
{
    // 3.5 Arithmetic operators overloading
    Complex c = {1.0, 2.0};
    // copy elision
    Complex cc = c + c;
}