#include <iostream>
#include <fstream>
#include <Heap.h>
#include <Task.h>

using namespace std;

ostream& operator<<(ostream& os, Task& dt)
{
    os << dt.getName() << " " << dt.getProirty() <<endl;
    return os;
}

int main()
{
    Heap<Task> heap;
    fstream my_file;
    my_file.open("tasks.txt");
    string data = "";
    int p = 0;
    while(my_file >> data)
    {
        Task task;
        task.setName(data);
        my_file >> p;
        task.setProirty(p);
        heap.add(task);
    }
    while(true)
    {
        cout<<"1-Search by name"<<endl;
        cout<<"2-Print"<<endl;
        cout<<"3-Get top"<<endl;
        cout<<"4-Exit"<<endl;
        int c;
        cin>>c;
        Task temp;
        if(c == 1)
        {
            string x;
            cin>>x;
            temp = heap.Search(x);
            cout<<temp;
        }
        else if(c == 2)
        {
            Task* arr = heap.heapSort();
            for(int i = 0; i < heap.getCurrentSize(); i++)
                cout<<arr[i];
        }
        else if(c == 3)
        {
            temp = heap.removeRoot();
            cout<<temp;
        }
        else if(c == 4)
            break;
        else
            cout<<"wrong choice"<<endl;
    }
    return 0;
}
