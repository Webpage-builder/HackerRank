char* timeConversion(char* s) {
    char *str = malloc(sizeof(char)*9);

    if(s[8]=='P'){
        if((s[1]>='8')||(s[0]=='1')){
            if((s[0]=='1')&&(s[1]=='2')){
            str[0]='1';
            str[1]='2';
        }
        else{
                str[0]='2';
                str[1]=((((((int)(s[1])-48))+2)%10)+48);
        }   
        }
        else{
            str[0]='1';
            str[1]=((((((int)(s[1])-48))+2)%10)+48);
        }
    }
    else{
        if((s[0]=='1')&&(s[1]=='2')){
            str[0]='0';
            str[1]='0';
        }
        else{
        str[0]=s[0];
        str[1]=s[1];
        }     
    }
    for(int i=2;i<8;i++){
        str[i]=s[i];
    }
    str[8]=0;
    return str;
}