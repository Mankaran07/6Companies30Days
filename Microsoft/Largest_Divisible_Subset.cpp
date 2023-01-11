//HANDLE : mankaran_84
#include<bits/stdc++.h>
using namespace std;

void FIO() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(),nums.end());
    vector<int> dp(n , 1), hash(n);
    int maxi = 1;
    int lastIndex = 0;
    for(int i=0;i<n;i++) {
        hash[i] = i;
        for(int j=0;j<i;j++) {
            if(nums[i] % nums[j] == 0 and dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                hash[i] = j;
            }
        }
        if(dp[i] > maxi) {
            maxi = dp[i];
            lastIndex = i;
        }
    }
    vector<int> ans;
    ans.push_back(nums[lastIndex]);
    while(hash[lastIndex] != lastIndex) {
        lastIndex = hash[lastIndex];
        ans.push_back(nums[lastIndex]);
    }
    return ans;
}

int main(){
	FIO();
	//Enter code here	
	int n;
	cin>>n;
	vector<int> nums(n);
	for(int i=0;i<n;i++) {
		cin>>nums[i];
	}
	vector<int> res = largestDivisibleSubset(nums);
	reverse(res.begin() , res.end());
	for(auto &i : res) cout<<i<<" ";
	cout<<endl;
}