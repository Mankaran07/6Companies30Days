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

void helper(int idx,int k,int n,vector<int> ds, vector<vector<int>> &ans) {
    if(ds.size() == k) {
        if(n == 0) {
            ans.push_back(ds);
        }
        return;
    }
    for(int i=idx;i<=9;i++) {
        ds.push_back(i);
        n -= i;
        helper(i+1,k,n,ds,ans);
        
        n += i;
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> ds;
    helper(1,k,n,ds,ans);
    return ans;
}

int main(){
	FIO();
	//Enter code here	
	int n;
	cin>>n;
	int k;
	cin>>k;
	vector<vector<int>> res;
	res = combinationSum3(k,n);
	for(int i=0;i<res.size();i++) {
		for(int j=0;j<res[0].size();j++) {
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
}