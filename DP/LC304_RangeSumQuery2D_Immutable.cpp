// my solution
class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        for(int i=0; i<matrix.size(); i++){
        	vector<int> t;
        	t.push_back(0);
        	for(int j=0; j<matrix[0].size(); j++){
        		t.push_back(t.back()+matrix[i][j]);
        	}
        	dp.push_back(t);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0, i;
        for(i=row1; i<=row2; i++){
        	sum += dp[i][col2+1];
        }
        for(i=row1; i<=row2; i++){
        	sum -= dp[i][col1];
        }
        return sum;
    }
private:
	vector<vector<int>> dp;
};


// Answer
class NumMatrix {
private:
    int row, col;
    vector<vector<int>> sums;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        row = matrix.size();
        col = row>0 ? matrix[0].size() : 0;
        sums = vector<vector<int>>(row+1, vector<int>(col+1, 0));
        for(int i=1; i<=row; i++) {
            for(int j=1; j<=col; j++) {
                sums[i][j] = matrix[i-1][j-1] + 
                             sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1] ;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1] - sums[row2+1][col1] - sums[row1][col2+1] + sums[row1][col1];
    }
};

// Answer 2
class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        accu = matrix;
        for (int i=0; i<matrix.size(); ++i)
            for (int j=0; j<matrix[0].size(); ++j)
                accu[i][j] += a(i-1, j) + a(i, j-1) - a(i-1, j-1);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return a(row2, col2) - a(row1-1, col2) - a(row2, col1-1) + a(row1-1, col1-1);
    }

private:
    vector<vector<int>> accu;
    int a(int i, int j) {
        return i >= 0 && j >= 0 ? accu[i][j] : 0;
    }
};