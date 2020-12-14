#include <iostream>
#include <vector>
#define MAX 5
using namespace std;
int fw[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int temp = 0;
char Arr[MAX][MAX];
vector<pair<int,int>> coord;
bool Select[MAX][MAX];
int answer = 0;

void input(){
    for(int i=0; i<MAX; i++)
        for(int j=0; j<MAX; j++)
            cin>>Arr[i][j];
}

bool adjancy(vector<pair<int,int>> coord){
    int flag =0;
    for(int i = 0; i<coord.size(); i++){ //조합 480700개 중 s가 4개이상인 애들 중 1개
        for(int j=0; j<4; j++){  //상하좌우
            if (coord[i].first+fw[j][0] >= 0 && coord[i].second+fw[j][1] >= 0 && coord[i].first+fw[j][0] < 5 && coord[i].second+fw[j][1] < 5){
                if(Select[coord[i].first+fw[j][0]][coord[i].second+fw[j][1]] == true){    //방문한게 true였다고 하면
                    flag++;
                    break;
                }
            }
        }
    }

    if(flag==7){
        for(int i=0; i<coord.size(); i++){
            cout<<"coord[i].first: "<<coord[i].first<<" "<<"coord[i].second: "<<coord[i].second<<"\n";
        }
        cout<<"\n";
    }
    
    if(flag==7) return true;
    else return false;
}

//cout<<"coord[i].first: "<<coord[i].first<<" "<<"coord[i].second: "<<coord[i].second<<"\n";
bool morethanfour(vector<pair<int,int>> coord){
    int scnt = 0;
    for(int i=0; i<coord.size(); i++)
        if(Arr[coord[i].first][coord[i].second]=='S')   scnt++;
    if(scnt>=4){
        if(adjancy(coord)==true)
            return true;
    }
    return false;
}

void DFS(int Idx, int Cnt){
    if (Cnt == 7){ //25개 중 7개의 조합
        coord.clear();
        for (int i = 0; i < MAX*MAX; i++){
                if(Select[i/MAX][i%MAX]==true)
                    coord.push_back(make_pair(i/MAX,i%MAX));
        }
        
        if(morethanfour(coord)==true)
                answer++;
        return;
    }
    
    for (int i = Idx; i < MAX*MAX; i++){
            if(Select[i/MAX][i%MAX] == true) continue;
            Select[i/MAX][i%MAX] = true;
            DFS(i, Cnt + 1);
            Select[i/MAX][i%MAX] = false;
    }
}



int main(void){
    input();
    DFS(0, 0);
    cout<<answer<<"\n";
}