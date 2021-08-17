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
public:
    struct Movie {
        string name;
        double rating;
        Movie *left, *right, *parent;
        // useful constructor:
        Movie(string theName = "0", double theRating=0.0) : name(theName), rating(theRating), left(0), right(0), parent(0) { }
    };

    MoviesBST(); // constructor
    ~MoviesBST(); //destructor
    void clear(Movie *n); //for destructor

    void printPreOrder() const;
    void printPreOrder(Movie *n) const;
    int getDepth(Movie *n) const;
    int Insert(Movie *n);
    void SearchAllNodes();

    Movie* findBestMovie(string prefix);
    bool isEmpty() const;


private:
    Movie* root; //pointer to root node






};

#endif //PA02_MOVIES_H
