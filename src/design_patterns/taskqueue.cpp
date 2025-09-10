#include <iostream>
#include <queue>
#include <mutex>
#include <thread>
using namespace std;

class TaskQueue
{
public:
    // = delete 代表函数禁用, 也可以将其访问权限设置为私有
    TaskQueue(const TaskQueue& obj) = delete;
    TaskQueue& operator=(const TaskQueue& obj) = delete;
    static TaskQueue* getInstance()
    {
        return &m_obj;
    }
    // 任务队列是否为空
    bool isEmpty()
    {
        lock_guard<mutex> locker(m_mutex);
        bool flag = m_taskQ.empty();
        return flag;
    }
    // 添加任务
    void addTask(int data)
    {
        lock_guard<mutex> locker(m_mutex);
        m_taskQ.push(data);
    }
    // 取出一个任务
    int takeTask()
    {
        lock_guard<mutex> locker(m_mutex);
        if (!m_taskQ.empty())
        {
            return m_taskQ.front();
        }
        return -1;
    }
    // 删除一个任务
    bool popTask()
    {
        lock_guard<mutex> locker(m_mutex);
        if (!m_taskQ.empty())
        {
            m_taskQ.pop();
            return true;
        }
        return false;
    }
private:
    TaskQueue() = default;
    static TaskQueue m_obj;
    queue<int> m_taskQ;
    mutex m_mutex;
};
TaskQueue TaskQueue::m_obj;
