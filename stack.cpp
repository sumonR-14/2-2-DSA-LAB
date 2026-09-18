#include<bits/stdc++.h>
using namespace std;

vector<int> st;

// Push
void pushElement()
{
    int n, value;

    cout << "How many elements do you want to push: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";

    for(int i = 0; i < n; i++)
    {
        cin >> value;
        st.push_back(value);
    }
}

// Pop
void popElement()
{
    if(st.empty())
    {
        cout << "Stack is empty." << endl;
        return;
    }

    cout << st.back() << " removed from stack." << endl;

    st.pop_back();
}

// Peek
void peek()
{
    if(st.empty())
    {
        cout << "Stack is empty." << endl;
        return;
    }

    cout << "Top element: " << st.back() << endl;
}

// Display
void display()
{
    if(st.empty())
    {
        cout << "Stack is empty." << endl;
        return;
    }

    cout << "Stack: ";

    for(int i = st.size() - 1; i >= 0; i--)
    {
        cout << st[i] << " ";
    }

    cout << endl;
}

// Check Empty
void isEmpty()
{
    if(st.empty())
        cout << "Stack is empty." << endl;
    else
        cout << "Stack is not empty." << endl;
}


int main()
{
    int choice;

    while(true)
    {
        cout << "\n----- Stack Menu -----" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display Stack" << endl;
        cout << "5. Check Empty" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                pushElement();
                display();
                break;

            case 2:
                popElement();
                display();
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
                cout << "Program ended." << endl;
                return 0;

            default:
                cout << "Invalid choice." << endl;
        }
    }

    return 0;
}