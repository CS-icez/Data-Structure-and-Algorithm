#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

using mss = multiset<string>;
const int N = 1e5+10, M = 3e4+10;
int son[N][26], top;
int idx[N], cnt;
mss s[M];

bool cmp(const mss& a, const mss& b){
    return a.size() == b.size()? *a.begin() < *b.begin(): a.size() > b.size();
}

void insert(const string& str){
    string cpy = str;
    sort(cpy.begin(), cpy.end());
    
    size_t p = 0, t;
    for (char c: cpy){
        t = c-'a';
        if (!son[p][t]) son[p][t] = ++top;
        p = son[p][t];
    }
    
    if (!idx[p]) idx[p] = ++cnt;
    s[idx[p]].insert(str);
}

int main(){
    for (string str; cin >> str; insert(str));
    sort(s+1, s+cnt+1, cmp);
    
    for (int i = 1; i <= 5 && i <= cnt; ++i){
        printf("Group of size %lld: ", s[i].size());
        auto pre = s[i].begin(), cur = ++s[i].begin();
        cout << *pre << " ";
        for (; cur != s[i].end(); ++pre, ++cur)
            if (*cur != *pre) cout << *cur << " ";
        cout << ".\n";
    }
}
