#define TEM template<typename T>
namespace geometry {
    TEM struct Point2D {
        T x, y;
        Point2D() { x = 0, y = 0; }
        Point2D(T x, T y) 
        {Point2D::x = x; Point2D::y = y;}
    };

    TEM double slope(Point2D<T>& a, Point2D<T>& b)  // slope(a, b)
    {return 1.0 * (b.y - a.y) / (b.x - a.x);}

    TEM double dist(Point2D<T>& a, Point2D<T>& b) // dist(a, b)
    {return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));}

    TEM bool collinear(Point2D<T>& a, Point2D<T>& b, Point2D<T>& c) // collinear(a, b, c)
    {return (b.y - a.y) * (c.x - b.x) == (b.x - a.x) * (c.y - b.y);}

    TEM int orientation(Point2D<T>& a, Point2D<T>& b, Point2D<T>& c) // orientation(a, b, c)
    {T k = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y); // collinear -> 0
    if (k == 0) return 0; return ((k < 0)? -1 : 1); } // left/anticlockwise -> -1, right -> 1

    TEM T tri_area_doubled(Point2D<T>& a, Point2D<T>& b, Point2D<T>& c) // tri_area_doubled(a, b, c)
    {return abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));}

    TEM T rect_area(Point2D<T>& bottom_left, Point2D<T>& top_right) // rect_area(a, c)
    {return (top_right.y - bottom_left.y) * (top_right.x - bottom_left.x);}

    // cin >> point; cout << point;
    TEM istream& operator>>(istream& in, Point2D<T>& p) 
    {in >> p.x >> p.y; return in;}
    TEM ostream& operator<<(ostream& out, Point2D<T>& p) 
    {out << "(" << p.x << "," << p.y << ")" << endl; return out;}
}
using namespace geometry;
#define Point Point2D<double>