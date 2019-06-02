#include <stdio.h>
void printArray(int* arrayPtr, int arrSize)
{
    int i = 0;
    for(i = 0; i < arrSize; i++)
    {
        printf("%d ",arrayPtr[i]);
    }
    printf("\n");
}

int* sortArray(int* nums, int numsSize, int *returnSize)
{
    int i, j;
    int key;
    returnSize = (int *)malloc(sizeof(int) * (numsSize));
    memcpy(returnSize, nums, (sizeof(int)*(numsSize)));
//    printArray(returnSize, numsSize);
    for(j = 1; j < numsSize; j++)
    {
        key = returnSize[j];
        i  = j - 1;
        while(i >= 0 &&  returnSize[i] > key)
        {
            returnSize[i+1] = returnSize[i];
            i = i - 1;
        }
        returnSize[i+1]= key;
    }
//    printArray(returnSize, numsSize);
    return returnSize;
}

int main(int argc, char **argv)
{
	int arr[] = {5, 3, 2, 1};
    int *retArray;
    int i = 0;
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    printf("arrSize is %d\n",arrSize);
    retArray = sortArray(arr, arrSize, retArray);
    printArray(retArray, arrSize);
    free(retArray);
	return 0;
}
