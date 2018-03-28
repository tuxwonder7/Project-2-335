
#include "tree_collection.h"


void tree_collection::newCensusSystem(stringstream& iFile,stringstream& oFile){
		 cout << "What " << endl;
		 iFile >> inputFile;
		oFile >> outputFile;
		 //pseudoServer newServer;
		 ifstream inputFileHandling;
		 inputFileHandling.open(inputFile.c_str());
		 fstream outputFileHandling;
		 outputFileHandling.open(outputFile.c_str(), ios::out | ios::in | ios::trunc);
		 AVL_Tree newAVLTree;
		 bool endofFile = false;
		int count = 0;
		//instance of stupid treecontainer then use it below
		while(endofFile != true){
			//cout << "What x" << endl;
			string treeInfo = "";
			getline(inputFileHandling, treeInfo);
			if(inputFileHandling.bad()  || inputFileHandling.eof()){cout << " One one time" << endl;endofFile = true;}
	 		else{	
			//cout << "What z " << treeInfo << endl;
			Tree newTree(treeInfo);
			//cout << newTree << endl;
			//treecontainer.avl.push_back(thing)
			newAVLTree.insert(newTree);
			//cout << "What y" << endl;
	 		//newqueue->push_back(treeInfo);
			
	  		}
			count++;
	 	}
		cout << " count " << count << endl;
		newAVLTree.printTree();
		
}

