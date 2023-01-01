#include <iostream>
#include <queue>
using namespace std;

const int N = 1111;
int V, E, h[N], e[N*N], ne[N*N], top, ind[N];

void add(int a, int b){
    ++top;
    e[top] = b, ne[top] = h[a], h[a] = top;
    ++ind[b];
}

void topoSort(){
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= V; ++i)
        if (!ind[i]) q.push(i);
    
    int t;
    while (!q.empty()){
        t = q.top();
        q.pop();
        cout << "v" << t << " ";
        for (t = h[t]; t; t = ne[t])
            if (!--ind[e[t]]) q.push(e[t]);
    }
    
}

int main(){
    int a, b;
    cin >> V >> E;
    while (E--){
        cin >> a >> b;
        add(a, b);
    }
    topoSort();
}
