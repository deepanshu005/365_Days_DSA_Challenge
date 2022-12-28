// CPP DSA Love Babbar 450
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // hum max heap lenge qunki humme cloest chahiye means jinka abs difference x k saath min ho
        int n = arr.size();
        priority_queue< pair<int, int> >pq;
        vector<int> vec;
        for( int i=0; i<n; i++ ){

            pq.push( {abs(arr[i]-x), arr[i]} );
            if( pq.size()>k ){
                pq.pop();
            }
        }
        while( !pq.empty() ){
            vec.push_back( pq.top().second );
            pq.pop();
        }
        sort( vec.begin(), vec.end());
        return vec;
    }
};
