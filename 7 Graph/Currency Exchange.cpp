#include <iostream>
#include <queue>
using namespace std;

const int MAX = 111;
int N, M, S;
double V;
int h[MAX], e[MAX*MAX], ne[MAX*MAX], top;
double r[MAX*MAX], c[MAX*MAX];
double dist[MAX];
int cnt[MAX];

void add(int a, int b, double r1, double c1){
    ++top;
    e[top] = b, ne[top] = h[a];
    h[a] = top;
    r[top] = r1, c[top] = c1;
}

bool spfa(){
    queue<int> q;
    q.push(S);
    dist[S] = V;
    
    int cur;
    double temp;
    while (!q.empty()){
        cur = q.front();
        q.pop();
        
        for (int t = h[cur], p; t; t = ne[t]){
            p = e[t];
            temp = (dist[cur]-c[t])*r[t];
            if (dist[p] < temp){
                dist[p] = temp;
                q.push(p);
                cnt[p] = cnt[cur]+1;
                if (cnt[p] == N) return true;
            }
        }
    }
    return false;
}

int main(){
    double r1, c1;
    cin >> N >> M >> S >> V;
    for (int i = 0, a, b; i < M; ++i){
        cin >> a >> b >> r1 >> c1;
        add(a, b, r1, c1);
        cin >> r1 >> c1;
        add(b, a, r1, c1);
    }
    
    cout << (spfa()? "YES": "NO") << endl;
}
