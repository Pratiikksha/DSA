class AuthenticationManager {
public:
    unordered_map<string,int>mp;
    int time;
    // void remove(uordered_map<string,int>& mp,int t){
    //     for(auto &it:mp){
    //         if(it.second<=t){
    //             mp.erase(it.first);
    //         }
    //     }
    // }
    AuthenticationManager(int timeToLive) {
        time=timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        mp[tokenId]=currentTime+time;
        // time++;
        // remove(mp,time);
    }
    
    void renew(string tokenId, int currentTime) {
        if(mp.count(tokenId)&&mp[tokenId]>currentTime){
            mp[tokenId]=currentTime+time;
        }
        // time++;
        // remove(mp,time);
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count=0;
        for(auto &it:mp){
            if(it.second>currentTime){
                count++;
            }
        }
        return count;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */