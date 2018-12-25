/*
    직접 BST insert delete를 구현해서 풀어보고자 했으나 막힘.
*/
#include <iostream>

using namespace std;

struct Node {
    string name;
    Node *left;
    Node *right;
    Node() {
        name = "";
        left = NULL;
        right = NULL;
    }
};

Node *root = new Node;

//insert시 노드의 주소도 받아야할듯함.
void insert(string name) {
    if(root->name == "") {
        root->name = name;
        return;
    }
     
    Node *cur = root;
    while(true) {
        if(cur->name > name) {
            if(cur->left == NULL) {
                cur->left = new Node;
                cur->left->name = name;
                break;
            } else {
                cur = cur->left;
            }
        } else if(cur->name < name) {
            if(cur->right == NULL) {
                cur->right = new Node;
                cur->right->name = name;
                break;
            } else {
                cur = cur->right;
            }
        } else {
            break;
        }
    }
}

void delNode(Node *node, string name) {
    if(node->name == "") return;

    //만약 들어온 Name 루트의 name 작으면?
    //왼쪽을 들어가야함
    if(node->name > name) {
        delNode(node->left, name);
    }
    
    else if(node->name < name) {
        delNode(node->right, name);
    }

    //찾았다면, 같다면
    else {
        //
        if(node->right == NULL) {

        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;

    for(int i=0;i<T;i++) {
        string name,cmd;
        cin >> name >> cmd;

        if(cmd == "enter") {
            insert(name);
        } else {
            delNode(name);
        }
    }

    return 0;
}