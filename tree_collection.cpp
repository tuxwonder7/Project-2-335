
#include "tree_collection.h"


void Tree_collection::newCensusSystem(stringstream& iFile,stringstream& oFile){
		 cout << "What " << endl;
		 iFile >> inputFile;
		 oFile >> outputFile;
		 //pseudoServer newServer;
		 ifstream inputFileHandling;
		 inputFileHandling.open(inputFile.c_str());
		 ifstream secondFileHandling;
		
		bool endofFile = false;
	
		//instance of stupid treecontainer then use it below
		while(endofFile != true){
				
				string treeInfo = "";
				getline(inputFileHandling, treeInfo);
				if(inputFileHandling.bad()  || inputFileHandling.eof()){cout << "break" << endl;endofFile = true;}
		 		else{	
				
				Tree newTree(treeInfo);
				
				newAVLTree.insert(newTree);
				
		  		}
			
		 }
			cout << total_tree_count() << " total nodes " << endl;
			inputFileHandling.close();
			  Command currCommands;
			 checkCommandFunc(secondFileHandling, outputFile, currCommands);

			
			//newAVLTree.printTree();
		
}

void Tree_collection::checkCommandFunc(ifstream &fin, string fileName, Command& command){
	   string    treename;
 	   int       zipcode;
  	   double    latitude, longitude, distance;
  	   bool      result;
	cout << "Check command f " << fileName <<  endl;
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

int Tree_collection::total_tree_count() const{
	//newAVLTree.AVL_TreeNodes_count();
	return newAVLTree.AVL_TreeNodes_count();
}

int Tree_collection::count_of_tree_species ( const string& species_name ) const{

}
int Tree_collection::count_of_trees_in_boro( const string& boro_name ) const{

}
list<string> Tree_collection::get_matching_species(const string & species_name) const{

}
list<string> Tree_collection::get_all_in_zipcode(int zipcode) const{

}
list<string> Tree_collection::get_all_near(double latitude, double longitude, double distance) const{

}














