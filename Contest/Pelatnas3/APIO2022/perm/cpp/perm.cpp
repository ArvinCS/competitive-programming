#include "perm.h"
#include <bits/stdc++.h>

using namespace std;

#define ll long long

std::vector<int> construct_permutation(long long k){
	k--;
	vector<int> ans;
	
	while(k > 0){
		for(int i=59;i>=0;i--){
			ll bit = (1ll << (i+1))-1;
			if(k >= bit){
				for(auto &val : ans){
					val += (i+1);
				}
				
				int l = ans.size();
				for(int x=0;x<=i;x++){
					ans.push_back(x);
				}
				k -= bit;
				
//				for(auto val : ans){
//					cout << val << " ";
//				}cout << endl;
					
//				cout << i << endl;
				for(int j=i;j>=1;j--){
					for(int r=j;r>=j;r--){
						bit = (1ll << (r+1)) - (1ll << j);
						while(k >= bit){
//							cout << j << " " << r << " " << k << " " << bit << endl;
							for(int x=0;x<l;x++){
								ans[x] += (r-j+1);
							}
							for(int x=l+j;x<ans.size();x++){
								ans[x] += (r-j+1);
							}
							
							for(int x=1;x<=r-j+1;x++){
								ans.push_back(ans[l+j-1]+x);
							}
							
		//					for(auto val : ans){
		//						cout << val << " ";
		//					}cout << " = " << endl;
							
							k -= bit;
						}
					}
				}
			}
		}
	}
//	for(auto val : ans){
//		cout << val << "\n";
//	}
	return ans;
}
