char* kangaroo(int x1, int v1, int x2, int v2) {
    int i=0;
    while((v1*i+x1)>=(v2*i+x2)){
        if((v1*i+x1)==(v2*i+x2))
            return "YES";
        i++; 
    }
    while((v1*i+x1)<=(v2*i+x2)){
        if((v1*i+x1)==(v2*i+x2))
            return "YES";
        i++; 
    }
    return "NO";
}