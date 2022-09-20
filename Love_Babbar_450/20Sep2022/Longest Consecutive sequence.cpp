//CN Lec 15
// CPP DSA Love Babbar 450
#include<vector>
#include<unordered_map>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    unordered_map< int, bool > ourmap;
    int Fstart = 0;
    int Fend = 0;
    int Flen = 0;
    for(int i=0; i<n; i++ )
		ourmap[arr[i]] = 1;
    for( int i=0; i<n; i++ ){
        int start = arr[i];
        int end = arr[i];
        int len=1;
        while( ourmap.count(end+1)> 0){
			end ++;
            len++;
        }
        if(len > Flen){
			Flen = len;
            Fstart = start;
            Fend = end;
        }
    }
    vector<int> v;
    v.push_back(Fstart);
    v.push_back(Fend);
    return v;
}
