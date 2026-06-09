class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     int n =s.size();
     int freq[256]={0};
     int i =0,maxlen=0,j=0;
     while(j<n){
        freq[s[j]]++;
     
     while(freq[s[j]]>1){
        freq[s[i]]--;
        i++;
     }
     maxlen = max(maxlen,j-i+1);
     j++;
    }
    return maxlen;
    }
};