class Solution {
    public long maxRunTime(int n, int[] batteries) {
        long start=1;
        long totalTime=0;

        for(int battery: batteries) {
            totalTime+=battery;
        }

        long end=totalTime/n;

        long mid=0, maxi=0;

        while(start<=end) {
            mid=start+(end-start)/2;
            long effTime=0;
            for (int batteryCapacity : batteries) {
                effTime+=Math.min((long)batteryCapacity, mid);
            }
            if (mid*n<=effTime) { 
                maxi=mid;
                start=mid+1;
            } else {
                end=mid-1;
            }
        } 

        return maxi;
    }
}