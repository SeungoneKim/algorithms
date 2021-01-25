#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using Point = pair<long long, long long>;
using Line = pair<Point, Point>;

int ccw(Point p1, Point p2, Point p3) {
    long long temp = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    temp -= p1.second * p2.first + p2.second * p3.first + p3.second * p1.first;
    if (temp > 0) return 1;
    if (temp < 0) return -1;
    return 0;
}
bool cross(Line l1, Line l2) {
    int l1l2 = ccw(l1.first, l1.second, l2.first) * ccw(l1.first, l1.second, l2.second);
    int l2l1 = ccw(l2.first, l2.second, l1.first) * ccw(l2.first, l2.second, l1.second);
    return l1l2 < 0 && l2l1 < 0;
}
int go(Point &p1, int n, vector<Point> &a) {
    for (int i=0; i<n; i++) {
        int t1 = ccw(a[i], a[i+1], p1);
        if (t1 == 0) {
            auto minx = min(a[i].first, a[i+1].first);
            auto maxx = max(a[i].first, a[i+1].first);
            auto miny = min(a[i].second, a[i+1].second);
            auto maxy = max(a[i].second, a[i+1].second);
            if (minx <= p1.first && p1.first <= maxx) {
                if (miny <= p1.second && p1.second <= maxy) {
                    return 1;
                }
            }
        }
    }
    Point p0 = {1, 2147483647};
    int cnt = 0;
    for (int i=0; i<n; i++) {
        Line l = {p0, p1};
        cnt += cross(l, Line({a[i], a[i+1]}));
    }
    return cnt%2;
}

int main(){

    int n;
    cin >> n;

    vector<Point> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i].first >> a[i].second;
    }
    a.push_back(a[0]);
    int m=3;
    while(m--){
        Point p1;
        cin >> p1.first >> p1.second;
        cout << go(p1, n, a) << '\n';
    }


    return 0;
}