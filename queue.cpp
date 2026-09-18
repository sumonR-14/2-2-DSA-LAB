#include<bits/stdc++.h>
using namespace std;

vector<int> q;
void display(){
    if(q.empty()){
        cout<<"Queue is empty." <<endl;
        return;
    }
    for(int x: q){
        cout<<x <<" " ;
    }
    cout<<endl;
}

void enqueue(){
    int n, value;

    cout << "How many elements do you want to enqueue: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";

    for(int i = 0; i < n; i++)
    {
        cin >> value;
        q.push_back(value);
    }
}

void dequeue(){
    if(q.empty()){
        cout<<"Queue is empty." <<endl;
        return;
    }
    cout<<q.front()<<"Removed from queue"<<endl;
    q.erase(q.begin());

    display();
}

void peek(){
    if(q.empty()){
        cout<<"Queue is empty." <<endl;
        return;
    }

    cout<<"Front element" <<q.front() <<endl;
}

void isEmpty(){
    if(q.empty()){
        cout<<"Queue is empty." <<endl;
    }
    else{
        cout<<"Queue is not empty." <<endl;
    }
}
int main() {
     int choice;
     int value;

    while(true)
    {
        cout << "\n===== QUEUE MENU =====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display Queue" << endl;
        cout << "5. Check Empty" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                // cout << "Enter value: ";
                // cin >> value;

                enqueue();
                display();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                isEmpty();
                break;

            case 6:
                cout << "Program terminated." << endl;
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}