/*
    문) 입력으로 주어진 수를 BST에 삽입시, 모양이 총 몇개가 만들어지는지
    1.트리가 같은지 다른지 검사를 해야하는데 어떻게 할수있을까?
    2.먼저 BST를 만들어봅시다.
    3.Preorder Insert 연산 구현 후, 방문에 대해 Oreder를 해주세요
            방문   왼쪽    오른쪽
    실제방   V      L      R
    방문끝   v      l      r
    이해가 안간다면 docs의 그림참조 (실제로는 숫자빼고 저장)
*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node() {
        val = 0;
        left = NULL;
        right = NULL;
    }
};

void remove (Node *node) {
    if(node->left) {
        remove(node->left);
    }
    if(node->right) {
        remove(node->right);
    }
    delete node;
}

string preorder (Node *node) {
    string ans="";
    ans += "V";
    if(node->left) {
        ans+="L";
        ans+=preorder(node->left);
        ans+="l";
    }
    if(node->right) {
        ans+="R";
        ans+=preorder(node->right);
        ans+="r";
    }
    ans+="v";

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    set<string> s;
    for(int i=0; i<n; i++) {
        vector<int> a(m);
        
        for(int j=0; j<m; j++) {
            cin >> a[j];
        }

        Node *root = new Node;
        root->val = a[0];

        for(int j=1; j<m; j++) {
            Node *cur = root;
            while(true) {
                //현재 커서의 밸류가 들어갈 val보다 크면 왼쪽에 위치
                if (cur->val > a[j]) {
                    if(cur->left == NULL) {
                        cur->left = new Node;
                        cur->left->val = a[j];
                        break;
                    } else {
                        cur = cur->left;
                    } 
                } else if(cur->val < a[j]) {
                    if(cur->right == NULL) {
                        cur->right = new Node;
                        cur->right->val = a[j];
                        break;
                    } else {
                        cur = cur->right;
                    }
                } else {
                    //여기에 들어올 경우는 언제이지? == 중복일때 안넣음
                    break;
                }
            }
        }
        s.insert(preorder(root));
        remove(root);
    }
    cout << s.size() << endl;
    return 0;
}