class Solution {
private:
    vector<int> hash;
    
public:
    bool isHappy(int n) {
        if(n == 1)
            return true;
        
        for(int i = 0; i < hash.size(); i++){
            if(n == hash[i])
                return false;
        }
        hash.push_back(n);
        
        int rem = 0;        
        while(n){
            int digit = n % 10;
            rem += digit * digit;
            n = n / 10;
        }
        return isHappy(rem);
    }
};