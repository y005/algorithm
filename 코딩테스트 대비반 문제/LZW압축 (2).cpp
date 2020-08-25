#include <iostream>
#include <map> 
#include <vector> 
#include <string>
using namespace std;

//문자열 라이브러리를 활용한 방식
//일단 문자,숫자를 맵 구조를 활용한 사전
//문자를 검색키로 설정합니다.
//사전은 뒤로 갈수록 검색키의 문자열 길이가
//길어지기 때문에 문자 탐색 방향은 역순으로 진행 
//매칭되고 남은 문자열이 있는 경우 사전에 새로운 부분 추   
int main(){
	vector<int> v;
	map<string,int> dic;	
	string msg,msg0;
	int idx;
	for(idx=0;idx<='Z'-'A';idx++){
		string tmp ="";
		tmp += (char)('A'+idx);
		dic.insert(pair<string,int>(tmp,idx+1));		
	}
	cin>>msg0;
	msg = msg0;
	map<string,int>::iterator iter; 
	string st; 
	int j; 
	while(msg.size()!=0){	
		//뒤에서부터 탐색  
		for(j=msg.size();j>0;j--){
			iter = dic.find(msg.substr(0,j));
			if(iter != dic.end()){
				break;
			}
		}	
		v.push_back(iter->second);	
		if(j!=msg.size()){
			//나머지 문자가 남아있는 경우    
			//나머지 문자열을 더한 문자열을 사전에 저장  
			//발견된 문자열을 제외한 나머지 문자열만 남겨둠
			st = iter->first + msg.at(j);
			msg = msg.substr(j);		
			dic.insert(pair<string,int>(st,++idx));	 
		}    
		else{
			msg.clear();
		}
	}	
	vector<int>::iterator it; 
	for(it= v.begin();it !=v.end();it++){
		cout<<*it<<" ";
	}
}
