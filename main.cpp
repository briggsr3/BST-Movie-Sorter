#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include <chrono>

#include "movies.h"
#include "utility.h"

using namespace std;
using namespace std::chrono;

bool parseLine(string &line, string &movieName, double &movieRating);

int main(int argc, char** argv){
  if(argc < 4){
    cerr << "Usage: " << argv[ 0 ] << "arg1 arg2 arg3" << endl;
    exit(1);
  }

  bool flag = false;
  if(strcmp(argv[1], "true") == 0){
    flag = true;
  } else if(strcmp(argv[1], "false") == 0) {
    flag = false;
  } else {
    cerr << "Argument 1 must be a boolean (true/false)" << endl;
    exit(1);
  }

    ifstream movieFile (argv[2]);
    string line, movieName;
    double movieRating;

    if (movieFile.fail()){
        cerr << "Could not open file " << argv[2];
        exit(1);
    }

    // Create an object of the BST class you defined
    // to contain the name and rating in the input file


    //PART TWO CODE

    //(1) What is the average time to search for all movies in a BST
    // as a function of the number of nodes in the bst?

    // (2) How does the number of nodes visited when inserting
    // a new key in the BST vary with the number of nodes in the bst?

  if(!flag) {
      ofstream myfile;
      myfile.open ("output_1000_ordered.csv");
      int N = 0;
      int N_visited=0;

      MoviesBST MovieBST;

      // Read each file and store the name and rating
      while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
          // Use std::string movieName and double movieRating
          MoviesBST::Movie* tempNode = new MoviesBST::Movie(movieName,movieRating);
          N_visited = MovieBST.Insert(tempNode);
          myfile << N << "," << N_visited << endl;
          N++;



      }

      movieFile.close();

      myfile << N << "," << N_visited << endl;

      myfile.close();
      return 0;
    /*
      auto start = high_resolution_clock::now();

      // Call the function, here search for

      int W = 50;
      //looping W times
      for(int k=0; k<W; k++) {
          MovieBST.SearchAllNodes();
      }

      // Get ending timepoint
      auto stop = high_resolution_clock::now();

      // Get duration. Substart timepoints to
      // get durarion. To cast it to proper unit
      // use duration cast method
      auto duration = duration_cast<microseconds>(stop - start);

      cout << "Time taken by function: "
           << (duration.count())/W<< " microseconds" << endl;

      return 0;

*/


  }
  //PART ONE CODE
  else {
      MoviesBST MovieBST;

      // Read each file and store the name and rating
      while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
          // Use std::string movieName and double movieRating
          MoviesBST::Movie* tempNode = new MoviesBST::Movie(movieName,movieRating);
          MovieBST.Insert(tempNode);
      }

      movieFile.close();

      //printing TREE:
      MovieBST.printPreOrder();

      //printing BESTMOVIE:
      MoviesBST::Movie* bestMovie = MovieBST.findBestMovie(argv[3]);

      if((bestMovie) == nullptr) {
          cout << endl;
          return 0;
      }
      else {
          cout << endl << "Best movie is " << bestMovie->name << " with rating " << bestMovie->rating << endl;

      }
      return 0;
  }
}

bool parseLine(string &line, string &movieName, double &movieRating) {
  if(line.length() <= 0) return false;
  string tempRating = "";

  bool flag = false;
  movieName = tempRating = "", movieRating = 0.0, flag = false;

  for (unsigned int i = 0; i < line.length(); i++){
    if(flag) tempRating += line[i];
    else if(line[i]==','&& line[0]!='"') flag = true;
    else {
      if(i==0 && line[0]=='"') continue;
      if(line[i]=='"'){ i++; flag=true; continue;}
      movieName += line[i];
    }
  }
  
  movieRating = stod(tempRating);
  return true;
}

