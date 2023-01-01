#include <iostream>
using namespace std;

const int N = 1e5+10;
int p[N*2]; // same, different

int find(int x){
    return x == p[x]? x: p[x] = find(p[x]);
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T, m, n, a, b, a1, b1, a2, b2;
    char op;
    cin >> T;
    
    while (T--){
        cin >> n >> m;
        for (int i = 1; i <= 2*n; ++i)
            p[i] = i;
        
        while (m--){
            cin >> op >> a >> b;
            a1 = find(a), b1 = find(b);
            a2 = find(a+n), b2 = find(b+n);
            
            switch (op){
                case 'D':
                    p[a1] = b2, p[b1] = a2;
                    break;
                case 'A':
                    if (a1 == b1)
                        cout << "In the same gang." << endl;
                    else if (a1 == b2)
                        cout << "In different gangs." << endl;
                    else
                        cout << "Not sure yet." << endl;
            }
        }
    }
}
