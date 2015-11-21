#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "DBentry.h"
#include "TreeNode.h"

using namespace std;

/* class TreeDB 
   TreeNode* root;
   int probesCount;
*/
   TreeDB::TreeDB() {
      root = NULL;
      probesCount = 0;
   }

   // the destructor, deletes all the entries in the database.
   TreeDB::~TreeDB(){
      //clear all --> delete [] root;

   }

   // inserts the entry pointed to by newEntry into the database. 
   // If an entry with the same key as newEntry's exists 
   // in the database, it returns false. Otherwise, it returns true.
   bool TreeDB::insert(DBentry* newEntry){
      if (root == NULL)
      {
         root = new DBentry(newEntry);
         probesCount++;
      }
   } 

   // searches the database for an entry with a key equal to name.
   // If the entry is found, a pointer to it is returned.
   // If the entry is not found, the NULL pointer is returned.
   // Also sets probesCount
   DBentry* TreeDB::find(string name){
      if (root==null){return NULL;}
      else if (name == root->getEntry())
   }

   // deletes the entry with the specified name (key)  from the database.
   // If the entry was indeed in the database, it returns true.
   // Returns false otherwise.
   // See section 6 of the lab handout for the *required* removal method.
   // If you do not use that removal method (replace deleted node by
   // maximum node in the left subtree when the deleted node has two children)
   // you will not match exercise's output.
   bool remove(string name);
	
   // deletes all the entries in the database.
   void clear();
    
   // prints the number of probes stored in probesCount
   void printProbes() const;
   
   // computes and prints out the total number of active entries
   // in the database (i.e. entries with active==true).
   void countActive () const;

   // Prints the entire tree, in ascending order of key/name
   friend ostream& operator<< (ostream& out, const TreeDB& rhs);