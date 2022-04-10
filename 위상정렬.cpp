#include<bits/stdc++.h>
using namespace std;

int N,M;
vector<vector<int> >adj;

vector<bool> visited;
vector<int> order;
void dfs(int here){
	visited[here]=true;
	for(int there=0; there<adj.size(); there++){
		if(adj[here][there]&&!visited[there]){
			dfs(there);
		}
	}
	order.push_back(here);
}

void topologicalSort(){
	int n=adj.size();
	visited=vector<bool>(N,false);
	order.clear();
	for(int i=0; i<N; i++){
		if(!visited[i]){
			dfs(i);
		}
	}
	reverse(order.begin(),order.end());
}

void printOrder(){
	for(int i=0; i<order.size(); i++){
		printf("%d ",order[i]);
	}
	printf("\n");
}

int main(void){
	printf("정점의 갯수 : ");
	scanf("%d", &N);
	
	printf("간선의 갯수 : ");
	scanf("%d", &M);

	visited = vector<bool>(N, false);
	adj = vector<vector<int> > (N, vector<int>(N, 0));

	for (int i = 0; i < M; i++) {
		int from, to;
		printf("정점1 -> 정점2 : ");
		scanf(" %d %d", &from, &to);
		adj[from][to] = 1;
	}
	
	topologicalSort();
	printOrder();
}
