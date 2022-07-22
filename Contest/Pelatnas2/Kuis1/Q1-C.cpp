#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, t;
	cin >> n >> t;
	
	int sum = 0;
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
		sum += a[x];
	}
	
	ll table[n][30][30][30];
	tuple<int, int, int, int> backtrack[n][30][30][30];
	
	table[0][log2(a[0])][log2(a[0])][log2()]
	for(int x=1;x<n;x++){
		for(int a=0;a<30;a++){
			for(int b=0;b<30;b++){
				for(int c=0;c<30;c++){
					
				}
			}
		}
	}
	return 0;
}
