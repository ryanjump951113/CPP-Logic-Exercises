#include<iostream>
using namespace std;
int main(void){
	int n,m;
	cin>>n>>m;
	int a[n+2][m+2]={};
	// add another place for the edge
	for(int i=0;i<=n+1;i++) a[i][0]=a[i][m+1]=-1;
	for(int j=0;j<=m+1;j++) a[0][j]=a[n+1][j]=-1;
		

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	int start_i,start_j;
	int min_value=100000000;
	
	// find the smallest place to start
	for(int i=1;i<n+1;i++){
		for(int j=1;j<m+1;j++){
			if(a[i][j]<min_value&&a[i][j]!=-1){
				start_i=i;
				start_j=j;
				min_value=a[i][j];
			}
		}
	}
	
	bool canfind;
	int now_i=start_i,now_j=start_j;
	int ans=0;
	int next_i,next_j;

	//judge if the robot can arrive to the new target place
	do{
		canfind=false;
		ans+=min_value;
	    min_value=100000000;
	    a[now_i][now_j]=-1;
		
		if(a[now_i+1][now_j]<min_value&&a[now_i+1][now_j]!=-1){
			min_value=a[now_i+1][now_j];
			next_i=now_i+1;
			next_j=now_j;
			canfind=true;
			
		}
		if(a[now_i-1][now_j]<min_value&&a[now_i-1][now_j]!=-1){
			min_value=a[now_i-1][now_j];
			next_i=now_i-1;
			next_j=now_j;
			canfind=true;
			
		}
		if(a[now_i][now_j+1]<min_value&&a[now_i][now_j+1]!=-1){
			min_value=a[now_i][now_j+1];
			next_i=now_i;
			next_j=now_j+1;
			canfind=true;
		
		}
		if(a[now_i][now_j-1]<min_value&&a[now_i][now_j-1]!=-1){
			min_value=a[now_i][now_j-1];
			next_i=now_i;
			next_j=now_j-1;
			canfind=true;
		
		}
		now_i=next_i;
		now_j=next_j;
		
	}while(canfind);
	cout<<ans<<endl;
	return 0;
}
