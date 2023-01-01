#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct P{
    int x, y, z;
};
struct D{
    P a, b;
    double d;
    friend ostream& operator<<(ostream& os, const D& t){
        printf("(%d,%d,%d)-(%d,%d,%d)=%.2f\n", t.a.x, t.a.y, t.a.z, t.b.x, t.b.y, t.b.z, t.d);
        return os;
    }
    bool operator<(const D& t) const{
        return d > t.d;
    }
};

inline double dist(const P a, const P& b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}

P p[15];
D d[225];

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> p[i].x >> p[i].y >> p[i].z;
    
    int idx = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            d[idx++] = {p[i], p[j], dist(p[i], p[j])};
        
    stable_sort(d, d+idx);
    for (int i = 0; i < idx; ++i)
        cout << d[i];    
}
