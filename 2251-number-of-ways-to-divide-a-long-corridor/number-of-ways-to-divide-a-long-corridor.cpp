class Solution {
public:
    int numberOfWays(string corridor) {
        int result = 1, seatCounter = 0, totalSeats = 0;
        int mod = 1e9+7;
        int j = corridor.size()-1;
        for(auto i:corridor){
            if(i == 'S')totalSeats ++;
        }
        if(totalSeats == 0 || totalSeats % 2 == 1) return 0;
        while(j>= 0 && corridor[j] != 'S')j--;
        for(int i= 0;i<=j;i++){
            if(seatCounter == 2){
                int temp = 1;
                while(i<corridor.size() && corridor[i] != 'S'){
                    i++;
                    temp++;
                }
                result  = (1LL * result*temp)%mod;
                seatCounter = 0;
            }
            if(corridor[i] == 'S') {seatCounter++;totalSeats++;}
            
        }
        return result;
    }
};