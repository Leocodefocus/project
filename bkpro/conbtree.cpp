#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

struct BinaryTreeNode{
    int m_nValue;
    BinaryTreeNode* p_nLeft;
    BinaryTreeNode* p_nRight;
    BinaryTreeNode* p_nParent;
};

BinaryTreeNode* ConstructCore(int* startPreOrder,int* endPreOrder,int* startInOrder,int* endInOrder){
    int mValue = startPreOrder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = mValue;
    root->p_nLeft=root->p_nRight=nullptr;
    if(startPreOrder==endPreOrder){
        if(startInOrder==endInOrder&&*startPreOrder==*startInOrder){
            return root;
        }else{
            logic_error ex("Invalid input"); 
            throw std::exception(ex);
        }
    }
    int* p = startInOrder;
    while(p<=endInOrder&&*p!=mValue) p++;
    if(p==endInOrder&&*p!=mValue) {
        logic_error ex("Invalid input"); 
        throw std::exception(ex);
    }
    int length = p-startInOrder;
    if(length>0){
        root->p_nLeft = ConstructCore(startPreOrder+1,startPreOrder+length,startInOrder,startInOrder+length-1);
    }
    if(length<(endPreOrder-startPreOrder)){
        root->p_nRight = ConstructCore(startPreOrder+length+1,endPreOrder,startInOrder+length+1,endInOrder);
    }
    return root;
}

BinaryTreeNode* Construct(int* preorder,int* inorder,int length){
    if(preorder==nullptr || inorder==nullptr || length<=0) return nullptr;
    return ConstructCore(preorder,preorder+length-1,inorder,inorder+length-1);
}

int printTree(BinaryTreeNode* root){
    if(root==nullptr) {
        printf("\n");
        return 0;
    }
    printf("%d ",root->m_nValue);
    printTree(root->p_nLeft);
    //printf("%d ",root->m_nValue);
    printTree(root->p_nRight);
}

BinaryTreeNode* getNext(BinaryTreeNode* pNode){
    if(pNode==nullptr) return nullptr;
    BinaryTreeNode* pNext=nullptr;
    if(pNode->p_nRight!=nullptr){
        BinaryTreeNode* pRight = pNode->p_nRight;
        while(pRight->p_nLeft!=nullptr) pRight = pRight->p_nLeft;
        pNext = pRight;
    }else if(pNode->p_nRight!=nullptr){
        BinaryTreeNode* pCurrent = pNode;
        BinaryTreeNode* pParent = pCurrent->p_nParent;
        while(pCurrent!=nullptr&&pCurrent==pParent->p_nRight){
            pCurrent = pParent;
            pParent = pParent->p_nParent;
        }
        pNext = pParent;
    }
    return pNext;
}

int main(int argc,char* argv[]){
    int preOrder[]={1,2,4,7,3,5,6,8};
    int inOrder[]={4,7,2,1,5,3,8,6};
    int level = 0;
    BinaryTreeNode* root = Construct(preOrder,inOrder,8);
    printTree(root,level);
    return 0;
}
