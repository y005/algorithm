#include <iostream>
#include <map> 
#include <vector> 
#include <string>
using namespace std;

//���ڿ� ���̺귯���� Ȱ���� ���
//�ϴ� ����,���ڸ� �� ������ Ȱ���� ����
//���ڸ� �˻�Ű�� �����մϴ�.
//������ �ڷ� ������ �˻�Ű�� ���ڿ� ���̰�
//������� ������ ���� Ž�� ������ �������� ���� 
//��Ī�ǰ� ���� ���ڿ��� �ִ� ��� ������ ���ο� �κ� ��   
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
		//�ڿ������� Ž��  
		for(j=msg.size();j>0;j--){
			iter = dic.find(msg.substr(0,j));
			if(iter != dic.end()){
				break;
			}
		}	
		v.push_back(iter->second);	
		if(j!=msg.size()){
			//������ ���ڰ� �����ִ� ���    
			//������ ���ڿ��� ���� ���ڿ��� ������ ����  
			//�߰ߵ� ���ڿ��� ������ ������ ���ڿ��� ���ܵ�
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
