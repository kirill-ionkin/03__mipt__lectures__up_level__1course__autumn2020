// С++ 7. Перегрузка операторов (продолжение).
// ссылка на лекцию: https://www.youtube.com/watch?v=oGwNuB7uflM&ab_channel=%D0%9B%D0%B5%D0%BA%D1%82%D0%BE%D1%80%D0%B8%D0%B9%D0%A4%D0%9F%D0%9C%D0%98


#include <iostream>


class UserId
{
    int id = 0;
public:
    UserId(int id) : id{id} {}

    // оператор приведения нашего класса к типу int
    explicit operator int() // explicit не разрешает неявно делать cast 
    {
        std::cout << "inside explicit operator int()\n";
        return id;
    }
};

// Literal suffixes overloading (since c++11)
UserId operator ""_uid(unsigned long long x)
{
    return UserId(x);
}


int main()
{
    // 3.9 Type conversion overloading and explicit keyword

    // Можно переопределить оператор приведения типа
    UserId id = 10;
    std::cout << int(id) + 1 << '\n'; // происходит неявный cast к типу int

    // хотя чисто из логики, складывать id с чем угодно, это странно
    // поэтому нужно уметь ЗАПРЕЩАТЬ НЕЯВНЫЕ cast-ы
    // для этого есть explicit!
    
    // Literal suffixes overloading (since c++11)
    std::cout << int(2_uid) << '\n';
    
}