// С++ 7. Перегрузка операторов (продолжение).
// ссылка на лекцию: https://www.youtube.com/watch?v=oGwNuB7uflM&ab_channel=%D0%9B%D0%B5%D0%BA%D1%82%D0%BE%D1%80%D0%B8%D0%B9%D0%A4%D0%9F%D0%9C%D0%98


#include <iostream>
#include <vector>


struct LineSegment
{
    double begin;
    double end;
};


void processSegment(LineSegment& s, bool inverted)
{
    double LineSegment::* begin = inverted ? &LineSegment::end : &LineSegment::begin;
    double LineSegment::* end = inverted ? &LineSegment::begin : &LineSegment::end;

    

}


int main()
{
    // 3.11 Pointers to members(указатели на члены)
    
    // p - указатель на член класса LineSegment, поле begin
    // по факту в нём содержится информация о смещении относительно начала структуры
    // чтобы можно было находить необходиый член для любого обьекиа структуры
    double LineSegment::* p = &LineSegment::begin;

    LineSegment s = {1.0, 2.0};
    LineSegment ss = {3.0, 4.0};

    std::cout << s.*p << '\n';    
    std::cout << ss.*p << '\n';


}