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

   bool TreeDB::insertTool (TreeNode* tempTN, DBentry* tempDB, int & p){
      if (tempTN == NULL)
      {
         tempTN = new TreeNode(tempDB);
         p++;
         return true;
      }
      else if (tempDB->getName() == tempTN->getEntry()->getName())
         {return false;}
      else if (tempDB->getName() < tempTN->getEntry()->getName())
      {
         return insertTool(tempTN->getLeft(), tempDB, p);
      }
      else
      {
         return insertTool(tempTN->getRight(), tempDB, p);
      }

   }
   // inserts the entry pointed to by newEntry into the database. 
   // If an entry with the same key as newEntry's exists 
   // in the database, it returns false. Otherwise, it returns true.
   bool TreeDB::insert(DBentry* newEntry){
      if (root == NULL)
      {
         root = new TreeNode(newEntry);
         probesCount++;
         return true;
      }
      else {return insertTool(root, newEntry, probesCount);}
   }  

   // searches the database for an entry with a key equal to name.
   // If the entry is found, a pointer to it is returned.
   // If the entry is not found, the NULL pointer is returned.
   // Also sets probesCount
   DBentry* TreeDB::findTool (TreeNode* tempTN, string name){
      if (tempTN == NULL)
      {return NULL;}
      else if (name == tempTN->getEntry()->getName())
      {return tempTN->getEntry();}
      else if (name < tempTN->getEntry()->getName())
      {return findTool(tempTN->getLeft(), name);}
      else
      {return findTool(tempTN->getRight(), name);}
   }

   DBentry* TreeDB::find(string name){
      if (root==NULL){return NULL;}
      else {return findTool(root, name);}
   }

   // deletes the entry with the specified name (key)  from the database.
   // If the entry was indeed in the database, it returns true.
   // Returns false otherwise.
   // See section 6 of the lab handout for the *required* removal method.
   // If you do not use that removal method (replace deleted node by
   // maximum node in the left subtree when the deleted node has two children)
   // you will not match exercise's output.
   bool TreeDB::remove(string name){
      return true;
   }
	
   // deletes all the entries in the database.
   void TreeDB::clear(){

   }
    
   // prints the number of probes stored in probesCount
   void TreeDB::printProbes() const{
      //print probesCount
   }
   
   // computes and prints out the total number of active entries
   // in the database (i.e. entries with active==true).
   void TreeDB::countActive () const{

   }

   TreeNode* TreeDB::getRoot() const{
       return root;
    }


   
   // Prints the entire tree, in ascending order of key/name
   // ofstream& operator<< (ofstream& out, const TreeDB* rhs){
   //    TreeNode* temp = rhs->getRoot();
   //    TreeNode* temp2;
   //    while (temp != NULL)
   //    {
   //       temp2 = temp ->getLeft();
   //       while (temp2 != NULL)
   //       {
   //          out << temp2->getEntry();
   //          temp2 = temp2->getLeft();
   //       }
   //    }
   // }