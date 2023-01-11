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

string getHint(string secret, string guess) {
    vector<int> hash(10,0) , hash2(10,0);
    int bull = 0,cows = 0;
    for(int i=0;i<secret.size();i++) {
        hash[(secret[i]-'0')]++;
        hash2[guess[i] - '0']++;
        if(secret[i] == guess[i]) {
            bull++;
            hash[(secret[i]-'0')]--;
            hash2[(guess[i] - '0')]--;
        }
    }
    for(int i=0;i<hash.size();i++) {
        if(hash[i] > 0 and hash2[i] > 0) {
            int diff = min(hash[i],hash2[i]);
            cows += diff;
        }
    }
    string ans = to_string(bull) + "A" + to_string(cows) + "B";
    return ans;
}

int main(){
	FIO();
	//Enter code here
	string secret , guess;
	cin>>secret>>guess;
	cout<<getHint(secret , guess)<<endl;

}