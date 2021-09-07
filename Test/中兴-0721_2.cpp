#include <iostream>
#include <vector>

using namespace std;

int dev_num, task_num;
int max_time = 0;
int dev_list[1000] = {0};
int task_list[1000][3] = {0,0,0};

int findTask() // 返回最优先任务的索引
{
    int idx = -1;
    int high_priority = 1000;
    int high_priority_time = 0;
    for(int i(0); i < task_num; ++i)
    {
        if(task_list[i][2] == 0)
        {
            if(task_list[i][1] < high_priority)
            {
                idx = i;
                high_priority = task_list[i][1];
                high_priority_time = task_list[i][0];
            }
            else if(task_list[i][1] == high_priority)
            {
                idx = task_list[i][0] > high_priority_time ? i : idx;
                high_priority_time = task_list[idx][0];
            } 
        }
    }
    return idx;
}

int findDev() // 返回最短任务时间设备的索引
{
    int idx = 0;
    int short_time = 9999999;
    for(int i(0); i < dev_num; ++i)
    {
        if(dev_list[i] < short_time)
        {
            short_time = dev_list[i];
            idx = i;
        }
    }
    return idx;
}

int findMaxTime() // 返回最长的任务时间
{
    int maxTime = 0;
    for(int i(0); i < dev_num; ++i)
    {
        maxTime = dev_list[i] > maxTime ? dev_list[i] : maxTime;
    }
    return maxTime;
}

int main()
{
    int tasks_have_done = 0;
    int max_time = 0;
    cin >> dev_num >> task_num;
    for(int i(0); i < task_num; ++i)
    {
        cin >> task_list[i][0] >> task_list[i][1];
    }
    if(dev_num >= task_num)
    {
        for(int i(0); i < task_num; ++i)
        {
            max_time = max(task_list[i][0], max_time);
        }
    }
    else
    {
        for(int i(0); i < dev_num; ++i)
        {
            int idx = findTask();
            task_list[idx][2] = 1;
            dev_list[i] = task_list[idx][0];
        }
        tasks_have_done = dev_num;
        while(tasks_have_done < task_num)
        {
            int idx_task = findTask();
            int idx_dev = findDev();
            dev_list[idx_dev] += task_list[idx_task][0];
            task_list[idx_task][2] = 1;
            tasks_have_done ++;
        }
        max_time = findMaxTime();
    }
    cout << max_time << endl;
    return 0;
}