#include <stdio.h>

#define MAX 100
int tree[MAX];
int completeNode = 7;
int getLeftChild(int index){
    if(tree[index] != '\0' && ((2*index)+1) <= completeNode){
        return 2*index +1;
    }
    else{
        return -1 ;
    }
}
int getRightChild(int index){
    if(tree[index] != '\0' && ((2*index)+2) <= completeNode){
        return 2*index +2;
    }
    else{
        return -1;
    }
}
void preorder(int index){
    if(index >= 0 && tree[index] != '\0'){
        printf("%d " , tree[index]);
        preorder(getLeftChild(index));
        preorder(getRightChild(index));
    }
    
}
void inorder(int index){
    if(index >= 0 && tree[index] != '\0'){
        inorder(getLeftChild(index));
        printf("%d " , tree[index]);
        inorder(getRightChild(index));
    }
    
}
void postorder(int index){
    if(index >= 0 && tree[index] != '\0'){
        postorder(getLeftChild(index));
        postorder(getRightChild(index));
        printf("%d " , tree[index]);
    }
    
}

void main(){
    printf("Enter array elements : ");
    for(int i = 0 ; i < 7 ; i++){
        scanf("%d" , &tree[i]);
    }
    printf("Post order\n");
    postorder(0);
    printf("\nInorder\n");
    inorder(0);
    printf("\nPre order\n");
    preorder(0);
}