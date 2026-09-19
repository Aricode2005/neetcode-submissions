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
    int minMeetingRooms(vector<Interval>& intervals) {
        auto comp=[&](Interval &a,Interval&b){
            if(a.start==b.start){
                return a.end<b.end;
            }
            return a.start<b.start;
        };
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),comp);
        priority_queue<int,vector<int>,greater<int>>pq;
        int cnt=0;
        for(int i=0;i<n;i++){
            int s=intervals[i].start;
            int e=intervals[i].end;
            if(pq.empty()|| pq.top()>s){
                cnt++;
                pq.push(e);
            }else{
                pq.pop();
                pq.push(e);
            }
        }

        return cnt;


    }
};
