// С++ 5. Конструкторы и деструкторы.
// ссылка на лекцию: https://www.youtube.com/watch?v=_3snOmHSErQ&ab_channel=%D0%9B%D0%B5%D0%BA%D1%82%D0%BE%D1%80%D0%B8%D0%B9%D0%A4%D0%9F%D0%9C%D0%98


#include <iostream>
#include <vector>
#include <string>


// реализация собственного класса string
class String
{
private:
    char* str = nullptr;
    size_t sz = 0;

public:
    // constructor
    String(size_t sz, char ch)
    {
        this->sz = sz;
        this->str = new char[sz];

        for (size_t i = 0; i < sz; ++i)
            this->str[i] = ch;

        std::cout << "inside constructor\n";
    }
    
    // initialize list
    String(const std::initializer_list<char> lst)
    {
        this->sz = lst.size();
        this->str = new char[sz];

        std::copy(lst.begin(), lst.end(), this->str);

        std::cout << "inside initialize list constructor\n";
    }



    // constructor copy
    String(const String& s)
    {
        this->sz = s.sz;
        this->str = new char[sz];

        for (size_t i = 0; i < sz; ++i)
        {
            this->str[i] = s.str[i];
        }

        std::cout << "inside copy constructor\n";
    }

    // destructor
    ~String()
    {
        delete [] this->str;

        std::cout << "inside destructor\n";
    }

};


struct S
{
    int x;
    double y;
    std::string s;
};


int main()
{
    // 3.2 Constructors, destructors(продолжение)

    // Shallow copy - поверхностное копирование - копирование полей
    // Deep copy - глубокое копирование - копирование и выделение памяти под данные в полях
    String s(10, 'a');
    String ss = s;

    // since c++ -Initialize List
    std::vector<int> v = {1, 2, 3, 4};
    String sss = {'a', 'b', 'c'}; // это работает с помощью initialize constructor


    // agregate initialization
    {
        S s = {1, 0.2, "asdasd"}; // это работает, хотя
                                  // конструктора initialize list не было реализовано
    }                             // ЭТО можно делать только со Struct с публичными полями
}
