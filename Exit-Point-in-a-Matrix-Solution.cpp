###################################################################################  Question  ########################################################################################################################################

Given a matrix of size n x m with 0’s and 1’s, you enter the matrix at cell (0,0) in left to right direction. Whenever you encounter a 0 you retain it in the same direction, else if you encounter a 1 you have to change the direction to the right of the current direction and change that 1 value to 0, you have to find out from which index you will leave the matrix at the end.

Example 1:

Input: 
n = 3, m = 3
matrix = {{0, 1, 0},
          {0, 1, 1}, 
          {0, 0, 0}}
Output: 
{1, 0}
Explanation: 
Enter the matrix at (0, 0) 
-> then move towards (0, 1) ->  1 is encountered 
-> turn right towards (1, 1)  -> again 1 is encountered 
-> turn right again towards (1, 0) 
-> now, the boundary of matrix will be crossed ->hence, exit point reached at 1, 0..
Example 2:

Input: 
n = 1, m = 2
matrix = {{0, 0}}
Output: 
{0, 1}
Explanation: 
Enter the matrix at cell (0, 0).
Since the cell contains a 0, we continue moving in the same direction.
We reach cell (0, 1), which also contains a 0. So, we continue moving in the same direction, we exit the matrix from cell (0, 1).
Your Task:
You don't need to read or print anything. Your task is to complete the function FindExitPoint() which takes the matrix as an input parameter and returns a list containing the exit point.

Expected Time Complexity: O(n * m) where n = number of rows and m = number of columns.
Expected Space Complexity: O(1)

Constraints:
1 <= n, m <= 100












####################################################################################  Solution  #######################################################################################################################################

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int>ans;
    
    vector<int> solve(int n, int m,int i,int j,int p, int dir,vector<vector<int>>& mat){
        if(i>=n || j>=m ||i<0 ||j<0){
            return ans;
        }
        
        if(mat[i][j]==0){
            ans.clear();
            ans.push_back(i);
            ans.push_back(j);
            int a=0,b=0;
            if(dir==0||dir==2){
                b=b+p;
            }else if(dir==1 || dir==3){
                a=a+p;
            }
            
            solve(n,m,i+a,j+b,p,dir,mat);
        }else{
            if(dir==0){
               ans.clear();
            ans.push_back(i);
            ans.push_back(j);
            mat[i][j]=0;
            solve(n,m,i+1,j,1,1,mat);
            
            }else if(dir==1){
                 ans.clear();
            ans.push_back(i);
            ans.push_back(j);
            mat[i][j]=0;
            solve(n,m,i,j-1,-1,2,mat);
            }else if(dir==2){
                 ans.clear();
            ans.push_back(i);
            ans.push_back(j);
            mat[i][j]=0;
            solve(n,m,i-1,j,-1,3,mat);
            }else if(dir==3){
                 ans.clear();
            ans.push_back(i);
            ans.push_back(j);
            mat[i][j]=0;
            solve(n,m,i,j+1,1,0,mat);
            }
            
            
        }
        return ans;
        
    }
    
    
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        solve(n,m,0,0,1,0,matrix);
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
