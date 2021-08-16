//
// Created by Bobby Briggs on 8/15/21.
//

#ifndef PA02_MOVIES_H
#define PA02_MOVIES_H

#include <iostream>
#include <string>

using namespace std;

//creating node class
class MoviesBST {
private:
    struct Movie {
        string name;
        int rating;
        Movie *left, *right, *parent;
        // useful constructor:
        Movie(string n = "0", int v=0) : name(n), rating(v), left(0), right(0), parent(0) { }
    };

    Movie* root; //pointer to root node

public:
    MoviesBST(); // constructor
    ~MoviesBST(); //destructor
    void clear(Movie *n); //for destructor

    int getDepth(Movie *r);
};

#endif //PA02_MOVIES_H
