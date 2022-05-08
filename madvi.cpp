#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main(){
    unsigned numTest = 0;
    std::cin >> numTest;
    std::vector<int> ris;

    while(numTest){
        numTest--;
        int n;
        std::cin >> n;
        std::vector<int> v;

        int t; int d = 1;
        while(std::cin >> t){
            v.push_back(t);
            if(d == n)
                break;
            d++;
        }
         
        int tot = 0;
        int tmp=0;
        for(int i = 0; i < n/2+1; ++i){
            for(int j = i+1; j < n; ++j){
                if( (tmp=fabs(v[i]-v[j]) + fabs(i-j)) > tot)
                    tot = tmp;
            }
        }
        ris.push_back(tot);
    }
    for(unsigned i = 0; i < ris.size(); i++)
        std::cout << ris[i] << '\n';

    return 0;
}
/*
2
3
2 -1 4
5
3 11 -2 8 13
*/
