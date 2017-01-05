// 22.12.2016, Tai<taitrananhvn@gmail.com>

#if 1
#include <string> //std::string
#include <vector>
#define VISITED 1
#define UNVISITED 0
#include <stdio.h>
#include <iostream>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vi dfs_num;
vector<vii> AdjList;

void dfs(int u) {
    dfs_num[u] = VISITED;
    for (int j=0; j < (int) AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if ((dfs_num[v.first] == UNVISITED))
            dfs(v.first);
    }
}
    

int main()
{
    int tc,v;
	char a,b,c;
	char str[20];


	
    scanf("%d",&tc);	
	while (tc--)
	{
		//scanf("%c",&c);
		cin >> c;
		v = c - '0' - 17;
		printf("Number of vertices: %d\n", v+1);
		AdjList.assign(v,vii());

		while((c=getchar()) != '\n');
		while (fgets(str,20,stdin) && sscanf(str,"%c%c",&a,&b))
		{
			printf("%c, %c\n",a,b);
			int u, v;
			u = a - '0' - 17;
			v = b - '0' - 17;
			printf("%d, %d\n",u,v);
			AdjList[u].push_back(ii(v,0));
			AdjList[v].push_back(ii(u,0));
		}
	}
  
    for (int j = 0; j < v; j++)
    {
    	printf("vertice: %d ->", j);
    	if (AdjList[j].size() > 0)
    	{
	    	for (int t=0; t < AdjList[j].size(); t++)
	    		printf("    %d", AdjList[j][t].first);
	    }
    	printf("\n");
    }
	printf("ok\n");

    return 0;
}
#endif


