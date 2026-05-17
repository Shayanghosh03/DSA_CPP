#include<iostream>
#include<queue>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }
        ~Node() {
            cout<<this -> data<<" Node is deleted"<<endl;
        }
};
void levelOrderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            cout<<endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout<<temp -> data<<" ";
            if(temp -> left) {
                q.push(temp -> left);
            }
            if(temp -> right) {
                q.push(temp -> right);
            }
        }
    }
}
Node* insertIntoBST(Node* root, int data) {
    // Base Case
    if(root == NULL) {
        root = new Node(data);
        return root;
    }
    if(data > root -> data) {
        root -> right = insertIntoBST(root -> right, data);
    } else {
        root -> left = insertIntoBST(root -> left, data);
    }
    return root;
}
void takeInput(Node* &root) {
    int data;
    cin>>data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin>>data;
    }
}void inorder(Node* root) {
    //L N R
    // Base Case
    if(root == NULL) {
        return;
    }
    inorder(root -> left);
    cout<<root -> data<<" ";
    inorder(root -> right);
}
void preorder(Node* root) {
    // N L R
    // Base Case
    if(root == NULL) {
        return;
    }
    cout<<root -> data<<" ";
    preorder(root -> left);
    preorder(root -> right);
}
void postorder(Node* root) {
    // L R N
    // Base Case
    if(root == NULL) {
        return;
    }
    postorder(root -> left);
    postorder(root -> right);
    cout<<root -> data<<" ";
}
Node* minValue(Node* root) {
    Node* temp = root;
    while(temp -> left != NULL) {
        temp = temp -> left;
    }
    return temp;
}
Node* maxValue(Node* root) {
    Node* temp = root;
    while(temp -> right != NULL) {
        temp = temp -> right;
    }
    return temp;
}
Node* deleteFromBST(Node* root, int data) {
    if(root == NULL) {
        return root;
    }
    if(root -> data == data) {
        // 0 child
        if(root -> left == NULL && root -> right == NULL) {
            delete root;
        }
        // 1 child
        if(root -> left != NULL && root -> right == NULL) {
            Node* temp = root -> left;
            delete root;
            return temp;
        }
        if(root -> left == NULL && root -> right != NULL) {
            Node* temp = root -> right;
            delete root;
            return temp;
        }
        // 2 child
        if(root -> left != NULL && root -> right != NULL) {
            int mini = minValue(root -> right) -> data;
            root -> data = mini;
            root -> right = deleteFromBST(root -> right, mini);
            return root; 
        }
        // 3 child
    } else if(root -> data > data) {
        root -> left = deleteFromBST(root -> left, data);
        return root;
    } else {
        root -> right = deleteFromBST(root -> right, data);
        return root;
    }
}
int main() {
    Node* root = NULL;

    cout<<"Enter data for creating Binary Search Tree-"<<endl;
    takeInput(root);
    cout<<"Binary Search Tree is"<<endl;
    levelOrderTraversal(root);
    cout<<"Post Order Traversal"<<endl;
    postorder(root);
    cout<<endl;
    cout<<"Pre Order Traversal"<<endl;
    preorder(root);
    cout<<endl;
    cout<<"In order Traversal"<<endl;
    inorder(root);
    cout<<endl;
    cout<<"Minimum Value is "<<minValue(root) -> data<<endl;
    cout<<"Maximum value is "<<maxValue(root) -> data<<endl;
    cout<<"Enter the number which you want to delte: ";
    int data;
    cin>>data;
    deleteFromBST(root, data);
    cout<<"After deletion Binary Search Tree is"<<endl;
    levelOrderTraversal(root);
    return 0;
}