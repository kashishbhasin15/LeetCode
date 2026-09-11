char nextGreatestLetter(char* letters, int lettersSize, char target) {
    
int low=0;
int high=lettersSize-1;

while(low<=high)
{
    int mid=(low+high)/2;
    if(letters[mid]<=target)
    {
        low=mid+1;
    }
    else
    {
        high=mid-1;
    }
}
return letters[low%lettersSize];
}