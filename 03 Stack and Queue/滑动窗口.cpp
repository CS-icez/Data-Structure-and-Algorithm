#include <iostream>
#include <deque>
using namespace std;

const int N = 1e6+13;
int a[N], n, k;
deque<int> q;

int main(){
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    
    // min
    for (int i = 0; i < n; ++i){
        if (!q.empty() && i - q.front() >= k) q.pop_front();
        while (!q.empty() && a[i] <= a[q.back()]) q.pop_back();
        q.push_back(i);
        if (i >= k-1) cout << a[q.front()] << " ";
    }
    
    cout << endl;
    q.clear();
    
    // max
    for (int i = 0; i < n; ++i){
        if (!q.empty() && i - q.front() >= k) q.pop_front();
        while (!q.empty() && a[i] >= a[q.back()]) q.pop_back();
        q.push_back(i);
        if (i >= k-1) cout << a[q.front()] << " ";
    }
}
