class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hpm = 60;
        hour %= 12;
        double hourAngle = hour + minutes/hpm;
        double anglepm = 6;
        hourAngle *= anglepm * 5;
        double minuteAngle = minutes*anglepm;
        double diff = abs(minuteAngle - hourAngle);
        diff = min(diff, 360 - diff);
        return diff;
    }
};
