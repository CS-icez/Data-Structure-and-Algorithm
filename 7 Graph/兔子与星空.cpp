#include <iostream>
#include <algorithm>
using namespace std;

struct Side{
    int a, b, w;
    bool operator<(const Side& t){
        return w < t.w;
    }
} s[77];

int n, m;
int p[29];

int find(int x){
    return p[x] == x? x: p[x] = find(p[x]);
}

int kruskal(){
    int res = 0;
    sort(s, s+m);
    
    for (int i = 0; i < n; ++i)
        p[i] = i;
    
    for (int i = 0, x, y; i < m; ++i){
        x = find(s[i].a), y = find(s[i].b);
        if (x != y){
            p[x] = y;
            res += s[i].w;
        }
    }
    
    return res;
}

int main(){
    cin >> n;
    char e1, e2;
    for (int i = 0, t, w; i < n-1; ++i){
        cin >> e1 >> t;
        while (t--){
            cin >> e2 >> w;
            s[m++] = {e1-'A', e2-'A', w};
        }
    }
    
    cout << kruskal() << endl;
}
