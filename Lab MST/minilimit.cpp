//Minimum Limit of Balls in a Bag

#include<bits/stdc++.h>
using namespace std;

int minimumSize(vector<int>& nums, int maxOperations) {
    int left = 1;
    int right = *max_element(nums.begin(), nums.end());
    int ans = right;

    while(left <= right){
        int mid = left + (right - left) / 2;

        long long operations = 0;

        for(int x : nums){
            operations += (x - 1) / mid;
        }

        if(operations <= maxOperations){
            ans = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }

    return ans;
}

int main(){
  int n;cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin>>a[i];
  int maxOp;cin>>maxOp;

  cout<<minimumSize(a,maxOp);
  return 0;
}


