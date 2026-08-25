class Solution {
    public int subarraySum(int[] nums, int k) {
       HashMap<Integer, Integer> mp= new HashMap<>();
       int n=nums.length;
       int sum=0;
       int ans=0;
       mp.put(0,1);
       for(int i=0;i<n;i++){
        sum+=nums[i];
        int need=sum-k;
        if(mp.containsKey(need)){
            ans+=mp.get(need);
        }
        mp.put(sum, mp.getOrDefault(sum,0)+1);
       } 
       return ans;
    }
}