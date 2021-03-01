#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;
int num;
set<int> output;

//숫자야구 후보 초기화를 위한 
int Arr[10];
vector<int> tmp;
//하나의 구조체로 정보처리를 간단하게 하였습니다.
//세가지 이상의 속성이므로 클래스로 생성하였습니다.
//C++ 클래스 접근자 디폴트 설정이 프라이빗이기 때문에 주의 요망!! 
class Node{
	public:
		int question,strike,ball; 
		Node(int q,int s,int b): question(q),strike(s),ball(b)  {}
};
vector<Node> input;
//숫자야구의 조건인 서로 다른 세 수 후보를 만들기 위한 함수
//재귀함수를 이용하여 구현  
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
	//두 숫자를 문자열로 변환하여
	//문자열 라이브러리를 활용한 비교 
	//to_string과 find 라이브러리 활용!! 
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
	//123~987 배열 output에 저장 
	for(iter=input.begin();iter!=input.end();iter++){
		check(*iter);
	}//질문들과 관계가 맞는지 체크하고 아닌 값은 ouput에서 제외	
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
