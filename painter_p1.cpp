#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;


class Transition {
	public:
		char a;  //symbol that is read
		int r;     //state the transition goes to if a is read
		char b;  //value that is written to screen
		char x;  //tells you to go to next/previous/same symbol
};

class State {
   public:
   	Transition transitions[300];
   	int num=-1;
   	int numTrans=0;
   	string special;
};


int main(int argc, char* argv[]) {
	
	int nCurrent;
	int totalState=0;
	int space;
	
	bool firstFile=false;
	
	State states[1001];
	
	string tranState;
	string stateNum;
	string current;
	string next;
	string substr;
	char others;
	
	ifstream fin;
	fin.open(argv[1]);
	
	while(getline(fin, tranState, '\n')){
		
		if (tranState.substr(0,5)=="state"){
			tranState.erase(0,6);
			
			space=tranState.find(' ');
			
			substr = tranState.substr(0,space);
			
			states[totalState].num=stoi(substr);
			tranState.erase(0, space+1);	
			if (tranState.size()>2){
				if (states[totalState].num <10){tranState.erase(0,2);}
				else if(states[totalState].num <100){tranState.erase(0,3);}
				else{tranState.erase(0,4);}
				for (int f =0; f<tranState.size(); f++){if (tranState[f]==' '){tranState.erase(f,1);f--;}}
				states[totalState].special = tranState;
			}
			totalState++;
			
		}
		
		else if(tranState.substr(0,10)=="transition"){
			tranState.erase(0,11);
			
			space=tranState.find(" ");
			nCurrent = stoi(tranState.substr(0,space));
			
			if (nCurrent <10){tranState.erase(0,2);}
			else if(nCurrent <100){tranState.erase(0,3);}
			else{tranState.erase(0,4);}
			
			states[nCurrent].numTrans++;
			
			space=tranState.find(" ");
			substr = tranState.substr(0,space);
			states[nCurrent].transitions[states[nCurrent].numTrans-1].a=substr[0];
			tranState.erase(0,2);
			
			space=tranState.find(" ");
			substr = tranState.substr(0,space);
			states[nCurrent].transitions[states[nCurrent].numTrans-1].r=stoi(substr);
			if (stoi(substr) <10){tranState.erase(0,2);}
			else if(stoi(substr) <100){tranState.erase(0,3);}
			else{tranState.erase(0,4);}
			
			space=tranState.find(" ");
			substr = tranState.substr(0,space);
			states[nCurrent].transitions[states[nCurrent].numTrans-1].b=substr[0];
			tranState.erase(0,2);
			
			space=tranState.find(" ");
			substr = tranState.substr(0,space);
			states[nCurrent].transitions[states[nCurrent].numTrans-1].x=substr[0];
			
		}
	}
		
	
	///Part 2
	string readIn=argv[2];
	readIn +="_______";
	string neew="quit";
	int numTransitions=stoi(argv[3]);
	int currentState;
	int strCnt=0;
		
	for (int i=0; i<totalState; i++){
		if (states[i].special=="start"){
			currentState=states[i].num;
			i=totalState;	
		}		
	}
	while(numTransitions>0){
			
		///Plug first symbol into start state
		for (int i=0; i<states[currentState].numTrans; i++){
			if (readIn[strCnt]==states[currentState].transitions[i].a){
				readIn[strCnt]=states[currentState].transitions[i].b;
				if(states[currentState].transitions[i].x=='L'){
					strCnt--;
				}
				if(states[currentState].transitions[i].x=='R'){
					strCnt++;
				}
				currentState=states[currentState].transitions[i].r;
				i = states[currentState].numTrans;
			}	
		}
		
		if (states[currentState].special == "accept" || states[currentState].special == "reject"){
			neew = states[currentState].special;
			numTransitions = 0;		
		}
			
			
		numTransitions--;		
	}
	for(int i=0; i < readIn.size(); i++){
		if (readIn[i]=='_'){readIn.erase(i,1);i--;}	
		if (readIn[i]==' '){readIn.erase(i,1);i--;}
	}
	
	cout << readIn << " " << neew << endl<<endl;
	fin.close();
	
	return 0;

}


