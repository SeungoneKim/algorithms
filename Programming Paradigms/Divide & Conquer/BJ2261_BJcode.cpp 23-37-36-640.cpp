#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
struct Point {
    int x, y;
};
bool cmp_x(const Point &u, const Point &v) {
    return make_pair(u.x, u.y) < make_pair(v.x, v.y);
}
bool cmp_xe(const Point &u, const Point &v) {
    return make_pair(u.x, u.y) <= make_pair(v.x, v.y);
}
bool cmp_y(const Point &u, const Point &v) {
    return make_pair(u.y, u.x) < make_pair(v.y, v.x);
}
int dist(Point p1, Point p2) {
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}
int brute_force(vector<Point> &a, int start, int end) {
    int ans = -1;
    for (int i=start; i<=end-1; i++) {
        for (int j=i+1; j<=end; j++) {
            int d = dist(a[i], a[j]);
            if (ans == -1 || ans > d) {
                ans = d;
            }
        }
    }
    return ans;
}
int closest(vector<Point> &ax, vector<Point> &ay, int start, int end) {
    int n = end-start+1;
    if (n <= 3) {
        return brute_force(ax, start, end);
    }
    int mid = (start + end) / 2;
    Point mid_p = ax[mid];
    vector<Point> ayl, ayr;
    for (Point p : ay) {
        if (cmp_xe(p, mid_p)) {
            ayl.push_back(p);
        } else {
            ayr.push_back(p);
        }
    }
    int left = closest(ax, ayl, start, mid);
    int right = closest(ax, ayr, mid+1, end);
    int ans = min(left, right);
    vector<Point> b;
    for (Point p : ay) {
        int d = p.x - mid_p.x;
        if (d*d < ans) {
            b.push_back(p);
        }
    }
    int m = b.size();
    for (int i=0; i<m-1; i++) {
        for (int j=i+1; j<m; j++) {
            int y = b[j].y - b[i].y;
            if (y*y < ans) { 
                int d = dist(b[i], b[j]);
                if (d < ans) {
                    ans = d;
                }
            } else {
                break;
            }
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Point> ax(n);
    vector<Point> ay(n);
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        ax[i] = {x, y};
        ay[i] = {x, y};
    }
    sort(ax.begin(), ax.end(), cmp_x);
    sort(ay.begin(), ay.end(), cmp_y);
    cout << closest(ax, ay, 0, n-1) << '\n';
    return 0;
}

