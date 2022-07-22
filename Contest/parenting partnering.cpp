#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

struct Time {
	int i, start, end;
};

bool sortThis(Time a, Time b){
	return a.start < b.start;
}

bool isOverlap(int size, Time list[], Time act){
	if(size == 0) return false;
	for(int x=size-1;x>=0;x--){
		if(list[x].start <= act.start && act.start < list[x].end){
			return true;
		} else if(list[x].start < act.end && act.end <= list[x].end){
			return true;
		} else if(act.start <= list[x].start && list[x].start < act.end){
			return true;
		} else if(act.start < list[x].end && list[x].end <= act.end){
			return true;
		}
	}	
	return false;
}

string findWays(int n, int i, int sumP1, int sumP2, Time activities[], Time actP1[], Time actP2[], bool checked[], string ans){
	if(i == n){
		return ans;
	}
	
	string temp = "";
	for(int x=0;x<n && temp == "";x++){
		if(!checked[x]){
			Time act = activities[x];
			checked[x] = true;
			bool p1 = isOverlap(sumP1, actP1, act);
			bool p2 = isOverlap(sumP2, actP2, act);
			if(p1 && p2) break;
			if(!p1){
				string tempAns = ans;
				tempAns.replace(act.i,1,"C");
				actP1[sumP1] = act;
				tempAns = findWays(n,i+1,sumP1+1, sumP2, activities, actP1, actP2, checked, tempAns);
				if(tempAns != "") temp = tempAns;
			}
			if(!p2){
				string tempAns = ans;
				tempAns.replace(act.i,1,"J");
				actP2[sumP2] = act;
				tempAns = findWays(n,i+1,sumP1, sumP2+1, activities, actP1, actP2, checked, tempAns);
				if(tempAns != "") temp = tempAns;
			}
			checked[x] = false;
		}
	}
	return temp;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	for(int c=1;c<=t;c++){
		int n;
		cin >> n;
		Time activities[n];
		//cout << "size: " << n << "\n";
		for(int x=0;x<n;x++){
			Time temp;
			temp.i = x;
			cin >> temp.start >> temp.end;
			activities[x] = temp;
		}
		
		string format(n, '-');
		int sumP1 = 0;
		Time actP1[n];
		int sumP2 = 0;
		Time actP2[n];
		
		sort(activities, activities+n, sortThis);
		
		for(int x=0;x<n;x++){
			Time act = activities[x];
			if(isOverlap(sumP1, actP1, act)){
				if(isOverlap(sumP2, actP2, act)){
					format = "IMPOSSIBLE";
					break;
				} else {
					actP2[sumP2] = act;
					format.replace(act.i, 1, "J");
					sumP2++;
				}
			} else {
				//cout << "C ";
				actP1[sumP1] = act;
				format.replace(act.i, 1, "C");
				sumP1++;
			}
		}
		//bool checked[n] = { false };
		//string answer = findWays(n,0,0,0,activities,actP1,actP2,checked,format);
		//if(answer == "") answer = "IMPOSSIBLE";
		cout << "Case #" << c << ": " << format << "\n";
	}
    return 0;
}
