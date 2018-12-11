int prime(int n){
  if(n<=1)return 0;
  else if(n==2)return 1;
  else if(n%2==0)return 0;
  int i,sel=1;
  for(i=3;i<n;i=i+2)
    if(n%i==0){
      sel = 0;
      break;
    }
    return sel;
}
