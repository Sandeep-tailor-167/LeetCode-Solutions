/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxDepthAfterSplit(char* seq, int* returnSize) {
    int size = strlen(seq);
    *returnSize = size;
    int *result = (int *)malloc(size*sizeof(int));
    int count = -1;
    for(int i = 0;i < size;i++){
        if(seq[i]=='('){
            count++;
            result[i] = count%2;
        }else{
            result[i] = count%2;
            count--;
        }
    }
    return result;
}