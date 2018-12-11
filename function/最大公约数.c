int gcd( int x, int y ){
	if(x<y){
		int t;
		t=x;
		x=y;
		y=t;
	}
	while(y!=0){
		int temp;
		temp=x%y;
		x=y;
		y=temp;
	}
	return x;
} 
