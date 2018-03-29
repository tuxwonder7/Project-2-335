
#include "tree_collection.h"
Tree_collection::Tree_collection(){
	 AVL_Tree newAVLTree;
	 TreeSpecies newTreeSpecies;
}

void Tree_collection::newCensusSystem(stringstream& iFile,stringstream& oFile){
		 cout << "What " << endl;
		 iFile >> inputFile;
		 oFile >> outputFile;
		 //pseudoServer newServer;
		 ifstream inputFileHandling;
		 inputFileHandling.open(inputFile.c_str());
		 ifstream secondFileHandling;
		
		bool endofFile = false;
		int count = 0;
		bool inList = false;
		//instance of stupid treecontainer then use it below
		while(endofFile != true){
				
				string treeInfo = "";
				getline(inputFileHandling, treeInfo);
				if(inputFileHandling.bad()  || inputFileHandling.eof()){cout << "break" << endl;endofFile = true;}
		 		else{	
				
					Tree newTree(treeInfo);
					newAVLTree.insert(newTree);
					//cout << "boroughlist.size()" << boroughList.size() << endl;
					for(int x = 0; x < boroughList.size(); x++){
						if(boroughList.at(x).borosV == newTree.borough_name()){boroughList[x].boroInt++; inList = true;}
					}
					if(inList == false){
					boroughList.push_back(Vector3d());
					boroughList[boroughList.size()-1].borosV = newTree.borough_name();
					boroughList[boroughList.size()-1].boroInt = 1;
					}
					inList = false;
				   if(newTree.common_name() == "") newTreeSpecies.add_species("stump or dead tree");
				   else newTreeSpecies.add_species(newTree.common_name());
				}
			
			count++;
			//if(count == 10) break;
		 }
		
		boroughList.insert(boroughList.begin(), Vector3d());
		boroughList[0].borosV = "New York City";
		boroughList[0].boroInt = total_tree_count();
		 totalBoroughSize = boroughList.size();//99
			//newAVLTree.printTree();
			//cout << total_tree_count() << " total nodes " << endl;
			string oak = "london planetree";
			cout << count_of_tree_species(oak) << " matching species of london planetree " << endl;
			//string tempStringboro = "Brooklyn";
			//cout << count_of_trees_in_boro(tempStringboro) << " What" << endl;
			inputFileHandling.close();
			 Command currCommands;
			 checkCommandFunc(secondFileHandling, outputFile, currCommands);//Basically need to take string, run through tree-species to see if it matches, take list and pass it and use it
			//ostream speciesOstream;
			//ostream allSpecStream(nullptr);
			stringstream testOStream;
			string testOstreamstring;
			vector<string> ostreamV;
			newTreeSpecies.print_all_species(testOStream);
			while(getline(testOStream,testOstreamstring)){ ostreamV.push_back(testOstreamstring);}
			//cout << "test" << endl;
			for(int z = 0; z < ostreamV.size(); z++){
			
			cout << ostreamV.at(z) << "  \t " <<  count_of_tree_species(ostreamV.at(z)) << endl;
			//break;
			}
			//cout << speciesOstream << endl;
			//cout << newTreeSpecies.number_of_species() << endl;
			//cout << boroughList.size() << "THE FUCKING SIZE" << endl;
			for(int x = 0; x < boroughList.size(); x++){
			cout << boroughList.at(x).borosV <<  " and " << boroughList.at(x).boroInt  << endl;
			}
			
			//newAVLTree.printInorder();
		
}

void Tree_collection::checkCommandFunc(ifstream &fin, string fileName, Command& command){
	   string    treename;
 	   int       zipcode;
  	   double    latitude, longitude, distance;
  	   bool      result;
	cout << "Check command f " << fileName <<  endl;
	fin.open( fileName.c_str(), ios::in );
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
	//return newAVLTree.AVL_TreeNodes_count_of_tree_species(species_name);
	//cout << species_name << " RE NAME RE " << endl;
	if(species_name == "stump or dead tree"){ 
		//cout << " TREEEE AAA " << endl;
		string tempSpecName = "";
		Tree newTempTree(tempSpecName, 0);
		
		list<Tree> tempListTree = newAVLTree.findallmatches(newTempTree);
		//cout << "tempListTree size" << tempListTree.size() << endl;
		return tempListTree.size();
	}// return newAVLTree.getTotalSpec("");
	Tree newTempTree(species_name, 0);
	list<Tree> tempListTree = newAVLTree.findallmatches(newTempTree);
	//return newAVLTree.getTotalSpec(species_name);
	return tempListTree.size();
	
}
int Tree_collection::count_of_trees_in_boro( const string& boro_name ) const{
	//cout << " na " << endl;
	return newAVLTree.getTotalBoro(boro_name);
}
list<string> Tree_collection::get_matching_species(const string & species_name) const{
	return newTreeSpecies.get_matching_species(species_name);
}
list<string> Tree_collection::get_all_in_zipcode(int zipcode) const{
	return newAVLTree.getAllInZip(zipcode);
}
list<string> Tree_collection::get_all_near(double latitude, double longitude, double distance) const{
	return newAVLTree.get_all_near(latitude, longitude, distance);
}
//https://gist.github.com/KodeSeeker/8677778
//Implement to find a node with thing you are looking for (in this case spc_common + borough count) so similar to (if spc_common == ) boroughcount of x ++

// So we would do a  new function that would traverse and find trees with spc_commons with name and borough and return that OR pass our container in and just increment it there!!













