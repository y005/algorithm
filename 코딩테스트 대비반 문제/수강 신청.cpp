#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <algorithm>
 
using namespace std;
int K, L;
map<int,int> A;
map<int,int>::iterator it;
vector<pair<int,int> > B;
//map의 특징 중복 키의 경우 val값이 덮어쓰기 됩니다.
//map의 키값을 학번으로 하면 같은 학번으로 대기번호가
//부여되면 대기번호는 나중 번호로 덮어쓰게 됩니다
//대기번호 순서로 정렬하기 위해서는 대기번호를 키값으로
//map 구조를 만들고 map을 정렬하면 됩니다. 
int main()
{
    scanf("%d%d", &K, &L);
 
    for(int i=1; i<=L; i++)
    {
        int s; scanf("%d", &s);
        A[s] = i;
		//먼저 학번을 키로 입력해줍니다 
        //중복인 학번인 경우 나중 순서로 덮어쓰기가 됩니다  
    }
 	//해당 map원소를 대기번호 순으로 정렬하기 위해서는 
	//대기번호를 키로 하고 학번을 나중으로 한 pair 벡터에 넣습니다   
    //pair의 비교는 첫번째 원소를 기준으로 합니다  
	for(it=A.begin(); it!=A.end(); it++)
        B.push_back(make_pair(it->second, it->first));
  
    //수강 신청 순서 기준으로 정렬
    sort(B.begin(), B.end());
 
    //수강 신청에 성공한 학생이 수강 가능 정원보다 적은 경우를 고려해야 함
    int num = min(K,int(B.size()));
    
    //해당 선착순까지만 출력하게 합니다  
    for(int i=0; i<num; i++)
        printf("%d\n", B[i].second);
}



