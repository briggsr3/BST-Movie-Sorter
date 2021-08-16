//
// Created by Bobby Briggs on 8/15/21.
//

#include "movies.h"


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


int getDepth(Movie *r) {

}
