void staircase(int n) {
    char str[n];
    for(int i=0;i<n;i++){
        str[i]='#';
        str[i+1]=0;
        printf("%*s",n,str); 
        if(i!=(n-1))
            printf("\n");
    }
}