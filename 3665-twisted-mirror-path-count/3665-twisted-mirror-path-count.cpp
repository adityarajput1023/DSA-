class Solution {
public:
    int LEFT = 0;
    int UP = 1;
    int mod = 1e9+7;
    int m;
    int n;

    int solve(vector<vector<int>>& grid , int i , int j , int camefrom ,vector<vector<array<int , 2>>>& t){

        if(i >= m || j>= n){
            return 0;
        }

        if(i == m-1 && j == n-1){
            return 1;
        }

        if(t[i][j][camefrom] != -1){
            return t[i][j][camefrom];
        }

        if(grid[i][j] == 1){
            if(camefrom == LEFT){
                return  t[i][j][camefrom] = solve(grid , i+1 , j ,UP , t);
            }
            else{
               return  t[i][j][camefrom] = solve(grid , i , j+1 ,LEFT , t);
            }
        }

        int totalPathCount = 0;
        totalPathCount = (totalPathCount + solve(grid, i, j+1, LEFT , t)) % mod;
        totalPathCount = (totalPathCount + solve(grid, i+1, j, UP , t)) % mod;

        return t[i][j][camefrom] = totalPathCount ;

    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<array<int , 2>>> t(m+1 , vector<array<int , 2>>(n, {-1,-1}));


        return solve(grid , 0 , 0 , LEFT , t);


    }
};