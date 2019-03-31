#include<iostream>
using namespace std;
int main()
{
	int N,M,C1,C2;
	cin>>N>>M>>C1>>C2;
	int i,j,i1,i2;
	int city[N];
	int roads[N][N];
	int dis[N];
	int total_team_i[N];
	int num_path_i[N];
	bool visited[N];
	for(i=0;i<N;++i)
	{
		dis[i] = -1;
		cin>>city[i];
		visited[i] = false;
		total_team_i[i] = city[i];
		num_path_i[i] = 0;
		for(j=0;j<N;j++)
			roads[i][j] = 0;
	}
	for(i=0;i<M;++i)
	{
		cin>>i1>>i2>>j;
		roads[i1][i2] = j;
		roads[i2][i1] = j;
	}
	visited[C1] = true; 
	dis[C1] = 0;
	num_path_i[C1] = 1;
	int tempi = C1, temp_path;
	for(i=1;i<N;++i)
	{
		for(j=0;j<N;j++)
		{
			if(roads[tempi][j] == 0 || visited[j] == true)
				continue;
			if(dis[j] == -1)
			{
				dis[j] = dis[tempi] + roads[tempi][j];
				total_team_i[j] = total_team_i[tempi] + city[j];
				num_path_i[j] = num_path_i[tempi];
				continue;
			}
			if(dis[j] > dis[tempi] + roads[tempi][j])
			{
				dis[j] = dis[tempi] + roads[tempi][j];
				total_team_i[j] = total_team_i[tempi] + city[j];
				num_path_i[j] = num_path_i[tempi];
				continue;
			}
			if(dis[j] == dis[tempi] + roads[tempi][j])
			{
				num_path_i[j] += num_path_i[tempi];
				if(total_team_i[j] < total_team_i[tempi] + city[j])
				{
					total_team_i[j] = total_team_i[tempi] + city[j];
				}
				continue;
			}
		}
		
		temp_path = 0;
		for(j=0;j<N;j++)
		{
			if(visited[j] == true || dis[j] == -1)
				continue;
			if(temp_path == 0 || temp_path > dis[j])
			{
				tempi = j;
				temp_path = dis[j];
				continue;
			}
		}
		visited[tempi] = true;
		if(tempi == C2)
			break;
	}
	
	cout<<num_path_i[C2]<<" "<<total_team_i[C2];
	
	return 0;
} 
