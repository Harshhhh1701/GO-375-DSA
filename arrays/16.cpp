//three sum
vector<vector<int>> threeSum(vector<int>& nums) {        
       vector< vector<int> > result;
       sort(nums.begin(), nums.end());       
       if(nums.size()<3 || nums[0]>0)
         return result;
       for(int i=0;i<nums.size();i++){
           if(i>0 && nums[i]==nums[i-1]) continue;            
           int first=nums[i]; //first numer        
           int p=i+1; //second number index
           int q=nums.size()-1; //third number index            
           while(p<q){             
               int sum_curr= nums[p]+nums[q];
               if(sum_curr+first==0){
                   result.push_back(vector<int>{first, nums[p], nums[q]});
                   while(p<q && nums[p]==nums[p+1]) p++;
                   while(p<q && nums[q]==nums[q-1]) q--;
                   p++;
                   q--;
               }               
              else if(sum_curr+first < 0) p++;               
              else q--;                
          } 
       }
      return result;  
    }