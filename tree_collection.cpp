
#include "tree_collection.h"


void Tree_collection::newCensusSystem(stringstream& iFile,stringstream& oFile){
		 cout << "What " << endl;
		 iFile >> inputFile;
		 oFile >> outputFile;
		 //pseudoServer newServer;
		 ifstream inputFileHandling;
		 inputFileHandling.open(inputFile.c_str());
		 ifstream secondFileHandling;
		// secondFileHandling.open(outputFile.c_str());
		   
		    AVL_Tree newAVLTree;
		   // istream& is = secondFileHandling;
		   // while(currCommands.get_next(is)){ cout << "REE" << endl;}
		  


			//secondFileHandling.open(outputFile.c_str());
			
			 bool endofFile = false;
			int count = 0;
			//instance of stupid treecontainer then use it below
			while(endofFile != true){
				//cout << "What x" << endl;
				string treeInfo = "";
				getline(inputFileHandling, treeInfo);
				if(inputFileHandling.bad()  || inputFileHandling.eof()){cout << "break" << endl;endofFile = true;}
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
			inputFileHandling.close();
			  Command currCommands;
			 checkCommandFunc(secondFileHandling, outputFile, currCommands);

			cout << "count " << count << endl;
			//newAVLTree.printTree();
		
}

void Tree_collection::checkCommandFunc(ifstream &fin, string fileName, Command& command){
	   string    treename;
 	   int       zipcode;
  	   double    latitude, longitude, distance;
  	   bool      result;
	cout << " Check command f " << fileName <<  endl;
	fin.open( fileName, ios::in );
	while ( ! fin.eof() ) {
        if ( ! command.get_next(fin) ) {
            if ( ! fin.eof() )
                cerr << "Could not get next command.\n";
            return;
        }
        command.get_args(treename, zipcode, latitude, longitude, 
                         distance, result);

        switch ( command.type_of() )
        {
            case tree_info_cmmd:
                cout << "tree_info_cmmd " << treename << endl;
                break;
            case listall_names_cmmd:
                cout << "listall_names_cmmd " << endl;
                break;
            case list_near_cmmd:
                cout << "list_near_cmmd " << latitude << " " << longitude
                     << " " << distance  << endl;
                break;
            case listall_inzip_cmmd:
                cout << "listall_inzip_cmmd " << zipcode << endl;               
                break;
            case bad_cmmd:
                    cout << "bad command " << endl;
                    break;
            default:
                    break;
        }
    }
    fin.close();


}

