//
//  main.cpp
//  디스크 컨트롤러
//
//  Created by JiHyun Kim on 30/08/2020.
//  Copyright © 2020 JiHyun Kim. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int t = 0;  //cur time
queue<pair<int,int>> arr;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
//queue<pair<int,int>> pq;
int answer = 0;
bool working = false;
int waiting = 0;
vector<vector<int>> jobs = {{3,4},{4,2},{15,3}};

void solution(vector<vector<int>> jobs) {
    int st = 0;
    int et = 0;
    int at = 0;
    
    for(int i=0; i<jobs.size(); i++)
        arr.push(make_pair(jobs[i][1], jobs[i][0]));
    
    while(true){  //시간을 1초씩 증가시켜줄거임.
        
        if(arr.front().second == t){  //working중일때도 해당 시각마다 받아오는건 그대로
            pq.push(make_pair(arr.front().first, arr.front().second));
            
            arr.pop();
        }
        
        if(st+et==t){  //다 돌았으면
            answer += t-at;
            working = false;
            if (arr.empty()&&pq.empty()&&st+et==t)
                break;

        }

        if (!working && !pq.empty()) //not empty일시 추가함
        {
            /*여기서 pq해줘야함*/
            
            if(pq.top().second<=t){ //현재시각 보다 작거나 같다면 실행 가능 
                st = t;
                et = pq.top().first; at = pq.top().second;
                working = true;
                pq.pop();
            }
        }

        t++;  //시간이 1초씩 증가한다.
    }
    
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    
    solution(jobs);
    
    cout<<answer/jobs.size();

    return 0;
}
