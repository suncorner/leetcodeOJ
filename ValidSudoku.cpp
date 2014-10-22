class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board)
    {
    	bool isChecked[10];
    
    	for (int row = 0; row < 9; row += 3){
    		for (int col = 0; col < 9; col += 3){
    			std::fill(isChecked+1, isChecked + 10, false);
    			for (int rowI = row; rowI < row + 3; ++rowI){
    				for (int colJ = col; colJ < col + 3; ++colJ){
    					char ch = board[rowI][colJ];
    					if (ch == '.')
    						;
    					else if (ch >= '1' && ch <= '9'){
    						if (!isChecked[ch - '0']){
    							isChecked[ch - '0'] = true;
    						}
    						else{
    							goto L1;
    						}
    					}
    				}
    			}
    		}
    	}
    	//cout << "Gong checking passed..." << endl;
    
    	for (int row = 0; row < 9; ++row){
    		std::fill(isChecked + 1, isChecked + 10, false);
    		for (int col = 0; col < 9; ++col){
    			char ch = board[row][col];
    			if (ch == '.')
    				;
    			else if (ch >= '1' && ch <= '9'){
    				if (!isChecked[ch - '0']){
    					isChecked[ch - '0'] = true;
    				}
    				else{
    					goto L1;
    				}
    			}
    		}
    	}
    	//cout << "Row checking passed..." << endl;
    
    	for (int col = 0; col < 9; ++col){
    		std::fill(isChecked + 1, isChecked + 10, false);
    		for (int row = 0; row < 9; ++row){
    			char ch = board[row][col];
    			if (ch == '.')
    				;
    			else if (ch >= '1' && ch <= '9'){
    				if (!isChecked[ch - '0']){
    					isChecked[ch - '0'] = true;
    				}
    				else{
    					goto L1;
    				}
    			}
    		}
    	}
    	//cout << "Col checking passed..." << endl;
    
    	return true;
    
    L1:
    	return false;
    }

};