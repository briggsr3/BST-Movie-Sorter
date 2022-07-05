# BST-Movie-Sorter
A binary search tree implementated program that recieves a file of movies and their ratings, sorts them by name, then, given an inputted prefix, sorts by rating.


Some file/folder descriptions: 
 >  - Movies.h is the header file for the BST data structure. Some function prototypes include standard contructor and destructor, as well as a printPreOrder,getDepth, insert, SearchAllNodes, and findBestMovie functions.
 >  - Movies.cpp implementation of functions
 >  - input*.csv are test files containing movies and their corresponding ratings

     
To use: 
 > 1. make all 
 > 2. ./runMovies <Prefix?True/False> <filename> <prefix>

  
Notes: 

> Code is unit tested
> Tests were also run to analyze the statistics of the average time to search in a BST and to see how does the number of nodes visited (proportional to the primitive operations) when inserting a new key in the BST vary with the number of nodes in the bst, run ./tests