long long getSum(int N, int A[]) {
	long long ans = 0;
	
	for(int x=0;x<N;x++){
		ans += A[x];
	}
	
  	return ans;
}
