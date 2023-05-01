// TODO: function prototypes of vector and matrix operations

int compare(int *vector1, int *vector2, int size);
int **cpy(int **original,int rows,int cols);
int *cpyvector(int *original,int rows);
int **add(int **matrix1,int **matrix2,int rows, int cols);
int *addvector(int *vector1, int *vector2, int rows);
void freematrix(int **matrix,int rows,int cols);