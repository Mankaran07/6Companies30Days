//HANDLE : mankaran_07
#include<bits/stdc++.h>
using namespace std;

#define ll long long

void FIO() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}
    
int evalRPN(vector<string>& tokens) {
    stack<ll> s;
    for(int i=0;i<tokens.size();i++) {
        if(tokens[i] == "+" or tokens[i] == "-" or tokens[i] == "*" or tokens[i] == "/") {
            ll n1 = s.top();
            s.pop();
            ll n2 = s.top();
            s.pop();
            ll res;
            if(tokens[i] == "+") res = n1+n2;
            if(tokens[i] == "-") res = n2-n1;
            if(tokens[i] == "*") res = n1*n2;
            if(tokens[i] == "/") res = n2/n1;
            s.push(res);
            
        }
        else{
            ll num = stoi(tokens[i]);
            s.push(num);
        }
    }
    return s.top();
}

int main(){
	FIO();
	//Enter code here
	int n;
	cin>>n;
	vector<string> tokens(n);
	for(int i=0;i<n;i++) {
		cin>>tokens[i];
	}	
	cout<<evalRPN(tokens)<<endl;
}