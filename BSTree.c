#include "BSTree.h"

int BSTreeSearch(BSTreeNode *root, Key key)
{
    //if(root == NULL){
    //    return -1;
    //}

    //if(root->key == key){
    //    return 0;
    //}

    //if(root->key < key){
    //    BSTreeSearch(root->right, key);
    //}else{
    //    BSTreeSearch(root->left, key);
    //}

    BSTreeNode *node = root;
    while(node){
        if(node->key == key){
            return 0;
        }else if(node->key > key){
            node = node->left;
        }else{
            node = node->right;
        }
    }
    return -1;
}

int BSTreeInsert(BSTreeNode **root, Key key)
{
    //BSTreeNode *node = *root;
    //BSTreeNode *par = NULL;

    //while(node){
    //    if(node->key == key){
    //        return -1;
    //    }

    //    par = node;
    //    if(node->key < key){
    //        node = node->right;
    //    }else{
    //        node = node->left;
    //    }
    //}

    //BSTreeNode *newNode = (BSTreeNode *)malloc(sizeof(BSTreeNode));
    //newNode->key = key;
    //newNode->left = newNode->right = NULL;

    //if(par == NULL){
    //    *root = newNode;
    //    return 0;
    //}

    //if(par->key < key){
    //    par->right = newNode;
    //}else{
    //    par->left = newNode;
    //}
    //return 0;

    if(*root == NULL){
        *root = (BSTreeNode *)malloc(sizeof(BSTreeNode));
        (*root)->left = (*root)->right = NULL;
        (*root)->key = key;
        return 0;
    }

    if((*root)->key == key){
        return -1;
    }

    if((*root)->key > key){
        return BSTreeInsert(&(*root)->left, key);
    }else{
        return BSTreeInsert(&(*root)->right, key);
    }
}

static void reMove(BSTreeNode **root, BSTreeNode *par, BSTreeNode *node)
{
    if(node->left == NULL && node->right != NULL){
        if(par == NULL){
            *root = node->right;
            free(node);
            return;
        }
        if(par->left == node){
            par->left = node->right;
        }else{
            par->right = node->right;
        }
        free(node);
        return;
    }
    else if(node->right == NULL && node->left != NULL){
        if(par == NULL){
            *root = node->left;
            free(node);
            return;
        }
        if(par->left == node){
            par->left = node->left;
        }else{
            par->right = node->left;
        }
        free(node);
        return;
    }
    else{ //左右子树都不为空，找右子树中最小的
        BSTreeNode *del = node->right;
        BSTreeNode *delPar = node;
        while(del->left){
            delPar = del;
            del = del->left;
        }

        node->key = del->key;

        if(delPar == node){ //要删结点的右子树中没有左孩子
            delPar->right = del->right;
        }else{ // 找到最左子节点，父节点的左指向del的右
            delPar->left = del->right;
        }

        free(del);
    }
}

int BSTreeDel(BSTreeNode **root, Key key)
{
    if(*root == NULL){
        return -1;
    }
    
    if((*root)->key < key){
        return BSTreeDel(&(*root)->right, key);
    }else{
        return BSTreeDel(&(*root)->left, key);
    }

    BSTreeNode *node = *root;
    if((*root)->left == NULL){
        *root = node->right;
        free(node);
    }else if((*root)->right == NULL){
        *root = node->left;
        free(node);
    }else{ //找左子树中最大的
        BSTreeNode *del = node->left;
        BSTreeNode *delPar = node;
        while(del->right){
            delPar = del;
            del = del->right;
        }
        node->key = del->key;
        if(delPar == node){
            delPar->left = del->left;
        }else{
            delPar->right = del->left;
        }
        free(del);
    }
    return 0;

    //BSTreeNode *node = *root;
    //BSTreeNode *par = NULL;

    //while(node){
    //    if(node->key == key){
    //        reMove(root, par, node);
    //        return 0;
    //    }

    //    par = node;
    //    if(node->key > key){
    //        node = node->left;
    //    }else{
    //        node = node->right;
    //    }
    //}

    //return -1;
}
