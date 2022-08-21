//Love bababar DSA Sheet 450
string writeAsYouSpeak(int n) {
    string str = "1";
    string temp ;
    for( int i=1; i<n; i++){ // this loop is to reach nth iteration
        temp = "";//stores the temp string
        int k = str.length();
        int count = 0;
        int j=0;
        for(int x=0; x<k;  ){//used to traverse current string
            count=0;
            while( str[x] == str[j] && j<k ){//count number of same digits
                count++;// this while loop will run atleast one time in each itera
                j++;
            }
            temp = temp + to_string(count) + str[x] ;
            x+=count;
            }
            str = temp;
        }
    return str;
}
