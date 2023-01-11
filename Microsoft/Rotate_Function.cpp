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

int maxRotateFunction(vector<int>& nums) {
    long sum = 0, original = 0;
    for(int i=0;i<nums.size();i++) {
        sum += nums[i];
        original += (i*nums[i]);
    }
    long res = original;
    for(int i=nums.size()-1;i>=0;i--) {
        original += sum - (nums[i]*nums.size());
        res = max(original,res);
    }
    return res;
}

int main(){
	FIO();
	//Enter code here	
	int n;
	cin>>n;
	vector<int> nums(n);
	for(auto &i : nums) cin>>i;
	cout<<maxRotateFunction(nums)<<endl;
}