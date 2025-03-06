// binary search
/*
#include "iostream"
using namespace std;
int binarySearch(int arr[], int n,int value,int low,int high){
    if(low>high){
        return -1;
    }
    int mid = (low+high)/2;
    if(arr[mid]==value){
        return mid;
    }
    if(arr[mid]>value){
        return binarySearch(arr,n,value,low,mid-1);
    }
    return binarySearch(arr,n,value,mid+1,high);

}
int main(){
    int n, arr[100], value;
    cout<<"input n\n";
    cin>>n;
    cout<<"input array\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"input value"<<endl;
    cin>>value;
    int result = binarySearch(arr,n,value,0,n-1);
    if(result==-1){
        cout<<"not found"<<endl;
    }else{
        cout<<"found at index "<<result<<endl;
    }
    return 0;
}
*/
//binary tree
#include "iostream"
using namespace std;
struct treeNode{
    int data;
    treeNode* left;
    treeNode* right;
};
struct binaryTree{
    treeNode *root;
};
treeNode* makeNode(int data){
    treeNode *newNode=(treeNode*)malloc(sizeof(treeNode));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
void init(binaryTree *tree){
    tree->root=NULL;
}
void insert(binaryTree *tree, int data){
    treeNode *newNode = makeNode(data);
    
    if (tree->root == NULL){
        tree->root = newNode;
        return;
    }
    treeNode *current = tree->root;
    treeNode *parent = NULL;
    
    while (current != NULL){
        parent = current;
        if (data < current->data){
            current = current->left;
        } 
        else{
            current = current->right;
        }
    }
    if (data < parent->data){
        parent->left = newNode;
    } 
    else{
        parent->right = newNode;
    }
}
void print(treeNode *node){
    if (node != NULL){
        print(node->left);
        printf("%d ", node->data);
        print(node->right);
    }
}
int main(){
    binaryTree tree;
    init(&tree);
    int arr[]={4,6,2,3,5,1,7};
    for(int i=0;i<7;i++){
        insert(&tree,arr[i]);
    }
    print(tree.root);
}