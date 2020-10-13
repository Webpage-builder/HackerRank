int* gradingStudents(int grades_count, int* grades, int* result_count) {
    *result_count=grades_count;
    int *o = malloc(grades_count * sizeof(int));
    for(int i=0;i<grades_count;i++){
        if(grades[i]<38){
            o[i]=grades[i];
        }
        else if((grades[i]%5)>2){
            o[i]=grades[i]+(5-(grades[i]%5));
        }
        else{
            o[i]=grades[i];
        }
    }
    return o;
}