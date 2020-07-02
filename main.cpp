#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

//#define DEBUG

class Point;

class Stick
{
private:
    double length;
    int x1;
    int y1;
    int x2;
    int y2;

    string nam1;
    string nam2;

public:

    Stick()
    {
        x1 = 0;
        y1 = 0;
        x2 = 0;
        y2 = 0;
    }

    ~Stick()
    {

    }

    void GetPoint1(const Point &point);
    void GetPoint2(const Point &point);

    void Print();

    double GetLength()
    {
        this->length = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

        return this->length;
    }

};



class Point             //Создаю класс Точка
{
private:
    string nam;
    int x;              //Объявляю поля класса
    int y;



public:
    friend void Stick::GetPoint1(const Point &point);
    friend void Stick::GetPoint2(const Point &point);

    Point();
    Point(int x, int y);
    Point(Point &other);
    ~Point();

    Point & operator =(Point &other);
    bool operator ==(const Point &other);
    bool operator !=(const Point &other);
    Point & operator ++();
    Point & operator ++(int v);
    Point & operator --();
    Point & operator --(int v);

    int GetX();
    void SetX(int x);
    int GetY();
    void SetY(int y);
    void SetNam(string nam);
    string GetNam();
    void ShowP();

    friend void resetclass(Point &obj);
};

    Point::Point()             //Создаю конструктор класса
    {
        x = 0;
        y = 0;

        #ifdef DEBUG
        cout << "Constructor default " << nam << endl;
        #endif // DEBUG
    }

    Point::Point(int x, int y)   //Перегружаю его на координаты точки
    {
        this->x = x;
        this->y = y;

        #ifdef DEBUG
        cout << "Constructor initialization " << nam << endl;
        #endif // DEBUG
    }

    Point::Point(Point &other)
    {
        this->x = other.x;
        this->y = other.y;

        #ifdef DEBUG
        cout << "Constructor of copy " << nam << endl;
        #endif // DEBUG
    }

    Point::~Point()            //Деструктор класса, в нём можно чистить данные дабы избежать утечки памяти
    {
        #ifdef DEBUG
        cout << "Destructor " << nam << endl;
        #endif // DEBUG
    }

    Point & Point::operator =(Point &other)
    {
        #ifdef DEBUG
        cout << "operator= " << nam << endl;
        #endif // DEBUG

        this->x = other.x;
        this->y = other.y;

        return *this;
    }

    bool Point::operator ==(const Point &other)
    {
        #ifdef DEBUG
        cout << "operator== " << this->nam  << " and " << other.nam << endl;
        #endif // DEBUG

        return ((this->x == other.x) && (this->y == other.y));
    }

    bool Point::operator !=(const Point &other)
    {
        #ifdef DEBUG
        cout << "operator!= " << this->nam  << " and " << other.nam << endl;
        #endif // DEBUG

        return !((this->x == other.x) && (this->y == other.y));
    }
    Point & Point::operator ++()
    {
        #ifdef DEBUG
        cout << "++operator " << nam << endl;
        #endif // DEBUG

        this->x++;
        this->y++;

        return *this;
    }

    Point & Point::operator ++(int v)
    {
        #ifdef DEBUG
        cout << "operator++ " << nam << endl;
        #endif // DEBUG

        Point t = *this;

        this->x++;
        this->y++;

        return t;
    }

    Point & Point::operator --()
    {
        #ifdef DEBUG
        cout << "--operator " << nam << endl;
        #endif // DEBUG

        this->x--;
        this->y--;

        return *this;
    }

    Point & Point::operator --(int v)
    {
        #ifdef DEBUG
        cout << "operator-- " << nam << endl;
        #endif // DEBUG

        Point t = *this;

        this->x--;
        this->y--;

        return t;
    }
                        //Дальше создаю геттеры и сеттеры
    int Point::GetX()
    {
        return x;
    }

    void Point::SetX(int x)
    {
        this->x = x;
    }

    int Point::GetY()
    {
        return y;
    }

    void Point::SetY(int y)
    {
        this->y = y;
    }

    void Point::SetNam(string nam)
    {
        this->nam = nam;
    }

    string Point::GetNam()
    {
        return nam;
    }

    void Point::ShowP()            //И создаю метод выведения информации о точке в консоль
    {
        cout << nam << " point:\n" << "x\t" << x << endl;
        cout << "y\t" << y << endl << endl;
    }

void resetclass(Point &obj)
{
    #ifdef DEBUG
    cout << "RESET CLASS" << endl;
    #endif // DEBUG

    obj.x = 0;
    obj.y = 0;
}


void Stick::GetPoint1(const Point &point)
    {
        x1 = point.x;
        y1 = point.y;
        nam1 = point.nam;
    }

void Stick::GetPoint2(const Point &point)
    {
        x2 = point.x;
        y2 = point.y;
        nam2 = point.nam;
    }

void Stick::Print()
    {
        cout << "Point #1 " << nam1 << endl;
        cout << "x:\t" << x1 << endl;
        cout << "y:\t" << y1 << endl;

        cout << "Point #2 " << nam2 << endl;
        cout << "x:\t" << x2 << endl;
        cout << "y:\t" << y2 << endl;

        this->length = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

        cout << "\nLength\t" << length << endl;
    }

int main()
{
    Point a;                //Создаю объект класса
    a.SetNam("A");

    a.ShowP();

    a.SetX(5);
    a.SetY(7);

    a.ShowP();

    cout << "\n-------------------\n\n";
    Point b(4, 5);
    b.SetNam("B");

    b.ShowP();

    cout << (a == b) << endl;
    cout << (a != b) << endl;

    Point c(a);
    c.SetNam("C");

    c.ShowP();

    cout << "C" << endl;

    c++;
    cout << "x: " << c.GetX() << " y: " << c.GetY() << endl;

    ++c;
    cout << "x: " << c.GetX() << " y: " << c.GetY() << endl;

    c--;
    cout << "x: " << c.GetX() << " y: " << c.GetY() << endl;

    --c;
    cout << "x: " << c.GetX() << " y: " << c.GetY() << endl;

    resetclass(c);

    c.ShowP();

    Stick st;

    st.GetPoint1(a);
    st.GetPoint2(b);

    st.Print();



    system("pause");
    return 0;
}
