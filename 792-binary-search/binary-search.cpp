class Solution {
public:
      
  int binsearch(vector<int>& nums, int tar,int st, int end){
if(st<=end){
    int mid = st+(end-st)/2;

     if (nums[mid] == tar){
        return mid;
     }
     
 else if(nums[mid]<=tar){
    return binsearch(nums,tar,mid+1,end);

 }
     else{
        return binsearch(nums,tar,st,mid-1);
     }
}
return -1;
  }
  
    int search(vector<int>& nums, int tar) {
        return binsearch(nums,tar,0,nums.size()-1);
    }
};