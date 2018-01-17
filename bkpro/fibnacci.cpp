#include<cstdio>
#include<cstdlib>

struct Matrix2by2{
    Matrix2by2
    (
        long long m00=0,
        long long m01=0,
        long long m10=0,
        long long m11=0
    ):m_00(m00),m_01(m01),m_10(m10),m_11(m11)
    {
    }
    long long m_00;
    long long m_01;
    long long m_10;
    long long m_11;
};

Matrix2by2 MatrixMultiply(Matrix2by2 matrix1,Matrix2by2 matrix2){
    return Matrix2by2(matrix1.m_00*matrix2.m_00+matrix1.m_01*matrix2.m_10,
		      matrix1.m_00*matrix2.m_01+matrix1.m_01*matrix2.m_11,
                      matrix1.m_10*matrix2.m_00+matrix1.m_11*matrix2.m_10,
                      matrix1.m_10*matrix2.m_01+matrix1.m_11*matrix2.m_11);
}

Matrix2by2 MatrixPower(unsigned int n){
    if(n<0) return Matrix2by2();
    Matrix2by2 matrix;
    if(n==1) return Matrix2by2(1,1,1,0);
    else if(n%2==0){
        matrix = MatrixPower(n/2);
        matrix = MatrixMultiply(matrix,matrix);
    }else if(n%2==1){
        matrix = MatrixPower((n-1)/2);
        matrix = MatrixMultiply(matrix,matrix);
        matrix = MatrixMultiply(matrix,Matrix2by2(1,1,1,0));
    }
    return matrix;
}

long long FibnacciMatrix(unsigned int n){
    if(n<0) return 0;
    if(n==1) return 1;
    if(n>=2){
        Matrix2by2 matrix = MatrixPower(n-1);
        return matrix.m_00;
    }
}

int FibnacciRecur(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    if(n>=2) return FibnacciRecur(n-1)+FibnacciRecur(n-2);
}

int FibnacciLoop(int n){
    int result[]={0,1};
    if(n<0) return 0;
    else if(n<2) return result[n];
    else if(n>=2){
        int re1 = 0;
        int re2 = 1;
        int res = 0;
        for(int i=2;i<=n;i++){
            res = re1 + re2;
            re1 = re2;
            re2 = res;
        }
        return res;
    }
    return 0;
}

int main(int argc,char* argv[]){
    int n = 10;
    int result1 = FibnacciRecur(n);
    int result2 = FibnacciLoop(n);
    int result3 = FibnacciMatrix(n);
    printf("Result:%d %d %d\n",result1,result2,result3);
    return 0;
}
