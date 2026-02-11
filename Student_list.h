#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H

#include<bits/stdc++.h>

struct Cnode; // Forward declaration

struct Snode
{
    int St_Num;
    Snode *SNext;
};
void Add_Student_To_Course(int Course_ID, int St_ID);
bool Search_Student_In_Course(int Course_ID, int St_ID);
void Delete_Student_From_Course(int Course_ID, int St_ID);
void Display_Students_In_Course(int Course_ID);

#endif