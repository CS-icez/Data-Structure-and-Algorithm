#include <iostream>
#include <vector>
using namespace std;

const int M = 100007;
vector<int> v[M];
int a[M][12];

bool isEqual(int x[], int y[]){
    for (int i = 0, j; i < 6; ++i){
        for (j = 0; j < 6; ++j)
            if (x[j] != y[i+j])
               break;
        if (j == 6) return true;
    }
    for (int i = 0, j; i < 6; ++i){
        for (j = 0; j < 6; ++j)
            if (x[5-j] != y[i+j])
               break;
        if (j == 6) return true;
    }
    return false;
}

bool contains(int idx, int hashCode){
    for (int x: v[hashCode])
        if (isEqual(a[idx], a[x]))
           return true;
    return false;
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, sum;
    
    cin >> n;
    for (int i = 0; i < n; ++i){
        sum = 0;
        for (int j = 0; j < 6; ++j){
            cin >> a[i][j];
            sum += a[i][j];
        }
        sum %= M;
        
        for (int j = 0; j < 6; ++j)
            a[i][j+6] = a[i][j]; 
            
        if (contains(i, sum)){
            cout << "Twin snowflakes found." << endl;
            return 0;
        }
        v[sum].push_back(i);
    }
    
    cout << "No two snowflakes are alike." << endl;
}
