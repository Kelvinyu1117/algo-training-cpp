#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;


const int MAXN = 100005;
const double EPS = 1e-9;

int dcmp(double a, double b = 0) {
    double d = a - b;
    return abs(d) <= EPS ? 0 : (d > 0 ? 1 : -1);
}

struct Point {
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}

    bool operator<(const Point &rhs) const { return x == rhs.x ? y < rhs.y : x < rhs.x; }
    bool operator==(const Point &rhs) const {
        bool same_x = x - rhs.x <= EPS;
        bool same_y = y - rhs.y <= EPS;
        
        return same_x && same_y;
    }
    Point operator+(const Point &rhs) const { return Point(x + rhs.x, y + rhs.y); }
    Point operator-(const Point &rhs) const { return Point(x - rhs.x, y - rhs.y); }
    Point operator*(const double a) const { return Point(x * a, y * a); }
    Point operator/(const double a) const { return Point(x / a, y / a); }
    friend double dot(const Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }
    friend double cross(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }

    friend double angle(const Point &a, const Point &b) {
        return acos(dot(a, b) / a.length() / b.length());
    }

    Point rotate(double rad) {
        return Point(x * cos(rad) - y * sin(rad),
                     x * sin(rad) + y * cos(rad));
    }

    double length() const { return sqrt(dot(*this, *this)); }

    Point getNormal() {
        Point res(-y, x);
        return res / length();
    }
} P[MAXN];

bool OnSeg(const Point &p, const Point &s, const Point &t) {
    if (min(s.x,t.x) <=p.x  && p.x<=max(s.x,t.x)  && min(s.y,t.y)<=p.y && p.y<=max(s.y,t.y)) 
        return true;
    return false;
}


bool getSegInter(const Point &as, const Point &at, const Point &bs, const Point &bt, Point &p) {
    if (!dcmp(cross(at - as, bt - bs))) {
        // comment the following line if the end point is not count as intersection point
        if(OnSeg(as, bs, bt) || OnSeg(at, bs, bt) || OnSeg(bs, as, at) || OnSeg(bt, as, at))
            return true;
        else
            return false;
    }
    
    double c1 = cross(bs - as, at - as), c2 = cross(bt - as, at - as);
    double c3 = cross(as - bs, bt - bs), c4 = cross(at - bs, bt - bs);
    if (dcmp(c1) * dcmp(c2) <= 0 && dcmp(c3) * dcmp(c4) <= 0) {
        p = (at * c3 - as * c4) / (c3 - c4);
        return true;
    } else return false;
}


// first two is the segemnt
// last two is the rectangle
bool inRect(Point p1, Point p2, Point p3, Point p4)
{
    return OnSeg(p1,p3,p4)&&OnSeg(p2,p3,p4);
}


Point segments[MAXN][2];
Point rectangle[MAXN][4];


void m() {
    int t;
    cin >> t;
    
    while(t--) {
        
        double x1, y1, x2, y2, x3, y3, x4, y4;
            
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
            
        segments[0][0] = {x1, y1};
        segments[0][1] = {x2, y2};
        
        rectangle[0][0] = {x3, y3};   // top left
        rectangle[0][1] = {x4, y4};   // bottom right
        rectangle[0][2] = {rectangle[0][1].x, rectangle[0][0].y}; // top right
        rectangle[0][3] = {rectangle[0][0].x, rectangle[0][1].y}; // bottom left
        
        if(inRect(segments[0][0], segments[0][1], rectangle[0][0], rectangle[0][1])) {
            cout << "T" << endl;
            continue;
        }
        
        Point intersection_pt;
        
        bool inter1 = getSegInter(segments[0][0], segments[0][1], rectangle[0][0], rectangle[0][2], intersection_pt);
        bool inter2 = getSegInter(segments[0][0], segments[0][1], rectangle[0][2], rectangle[0][1], intersection_pt);
        bool inter3 = getSegInter(segments[0][0], segments[0][1], rectangle[0][1], rectangle[0][3], intersection_pt);
        bool inter4 = getSegInter(segments[0][0], segments[0][1], rectangle[0][3], rectangle[0][0], intersection_pt);
    
        if(inter1 || inter2 || inter3 || inter4)
            cout << "T" << endl;
        else
            cout << "F" << endl;
    }
}





int main()
{
    m();

    return 0;
}
