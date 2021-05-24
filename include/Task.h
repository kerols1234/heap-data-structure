#ifndef TASK_H
#define TASK_H
#include <iostream>

using namespace std;

class Task
{
    public:
        Task(){};
        Task(int x, string y)
        {
            name = y;
            proirty = x;
        };
        int getProirty()
        {
            return proirty;
        };
        void setProirty(int x)
        {
            proirty = x;
        };
        string getName()
        {
            return name;
        };
        void setName(string x)
        {
            name = x;
        };
        bool operator < (const Task &obj)
        {
             return (proirty < obj.proirty);
        };
        bool operator > (const Task &obj)
        {
             return (proirty > obj.proirty);
        };
        bool operator <= (const Task &obj)
        {
             return (proirty <= obj.proirty);
        };
        bool operator >= (const Task &obj)
        {
             return (proirty >= obj.proirty);
        };
        bool operator == (const Task &obj)
        {
             return (proirty == obj.proirty);
        };
        bool operator == (const string nam)
        {
             return (name == nam);
        };
        friend ostream& operator<<(ostream& os,Task& dt);
    private:
        string name;
        int proirty;
};

#endif // TASK_H
