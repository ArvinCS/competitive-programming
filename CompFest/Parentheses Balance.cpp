#include <iostream>
#include <stack>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

void solve(string s){
	stack<char> stack;
	for(int x=0;x<s.length();x++){
		if(s[x] == '[' || s[x] == '('){
			stack.push(s[x]);
		} else {
			if(stack.size() > 0 && s[x] == ']' && stack.top() == '['){
				stack.pop();	
			} else if(stack.size() > 0 && s[x] == ')' &&  stack.top() == '('){
				stack.pop();
			} else {
				cout << "tidak\n";
				return;
			}
		}
	}	
	cout << "ya\n";
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		string s;
		cin >> s;
		
		solve(s);
	}
	
    return 0;
}

