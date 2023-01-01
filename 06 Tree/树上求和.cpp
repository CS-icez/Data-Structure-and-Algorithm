#include <iostream>
using namespace std;

/*
tricky tests:
0 () -> no
0 (0()()) -> yes
0 (0()(1()())) -> no
*/

int goal;
bool flag;

inline char getchar_noBlank(){
    char c;
    do{
        c = getchar();
    } while (c == ' ' || c == '\n' || c == '\t' || c == EOF);
    return c;
}

inline int readNumber(){
    int res = 0;
    bool sgn = false;
    char c;
    do{
        c = getchar();
        if (c == '-') sgn = true;
    } while (c < '0' || c > '9');
    do{
        res = res*10+c-'0';
        c = getchar();
    } while (c >= '0' && c <= '9');
    ungetc(c, stdin);
    return sgn? -res: res;
}

bool isEmpty(int cur){
    char c;
    int t;
    
    c = getchar_noBlank();
    c = getchar_noBlank();
    if (c == ')') return true;
    
    ungetc(c, stdin);
    t = readNumber();
    cur += t;
    int f1 = isEmpty(cur);
    int f2 = isEmpty(cur);
    if (f1 && f2 && cur == goal)
        flag = true;
        
    c = getchar_noBlank();
    return false;
}


int main(){
    while (~scanf("%d", &goal)){
        flag = 0;
        isEmpty(0);
        puts(flag? "yes": "no");
    }
}
