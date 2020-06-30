#include <iostream>
#include <vector>
#include <thread>

using namespace std;

/*
 * 适用情况：
 *      一个生产者，多个消费者;
 *      并且生产者的生产速度需要远快于消费者的消费速度;
 *      并且各个消费者的消费速度基本相同。
 * 实现原理：生产者将任务依次分派给各个消费者。
 */

class Task
{
public:
    Task()
    {
        m_queueHead = 0;
        m_queueRear = 0;
        m_stopFlag = false;
    }

    bool stop()
    {
        return m_stopFlag && (m_queueHead == m_queueRear);
    }

    bool setTask(int task)
    {
        if (m_queueHead == (m_queueRear + 1) % 16)
            return false;
        m_taskQueue[m_queueRear++] = task;
        m_queueRear %= 16;
        return true;
    }

    bool getTask(int & task)
    {
        if (m_queueHead == m_queueRear)
            return false;
        task = m_taskQueue[m_queueHead++];
        m_queueHead %= 16;
        return true;
    }
    
public:
    int m_taskQueue[16];
    unsigned int m_queueHead;
    unsigned int m_queueRear;
    bool m_stopFlag;
};

class Worker
{
public:
    Worker() { }
 
public:
    void operator() (Task & task)
    {
        while (!task.stop())
        {
            int job;
            if (!task.getTask(job))
                continue;
            std::cout << "worker: " << m_index << ", task: " << job << std::endl;
        }
    }

    void setIndex(unsigned int index)
    {
        m_index = index;
    }

private:
    unsigned int m_index;
};

class Master
{
public:
    Master()
    {
        for (unsigned int i = 0; i < 3; ++i)
            m_workers[i].setIndex(i);
        for (unsigned int i = 0; i < 3; ++i)
            m_threads.emplace_back(m_workers[i], std::ref(m_tasks[i]));
    }
    ~ Master()
    {
        for (std::thread & t: m_threads)
        {
            t.join();
        }
    }
public:

    void Start()
    {
        int num;
        int i = 0;
        while(cin >> num)
        {
            m_tasks[(i++) % 3].setTask(num);   
        } 
    }

private:
    Task m_tasks[3];
    Worker m_workers[3];
    std::vector<std::thread> m_threads;
};



int main()
{
    Master master;
    master.Start();
    return 0;
}
