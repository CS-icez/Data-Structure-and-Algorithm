#include <iostream>
#include <cstring>
using namespace std;

const int N = 33;
int a[N], n;

inline void swap_row(int x, int y){
    int t = a[x];
    a[x] = a[y];
    a[y] = t; 
}

inline void row_to_row(int dst, int src){
    a[dst] ^= a[src];
}

int gauss(){
    int r = 0, t;
    
    for (int c = 0; c < n+1; ++c){
        t = -1;
        
        for (int i = r; i < n; ++i)
            if (a[i]&(1<<c)){
                t = i;
                break;
            }
            
        if (t == -1) continue;
        
        swap_row(r, t);
        
        for (int i = r+1; i < n; ++i)
            if (a[i]&(1<<c)) row_to_row(i, r);
        
        if (c != n) ++r;
    }
    
    return a[r]&(1<<n)? r==n: 1<<(n-r);
}

int main(){
    int K;
    cin >> K;
    
    while (K--){
        memset(a, 0, sizeof a);
        
        cin >> n;
        for (int i = 0, t; i < n; ++i){
            cin >> t;
            a[i] = t<<n;
        }
        
        for (int i = 0, t; i < n; ++i){
            cin >> t;
            a[i] ^= t<<n;
        }
        
        for (int i = 0; i < n; ++i)
            a[i] |= 1<<i;
        for (int i = 0, x, y; ; ++i){
            cin >> x >> y;
            if (!x && !y) break;
            a[y-1] |= 1<<(x-1);
        }
        
        int res = gauss();
        if (res) cout << res << endl;
        else cout << "Oh,it's impossible~!!" << endl;
    }

}
