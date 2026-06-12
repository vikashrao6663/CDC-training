class Solution {
public:
    int compress(vector<char>& chars) {
     int n =chars.size();
     int i =0;
     int idx = 0 ;
     while(i<n){ // array ko traverse krna h 
        char ch = chars[i]; 
        int count =0;
        // same wale ko count kro 
        while(i<n && chars[i]==ch){ 
            count++;
            i++;        }
       
     chars[idx++]=ch;
     if(count>1){
        string s=to_string(count);

        for(int j=0;j<s.size();j++){
            chars[idx++] = s[j];
        }
     }
     }
     return idx;
    }
};