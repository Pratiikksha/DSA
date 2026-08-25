class Solution {
    public int characterReplacement(String s, int k) {
        int n=s.length();
        int[] freq= new int[26];
        int l=0;
        int maxF=0;
        int maxLen=0;
        int winLen=0;
        for(int i=0;i<n;i++){
            char c=s.charAt(i);
            freq[c-'A']++;
            maxF=Math.max(maxF, freq[c-'A']);
            winLen= i-l+1;
            while(winLen-maxF >k && l<=i){
                freq[s.charAt(l)-'A']--;
                l++;
                winLen=i-l+1;
            }
            maxLen=Math.max(maxLen, i-l+1);
        }
        return maxLen;
    }
}