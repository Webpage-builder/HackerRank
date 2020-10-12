int* compareTriplets(int a_count, int* a, int b_count, int* b, int* result_count) {
    *result_count =2;
    int* outArr = malloc(2 * sizeof(int));
    outArr[0]=0;
    outArr[1]=0;
    for(int i=0;i<a_count;i++){
        if(a[i]>b[i]){
            outArr[0]++;
        }
        else if(b[i]>a[i]){
            outArr[1]++;
        }
    }
    return outArr;
}