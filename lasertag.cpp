#include <iostream>
#include <fstream>
#include <string>
#include "Team.h"
#include "Match.h"

using namespace std;

main(int argc, char* argv[]){

	string filename[4];
	string verbosity;
	if (argc!=6) {
		cout<<"Invalid Argument count. Using default filename names."<<endl;
		filename[0]="TeamA.txt";
		filename[1]="TeamB.txt";
		filename[2]="MatchFile.txt";
		filename[3]="OutputFile.txt";
		verbosity="vhigh";
	} else {
		filename[0]=argv[1];
		filename[1]=argv[2];
		filename[2]=argv[3];
		filename[3]=argv[4];
		verbosity=argv[5];
	}
	//get arguments
	
	Team team[2];
	for (int i=0;i<2;i++){
		ifstream file(filename[i].c_str());
		getline(file,team[i].name);
		file>>team[i].count;
		int j;
		while (file>>j){
			cout<<"!"<<endl;
			file>>team[i].members[j];
		}
		file.close();
	}
	//read teams
	
	Match match[2];
	ifstream file("MatchFile.txt");
	int count;
	file>>count;
	int j,k,l,m;
	while (file>>j){
		cout<<m<<endl;
		file>>k;
		file>>l;
		file>>m;
		for (int i=0;i<2;i++){
			if (team[i].members[j]!="") {
				match[i].log(j,k,m);
			}
		}
	}
	//read matches
	
	for (int i=0;i<2;i++){
		match[i].calculatePlayerTotalTags();
		match[i].calculatePlayerTotalPoints();
		match[i].calculateTeamTotalPoints();
	}
	//calculate values

	for (int i=0;i<2;i++){
		cout<<team[i].name<<endl;
		cout<<team[i].count<<endl;
		for (int j=0;j<11;j++){
			cout<<j<<" "<<team[i].members[j]<<endl;
		}
	}
	//print teams
	
	for (int k=0;k<2;k++){
		for (int i=0;i<11;i++){
			for (int j=0;j<11;j++){
				cout<<match[k].tags[i][j]<<'\t';
			}
			cout<<endl;
		}
		cout<<endl;
		for (int i=0;i<11;i++){
			for (int j=0;j<11;j++){
				cout<<match[k].points[i][j]<<'\t';
			}
			cout<<endl;
		}
		cout<<endl;
	}
	//print matches
	
	if (verbosity=="vhigh"){
		for (int k=0;k<2;k++){
			for (int i=0;i<11;i++){
				for (int j=0;j<11;j++){
					if (match[k].tags[i][j]!=0){
						cout<<team[k].members[i]<<" tagged "<<team[1-k].members[j]<<" for "<<match[k].tags[i][j]<<endl;
					}
				}
			}
		}
	}
	if (verbosity=="vmid" || verbosity=="vhigh"){
		for (int k=0;k<2;k++){
			cout<<team[k].name<<":"<<endl;
			for (int i=0;i<11;i++){
				cout<<team[k].members[i]<<" tagged "<<match[k].tags[i][0]<<endl;
			}
			cout<<"Best Player: "<<team[k].members[match[k].getMostPointPlayer()]<<endl;
		}
	}
	if (verbosity=="vlow" || verbosity=="vmid" || verbosity=="vhigh"){
		for (int k=0;k<2;k++){
			cout<<team[k].name<<": "<<match[k].points[0][0]<<endl;
		}
		if (match[0].points[0][0]>match[1].points[0][0]){
			cout<<"Winner: "<<team[0].name<<endl;
		} else if (match[0].points[0][0]<match[1].points[0][0]){
			cout<<"Winner: "<<team[1].name<<endl;
		} else {
			cout<<"Draw"<<endl;
		}
	}
	//write files
}
