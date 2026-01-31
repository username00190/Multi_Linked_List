#include "Student_list.cpp"
#include "Course_list.cpp"
#include <bits/stdc++.h>

using namespace std;

int main()
{
     cout<<"Welcom to Karachi University's Course registration \n";
     bool flag = false;
     int action;
     while(!flag)
    {
        cout<<"Enter the Number corrospoding to the action you want to perform. \n 1 for adding a course, 2 for searching a course, 3 for deleting a course,\n 4 for dispaying course list, 5 for adding a student to a course,\n  6 for Searching a student in a course, 7 for Deleting a student from a Course,\n 8 for displaying students in a course, 9 for Displaying Courses with Students \n and 10 for exiting : ";
        cin>>action;

        switch(action)
        {
            case 1:
                int course_num;
                cout<<"Enter the Course Number you want to add : ";
                cin>>course_num;
                AddCourse(course_num);
                cout<<"Course Added Successfully \n";

            break;
            
            case 2:
                int search_course_num;
                cout<<"Enter the Course Number you want to search : ";
                cin>>search_course_num;
                if(SearchCourse(search_course_num))
                {
                    cout<<"Course Found \n";
                }
                else
                {
                    cout<<"Course Not Found \n";
                }
                break;

            case 3:
                int del_course_num;
                cout<<"Enter the Course Number you want to delete : ";
                cin>>del_course_num;
                DellCourse(del_course_num);
                

            break;

            case 4:
                DisplayCourses();
            break;

            case 5:
                int course_number;
                int st_id;
                cout<<"Enter the Course Number you want to add student to : ";
                cin>>course_number;
                cout<<"Enter the Student ID you want to add to the course : ";
                cin>>st_id;
                Add_Student_To_Course(course_number, st_id);
            break;

            case 6:
                int course_number_search;
                int st_id_search;
                cout<<"Enter the Course Number you want to search student in : ";
                cin>>course_number_search;
                cout<<"Enter the Student ID you want to search in the course : ";
                cin>>st_id_search;
                if(Search_Student_In_Course(course_number_search, st_id_search))
                {
                    cout<<"Student Found in Course \n";
                }
                else
                {
                    cout<<"Student Not Found in Course \n";
                }
                
            break;

            case 7:
                int course_number_del;
                int st_id_del;
                cout<<"Enter the Course Number you want to delete student from : ";
                cin>>course_number_del;
                cout<<"Enter the Student ID you want to delete from the course : ";
                cin>>st_id_del;
                Delete_Student_From_Course(course_number_del, st_id_del);
            break;

            case 8:
                int course_number_display;
                cout<<"Enter the Course Number you want to display students from : ";
                cin>>course_number_display;
                Display_Students_In_Course(course_number_display);
            break;

            case 9:
                DisplayCourse_With_Students();
            break;
            
            default:
                cout<<"Program Exited Successfully. \n";
                return 0;
            break;
            
        }
    }
    return 0;
}