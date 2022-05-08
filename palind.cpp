#include <iostream>
#include <vector>
#include <string>
using namespace std;

int LPSd(string& s, int i, int j, vector<vector<int> >& dp) {
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i > j)
        return 0;
    if (i == j)
        return 1;
    if (i < j && s[i] == s[j]) {
        dp[i][j] = 2 + LPSd(s, i+1, j-1, dp);
        return dp[i][j];
    }
    if (i < j && s[i] != s[j]) {
        dp[i][j] = std::max(
            LPSd(s, i, j-1, dp),
            LPSd(s, i+1, j, dp)
        );
        return dp[i][j];
    }

    return 0;
}

int main(){
    string s;
    vector<int>ris;
    while(getline(cin, s)){
        if(s == "-1")
            break;
        vector<vector<int>> dp(s.size());
        for(unsigned i = 0; i < s.size(); ++i)
            dp[i] = vector<int>(s.size(), -1);
        ris.push_back(LPSd(s, 0, s.size()-1, dp));
    }

    for(auto i : ris)
        cout << i << endl;
    return 0;
}