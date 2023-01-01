#include <iostream>
#include <string>
using namespace std;

/*
1-9 -> 9
10-99 -> 9+90*2=189
100-999 -> 189+900*3=2889
1000-9999 -> 2889+9000*4=38889
10000-99999 -> 38889+90000*5=488889
*/

const int N = 31270;
long a[N], sum[N];

long f(long n){
    if (n <= 9) return n;
    else if (n <= 99) return 9+(n-9)*2;
    else if (n <= 999) return 189+(n-99)*3;
    else if (n <= 9999) return 2889+(n-999)*4;
    else return 38889+(n-9999)*5;
}

int main(){
    for (int i = 1; i < N; ++i)
        a[i] = f(i);
    for (int i = 1; i < N; ++i)
        sum[i] = sum[i-1]+a[i];
    
    int T;
    cin >> T;
    long k, cur;
    while (T--){
        cin >> k;
        
        for (cur = 1; sum[cur] <= k; ++cur);
        k -= sum[--cur];
        if (!k){
            cout << cur%10 << endl;
            continue;
        }
        
        for (cur = 1; a[cur] <= k; ++cur);
        k -= a[--cur];
        if (!k) cout << cur%10 << endl;
        else cout << to_string(cur+1)[k-1] << endl;
    }
}
