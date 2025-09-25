  bool d=0;
  bitset<mx> dp=1;
  for(auto u:v){
   dp|=(dp<<u);
  }
  for(int i=0;i<=sum;i++){
   if(dp[i]){
      if(i<=k&&(sum-i)<=n-k){
         d=1;
         break;
      }
   }
  }
