
#include "inputHandler.h"


void inputHandler::newCensusSystem(stringstream& iFile,stringstream& oFile){
		 cout << "What " << endl;
		 iFile >> inputFile;
		oFile >> outputFile;
		 //pseudoServer newServer;
		 ifstream inputFileHandling;
		 inputFileHandling.open(inputFile.c_str());
		 fstream outputFileHandling;
		 outputFileHandling.open(outputFile.c_str(), ios::out | ios::in | ios::trunc);
		
		 bool endofFile = false;
		//instance of stupid treecontainer then use it below
		while(endofFile != true){
			cout << "What x" << endl;
			string treeInfo;
			getline(inputFileHandling, treeInfo);
			if(inputFileHandling.bad()  || inputFileHandling.eof()){endofFile = true;}
	 		else{	
			//cout << "What z " << treeInfo << endl;
			Tree newTree(treeInfo);
			//treecontainer.avl.push_back(thing)

			//cout << "What y" << endl;
	 		//newqueue->push_back(treeInfo);
	  		}
	 	}
}

