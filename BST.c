//TIME complexity of all traversal algos is O(n)
//Space complexity in owrst case is O(h) and best/AVG = O(LOG2n)
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left, *right;
};

int findMin(struct node*);
int findMax(struct node*);
int findHeight(struct node*);
void BreadthTraversal(struct node* , int );
void print_traversal(struct node*);
void preorder(struct node*);

struct node* search(struct node* root, int key);
// A utility function to create a new BST node
struct node* newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);

    } else{ return;}
}


//post order
void post_order(struct node *root)
{
    if (root != NULL)
    {
        post_order(root->left);
        post_order(root->right);

        printf("%d \n", root->key);

    } else{ return;}
}


/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

// Driver Program to test above functions
int main()
{

    struct node *root = NULL;
    root = insert(root, 1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);
    insert(root, 6);
    insert(root, 7);


    // print inoder traversal of the BST
    print_traversal(root);
    return 0;
}

int findMin(struct node* root){

    if (root ==NULL){

        printf("Error; the tree is empty");
        return 0;
    }
    else if (root->left ==NULL){
        return root->key;
    }
    return findMin(root->left);
}

int findMax(struct node* root){

    if (root == NULL){
        printf("THE Tree is empty");
        return 0;
    } else if (root->right == NULL){
        return root->key;
    }

    return findMax(root->right);
}

int findHeight(struct node* root){
    if (root == NULL){
        return -1;
    }
    /* compute the depth of each subtree */
    int lDepth = findHeight(root->left);
    int rDepth = findHeight(root->right);

    /* use the larger one */
    if (lDepth > rDepth)
        return(lDepth+1);
    else return(rDepth+1);

}

void BreadthTraversal(struct node* root , int level){
    if (root == NULL){
        return;
    }
    if (level == 0){
        printf("%d" , root->key);
    } else if (level >0){
        BreadthTraversal(root->left, level-1);
        BreadthTraversal(root->right  , level-1);
    }
}

void print_traversal(struct node* root){
    int h = findHeight(root);
    for (int i = 0; i <= h; ++i) {
        //START
        BreadthTraversal(root , i);
    }
}

void preorder(struct node* root){
    if (root == NULL){ return;}
    printf("%d", root->key);
    preorder(root->left);
    preorder(root->right);
}

struct node* search(struct node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
        return root;

    // Key is greater than root's key
    if (root->key < key)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}