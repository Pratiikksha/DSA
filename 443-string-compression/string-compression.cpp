class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        if(n==1) return 1;
        int i=0;
        int j=0;
        int idx=0;
        while(i<n){
            int cnt=0;
            j=i;
            while(j<n && chars[j]==chars[i]){
                cnt++;
                j++;
            }
            if(cnt==1){
            chars[idx++]=chars[i];
            i=j;
            continue;
            }
            else{
                chars[idx++]=chars[i];
                string s=to_string(cnt);
                reverse(s.begin(),s.end());
                int len=s.size();
                cnt=stoi(s);
                while(cnt || len){
                    int x=cnt%10;
                    chars[idx++]=x+'0';
                    cnt/=10;
                    len--;
                }
            }
            i=j;
        }
        return idx;
    }
};