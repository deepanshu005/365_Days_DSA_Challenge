// CPP DSA Love Babbar 450
// My prev code wasn't running bcoz there can be the case when there is only on train for platform number 1 and i was not checking if there can be change in platform just after 1st train
#include<bits/stdc++.h>
bool cmp( vector<int>a, vector<int>b ){
    if( a[2] != b[2] ){
        if( a[2] <= b[2] )    return true;
        return false;
    }
    else{
        if( a[1] <= b[1] )    return true;
        return false;
    }
}
int maxStop( vector<vector<int>> &trains, int n, int m ){
    sort( trains.begin() ,trains.end(),cmp );
    int limit = trains[0][1];
    int count = 1;
    int pre = trains[0][2];
    
    for( int i=1; i<n; i++ ){
        if( limit<=trains[i][0] && pre == trains[i][2] ){ 
            limit = trains[i][1];
            count++;
        }
        else if( pre != trains[i][2]){//if there occurs a chng in platform and im counting this case as
            // train with least departure time on any new platform can stop always 
            limit = trains[i][1];
            pre = trains[i][2];
            count++;
        }
    }
    return count;
}


