//https://www.acmicpc.net/problem/15811
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>

using namespace std;

int n,ans;
string tmp,result;
//문제 SUN FUN SWIM
vector<string> v;
//문제에 나온 알파벳 종류가 숫자로 저장
//6,9,13,4
vector<int> letter;
//중복여부확인
int alphabet[26];
int decimal[10];
//각 알파벳 매핑된 번호
//{6:0},{9:1},{13,2}
map<int,int> dic;
//문자에 매칭되는 숫자
vector<int> num;
int quiz[3];

void func(int idx){
    int ten;
    if(idx == letter.size()){
        quiz[0]=0;
        quiz[1]=0;
        quiz[2]=0;
        for(int i=0;i<3;i++){
            ten=1;
            for(int j=0;j<v[i].length();j++){
                quiz[i] += num[dic[v[i][v[i].length()-j-1]-'A']]*ten;
                ten *= 10;
            }
        }
        if(quiz[0]+quiz[1]==quiz[2]){ans=1;}
        return;
    }
    else{
        for(int i=0;i<10;i++){
            if(decimal[i]){continue;}
            num.push_back(i);
            decimal[i] = 1;
            func(idx+1);
            num.pop_back();
            decimal[i] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string tmp;
    for(int i=0;i<3;i++){
        cin>>tmp;
        v.push_back(tmp);
        for(int i=0;i<tmp.length();i++){
            if(alphabet[tmp[i]-'A']){continue;}
            letter.push_back(tmp[i]-'A');
            alphabet[tmp[i]-'A'] = 1;
        }
    }
    sort(letter.begin(),letter.end());
    for(int i=0;i<letter.size();i++){
        dic.insert({letter[i],i});
    }
    func(0);
    result = ans ? "YES":"NO";
    cout<<result<<'\n';
}
