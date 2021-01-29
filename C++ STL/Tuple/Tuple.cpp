#include <iostream>
#include <cstring>
#include <map>
#include <utility>
#include <tuple>

using namespace std;

int main(){

    pair<string,string> my_pair={"test1","test2"}; // {}를 이용해서 pair 객체 생성하기
    auto my_pair1 = make_pair(4,5);                // make_pair()를 이용해서 pair 객체 생성하기
    auto my_pair2 = make_pair(4,7);
    auto my_pair3 = make_pair(5,7);
    tuple<int, int, int, int> t1=make_tuple(1,2,3,4); // tuple객체는 {}가 아니라 make_tuple()를 이용해서만 생성할 수 있다
    tuple<int, int, string, char> t2=make_tuple(5,6,"seungone",'a');

    /* Theme 1 : pair 멤버에 접근하기 */

    cout << my_pair1.first << ' ' << my_pair1.second << '\n';

    // pair객체가 비교될 때는 첫 멤버를 비교하고, 같다면 두번째 멤버를 비교한다.
    if(my_pair1<my_pair2){
        cout << "my pair 2 is bigger" << '\n';
    }
    else{
        cout << "maybe not" << '\n';
    }

    /* Theme 2 : tuple 멤버에 접근하기 */
    //get는 1대1대응, tie는 다대다대응(단, ignore를 통해 선택가능)

    cout << get<0>(t1) << ' ' << get<1>(t1) << ' ' << get<2>(t1) << ' ' << get<3>(t1) << '\n';

    int a1,a2,a3,a4;
    tie(a1,a2,a3,a4) = t1;
    cout << a1 << ' ' << a2 << ' ' << a3 << ' ' << a4 << '\n';

    return 0;
}