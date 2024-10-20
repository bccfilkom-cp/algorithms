sing namespace std; 

vector<int> parent(100001);
vector<int> rankSet(100001, 0); 

int representasi(int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = representasi(parent[x]); 
}

void join(int a, int b){
    int kiri = representasi(a); 
    int kanan = representasi(b); 

    if(kiri != kanan) { 
        if(rankSet[kiri] < rankSet[kanan]) {
            parent[kiri] = kanan;
        } else if(rankSet[kiri] > rankSet[kanan]) {
            parent[kanan] = kiri;
        } else {
            parent[kiri] = kanan;
            rankSet[kanan]++;
        }
    }
}

bool check(int a, int b){
    return representasi(a) == representasi(b); 
}

int main(){
    int n; cin>>n;

    for(int i=0; i<=100000; i++){
        parent[i] = i;
    }

    int t; cin>>t; 

    while(t--){
        int c, a, b;
        cin>>c>>a>>b;
        
        if(c==1){
            join(a, b); 
        }else{
            if(check(a, b)) cout<<"Y"<<endl;
            else{
                cout<<"T"<<endl; 
            }
        }
    }
}