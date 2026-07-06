class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string,int>mp;
        int n=req_skills.size();
        for(int i=0;i<n;i++){
            mp[req_skills[i]]=i;
        }
        int m=people.size();
        vector<int>skills(m,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<people[i].size();j++){
                if(mp.count(people[i][j])){
                    skills[i]|=1<<mp[people[i][j]];
                }
            }
        }
        vector<int>dp(1<<n,m+1);
        vector<int>prevMask(1<<n,-1);
        vector<int>prevPerson(1<<n,-1);
        int fullState=(1<<n)-1;
        dp[0]=0;
        for(int mask=0;mask<(1<<n);mask++){
            if(dp[mask]==m+1) continue;
            for(int i=0;i<m;i++){
                int newMask=mask|skills[i];
                if(dp[newMask]>dp[mask]+1){
                    dp[newMask]=dp[mask]+1;
                    prevMask[newMask]=mask;
                    prevPerson[newMask]=i;
                }
            }
        }
        vector<int>team;
        int  curr=fullState;
        while(curr!=0){
            int p=prevPerson[curr];
            if(p==-1) break;
            team.push_back(p);
            curr=prevMask[curr];
        }
        return team;
    }
};