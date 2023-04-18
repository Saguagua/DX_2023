#include <iostream>

template<class T>
class List
{
public:
    List<T>() : pre(nullptr), next(nullptr), iterator(*this)
    {}
    bool push_front(T value)
    {
        List<T>* list = new List<T>();

    }
    static int* iterator;
private:
    void setFrontNode(int* ptr)
    {
        this->next = ptr;
    }

    void setBackNode(int* ptr)
    {
        this->pre = ptr;
    }
    T data;
    int* pre;
    int* next;
};

int main()
{
    List<int>* list = new List<int>();


}