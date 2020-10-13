int birthdayCakeCandles(int ar_count, int* ar) {
    int highest=0;
    int count =0;
    for(int i =0;i<ar_count;i++){
        if(ar[i]>highest){
            highest=ar[i];
            count=1;
        }
        else if(ar[i]==highest){
            count++;
        }
    }
    return count;
}