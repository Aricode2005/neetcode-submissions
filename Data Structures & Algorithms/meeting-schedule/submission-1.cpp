/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        auto comp=[&](Interval &a,Interval&b){
            if(a.start==b.start){
                return a.end>b.end;
            }
            return a.start<b.start;
        };
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),comp);
        bool ok=true;
        int last=-1;
        for(int i=0;i<n;i++){
            int s=intervals[i].start;
            if(s<last){
                ok=false;
                break;
            }else{
                last=intervals[i].end;
            }
        }
        return ok;
    }
};
