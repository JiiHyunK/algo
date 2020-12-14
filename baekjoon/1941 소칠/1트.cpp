#include <iostream>
#include <vector>
#define MAX 5
using namespace std;

char Arr[MAX][MAX];
vector<pair<int,int>> coord;
bool Select[MAX][MAX];
int answer = 0;

void input(){
    for(int i=0; i<MAX; i++)
        for(int j=0; j<MAX; j++)
            cin>>Arr[i][j];
}

void print(int Idx){
    for (int i = Idx/MAX; i < MAX*MAX; i++){
        for (int j = Idx%MAX; j < MAX*MAX; j++)
            if(Select[i][j] == true) cout<<Arr[i][j]<<"\n";
    }
}
bool adjancy(vector<pair<int,int>> coord){

    for(int i=1; i<coord.size(); i++){
        for(int j=0; j<i; j++){
            if(coord[i-1].first-coord[j].first==1||coord[i-1].second - coord[j].second ==1){
//                cout<<"coord["<<i<<"-1].first: "<<coord[i-1].first<<" != "<<"coord["<<j<<"].first: "<<coord[j].first<<" || "<<"coord["<<i<<"-1].second: "<<coord[i-1].second<<" != "<<"coord["<<j<<"].second: "<<coord[j].second<<"\n";
                return true;
            }
        }
    }
    return false;
}
bool morethanfour(vector<pair<int,int>> coord){
    int scnt = 0;
    for(int i=0; i<coord.size(); i++)
        if(Arr[coord[i].first][coord[i].second]=='S')   scnt++;
    if(scnt>=4){
//        for(int i=0; i<coord.size(); i++)         //소칠2.txt 확인
//            cout<<"흠"<<coord[i].first<<coord[i].second<<" ";
//        cout<<"\n";
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
//        for(int i=0; i<coord.size(); i++)
//            cout<<coord[i].first<<coord[i].second<<"  ";   //소칠1.txt확인 //조합 잘 나오는거 확인 가능
//        cout<<"\n";
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
    cout<<answer;
}