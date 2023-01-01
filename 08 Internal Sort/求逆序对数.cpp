#include <iostream>
using namespace std;

const int N = 20011;
int n, cnt;
int a[N], t[N];

void merge_sort(int l, int r){
    if (l == r) return;
    
    int mid = (l+r)/2;
    merge_sort(l, mid);
    merge_sort(mid+1, r);
    
    for (int i = l; i <= mid; ++i)
        t[i] = a[i];
    for (int i = 0; i < r-mid; ++i)
        t[mid+1+i] = a[r-i];
    
    for (int k = l, i = l, j = r; k <= r; ++k)
        if (t[i] <= t[j]) a[k] = t[i++];
        else cnt += mid-i+1, a[k] = t[j--];
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    
    while (cin >> n, n){
        cnt = 0;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        merge_sort(0, n-1);
        cout << cnt << endl;
    }
}
