#include <bits/stdc++.h>
#include "Student_list.h"
#include "Course_list.h"

using namespace std;

// struct Snode
// {
//     int St_Num;
//     Snode *SNext;
// };
Snode *Head_student = NULL;



void Add_Student_To_Course(int Course_ID,int St_ID)
{
    Snode *Stemp = new Snode;
    Stemp -> SNext = NULL;
    Stemp -> St_Num = St_ID;

    if(!(SearchCourse(Course_ID)))
    {
        cout<<"The Course does not exist \n";
        return;
    }
    else if(Search_Student_In_Course(Course_ID,St_ID))
    {
        cout<<"Student is already enrolled in this course. \n";
        return;
    }

    Cnode *Curr_course = Head_course;

    while(Curr_course != NULL)
    {
        if(Course_ID == Curr_course -> C_Num)
        {
            if(Curr_course->St_List == NULL)
                Curr_course -> St_List = Stemp;
            else
            {
                Snode *S_curr = Curr_course->St_List;
                while(S_curr -> SNext !=NULL)
                {
                    S_curr = S_curr -> SNext;
                }
                S_curr -> SNext = Stemp;
            }

            cout<<"Student Added to Course "<< Curr_course -> C_Num<<" Successfully \n";
            return;
        }
        Curr_course = Curr_course -> CNext;
    }
    cout<<"Course not found to add student\n";
}

bool Search_Student_In_Course(int Course_ID, int St_ID)
{
    if(!(SearchCourse(Course_ID)))
    {
        cout<<"There is no Course by this ID \n";
        return false;
    }
    else
    {
        Cnode *Curr_course = Head_course;
        while(Curr_course != NULL)
        {
            if(Curr_course -> C_Num == Course_ID)
            {
                break;
            }
            Curr_course = Curr_course -> CNext; 
        }

        Snode *Curr_st = Curr_course -> St_List;
        while(Curr_st != NULL)
        {
            if(Curr_st -> St_Num == St_ID)
            {
                cout<<"Student was found in course "<<Curr_course -> C_Num<<endl;
                return true;
            }
            Curr_st = Curr_st ->SNext;
        }
    }
    return false;
}

void Delete_Student_From_Course(int Course_ID, int St_ID)
{
    if(!(Search_Student_In_Course(Course_ID, St_ID)))
    {
        cout<<"The student is not enrolled in this course. \n";
        return;
    }

    else
    {

        Cnode *Curr_course = Head_course;
        while(Curr_course != NULL)
        {
            if(Curr_course -> C_Num == Course_ID)
            {
                break;
            }
            Curr_course = Curr_course -> CNext; 
        }  

        if(Curr_course -> St_List -> St_Num == St_ID)
        {
            Snode *temporary = Curr_course -> St_List;
            cout<<"Student "<<Curr_course -> St_List -> St_Num<<" was successfully deleted from course "<<Curr_course -> C_Num<<".\n";
            Curr_course -> St_List = Curr_course -> St_List -> SNext;
            delete temporary;
            return;
        }

        Snode *Curr_st = Curr_course -> St_List;
        Snode *prev_st = NULL;
        while(Curr_st != NULL)
        {
            if(Curr_st -> St_Num == St_ID)
            {
                prev_st -> SNext = Curr_st -> SNext;
                cout<<"Student "<< Curr_st -> St_Num<<" was successfully deleted from course "<<Curr_course -> C_Num<<".\n";
                delete Curr_st;
                return;
            }
            prev_st = Curr_st;
            Curr_st = Curr_st ->SNext;
        }
        
    }
}

void Display_Students_In_Course(int Course_ID)
{
    if(!SearchCourse(Course_ID))
    {
        cout<<"The Course does not exist \n";
        return;
    }

    Cnode *Curr_course = Head_course;

    while(Curr_course != NULL)
    {
        if(Course_ID == Curr_course -> C_Num)
        {
            Snode *S_curr = Curr_course->St_List;
            if(S_curr == NULL)
            {
                cout<<"---> ";
                cout<<"No Students Enrolled in Course "<<Course_ID<<"\n";
                return;
            }

            cout<<"Students Enrolled in Course "<<Course_ID<<" are : \n";
            cout<<"---> ";
            while(S_curr != NULL)
            {
                cout<<"  Student ID: "<<S_curr -> St_Num;
                S_curr = S_curr -> SNext;
            }
            cout<<"\n";
            return;
        }
        Curr_course = Curr_course -> CNext;
    }
}
