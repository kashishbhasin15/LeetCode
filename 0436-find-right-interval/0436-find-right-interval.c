/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* findRightInterval(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize) {


    // int *ans[intervalsSize];
    int *ans=malloc(intervalsSize*sizeof(int));
    *returnSize = intervalsSize;
    
    for (int i =0;i<intervalsSize;i++)
    {
        int minStart=1000000;
        int idx=-1;

        for(int j=0;j<intervalsSize;j++)
        {
            if(intervals[j][0] >= intervals[i][1] && minStart>intervals[j][0])
            {
                idx=j;
                minStart=intervals[j][0];
            }
        }
        ans[i]=idx;
    } 
    
    return ans;
}