// Time Complexity: O(4^(n^2)*n)
// Space Complexity:  O(n^2)

#include <bits/stdc++.h> 
void toMatrix(string move,vector<int>&v,int n)
{
  vector<vector<int>>vv(n,vector<int>(n,0));
  int r=0,c=0;
  vv[r][c]=1;
  for(int i=0;i<move.length();i++)
  {
    if(move[i]=='U')
    {
       r=r-1;
       c=c;
       vv[r][c]=1;
    }
    else if(move[i]=='D')
    {
       r=r+1;
       c=c;
       vv[r][c]=1;
    }
     else if(move[i]=='L')
    {
       r=r;
       c=c-1;
       vv[r][c]=1;
    }
     else if(move[i]=='R')
    {
       r=r;
       c=c+1;
       vv[r][c]=1;
    }
  }
  for (int i = 0; i < n; i++) {
    for(int j=0;j<n;j++)
    {
      v.push_back(vv[i][j]);
    }
  }
}
void solve(int r, int c, vector<vector<int> > &maze, int n, vector<vector<int> > &vis
, vector<vector<int> > &ans,string move)
{
  if(r==n-1 && c==n-1)
  {
    vector<int>v;
    toMatrix(move,v,n);
    ans.push_back(v);
    return;
  }
  for(int i= -1;i<=1;i++)
  {
    for(int j= -1;j<=1;j++)
    {
      if(abs(i)!=abs(j))
      {
        int newR=r+i;
        int newC=c+j;
        if(newR>=0 && newR<n && newC>=0 && newC<n && vis[newR][newC]==0 && maze[newR][newC]==1)
        {
          vis[r][c]=1;
          if(i== -1 && j==0)
          {
            solve(newR,newC,maze,n,vis,ans,move+'U');
          }
          else if(i== 1 && j==0)
          {
            solve(newR,newC,maze,n,vis,ans,move+'D');
          }
          else if(i== 0 && j==-1)
          {
            solve(newR,newC,maze,n,vis,ans,move+'L');
          }
          else if(i== 0 && j==1)
          {
            solve(newR,newC,maze,n,vis,ans,move+'R');
          }
          
          vis[r][c]=0;
        }
      }
    }
  }
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
  
  vector<vector<int> >ans;
  if(maze[0][0]==0) return ans;
  string move="";
  vector<vector<int>>vis(n,vector<int>(n,0));
  solve(0,0,maze,n,vis,ans,move);
  return ans;
}