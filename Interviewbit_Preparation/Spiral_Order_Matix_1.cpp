vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    vector<int> v,s;
    int m,n,a,b,c=1;
    m = A.capacity();
    n = A[0].capacity();
    a= 0;
    b =-1;
    while((m > 0) && (n>0)  ){
        v.push_back(n);
        m = m - 1;
        v.push_back(m);
        n = n-1;
    }
    for(auto t: v){
        for(int i=0;i<t;i++){
            if(c == 1){
                b += 1;
                s.push_back(A[a][b]);
            }
            else if(c == 2){
                a += 1;
                s.push_back(A[a][b]);
            }
            else if(c == 3){
                b -= 1;
                s.push_back(A[a][b]);
            }
            else if(c == 4){
                a -= 1;
                s.push_back(A[a][b]);
            }
        }
        c +=1;
        c = c > 4?c%4:c;
    }
    return s;
    
}