#include <iostream>
#include <vector>
using namespace std;

bool mp[11][11];
bool vis[11][11];
int xe, ye;
int res = 1e9, tot;
vector<pair<int, int>> path, best;
const int dx[]{1, -2, -2, -1, 2, 2, 1, -1},
          dy[]{2, -1, 1, 2, 1, -1, -2, -2},
          bx[]{0, -1, -1, 0, 1, 1, 0, 0},
          by[]{1, 0, 0, 1, 0, 0, -1, -1};
          

void dfs(int xs, int ys, int step){
    if (step > res) return;
    
    if (xs == xe && ys == ye){
        if (step < res) res = step, tot = 1, best = path;
        else ++tot;
        return;
    }
    
    for (int i = 0, x, y, a, b; i < 8; ++i){
        x = xs+dx[i], y = ys+dy[i];
        a = xs+bx[i], b = ys+by[i];
        if (x < 0 || y < 0 || x > 10 || y > 10) continue;
        if (mp[a][b] || vis[x][y]) continue;
        path.push_back({x, y}); vis[x][y] = 1;
        dfs(x, y, step+1);
        path.pop_back(); vis[x][y] = 0;
    }
}

int main(){
    int xs, ys, m, x, y;
    cin >> xs >> ys >> xe >> ye >> m;
    while (m--){
        cin >> x >> y;
        mp[x][y] = 1;
    }
    
    dfs(xs, ys, 0);
    if (tot == 1){
        printf("(0,0)");
        for (auto& [a, b]: best)
            printf("-(%d,%d)", a, b);
    }
    else printf("%d", tot);
}
