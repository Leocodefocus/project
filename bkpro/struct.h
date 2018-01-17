#ifndef STRUCT_H
#define STRUCT_H
#include<stack>
struct BinaryTreeNode{
    int m_nValue;
    BinaryTreeNode* p_nLeft;
    BinaryTreeNode* p_nRight;
    BinaryTreeNode* p_nParent;
};
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
template <typename T>
class CQueue{
    public:
        CQueue(void);
       ~CQueue(void);

        void appendTail(const T& node);
        T deleteNode();
    private:
        stack<T> stack1;
        stack<T> stack2;
};
#endif
