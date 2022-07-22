#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	set<int> st;
	for(int x=0;x<n;x++){
		int val;
		cin >> val;
		
		st.insert(val);
	}
	
	cout << st.size() << "\n";
    return 0;
}

