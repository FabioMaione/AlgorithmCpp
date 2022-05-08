#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int massimo(int *a, int tot, int n){
    int tmp = 0;
    for(int i = 0; i < n/2+1; ++i){
        for(int j = i+1; j < n; ++j){
            if( (tmp=fabs(a[i]-a[j]) + fabs(i-j)) > tot);
                tot = tmp;
        }
    }
    return tot;
}

int main(){
    int test = 0;
    vector<int>ris;
    cin >> test;
    while(test-- > 0){
        int n;
        cin >> n;
        int *a = new int[n];
        int t; int d = 0;
        while(cin >> t){
            a[d] = t;
            d++;
            if(d == n)
                break;   
        }      
        int tot = 0;
        int mas = massimo(a, tot, n);
        
        ris.push_back(mas);
    }
    for(auto i : ris)
        cout << i << endl;
    return 0;
}   /* 2 3 2 -1 4 5 3 11 -2 8 13 */