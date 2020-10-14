int diagonalDifference(int arr_rows, int arr_columns, int** arr) {
    int leftDiag=0;
    int rightDiag=0;

    for(int i=0;i<arr_rows;i++){
        leftDiag+=arr[i][i];  
    }
    for(int i=0;i<arr_rows;i++){
        rightDiag+=arr[i][arr_rows-i-1];
    }
    if(leftDiag>rightDiag)
        return (leftDiag-rightDiag);
    else
        return (rightDiag-leftDiag);
}