
#include "tree_collection.h"
Tree_collection::Tree_collection(){
	 AVL_Tree newAVLTree;
	 TreeSpecies newTreeSpecies;
}

void Tree_collection::newCensusSystem(stringstream& iFile,stringstream& oFile){
		
		 iFile >> inputFile;
		 oFile >> outputFile;
		 //pseudoServer newServer;
		 ifstream inputFileHandling;
		 inputFileHandling.open(inputFile.c_str());
		 ifstream secondFileHandling;
				 boroughList.push_back(Vector3d());
				boroughList[boroughList.size()-1].borosV = "Queens";
				boroughList[boroughList.size()-1].boroInt = 0;
				boroughList.push_back(Vector3d());
				boroughList[boroughList.size()-1].borosV = "Brooklyn";
				boroughList[boroughList.size()-1].boroInt =0;
				boroughList.push_back(Vector3d());
				boroughList[boroughList.size()-1].borosV = "Manhattan";
				boroughList[boroughList.size()-1].boroInt = 0;
				boroughList.push_back(Vector3d());
				boroughList[boroughList.size()-1].borosV = "Staten Island";
				boroughList[boroughList.size()-1].boroInt = 0;
				boroughList.push_back(Vector3d());
				boroughList[boroughList.size()-1].borosV = "Bronx";
				boroughList[boroughList.size()-1].boroInt = 0;
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

			inputFileHandling.close();
			 Command currCommands;
			 checkCommandFunc(secondFileHandling, outputFile, currCommands);//Basically need to take string, run through tree-species to see if it matches, take list and pass it and use it
		
}

void Tree_collection::checkCommandFunc(ifstream &fin, string fileName, Command& command){
	   string    treename;
 	   int       zipcode;
  	   double    latitude, longitude, distance;
  	   bool      result;
	cout << "\n\nCheck command f " << fileName <<  endl;
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
            case tree_info_cmmd:{
                cout << "tree_info_cmmd " << treename << endl;
		tree_info_func(treename);
                break;
		}
            case listall_names_cmmd:
                {
		cout << "listall_names_cmmd " << endl;
		newTreeSpecies.print_all_species(cout);
		}
                break;
            case list_near_cmmd:
		{
                cout << "list_near_cmmd " << latitude << " " << longitude
                     << " " << distance  << endl;
		list<string> treeList = get_all_near(latitude, longitude, distance);
		string item;
			int count = 1;
			int extcount = 0;
			int extBlank = 0;
			for (std::list<string>::const_iterator iterator = treeList.begin(), end = treeList.end(); iterator != end; ++iterator) {
   			 if(*iterator == ""){
			 if(extBlank == 0)cout << setw(25) << " Dead or stump " <<setw(20);
			  extBlank++;
			 }
			 if(item == *iterator){
				count++;
			 }
			 else if(extcount != 0){
			  cout << count << endl;
			  count = 1;
			  item = *iterator;
			  cout << setw(25) << item <<  setw(20);
			 }
			 else if(extcount == 0){
			  item = *iterator;
			  cout << setw(25) << item <<  setw(20);
			 }
			 extcount++;
	 		
	
			}
		 cout << count << endl;
			
		}
                break;
            case listall_inzip_cmmd:
               	{
			cout << "listall_inzip_cmmd   " << zipcode <<  endl;
			list<string> treetemp = get_all_in_zipcode(zipcode);
			string item;
			int count = 1;
			int extcount = 0;
			int extBlank = 0;
			for (std::list<string>::const_iterator iterator = treetemp.begin(), end = treetemp.end(); iterator != end; ++iterator) {
   			if(*iterator == ""){
			 if(extBlank == 0)cout << setw(25) << "Dead or stump " <<  setw(20);
			  extBlank++;
			 }
			 if(item == *iterator){
				count++;
			 }
			 else if(extcount != 0){
			  cout << count << endl;
			  count = 1;
			  item = *iterator;
			  cout << setw(25) << item <<  setw(20);
			 }
			 else if(extcount == 0){
			  item = *iterator;
			  cout << setw(25) << item <<  setw(20);
			 }
			 extcount++;
	 		
	
			}
		 cout << count << endl;
			
		}
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

void Tree_collection::tree_info_func(string treename){
	cout << "The matching species are: " << endl;
	list<string> matchingSpecx = get_matching_species(treename);
	vector <Vector3d> boroughListTreeFun;
	vector<vector <Vector3d> > boroughListTreeFunVec;
	vector<string> matchingSpec;
	for (std::list<string>::const_iterator iterator = matchingSpecx.begin(), end = matchingSpecx.end(); iterator != end; ++iterator) {
   	 std::cout << *iterator << endl;		
	 matchingSpec.push_back(*iterator);
	
	}
	cout << "Popularity in the city:" << endl;
	int totalCount = 0;
	vector< vector<Tree> > allMatchingSpecTree;
	for(int i = 0; i < matchingSpec.size(); i++){
		int totalCount = count_of_tree_species(matchingSpec.at(i));
		list<Tree> tempTree = count_of_tree_speciesAlternative(matchingSpec.at(i));
		vector<Tree> copytempTreeV(tempTree.begin(), tempTree.end());
		allMatchingSpecTree.push_back(copytempTreeV);

	}
	bool inList = false;
	
	for(int z = 0; z < allMatchingSpecTree.size(); z++){
		boroughListTreeFunVec.push_back(boroughListTreeFun);
	 for(int x = 0; x < allMatchingSpecTree.at(z).size(); x++){
			for(int a = 0; a < boroughListTreeFun.size(); a++){
				
				if(boroughListTreeFunVec.at(z).at(a).borosV == allMatchingSpecTree.at(z).at(x).borough_name()){boroughListTreeFunVec.at(z)[a].boroInt++; inList = true;}
			}
			
			if(inList == false){
			
			boroughListTreeFunVec.at(z).push_back(Vector3d());
			
			boroughListTreeFunVec.at(z)[boroughListTreeFunVec.at(z).size()-1].borosV = allMatchingSpecTree.at(z).at(x).borough_name();
			
			boroughListTreeFunVec.at(z)[boroughListTreeFunVec.at(z).size()-1].boroInt = 1;
			}
			inList = false;	
	 }
	}
				vector <Vector3d> boroughListTreeFunREAL;
				boroughListTreeFunREAL.push_back(Vector3d());
				boroughListTreeFunREAL[boroughListTreeFunREAL.size()-1].borosV = "New York";
				boroughListTreeFunREAL[boroughListTreeFunREAL.size()-1].boroInt = 0;
				boroughListTreeFunREAL.push_back(Vector3d());
				boroughListTreeFunREAL[boroughListTreeFunREAL.size()-1].borosV = "Queens";
				boroughListTreeFunREAL[boroughListTreeFunREAL.size()-1].boroInt = 0;
				boroughListTreeFunREAL.push_back(Vector3d());
				boroughListTreeFunREAL[boroughListTreeFunREAL.size()-1].borosV = "Brooklyn";
				boroughListTreeFunREAL[boroughListTreeFunREAL.size()-1].boroInt =0;
				boroughListTreeFunREAL.push_back(Vector3d());
				boroughListTreeFunREAL[boroughListTreeFunREAL.size()-1].borosV = "Manhattan";
				boroughListTreeFunREAL[boroughListTreeFunREAL.size()-1].boroInt = 0;
				boroughListTreeFunREAL.push_back(Vector3d());
				boroughListTreeFunREAL[boroughListTreeFunREAL.size()-1].borosV = "Staten Island";
				boroughListTreeFunREAL[boroughListTreeFunREAL.size()-1].boroInt = 0;
				boroughListTreeFunREAL.push_back(Vector3d());
				boroughListTreeFunREAL[boroughListTreeFunREAL.size()-1].borosV = "Bronx";
				boroughListTreeFunREAL[boroughListTreeFunREAL.size()-1].boroInt = 0;
	inList = false;
	
	for(int z = 0; z < boroughListTreeFunVec.size(); z++){
		inList = false;
		for(int x = 0; x <  boroughListTreeFunVec.at(z).size(); x++){
		
			totalCount++;
		
			for(int a = 0; a < boroughListTreeFunREAL.size(); a++){
				if(boroughListTreeFunREAL.at(a).borosV == boroughListTreeFunVec.at(z).at(x).borosV){boroughListTreeFunREAL[a].boroInt++;  inList = true; break;}
			}
			
				if(inList == false){
				boroughListTreeFunREAL.push_back(Vector3d());
				boroughListTreeFunREAL[boroughListTreeFunREAL.size()-1].borosV = boroughListTreeFunVec.at(z).at(x).borosV;
				boroughListTreeFunREAL[boroughListTreeFunREAL.size()-1].boroInt = 1;
			}
			
			inList = false;
		}
	}

	
	
	static const int arr[] = { totalCount, boroughListTreeFunREAL.at(1).boroInt, boroughListTreeFunREAL.at(2).boroInt, boroughListTreeFunREAL.at(3).boroInt, boroughListTreeFunREAL.at(4).boroInt, boroughListTreeFunREAL.at(5).boroInt};
	vector<int> TrueValue (arr, arr + sizeof(arr) / sizeof(arr[0]) );
	
	for(int x = 0; x < boroughListTreeFunREAL.size(); x++){
			cout <<  setw(25) << boroughList.at(x).borosV <<  setw(15) << std::internal << TrueValue[x] << setw(20) << "(      " << boroughList.at(x).boroInt << " )"
			<< setw(25);
			if(TrueValue[x] != 0){ cout << ((double)TrueValue[x]/(double)boroughList.at(x).boroInt)*100.00 << "%"  << endl;}
			else{ cout << "0.00%" << endl;}
			
	}
	

}











list<Tree> Tree_collection::count_of_tree_speciesAlternative( const string& species_name ) const{
	if(species_name == "stump or dead tree"){ 
		string tempSpecName = "";
		Tree newTempTree(tempSpecName, 0);
		list<Tree> tempListTree = newAVLTree.findallmatches(newTempTree);
		return tempListTree;
	}
	Tree newTempTree(species_name, 0);
	list<Tree> tempListTree = newAVLTree.findallmatches(newTempTree);
	return tempListTree;
}


int Tree_collection::total_tree_count() const{
	
	return newAVLTree.AVL_TreeNodes_count();
}

int Tree_collection::count_of_tree_species ( const string& species_name ) const{
	if(species_name == "stump or dead tree"){ 
		string tempSpecName = "";
		Tree newTempTree(tempSpecName, 0);
		list<Tree> tempListTree = newAVLTree.findallmatches(newTempTree);
		return tempListTree.size();
	}
	Tree newTempTree(species_name, 0);
	list<Tree> tempListTree = newAVLTree.findallmatches(newTempTree);
	return tempListTree.size();
	
}
int Tree_collection::count_of_trees_in_boro( const string& boro_name ) const{
	for(int x = 0; x < boroughList.size(); x++){
		if(boroughList.at(x).borosV == boro_name) return boroughList.at(x).boroInt;
	}
	
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









