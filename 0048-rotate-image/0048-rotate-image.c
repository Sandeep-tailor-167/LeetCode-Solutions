void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int stack[matrixSize*matrixColSize[0]];
    int top = -1; 
    void push(int el){
        stack[++top] = el;
    }
    int pop(){
        return stack[top--];
    }
    int row = matrixSize - 1;
    for(int i = row;i >= 0; i--){
        for(int j = 0;j < matrixColSize[i];j++){
            push(matrix[j][i]);
        }
    }
    for(int i = 0;i<=row;i++){
        for(int j = 0;j < matrixColSize[i];j++){
            matrix[i][j] = pop();
        }
    }
}