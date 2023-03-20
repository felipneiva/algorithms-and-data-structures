#include <stdio.h>
#include <stdlib.h>
typedef struct BSTNode{
    int key;
    int element;
    struct BSTNode* left;
    struct BSTNode* right;
    } BSTNode;

typedef struct BST{
    BSTNode* root;
    int nodecount;
    } BST;

BSTNode* create_bstnode(int key, int element){
    BSTNode* node = (BSTNode*) malloc(sizeof(BSTNode));
    node->key = key;
    node->element = element;
    return node;
}

BST* create_bst(){
    BST* tree = (BST*) malloc(sizeof(BST));
    tree->root = NULL;
    tree->nodecount = 0;
    return tree;
}

int findhelp(BSTNode* root, int key){
    if (root == NULL){
        return -1;
    }
    else{
        if (root->key > key){
            return findhelp(root->left, key);
        }
        else if (root->key == key){
            return root->element;
        }
        else{
            return findhelp(root->right, key);
        }
    }
}

int find(BST* tree, int key){
    return findhelp(tree->root, key);
}

BSTNode* inserthelp(BSTNode* root, int key, int element){
    if (root == NULL){
        return create_bstnode(key, element);
    }
    else{
        if (root->key > key){
            root->left = inserthelp(root->left, key, element);
        }
        else{
            root->right = inserthelp(root->right, key, element);
        }
        return root;
    }
}

void insert(BST* tree, int key, int element){
    tree->root = inserthelp(tree->root, key, element);
    tree->nodecount++;
}

void preorder(BSTNode* root){
    if (root != NULL){
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(BSTNode* root){
    if (root != NULL){
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void posorder(BSTNode* root){
    if (root != NULL){
        posorder(root->left);
        posorder(root->right);
        printf("%d ", root->key);
    }
}


int main(){
    BST* tree = create_bst();
    int nodecount;
    scanf("%d", &nodecount);
    for (int i = 0; i<nodecount; i++){
        int number;
        scanf("%d", &number);
        insert(tree, number, number);
    }
    printf("Pre order : ");
    preorder(tree->root);
    printf("\n");
    printf("In order  : ");
    inorder(tree->root);
    printf("\n");
    printf("Post order: ");
    posorder(tree->root);

    return 0;
}
