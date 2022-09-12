#include <stdio.h>
#include <stdlib.h>
typedef struct BSTNode{
    int key;
    int height;
    struct BSTNode* left;
    struct BSTNode* right;
    } BSTNode;

typedef struct BST{
    BSTNode* root;
    int nodecount;
    } BST;

BSTNode* create_bstnode(int key){
    BSTNode* node = (BSTNode*) malloc(sizeof(BSTNode));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 0;
    return node;
}

BST* create_bst(){
    BST* tree = (BST*) malloc(sizeof(BST));
    tree->root = NULL;
    tree->nodecount = 0;
    return tree;
}

int max(int n1, int n2)
{
    if (n1 > n2){
        return n1;
    }
    else{
        return n2;
    }
}

int height(BSTNode* root){
    if (root == NULL){
        return -1;
    }
    return root->height;
}

int getBalance(BSTNode* root){
    if (root == NULL){
        return 0;
    }
    return height(root->left) - height(root->right);
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
            return root->key;
        }
        else{
            return findhelp(root->right, key);
        }
    }
}

int find(BST* tree, int key){
    return findhelp(tree->root, key);
}

BSTNode* rightRotate(BSTNode* root){
    BSTNode* l = root->left;
    BSTNode* lr = l->right;
    l->right = root;
    root->left = lr;
    root->height = max(height(root->left), height(root->right)) + 1;
    l->height = max(height(l->left), height(l->right)) + 1;

    return l;
}

BSTNode* leftRotate(BSTNode* root){
    BSTNode* r = root->right;
    BSTNode* rl = r->left;
    r->left = root;
    root->right = rl;
    root->height = max(height(root->left), height(root->right)) + 1;
    r->height = max(height(r->left), height(r->right)) + 1;

    return r;
}

BSTNode* inserthelp(BSTNode* root, int key){
    if (root == NULL){
        return create_bstnode(key);
    }

    if (root->key > key){
        root->left = inserthelp(root->left, key);
    }
    else{
        root->right = inserthelp(root->right, key);
    }

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);
    if ((balance < -1) && (key >= root->right->key)){
        return leftRotate(root);
    }
    if ((balance > 1) && (key < root->left->key)){
        return rightRotate(root);
    }
    if ((balance > 1) && (key >= root->left->key)){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if ((balance < -1) && (key < root->right->key)){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void insert(BST* tree, int key){
    tree->root = inserthelp(tree->root, key);
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
    



    return 0;
}


