#include <mutex>
#include <atomic>
#include <iostream>

namespace singleton {

// 定义一个单例模式的类
class Singleton
{
public:
    // = delete 代表函数禁用, 也可以将其访问权限设置为私有
    Singleton(const Singleton& obj) = delete;
    Singleton& operator=(const Singleton& obj) = delete;
    static Singleton* getInstance();
private:
    Singleton() = default;
    static Singleton* m_obj;
};

// 饿汉模式
class TaskQueue
{
public:
    // = delete 代表函数禁用, 也可以将其访问权限设置为私有
    TaskQueue(const TaskQueue& obj) = delete;
    TaskQueue& operator=(const TaskQueue& obj) = delete;
    static TaskQueue* getInstance()
    {
        return m_taskQ;
    }
private:
    TaskQueue() = default;
    static TaskQueue* m_taskQ;
};
// 静态成员初始化放到类外部处理
TaskQueue* TaskQueue::m_taskQ = new TaskQueue;

// 懒汉模式
class TaskLazyQueue
{
public:
    // = delete 代表函数禁用, 也可以将其访问权限设置为私有
    TaskLazyQueue(const TaskLazyQueue& obj) = delete;
    TaskLazyQueue& operator=(const TaskLazyQueue& obj) = delete;
    static TaskLazyQueue* getInstance()
    {
        if(m_taskQ == nullptr)
        {
            m_taskQ = new TaskLazyQueue;
        }
        return m_taskQ;
    }
private:
    TaskLazyQueue() = default;
    static TaskLazyQueue* m_taskQ;
};
TaskLazyQueue* TaskLazyQueue::m_taskQ = nullptr;

// 解决懒汉模式的线程安全问题
class TaskMutexQueue
{
public:
    // = delete 代表函数禁用, 也可以将其访问权限设置为私有
    TaskMutexQueue(const TaskMutexQueue& obj) = delete;
    TaskMutexQueue& operator=(const TaskMutexQueue& obj) = delete;
    static TaskMutexQueue* getInstance()
    {
        m_mutex.lock();
        if (m_taskQ == nullptr)
        {
            m_taskQ = new TaskMutexQueue;
        }
        m_mutex.unlock();
        return m_taskQ;
    }
private:
    TaskMutexQueue() = default;
    static TaskMutexQueue* m_taskQ;
    static std::mutex m_mutex;
};
TaskMutexQueue* TaskMutexQueue::m_taskQ = nullptr;
std::mutex TaskMutexQueue::m_mutex;


// 双重检查锁定
class TaskDoubleCheckQueue
{
public:
    // = delete 代表函数禁用, 也可以将其访问权限设置为私有
    TaskDoubleCheckQueue(const TaskDoubleCheckQueue& obj) = delete;
    TaskDoubleCheckQueue& operator=(const TaskDoubleCheckQueue& obj) = delete;
    static TaskDoubleCheckQueue* getInstance()
    {
        if (m_taskQ == nullptr)
        {
            md_mutex.lock();
            if (m_taskQ == nullptr)
            {
                m_taskQ = new TaskDoubleCheckQueue;
            }
            md_mutex.unlock();
        }
        return m_taskQ;
    }
private:
    TaskDoubleCheckQueue() = default;
    static TaskDoubleCheckQueue* m_taskQ;
    static std::mutex md_mutex;
};
TaskDoubleCheckQueue* TaskDoubleCheckQueue::m_taskQ = nullptr;
std::mutex TaskDoubleCheckQueue::md_mutex;


// 使用atomic
class TaskAtomicQueue
{
public:
    // = delete 代表函数禁用, 也可以将其访问权限设置为私有
    TaskAtomicQueue(const TaskAtomicQueue& obj) = delete;
    TaskAtomicQueue& operator=(const TaskAtomicQueue& obj) = delete;
    static TaskAtomicQueue* getInstance()
    {
        TaskAtomicQueue* queue = m_taskQ.load();  
        if (queue == nullptr)
        {
            // m_mutex.lock();  // 加锁: 方式1
            std::lock_guard<std::mutex> locker(ma_mutex);  // 加锁: 方式2
            queue = m_taskQ.load();
            if (queue == nullptr)
            {
                queue = new TaskAtomicQueue;
                m_taskQ.store(queue);
            }
            // m_mutex.unlock();
        }
        return queue;
    }

    void print()
    {
        std::cout << "TaskAtomicQueue: hello, world!!!" << std::endl;
    }
private:
    TaskAtomicQueue() = default;
    static std::atomic<TaskAtomicQueue*> m_taskQ;
    static std::mutex ma_mutex;
};
std::atomic<TaskAtomicQueue*> TaskAtomicQueue::m_taskQ;
std::mutex TaskAtomicQueue::ma_mutex;

// 使用静态局部变量
class TaskStaticQueue
{
public:
    // = delete 代表函数禁用, 也可以将其访问权限设置为私有
    TaskStaticQueue(const TaskStaticQueue& obj) = delete;
    TaskStaticQueue& operator=(const TaskStaticQueue& obj) = delete;
    static TaskStaticQueue* getInstance()
    {
        static TaskStaticQueue taskQ;
        return &taskQ;
    }
    void print()
    {
        std::cout << "TaskStaticQueue: hello, world!!!" << std::endl;
    }

private:
    TaskStaticQueue() = default;
};

} // namespace singleton




