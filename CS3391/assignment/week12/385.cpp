#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
const double EPS = 1e-9;

using namespace std;

int dcmp(double a, double b = 0) {
    double d = a - b;
    return abs(d) <= EPS ? 0 : (d > 0 ? 1 : -1);
}

struct Point {
    double x, y;

    Point(double x = 0, double y = 0): x(x), y(y) {}

   	bool operator == (const Point& u) const { return dcmp(x - u.x) == 0 && dcmp(y - u.y) == 0; }
	bool operator != (const Point& u) const { return !(*this == u); }
	bool operator < (const Point& u) const { return x < u.x || (x == u.x && y < u.y); }
	bool operator > (const Point& u) const { return u < *this; }
	bool operator <= (const Point& u) const { return *this < u || *this == u; }
	bool operator >= (const Point& u) const { return *this > u || *this == u; }
	Point operator + (const Point& u) const{ return Point(x + u.x, y + u.y); }
	Point operator - (const Point& u) const{ return Point(x - u.x, y - u.y); }
	Point operator * (const double u) const{ return Point(x * u, y * u); }
	Point operator / (const double u) const{ return Point(x / u, y / u); }
	double operator * (const Point& u) const{ return x*u.y - y*u.x; }
    
    friend double dot(const Point & a,
        const Point & b) {
        return a.x * b.x + a.y * b.y;
    }
    friend double cross(const Point & a,
        const Point & b) {
        return a.x * b.y - a.y * b.x;
    }

    friend double angle(const Point & a,
        const Point & b) {
        return acos(dot(a, b) / a.length() / b.length());
    }

    Point rotate(double rad) {
        return Point(x * cos(rad) - y * sin(rad),
            x * sin(rad) + y * cos(rad));
    }

    double length() const {
        return sqrt(dot( * this, * this));
    }

    Point getNormal() {
        Point res(-y, x);
        return res / length();
    }
}
P[MAXN], ch[MAXN];

bool OnSeg(const Point &p, const Point &s, const Point &t) {
    return dcmp(cross(s - p, t - p)) == 0 && dcmp(dot(s - p, t - p)) < 0;
}


int getConvexHull(int n) {
        std::sort(P, P + n);
    
        int m = 0;
        for (int i = 0; i < n; i++) {
            while (m > 1 && cross(ch[m - 1] - ch[m - 2], P[i] - ch[m - 2]) <= 0) m--;
            ch[m++] = P[i];
        }
    
        int k = m;
        for (int i = n - 1; ~i; i--) {
            while (m > k && cross(ch[m - 1] - ch[m - 2], P[i] - ch[m - 2]) <= 0) m--;
            ch[m++] = P[i];
        }
    
        m > 1 ? m-- : 0;
        return m;
    }

double polyArea(Point *p, int n) {
    double sum = 0;
    for (int i = 1; i <= n - 2; i++)
        sum += cross(p[i] - p[0], p[i + 1] - p[0]);
    return std::abs(sum / 2.0);
}

int insidePoly (Point* p, int n, Point o) {
		int wn = 0;
		for (int i = 0; i < n; i++) {
			int j = (i + 1) % n;
			if (OnSeg(o, p[i], p[j]) || o == p[i]) return 0;
			int k = dcmp(cross(p[j] - p[i], o-p[i]));
			int d1 = dcmp(p[i].y - o.y);
			int d2 = dcmp(p[j].y - o.y);
			if (k > 0 && d1 <= 0 && d2 > 0) wn++;
			if (k < 0 && d2 <= 0 && d1 > 0) wn--;
		}
		return wn ? -1 : 1;
}    
    
void m() {
    int t;
    int cnt = 1;
    while(cin >> t && t) {
        cout << "Tile #" << cnt << endl;
        for(int i = 0; i < t; i++) {
            cin >> P[i].x >> P[i].y;
        }
        
        double area1 = polyArea(P, t);
        int m = getConvexHull(t);
        double area2 = polyArea(ch, m);
        
        printf("Wasted Space = %.2lf %%\n\n" , (area2 - area1)*100.0 / area2);
        
        cnt++;
    }
}


int main()
{
    m();

    return 0;
}
