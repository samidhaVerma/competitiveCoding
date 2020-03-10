#include <bits/stdc++.h>
using namespace std;

queue<int> readData(int n){
    queue<int> trucks;
    int temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        trucks.push(temp);
    }

    return trucks;
}

bool checkOrder(queue<int> orderedQueue){
    int counter = 1;
    while(!orderedQueue.empty()){
        if(orderedQueue.front() != counter++)
            return false;
        orderedQueue.pop();
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    while(n != 0){
        queue<int> trucks = readData(n);
        stack<int> sideRoad;
        queue<int> orderedTrucks;

        int counter = 1;
        while(!trucks.empty()){
            if(trucks.front() == counter){
                orderedTrucks.push(trucks.front());
                trucks.pop();
                counter++;
            }else if(!sideRoad.empty() && sideRoad.top() == counter){
                orderedTrucks.push(sideRoad.top());
                sideRoad.pop();
                counter++;
            }else{
                sideRoad.push(trucks.front());
                trucks.pop();
            }
        }

        while(!sideRoad.empty()){
            orderedTrucks.push(sideRoad.top());
            sideRoad.pop();
        }

        if(checkOrder(orderedTrucks))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
        
        cin >> n;
    }

    return 0;
}