
//Approach : Dynamic Programming


//Algorithm:
/*
    Create a dp[] array of size N, where N is the size of the given array.
    Initialise all the elements of the array to INT_MAX.
    Initialise dp[0] = 0, since, we are standing at the first index and we need no jumps to reach the first element.
    The recursive structure would be:
    dp[i] = 1 + min(dp[i], 1 + min( dp[i+1], dp[i+2],. . . dp[i + dp[i] + 1]))
    Iterate a loop from 0 till N – 1. Run a nested loop from i + 1 till min(i + arr[i] + 1, n) and find the minimum of jumps[i] and i + jumps[i].
    After iterations, return the value of dp[N – 1]
*/


int minJump(int num[], int n){
    int dp[n] = {INT_MAX}
    dp[0] = 0
    for(i = 0 to i < n){
        for(j = i+1 to j < min(i+num[i]+1, n)) {
            dp[j] = min(dp[j], 1 + dp[i])
        }
    }
    return dp[n-1]
}
    


//Approach : Greedy Approach

/* Algorithms: 

Consider three variables, jumps, which stores the number of jumps, end, which denotes the end of the array and farthest denoting the farthest one can jump and initialise them to 0.
    Traverse over the given array and perform the following operation:
        farthest = i + nums[i]
        If end is reached, then ith jump is finished, therefore update end = farthest.
    Return total jumps.
*/

int minJump(int nums[], int n) {
        int jumps = 0, currentJumpEnd = 0, farthest = 0;
        for (int i = 0; i < n - 1; i++) {
             farthest = max(farthest, i + nums[i]);
             if (i == currentJumpEnd) {
                jumps++;
                currentJumpEnd = farthest;
            }
        }
        return jumps;
    }