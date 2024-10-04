#include <iostream>

using namespace std;

template <typename T>
class tree {
   private:
    struct Node {
        int priority;
        T value;
        Node* left;
        Node* right;
    };

    Node* root;
    size_t sz;

    //private helper function for deconstructor
    void deleteTree(Node* curr){
        if(curr->left != nullptr){ //removes all left most nodes first
            deleteTree(curr->left);
        }
        if(curr->right != nullptr){ //removes all right most nodes next
            deleteTree(curr->right);
        }
        delete curr; //deletes current node with no children
    }

   public:

    //creates an empty tree, default constructor
    tree() {
        root = nullptr;
        sz = 0;
    }
    //tree deconstructor, frees all allocated nodes in tree using helper function
    ~tree() {
        if (root == nullptr){
            return;
        }

        deleteTree(root);
        sz = 0;
    }

    //function appends node with value to tree
    void addNode(T value) {
        // adds root node if none exists
        // sets value and empty and child nodes
        if(root == nullptr) {
            root = new Node();
            root->value = value;
            root->left = nullptr;
            root->right = nullptr;
            sz++;
            return;
        }

        Node* curr = root;
        while(curr != nullptr) {
            //checks if new node value is less than curr value
            if(curr->value > value) {
                //adds new node with value if it is less than curr value and no left node
                if(curr->left == nullptr) {
                    curr->left = new Node();
                    curr->left->value = value;
                    curr->left->left = nullptr;
                    curr->left->right = nullptr;
                    sz++;
                    curr = nullptr;
                }
                //sets curr to left node if it exists
                else {
                    curr = curr->left;
                }
            }
            //checks if current value is less than user value
            else if(curr->value < value) {
                //creates new node on right if no child and user value is greater than curr value
                if(curr->right == nullptr) {
                    curr->right = new Node();
                    curr->right->value = value;
                    curr->right->left = nullptr;
                    curr->right->right = nullptr;
                    sz++;
                    curr = nullptr;
                }
                //sets curr to right if it exists
                else {
                    curr = curr->right;
                }
            }
            //occurs when value is already in tree, simply ignores it
            else {
                curr == nullptr;
            }
        }//while
    }//void

    //bool return to see if value exists in tree
    bool findVal(T value) {
        //returns false for empty tree
        if(root == nullptr) {
            return false;
        }

        Node* curr = root;
        while(curr != nullptr) {
            //return true when curr value is the search
            if(curr->value == value) {
                return true;
            }
            //sets curr to left when user value less than curr value
            else if(curr->value > value) {
                curr = curr->left;
            }
            //sets curr to right when user value more than curr value
            else {
                curr = curr->right;
            }
        }
            return false; //return false when curr is nullptr
    }

    //returns the number of nodes in the tree
    size_t size() const {  // NOLINT(*-use-nodiscard)
        return sz;
    }

};
