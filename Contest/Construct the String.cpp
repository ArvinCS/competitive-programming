#include <iostream>

using namespace std;

string solve(int n, int a, int b, int i, string ans){
	if(i >= n){
		//cout << ans << "\n";
		for(int x=1;x+a-1<=n;x++){
			string temp = ans.substr(x-1,a);
			//cout << x+a << " " << temp;
			bool alphabet[26] = { false };
			int unique = 0;
			for(int t=0;t<a;t++){
				if(!alphabet[temp[t] - char(97)]){
					alphabet[temp[t] - char(97)] = true;
					unique++;
				}
			}
			if(unique != b){
				//cout << " FAILED\n";
				return "";
			}
			 //else cout << " SUCCESS \n";
		}
		//cout << "OVERALL SUCCESS\n";
		return ans;
	}
	string temp = "";
	for(int x=0;x<b && temp == "";x++){
		string tempAns = ans;
		tempAns.push_back(char(97+x));
		temp = solve(n,a,b,i+1,tempAns);
	}
	return temp;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	for(int c=0;c<t;c++){
		int n,a,b;
		cin >> n >> a >> b;
		cout << "ANS: " << solve(n,a,b,0,"") << "\n";
	}
    return 0;
}
