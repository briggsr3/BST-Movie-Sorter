//
// Created by Bobby Briggs on 8/15/21.
//

#include "movies.h"
#include <iostream>
#include <stack>


MoviesBST::MoviesBST() : root(nullptr) { }

// destructor deletes all nodes
MoviesBST::~MoviesBST() {
    clear(root);
}


//recursive helper for destructor
void MoviesBST::clear(Movie *n) {
    if (n) {
        clear(n->left);
        clear(n->right);
        delete n;
    }
}



//function should get depth (ex. root has depth 0 the kids are depth 1, their kids are depth 2
int MoviesBST::getDepth(Movie* n) const {
    Movie* current = root;
    int i = 0;
    while(current) {
        if(current->name == n->name) {
            return i;
        }
        else if(n->name<current->name) {
            current=current->left;
        }
        else{
            current=current->right;
        }
        i++;
    }
    return -1;

}


// print tree data pre-order
void MoviesBST::printPreOrder() const {
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void MoviesBST::printPreOrder(Movie *n) const {
    if (n) {
        cout << n->name << ", " << n->rating << ", "  << getDepth(n) << endl;
        printPreOrder(n->left);
        printPreOrder(n->right);
    }
}

bool MoviesBST::isEmpty() const {
    if (root == NULL)
        return true;
    else {
        return false;
    }
}


void MoviesBST::Insert(Movie *n) {
    //checking if tree is empty:
    if(root == nullptr){
        root =  n;
    }
    else {
        Movie* currentMovie = root;
        while(currentMovie) {
            //less than case
            if(n->name < currentMovie->name) {
                //if no left child exists
                if(currentMovie->left == nullptr) {
                    currentMovie->left = n;
                    currentMovie = nullptr;
                }
                else {
                    currentMovie = currentMovie->left;
                }
            }
            //greater than case
            else {
                //if no right child exists
                if(currentMovie->right == nullptr) {
                    currentMovie->right = n;
                    currentMovie = nullptr;
                }
                else {
                    currentMovie = currentMovie->right;
                }

            }

        }
    }
}

/*
MoviesBST::Movie* MoviesBST::SearchR(string desiredKey) {
    Movie* current = root;
    while(current) {
        if(current->rating==desiredKey) {
            return current;
        }
        else if(desiredKey<current->rating) {
            current=current->left;
       }
        else{
            current=current->right;
        }
   }
    return nullptr;

}
*/


MoviesBST::Movie* MoviesBST::findBestMovie(string prefix) {

    //init
    stack<Movie*> s;
    Movie *curr = root;
    Movie *topRated = new Movie();

    while (curr != NULL || !s.empty()) {
        // Reach the left most Node of the curr Node
        while (curr !=  NULL){
            //the node's left subtree
            s.push(curr);
            curr = curr->left;
        }

        // Current must be NULL at this point
        curr = s.top();
        s.pop();

        if (curr->name.substr(0, prefix.length()) == prefix) {
            if(topRated->rating < curr->rating) {
                topRated = curr;
            }

        }
        curr = curr->right;

    } //end of while

    if(topRated->rating == 0.0) {
        return nullptr;
    }
    else {
        return topRated;
    }

}




