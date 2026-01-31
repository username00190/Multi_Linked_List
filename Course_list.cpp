#pragma once
#include<bits/stdc++.h>
#include "Student_list.cpp"
void Display_Students_In_Course(int Course_ID);
using namespace std;
struct Snode;
struct Cnode
{
     int C_Num;
     Cnode *CNext;
     Snode *St_List;
};
Cnode *Head_course = NULL;

void AddCourse(int Course_ID)
{
    Cnode *Ctemp = new Cnode;
    Ctemp -> CNext =NULL;
    Ctemp -> St_List =NULL;
    Ctemp -> C_Num =Course_ID;

    if(Head_course == NULL)
    {
        Head_course = Ctemp;
    }

    else
    {
        Cnode *Curr_course = Head_course;
        while(Curr_course -> CNext != NULL)
        {
            Curr_course = Curr_course -> CNext;
        }
        Curr_course -> CNext = Ctemp;
    }
}

void DellCourse(int Course_ID)
{
    if(Head_course -> C_Num == Course_ID)
    {
        Cnode * temp_course = Head_course;
        Head_course = Head_course -> CNext;
        delete temp_course;
        cout<<"Course Deleted Successfully \n";
    }

    else
    {
        Cnode *Curr_course = Head_course;
        Cnode *Prev_course = NULL;
        while(Curr_course != NULL)
        {
            if(Curr_course -> C_Num == Course_ID)
            {
                Prev_course -> CNext = Curr_course -> CNext;
                delete Curr_course;
                cout<<"Course Deleted Successfully \n";
                return;
            }
            Prev_course = Curr_course;
            Curr_course = Curr_course -> CNext;
        }
        cout<<"The Course with this ID does not Exist \n";
    }

}

bool SearchCourse(int Course_ID)
{
    if(Head_course == NULL)
    {
        return false;
    }

    else
    {
        Cnode *Curr_course = Head_course;
        while(Curr_course != NULL)
        {
            if(Curr_course -> C_Num== Course_ID)
            {
                return true;
            }
            Curr_course = Curr_course -> CNext;
        }
        return false;
    }
}

void DisplayCourses()
{
    if(Head_course == NULL)
    {
        cout<<"No Courses Available \n";
        return;
    }

    Cnode *Curr_course = Head_course;
    cout<<"The Available Courses are : \n";
    while(Curr_course != NULL)
    {
        cout<<"  Course No. "<<Curr_course -> C_Num<<"\n";
        Curr_course = Curr_course -> CNext;
    }
}

void DisplayCourse_With_Students()
{
        if(Head_course == NULL)
    {
        cout<<"No Courses Available \n";
        return;
    }

    Cnode *Curr_course = Head_course;
    cout<<"The Available Courses are : \n";
    while(Curr_course != NULL)
    {
        cout<<"  Course No. "<<Curr_course -> C_Num<<"\n";

        if(Curr_course -> St_List != NULL)
        {
            Display_Students_In_Course(Curr_course -> C_Num);
            cout<<endl;
        }
        else
        {
            cout<<"! No Students Yet ! \n";
        }

        Curr_course = Curr_course -> CNext;
    }
}
