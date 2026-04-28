#include "TaskNode.h"

TaskNode::TaskNode(string title, string cat, int prio)
{
    taskTitle = title;
    category = cat;
    priority = prio;
    next = nullptr;
}