#include <iostream>
#include <unordered_set>
using namespace std;

struct P{
    int x, y;
    bool operator==(const P&) const{
        return true;
    }
};
struct PHash{
    static const int N = 20011;
    int operator()(const P& p) const{
        return p.x*N+p.y;
    }
};

unordered_set<P, PHash> s;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    while (cin >> n, n){
        int cnt = 0, dx, dy;
        P a, b;
        s.clear();
        
        while (n--){
            cin >> a.x >> a.y;
            s.insert(a);
        }
        
        for (auto p = s.begin(); p != s.end(); ++p){
            a = *p;
            for (auto q = p; q != s.end(); ++q){
                if (p == q) continue;
                b = *q;
                dx = a.y-b.y, dy = b.x-a.x;

                if (s.count({a.x+dx, a.y+dy}) && s.count({b.x+dx, b.y+dy}))
                    ++cnt;
                if (s.count({a.x-dx, a.y-dy}) && s.count({b.x-dx, b.y-dy}))
                    ++cnt;
            }
        }
        
        cout << (cnt/4) << endl;
    }
}
