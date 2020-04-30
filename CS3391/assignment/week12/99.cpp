#include <iostream>

#include <iomanip>

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

    Point(double x = 0, double y = 0): x(x), y(y) {}

    bool operator < (const Point & rhs) const {
        return x == rhs.x ? y < rhs.y : x < rhs.x;
    }
    bool operator == (const Point & rhs) const {
        bool same_x = x - rhs.x <= EPS;
        bool same_y = y - rhs.y <= EPS;

        return same_x && same_y;
    }
    Point operator + (const Point & rhs) const {
        return Point(x + rhs.x, y + rhs.y);
    }
    Point operator - (const Point & rhs) const {
        return Point(x - rhs.x, y - rhs.y);
    }
    Point operator * (const double a) const {
        return Point(x * a, y * a);
    }
    Point operator / (const double a) const {
        return Point(x / a, y / a);
    }
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
P[MAXN];

double r[MAXN];

void m() {
    int n;
    while (cin >> n) {
        if(!n) return;
        for (int i = 0; i < n; i++) {
            cin >> P[i].x >> P[i].y >> r[i];
        }

        double maxLen = 0.0;
        for (int i = 0; i < 24 * 60; i++) {
            Point A, B, C;

            A = Point(0, 0);

            double angle = 2 * M_PI * i/(24.0 * 60);

            B = Point(500 * sin(angle), 500 * cos(angle));
            double sum = 0.0;
            
            for (int j = 0; j < n; j++) {
                C = P[j];
                double projection = (B.x * C.x + B.y * C.y) / sqrt(B.x * B.x + B.y * B.y);
                if(projection < 0) continue;
                
                double dis = C.x * C.x + C.y * C.y - projection * projection;
                if (dis < r[j]*r[j])
                    sum += 2.0 * sqrt(r[j] * r[j] - dis);
            }

            maxLen = max(maxLen, sum);
        }

        cout << fixed << setprecision(3) << maxLen << endl;
    }
}

int main() {
    m();

    return 0;
}