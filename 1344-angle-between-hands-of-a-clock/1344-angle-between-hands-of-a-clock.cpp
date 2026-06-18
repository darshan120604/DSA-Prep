class Solution {
public:
    double angleClock(int hour, int minutes) {
        double md = minutes * 6;
        double hd = (hour * 30) % 360;

        double hmd =  30 * md / 360;

        double ans = abs((hd + hmd) - md);
        
        if(int(ans) == 360) return 0;
        if(abs(ans) > 180) return 360 - abs(ans);
        return abs(ans); 
        
    }
};