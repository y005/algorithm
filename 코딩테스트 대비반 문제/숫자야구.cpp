#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;
int num;
set<int> output;

//���ھ߱� �ĺ� �ʱ�ȭ�� ���� 
int Arr[10];
vector<int> tmp;
//�ϳ��� ����ü�� ����ó���� �����ϰ� �Ͽ����ϴ�.
//������ �̻��� �Ӽ��̹Ƿ� Ŭ������ �����Ͽ����ϴ�.
//C++ Ŭ���� ������ ����Ʈ ������ �����̺��̱� ������ ���� ���!! 
class Node{
	public:
		int question,strike,ball; 
		Node(int q,int s,int b): question(q),strike(s),ball(b)  {}
};
vector<Node> input;
//���ھ߱��� ������ ���� �ٸ� �� �� �ĺ��� ����� ���� �Լ�
//����Լ��� �̿��Ͽ� ����  
void start(int n){
	if(n==4){
		int sum =0;
		int mul = 1;
		for(int i=3;i>-1;i--){
			sum = sum + mul*tmp[i];
			mul *= 10; 
		}
		if((sum>122)&&(sum<988)){
		    //cout<<sum<<" ";
		    output.insert(sum);
		}
	}
	for(int i=0;i<10;i++){
		if(!Arr[i]){
			Arr[i]=1;
			tmp.push_back(i); 
			start(n+1);
			tmp.pop_back(); 
			Arr[i]=0;
		}		
	}	
}
bool isPossible(int& candidate,Node& q){
	//�� ���ڸ� ���ڿ��� ��ȯ�Ͽ�
	//���ڿ� ���̺귯���� Ȱ���� �� 
	//to_string�� find ���̺귯�� Ȱ��!! 
	string a = to_string(candidate);
	string b = to_string(q.question);
	int strike=0;
	int ball=0;
	
	for(int i=0;i<3;i++){
		char c = b[i];
		if(a.find(c)==-1){continue;}
		else{
			if(a.find(c)==i){strike++;}
			else{ball++;}
		}
	}	
	//cout<<strike<<","<<ball<<endl;
	if((q.strike==strike)&&(q.ball==ball)){return true;}
	return false;
}
void check(Node& node){
	set<int>::iterator iter;
	for(iter=output.begin();iter!=output.end();iter++){
		int n = *iter;
		if(!isPossible(n,node)){output.erase(iter);}
	}	
}
void find(){
	vector<Node>::iterator iter;
	start(0);
	//123~987 �迭 output�� ���� 
	for(iter=input.begin();iter!=input.end();iter++){
		check(*iter);
	}//������� ���谡 �´��� üũ�ϰ� �ƴ� ���� ouput���� ����	
}
int main(){
	cin>>num;
	int q,s,b;
	for(int i=0;i<num;i++){
		cin>>q>>s>>b;
		Node n = Node(q,s,b);		
		input.push_back(n);
	}	
	find();
	cout<<output.size()<<endl;
	set<int>::iterator iter;
	for(iter=output.begin();iter!=output.end();iter++){
		cout<<*iter<<endl;
	}
}
