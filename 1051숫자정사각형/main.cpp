#include <iostream>
#define MAX 50
using namespace std;
int ans = 1;
int Arr[MAX][MAX];
int r; int c;

void input(){
    cin>>r; cin>>c;
    char temp;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>temp;
            Arr[i][j] = temp-'0';
        }
    }
}

bool range(int i,int j){
    return i >= 0 && i < r && j >= 0 && j < c;
}


int main(){
    input();
    int ci; int cj;

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            ci=1+i; cj=1+j;

            while(range(ci,cj)){
                if(Arr[i][j]==Arr[i][cj] && Arr[i][j]==Arr[ci][j] && Arr[i][j]==Arr[ci][cj])
                    ans = max(ans,ci-i+1);
                
                ++ci; ++cj;
            }
        }
    }
    cout<<ans*ans;
    return 0;
}
