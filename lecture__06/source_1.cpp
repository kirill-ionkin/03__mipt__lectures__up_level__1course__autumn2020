// С++ 6. Перегрузка операторов.
// ссылка на лекцию: https://www.youtube.com/watch?v=el8ZSs-Lf1A&ab_channel=%D0%9B%D0%B5%D0%BA%D1%82%D0%BE%D1%80%D0%B8%D0%B9%D0%A4%D0%9F%D0%9C%D0%98


#include <iostream>


// реализация собственного класса string
class String
{
private:
    size_t sz = 0; // в правильном порядке перечисляем поля
    char* str = nullptr;
    

public:
    // constructor - используем initializer list in constructor
    String(size_t sz, char ch) : sz{sz}, str{new char[sz]}
    {
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


    // getter
    size_t size() const
    {
        return this->sz;
    }


    // 3.6 Constant methods and operator [] overloading  
    char& operator[](size_t index)
    {
        return this->str[index];
    }

    // если строка const, нужно использовать const
    const char& operator[](size_t index) const
    {
        return this->str[index];
    }


    // 3.7 Stream input/output overloading
    // определять нужно вне класа т.к. левый операнд - поток
    friend std::istream& operator>>(std::istream& in, String& s);
};

// 3.7 Stream input/output overloading
// operator <<
std::iostream& operator<<(std::iostream& out, String& s)
{
    for (int i = 0; i < s.size(); ++i)
    {
        out << s[i];
    }
    return out;
}

// operator >>
std::istream& operator>>(std::istream& in, String& s)
{
    
}


int main()
{
    // 3.3 Operators overloading. Assignment operator. The rule of three. (продолжение)
    
    // 3.4 Initializer lists in constructor - Member Initializers
    // см. код конструктора



}
