//Maximum Product of Word Lengths
#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<string>& words) {
    int maxi = 0;
    int n = words.size();

    for(int i = 0; i < n - 1; i++){
        vector<int> freq1(26,0);

        for(int k = 0; k < words[i].size(); k++){
            freq1[words[i][k] - 'a']++;
        }

        for(int j = i + 1; j < n; j++){
            bool isMatch = false;   

            for(int k = 0; k < words[j].size(); k++){
                if(freq1[words[j][k] - 'a'] != 0){
                    isMatch = true;
                    break;     
                }
            }
            if(!isMatch){
                int se = words[i].size() * words[j].size();
                maxi = max(maxi, se);
            }
        }
    }
    return maxi;
}

int main(){
  vector<string> words = ["abcw","baz","foo","bar","xtfn","abcdef"];
  cout<<maxProduct(words);
  return 0;
}
