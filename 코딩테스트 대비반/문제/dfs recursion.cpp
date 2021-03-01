#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// dfs�� ������ '�湮'�Ѱŷ� �Ǵ�
// �ش� ��ġ�� check true�� ���ش�.
void dfs(int start, vector<int> graph[], bool check[]){
	check[start]= true;
	cout << start << " ";

	for(int i=0; i < graph[start].size(); i++){
		int next = graph[start][i];
		// �湮���� �ʾҴٸ�
		if(check[next]==false){
			// ����Լ��� ȣ���Ѵ�.
			dfs(next, graph, check);
		}
	}
}

int main (){

	int n, m, start;
	cin >> n >> m >> start;

	vector<int> graph[n+1];
	bool check [n+1];
	fill(check, check+n+1, false);

	for(int i=0; i<m; i++){
		int u,v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	// Sorting�� �� �Ѱ���?
	// ������ �������� ��� ������ ���� ���� ���� �湮�ϱ� ����
	for(int i=1; i<=n; i++){
		sort(graph[i].begin(), graph[i].end());
	}

	//dfs
	dfs(start, graph, check);
	cout << endl;

	return 0;
}
