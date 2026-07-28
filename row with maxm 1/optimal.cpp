int rowWithMax1s(vector<vector<int> > arr, int m, int n) {
	    int i = 0, j = n - 1;
	    
	    int ans = -1;
	    while(i < m && j >= 0)
	    {
	        if(arr[i][j] == 1)
	        {
	            ans = i;
	            j--;
	        }
	        else
	            i++;
	    }
	    return ans;
	}