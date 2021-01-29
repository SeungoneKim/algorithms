#include <iostream>
#include <queue> // priority_queue is included in queue header file.
#include <cstring>

using namespace std;

int main(){

    priority_queue<string> words;
    priority_queue<string,vector<string,greater<string>> words1;
    priority_queue<pair<int,int>>pq;

    // Theme1 : 우선순위 큐를 위한 연산
    words.push("one");
    words.push("two");
    words.push("three");

    cout << words.size() << '\n';
    cout << words.top() << '\n';
    words.pop(); // top()과 pop()은 동시에 이루어지지 않는 다는 것을 우선순위 큐에서도 조심해야한다.

    if(words.empty()){
        cout << "pq is empty" << '\n';
    }
    else{
        cout << "Maybe not" << '\n';
    }

    // 응용1 : 2번째 인자를 기준으로 pq가 정렬하기를 원하는 상황 
    // pq는 항상 첫원소를 기준으로 오름차순으로 정렬하므로, 두번째원소와 자리를 바꾸어 pq에 넣고, 꺼내서 쓸때는 다시 뒤집는다.
    // 원소 : (2,1), (4,3), (6,5)
    pq.push({1,2});
    pq.push({3,4});
    pq.push({5,6});
    int ycor=pq.top().first;
    int xcor=pq.top().second;

    // 응용2 : 2번째 인자를 내림차순 기준으로 pq가 정렬하기를 원하는 상황
    // pq는 항상 첫원소를 기준으로 오름차순으로 정렬하므로, 두번째원소와 자리를 바꾸어 pq에 넣고, 기호를 반대로 한후, 꺼내서 쓸때는 다시 뒤집고, 부호를 바꾸어서 쓴다.
    // 원소 : {2,1}, {4,3}, {6,5}
    pq.push({-1,2});
    pq.push({-4,3});
    pq.push({-6,5});
    int ycor= -pq.top().first;
    int xcor= pq.top().second;


    return 0;
}