#include<iostream>
#include<queue>
#include<stack>
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
};
Node* buildTree(Node* root) {
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    if(data == -1) {
        return NULL;
    }
    cout<<"Enter data for inserting in left :"<<endl;
    root -> left = buildTree(root -> left);
    cout<<"Enter data for inserting in right :"<<endl;
    root -> right = buildTree(root -> right);

    return root;
}
void BiuldFromLevelOrder(Node* &root) {
    queue<Node*> q;
    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout<<"Enter the left node for: "<<temp -> data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData != -1) {
            temp -> left = new Node(leftData);
            q.push(temp -> left);
        }
        cout<<"Enter the right node for: "<<temp -> data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData != -1) {
            temp -> right = new Node(rightData);
            q.push(temp -> right);
        }
    }
}
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
void reverseLevelOrder(Node* root) {
    if(root == NULL) {
        return;
    }
    queue<Node*> q;
    stack<vector<int>> s;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        vector<int> level;
        for(int i=0;i<size;i++) {
            Node* temp = q.front();
            q.pop();
            level.push_back(temp->data);
            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }
        s.push(level);
    }
    while(!s.empty()) {
        vector<int> level = s.top();
        s.pop();
        for(int x : level) {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
void inorder(Node* root) {
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


int main() {
    Node* root = NULL;
    cout<<"1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1"<<endl;
    root = buildTree(root);

    levelOrderTraversal(root);
    cout<<endl;
    reverseLevelOrder(root);

    cout<<"Inorder Traversal"<<endl;
    inorder(root);
    cout<<endl;
    cout<<"Preorder Traversal"<<endl;
    preorder(root);
    cout<<endl;
    cout<<"Postorder Traversal"<<endl;
    postorder(root);
    cout<<endl;
    BiuldFromLevelOrder(root);
    levelOrderTraversal(root);

    return 0;
}