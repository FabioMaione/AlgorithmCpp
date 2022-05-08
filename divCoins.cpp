#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 101;
const int M = 25001;
bool  v[M];

int dvCns(int n)
{
    return (n > 0)? n : -n;
}

int main(){
    int nP, nM, sum, m, j;
    vector<int>ris;
    int a[N];
    cin >> nP;
    while(nP-- > 0){
        cin >> nM;
        sum = 0;
        for(int i = 0; i < nM; ++i){
            cin >> a[i]; 
            sum += a[i];
        }

        m = sum/2;
        memset(v, 0, sizeof(v));
        v[0] = true;

        for(int i = 0; i < nM; ++i)
            for(j = m; j >= 1; --j)
                if(!v[j])
                    v[j] = (a[i] <= j)? v[j-a[i]] :false; 

        for(j = m; j >= 1; --j)
            if(v[j])
                break;

        
        ris.push_back(dvCns(sum - j * 2));
    }
        for(auto i : ris)
            cout << i << endl;
    return 0;
}