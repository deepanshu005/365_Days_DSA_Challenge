// Top interview playlist question 79
double median(vector<int> a, vector<int> b)
{
    // Write your code here.
    int i=0,j=0,k=0;
    int s=0;
    double Median=0;
    vector<double> m;
    while(i<a.size() and j<b.size()){
        if(a[i]> b[j]){
            m.push_back(b[j]);
            j++;
        }
        else{
           m.push_back(a[i]); 
            i++;
        }
    }
    if( j<b.size()){
        while(j<b.size()){
            m.push_back(b[j]);
            j++;
        }
    }
    else if(i<a.size()){
        while(i<a.size()){
            m.push_back(a[i]);
            i++;
        }
    }
    
    if(m.size()%2==0){
       s = m.size()/2;
       Median =(m[s-1]+m[s])/2;
    }
    else{
        Median= m[(m.size())/2];
    }
    return Median;
}
