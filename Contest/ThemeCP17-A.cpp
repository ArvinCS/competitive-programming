#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	string s;
	cin >> s;
	
	int n = s.length();
	stack<char> st;
	for(int x=0;x<n;x++){
		while(!st.empty() && st.top() >= s[x]){
			st.pop();
		}
		st.push(s[x]);
		
		cout << (st.size() % 2 == 0 ? "Ann" : "Mike") << "\n";
	}
	
    return 0;
}

