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




Point lines[MAXN][2];



void m() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        for(int i = 0; i < n; i++) {
            int x1, y1, x2, y2;
            
            cin >> x1 >> y1 >> x2 >> y2;
            Point p1(x1, y1);
            Point p2(x2, y2);
            
            lines[i][0] = p1;
            lines[i][1] = p2;
        }
        
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            int inter = 0;
            for(int j = 0; j < n; j++) {
                Point intersection_pt;
                if(i == j) continue;
                if(getSegInter(lines[i][0], lines[i][1], lines[j][0], lines[j][1], intersection_pt)) {
                    inter++;
                    break;
                }
            }
            
            if(!inter)
                cnt++;
        }
        
        cout << cnt << endl;
    }
}





int main()
{
    m();

    return 0;
}
