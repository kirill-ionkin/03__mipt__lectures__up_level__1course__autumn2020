// С++ 5. Конструкторы и деструкторы.
// ссылка на лекцию: https://www.youtube.com/watch?v=_3snOmHSErQ&ab_channel=%D0%9B%D0%B5%D0%BA%D1%82%D0%BE%D1%80%D0%B8%D0%B9%D0%A4%D0%9F%D0%9C%D0%98


#include <iostream>


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

    // ASSIGNMENT OPERATOR
    String& operator=(const String& s)
    {
        // check situation s = s;
        if (this == &s) return *this;


        // free old memory
        delete [] this->str;

        // get data from s
        this->sz = s.sz;
        this->str = s.str;
        for (size_t i = 0; i < sz; ++i)
        {
            this->str[i] = s.str[i];
        }

        return *this;
    }

    // ДРУГОЙ СПОСОБ СОЗДАНИЯ ОПЕРАТОРА ПРИСВАИВАНИЯ ЧЕРЕЗ КОНСТУРКТОР КОПИРОВАНИЯ И SWAP
    // // copy and swap
    // void swap(String& s)
    // {
    //     std::swap(this->str, s.str);
    //     std::swap(this->sz, s.sz);
    // }
    // // ASSIGNMENT OPERATOR with swap implementation!!!
    // String& operator=(const String& s)
    // {
    //     // check situation s = s;
    //     if (this == &s) return *this;

    //     // ! КЛАССНО!
    //     String copy_str = s; // создаём копию строки s
    //     this->swap(copy_str); // и меняем нашу строку с созданной копией 

    //     return *this;
    // }

    // destructor
    ~String()
    {
        delete [] this->str;

        std::cout << "inside destructor\n";
    }
};

int main()
{
    // 3.3 Operators overloading. Assignment operator. The rule of three. (начало)

    // Реализация оператора присваивания 
    // по чесному и элегантно с помощью 
    // коструктора копирования и swap
}
