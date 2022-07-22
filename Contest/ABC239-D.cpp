#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	
	bool takahashi = false;
	for(int x=a;x<=b;x++){
		bool valid = false;
		for(int y=c;y<=d;y++){
			int sum = x+y;
			
			bool prime = true;
			for(int y=2;y*y<=sum;y++){
				if(sum % y == 0){
					prime = false;
					break;
				}
			}
			
			if(prime){
				valid = true;
				break;
			}
		}
		
		if(!valid){
			takahashi = true;
			break;
		}
	}
	
	cout << (takahashi ? "Takahashi" : "Aoki") << "\n";
    return 0;
}

