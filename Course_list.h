#ifndef COURSE_LIST_H
#define COURSE_LIST_H

#include<bits/stdc++.h>

struct Snode; // Forward declaration

struct Cnode
{
    int C_Num;
    Cnode *CNext;
    Snode *St_List;
};
extern Cnode *Head_course;
void AddCourse(int Course_ID);
void DellCourse(int Course_ID);
bool SearchCourse(int Course_ID);
void DisplayCourses();
void DisplayCourse_With_Students();

#endif