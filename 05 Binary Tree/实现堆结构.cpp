#include <iostream>
using namespace std;

const int N = 1e5+10;
int node[N], idx;

void up(int cur){
    while (cur != 1 && node[cur] < node[cur/2]){
        swap(node[cur], node[cur/2]);
        cur /= 2;
    }
}

void down(int cur){
    int t = cur, u = cur*2;
    if (u <= idx && node[u] < node[t])
        t = u;
    ++u;
    if (u <= idx && node[u] < node[t])
        t = u;
    if (t != cur){
        swap(node[t], node[cur]);
        down(t);
    } 
}

void insert(){
    cin >> node[++idx];
    up(idx);
}

void remove(){
    cout << node[1] << endl;
    swap(node[1], node[idx--]);
    down(1);
}

int main(){
    int T, n, op;
    cin >> T;
    
    while (T--){
        idx = 0;
        cin >> n;
        while (n--){
            cin >> op;
            if (op == 1) insert();
            else remove();
        }
    }
}
