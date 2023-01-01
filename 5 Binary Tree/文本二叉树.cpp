#include <iostream>
#include <cstring>
using namespace std;

struct{
    int l, r, h;
    char c;
} node[111];
int idx;

int create(int rt){
    int t;
    if (rt >= idx) return 0;
    
    if (node[rt+1].h != node[rt].h+1)
        return rt+1;
    if (node[rt+1].c != '*'){
        node[rt].l = rt+1;
        t = create(rt+1);
        if (node[t].h != node[rt].h+1)
            return t;
        node[rt].r = t;
        return create(t);
    }
    else{
        node[rt].r = rt+2;
        return create(rt+2);
    }
}

void read(){
    int cnt = 0;
    char c;
    for (cin >> c; !isdigit(c); cin >> c){
        for (; c == '-'; ++cnt, cin >> c);
        node[++idx] = {0, 0, cnt, c};
        cnt = 0;
    }
}

void preorder(int rt){
    if (!rt) return;
    cout << node[rt].c;
    preorder(node[rt].l);
    preorder(node[rt].r);
}

void inorder(int rt){
    if (!rt) return;
    inorder(node[rt].l);
    cout << node[rt].c;
    inorder(node[rt].r);
}

void postorder(int rt){
    if (!rt) return;
    postorder(node[rt].l);
    postorder(node[rt].r);
    cout << node[rt].c;
}

int main(){
    int T;
    cin >> T;
    while (T--){
        idx = 0;
        read();
        create(1);
        preorder(1); 
        cout << endl;
        postorder(1); 
        cout << endl;
        inorder(1);
        cout << endl << endl;
    }
}
