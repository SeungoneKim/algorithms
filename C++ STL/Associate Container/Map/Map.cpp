#include <iostream>
#include <map>
#include <cstring>

using namespace std;

class Name{
private:
    string firstname{};
    string secondname{};

public:
    Name(string first, string second) : firstname{first},secondname{second}{};
    Name()=default;

    bool operator<(const Name& name){
        return secondname < name.secondname || ((secondname==name.secondname) && (firstname<name.secondname));
    }
};

int main(){
    map<char,int> m;
    map<char,int>::iterator it; // iterator for map
    map<string,size_t>people{ {"Ann",25}, {"Bill",46}, {"Jack",32}, {"Jill",32} }; // {}를 사용하면 암묵적으로 make_pair로 변환한다.

    /* Theme 1 : inserting a element in the map */
    
    m['B'] = 2;                        //m : (B,2)
    m.insert(make_pair('A',1));        //m : (A,1) (B,2)
    m['C'] = 3;                        //m : (A,1) (B,2) (C,3)

    people["Jack"]=57;                 //people : (Ann,25), (Bill,46), (Jack,32), (Jill,32), (Jack,57)
    auto pr=make_pair("Fred",22);
    auto pr = people.insert(pr);       // insert()는 pair<iterator, bool>을 반환한다. 
                                       // 삽입에 성공하면 삽입된 원소를 가리키는 반복자를, 삽입에 실패하면 삽입을 방해한 원소를 가리키는 반복자를 반환하며, bool은 삽입 성공 여부를 나타낸다.

    /* Theme 2 : referencing to the members of a map */
    
    //m전체를 순회하며 key와 value 출력
    for(it = m.begin(); it != m.end(); it++){
        cout << it->first << ' ' << it->second << '\n';
    }
    
    // enhanced for문을 이용하여 반복자를 쓰지 않고, 멤버에 접근하여 key와 value를 출력
    for(const auto& p : people){
        cout << p.first << ' ' << p.second << '\n';
    }

    auto ret_pr = people.insert(make_pair("Bill",46));
    if(!ret_pr.second){
        ret_pr.first->second = 48; // 반복자를 이용해서 기존 멤버에 접근하여 value를 바꾸기
    }

    // count()를 통해서 해당 키를 가지고 있는 원소 개수를 반환하도록 하여서(0 or 1), map에 insert를 할 수 있는지 확인하고 insert하는 것이 좋다
    if(people.count("Ian")){
        people.insert({"Ian",38});
    }

    // find()를 통해서 해당 원소를 가리키는 반복자를 반환하게 한 뒤, map의 end()를 가리키는지 여부로 해당 원소가 존재하는지 확인 할 수 있다.
    if(m.find('B') != m.end()) // key가 k인 노드가 존재하지 않는 경우, m의 마지막 원소를 가리키는 iterator 리턴
        cout << "key값이 B인 노드가 존재합니다." << '\n';
    else
        cout << "key값이 B인 노드가 존재하지 않습니다." << '\n';

    // at()를 통해서 map의 멤버에 접근하여서 해당 키를 가진 멤버가 존재하지 않으면 예외를 던지도록 할 수 있다.
    try{
        string key="Brandon";
        auto value =people.at(key);
        cout << key << ' ' << "is aged" << value << '\n';
    }
    catch(const out_of_range e){
        cout >> "not found" << '\n';
    }

    // []를 사용할 때, map에 해당 원소가 없다면 새로 삽입되지만, 기존에 존재한다면 value가 변한다.
    people["Jack"]=33;


    /* Theme 3 : Deleting an element from the map*/

    m.erase('A');                      //m : (B,2) (C,3)
    auto howmany= m.erase('A');         // 삭제되는 원소의 수를 반환한다. (map에서는 키가 유일하므로 0 or 1)

    m.clear(); // m의 모든 원소를 삭제한다.

    return 0;
}