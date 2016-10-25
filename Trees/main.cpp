//
//  main.cpp
//  Trees
//
//  Created by Michael Pszonka on 11/20/15.
//  Copyright (c) 2015 Michael Pszonka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct node {
    
    int val;
    struct node *left;
    struct node *right;
};

class btree
{
public:
    btree();
    
    void insert(int key);
    node* search(int key);
    void destroy_tree();
    void display_tree();
    void preorder(btree &t);
    void postorder(btree &t);
    void inorder(btree &t);
    
    
private:
    void destroy_tree(node *leaf);
    void insert(int key, node *leaf);
    void preorder(btree &t, node *leaf);
    void postorder(btree &t, node *leaf);
    void inorder(btree &t, node *leaf);
    node *search(int key, node *leaf);
    
    node *root;
};

    btree::btree() {
        root = NULL;
    }

void btree::destroy_tree(node* leaf ) {
    
    if(leaf!=NULL) {
        
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

void btree::insert(int key) {
    
    if(root != NULL) {
        insert(key, root);
    }
    else {
        root = new node;
        root->val = key;
        root->left = NULL;
        root->right = NULL;
    }
}

void btree::insert(int key, node *leaf) {
    
    if(key<leaf->val) {
        
        if(leaf->left!=NULL) {
            insert(key, leaf->left);
        }
        else {
            
            leaf->left = new node;
            leaf->left->val = key;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    }
    else if(key>leaf->val) {
        
        if(leaf->right!=NULL) {
            insert(key, leaf->right);
        }
        else {
            leaf->right = new node;
            leaf->right->val = key;
            leaf->right->left = NULL;
            leaf->right->right=NULL;
        }
    }
}

node* btree::search(int key, node* leaf) {
    
    if(leaf != NULL) {
            cout << "hello" << endl;
            return leaf;
        
        if(key<leaf->val) {
            return search(key, leaf->left);
        }
        else
        {
            return search(key, leaf->right); }
    }
    else
        return NULL;
}

void btree::preorder(btree &t, node *leaf) {
    
    if(leaf == NULL)
        return;
    
    cout << leaf->val << " ";
    preorder(t, leaf->left);
    preorder(t, leaf->right);
}

void btree::postorder(btree &t, node *leaf) {
    
    if(leaf == NULL)
        return;
    
    postorder(t, leaf->left);
    postorder(t, leaf->right);
    cout << (leaf->val) << " ";

}

void btree::inorder(btree &t, node *leaf) {
    
    if(leaf == NULL)
        return;
    
    inorder(t, leaf->left);
    cout << leaf->val << " ";
    inorder(t, leaf->right);
    
    
}

void btree::preorder(btree &t) {
    preorder(t, root);
}

void btree::postorder(btree &t) {
    postorder(t, root);
}

void btree::inorder(btree &t) {
    inorder(t, root);
}

node* btree::search(int key) {
    return search(key, root);
}

void btree::destroy_tree() {
    destroy_tree(root);
}


int main(int argc, const char * argv[]) {
    
    
    
    btree tree;
    tree.insert(11);
    tree.insert(4);
    tree.insert(15);
    tree.insert(9);
    tree.insert(7);
    tree.insert(25);
    tree.insert(2);
    
    cout << "Preorder: " << endl;
    tree.preorder(tree);
    cout << "" << endl;
    cout << "Postorder: " << endl;
    tree.postorder(tree);
    cout << "" << endl;
    cout << "InOrder: " <<  endl;
    tree.inorder(tree);
    

    
    

}
