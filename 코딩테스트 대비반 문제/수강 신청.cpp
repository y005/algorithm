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
//map�� Ư¡ �ߺ� Ű�� ��� val���� ����� �˴ϴ�.
//map�� Ű���� �й����� �ϸ� ���� �й����� ����ȣ��
//�ο��Ǹ� ����ȣ�� ���� ��ȣ�� ����� �˴ϴ�
//����ȣ ������ �����ϱ� ���ؼ��� ����ȣ�� Ű������
//map ������ ����� map�� �����ϸ� �˴ϴ�. 
int main()
{
    scanf("%d%d", &K, &L);
 
    for(int i=1; i<=L; i++)
    {
        int s; scanf("%d", &s);
        A[s] = i;
		//���� �й��� Ű�� �Է����ݴϴ� 
        //�ߺ��� �й��� ��� ���� ������ ����Ⱑ �˴ϴ�  
    }
 	//�ش� map���Ҹ� ����ȣ ������ �����ϱ� ���ؼ��� 
	//����ȣ�� Ű�� �ϰ� �й��� �������� �� pair ���Ϳ� �ֽ��ϴ�   
    //pair�� �񱳴� ù��° ���Ҹ� �������� �մϴ�  
	for(it=A.begin(); it!=A.end(); it++)
        B.push_back(make_pair(it->second, it->first));
  
    //���� ��û ���� �������� ����
    sort(B.begin(), B.end());
 
    //���� ��û�� ������ �л��� ���� ���� �������� ���� ��츦 ����ؾ� ��
    int num = min(K,int(B.size()));
    
    //�ش� ������������ ����ϰ� �մϴ�  
    for(int i=0; i<num; i++)
        printf("%d\n", B[i].second);
}



