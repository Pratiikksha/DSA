class Solution {
public:
    double angleClock(int hour, int minutes) {
        if (minutes == 0) {
            double angle = hour * 5 * 6;
            if (angle > 180)
                return 360 - angle;
            return angle;
        }
        // double Hinterval=hour+1;
        // if(Hinterval>12) Hinterval-=12;
        // double Minterval=minutes/5.0;
        // double H=abs(Minterval-Hinterval);
        // double ans=((minutes/12.0)+(5*H))*6.0;
        // if(ans>180) return 360-ans;
        // return ans;
        double angleH = ((hour * 5)+(minutes/12.0));
        double totalAngle = abs(angleH - minutes)*6.0;
        if (totalAngle > 180)
                return 360 - totalAngle;
            return totalAngle;
    }
};