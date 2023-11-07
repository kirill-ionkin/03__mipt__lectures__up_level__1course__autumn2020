// С++ 7. Перегрузка операторов (продолжение).
// ссылка на лекцию: https://www.youtube.com/watch?v=oGwNuB7uflM&ab_channel=%D0%9B%D0%B5%D0%BA%D1%82%D0%BE%D1%80%D0%B8%D0%B9%D0%A4%D0%9F%D0%9C%D0%98


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>


// функциональный класс
class GreaterThanZero
{
public:
    bool operator()(int x)
    {
        return x > 0;
    }
};


class MyComparator
{
public:
    bool operator()(int x, int y) const
    {
        return abs(x) < abs(y); 
    }
};


int main()
{
    // 3.10 Function call overloading, comparators.
    GreaterThanZero gtz; // функтор - обьект функционального класса
    std::cout << "gtz(10) = " << gtz(10) << '\n';

    // пример использования функтора
    std::vector<int> v = {-2, 0, 3, 4, 1};
    std::cout << *std::find_if(v.begin(), v.end(), GreaterThanZero()); // GreaterThanZero() можно передать в качестве предиката!


    // создание map, но сортитовка с помощью компаратора(задан оператор меньше) задана - модули ключей 
    std::map<int, int, MyComparator> m;
    m[-1] = 10;
    m[-3] = 40;
    std::cout << "m.begin()->second = " << m.begin()->second << '\n';

    std::sort(v.begin(), v.end(), MyComparator());
    for (int x : v)
        std::cout << x << ' ';
    std::cout << '\n';

    
}