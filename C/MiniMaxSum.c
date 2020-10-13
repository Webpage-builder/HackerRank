void miniMaxSum(int arr_count, int* arr) {
    unsigned long long int min= LLONG_MAX;
    unsigned long long int max= 0;
    unsigned long long int sum;
    for(int miss=0;miss<arr_count;miss++){
        sum=0;
        for(int i=0;i<arr_count;i++){
            if(i!=miss)
                sum+=arr[i];
        }
        if(sum>max)
            max=sum;
        if(sum<min)
            min=sum;
    }    
    printf("%ld %ld",min,max);
}