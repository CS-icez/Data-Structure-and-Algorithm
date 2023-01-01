#include <iostream>
#include <unordered_map>
using namespace std;

#define cube(x) (x*x*x)
unordered_map<int, int> m12, m345;

int main(){
    int a1, a2, a3, a4, a5;
    cin >> a1 >> a2 >> a3 >> a4 >> a5;
    
    for (int i = -50, y; i <= 50; ++i){
        if (!i) continue;
        y = a1*cube(i);
        for (int j = -50; j <= 50; ++j)
            if (j) ++m12[y+a2*cube(j)];
    }
        
            
    
    for (int i = -50, y; i <= 50; ++i){
        if (!i) continue;
        y = a3*cube(i);
        for (int j = -50, z; j <= 50; ++j){
            if (!j) continue;
            z = y+a4*cube(j);
            for (int k = -50; k <= 50; ++k)
                if (k) ++m345[z+a5*cube(k)];
        }
    }
                
    int res = 0;
    for (auto t: m12)
        res += m345[-t.first]*t.second;
    
    cout << res << endl;
}
