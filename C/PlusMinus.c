void plusMinus(int arr_count, int* arr) {
    int* types = malloc(3 * sizeof(int));
    for(int i=0;i<3;i++){
        types[i]=0;
    }
    for(int i = 0;i<arr_count;i++){
        if(arr[i]>0)
            types[0]++;
        else if(arr[i]<0)
            types[1]++;
        else 
            types[2]++;
    }
    for(int i=0;i<3;i++){
        printf("%.6f\n",(float)types[i]/arr_count);
    }
}