#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<stack>
#include<exception>

using namespace std;

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

template <typename T> CQueue<T>::CQueue(){}
template <typename T> CQueue<T>::~CQueue(){}
template <typename T> void CQueue<T>::appendTail(const T& node){
    stack1.push(stack1);
}
template <typename T> T CQueue<T>::deleteNode(){
    if(stack2.size<=0){
        while(stack1.size>0){
            T& node = stack1.top();
            stack1.pop();
            stack2.push(node);
        }
    }
    if(stack2.size<=0){
        logic_error ex("queue is empty");
        throw new exception(ex);
    }
    T& head = stack2.top();
    stack2.pop();
    return head;
}

int main(int argc,char* argv[]){
    printf("Hello,CQueue!\n");
    return 0;
}
