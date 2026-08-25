class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n=s.length();
        int l=0;
        HashMap<Character,Integer>hmp= new HashMap<>();
        int maxi=0;
        for(int r=0;r<n;r++){
            char c=s.charAt(r);
            if(hmp.containsKey(c)){
                l=Math.max(l,hmp.get(c)+1);
            }
            maxi=Math.max(maxi, r-l+1);
            hmp.put(c,r);
        }
        return maxi;
    }
}