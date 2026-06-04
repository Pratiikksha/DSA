class Solution {
public:
    int totalWaviness(int num1, int num2) {
      if((num1/100)==0){
        if((num2/100)==0) return 0;
        else{
            num1=99;
        }
      }
      int sum=0;
      for(int i=num1;i<=num2;i++){
        string s=to_string(i);
        for(int j=1;j<s.size()-1;j++){
            int a=s[j-1]-'0';
            int b=s[j]-'0';
            int c=s[j+1]-'0';
            if(b>a && b>c) sum++;
            if(b<a && b<c) sum++;
        }
      }
      return sum;
    }
};