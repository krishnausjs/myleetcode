//Given an array with n integers, your task is to check if it could become non-decreasing 
//by modifying at most 1 element. We define an array is non-decreasing 
//if array[i] <= array[i + 1] holds for every i (1 <= i < n).


// Example 1 : 
// input  4 2 3
// output true. As we can replace 4 with 1 

//Example 2:
//input: 4 2 1
// Output false. We cant change one element and make it sorted.
//So if there are more than one element which satisfies condition a[i+1] < a[i] then we return false.
#include <stdio.h>
#include <stdbool.h>

bool checkPossibility(int* nums, int numsSize)
{
    int i = 0;
    int j;
    int count  = 0;
    for(i = 0; i < numsSize; i++)
    {
        if(nums[i+1] < nums[i])
        {
            break;
        }
        if( i >= (numsSize - 1))
            return true;
            
        for(j = i+1; j < numsSize; ++j)
        {
            if(nums[j+1] < nums[j])
                return false;
        }
        if(i == 0)
            return true;
       if(nums[i-1] < nums[i+1] || nums [i] < nums[i+2]) return true;
            return false;
    }
    return true;
}

int main(int argc, char **argv)
{
    int arr[] = {1, 4, 2,  2, 3};
    bool result;
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    result = checkPossibility(arr, arrSize);
    result ? printf("true\n"): printf("false \n");
	return 0;
}
