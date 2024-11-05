#include <iostream>
#include <bits/stdc++.h>

class Students{
    public:
        int m_regNo;
        std::string m_name;
        float m_age;
        std::string m_parentage;
        std::string m_semester;
        int m_rollNo;
        int m_attendance;
        float m_marks[5];
        float m_total_marks;
        float m_percentage;
    
        void getDetails()
        {
            std::cout << "Enter Registration no: ";
            std::cin >> m_regNo;
            std::cout << "Enter Student name: ";
            std::cin >> m_name;
            std::cout << "Enter Student's age: ";
            std::cin >> m_age;
            std::cout << "Enter Student's Parentage: ";
            std::cin >> m_parentage;
            std::cout << "Enter Student's Semester: ";
            std::cin >> m_semester;
            std::cout << "Enter Student's Roll No: ";
            std::cin >> m_rollNo;
            std::cout << "Enter Student's Attendance: ";
            std::cin >> m_attendance;
            std::cout << "Enter Student's Subject wise marks: " << std::endl;
            for (int i = 0; i < 5; i++){
                std::cout << (i+1) << " Subject marks: ";
                std::cin >> m_marks[i];
                m_total_marks += m_marks[i];
            }
            m_percentage = (float)(m_total_marks/5.0);
            printLines();
        }

        void showDetails()
        {
            std::cout << "Registration no: " << m_regNo << std::endl;
            std::cout << "Student name: " << m_name << std::endl;
            std::cout << "Student's age: " << m_age << std::endl;
            std::cout << "Student's Parentage: " << m_parentage << std::endl;
            std::cout << "Student's Semester: " << m_semester << std::endl;
            std::cout << "Student's Roll No: " << m_rollNo << std::endl;
            std::cout << "Student's Attendance: " << m_attendance << "%" << std::endl;
            std::cout << "Student's Subject wise marks: " << std::endl;
            for (int marks: m_marks){
                std::cout << marks << "  "; 
            }
            printLines();
        }

        void showName()
        {
            std::cout << "Student's Name => " << m_name << std::endl;
            printLines();
        }

        void showRollNo()
        {
            std::cout << "Student's Roll No => " << m_rollNo << std::endl;
            printLines();
        }

        void showAttendance()
        {
            std::cout << "Student's Attendance => " << m_attendance << "%" << std::endl;
            printLines();
        }

        void printLines() 
        {
            for (int i = 0; i <= 30; i++) 
            std::cout << "-"; 
            std::cout << std::endl;
        }

        friend void showShortage(Students students[],int n);
        friend void showTop5(Students student_list[],int n);
        friend void show90(Students student_list[], int n);

};

void showShortage(Students student_list[],int n)
{
    bool flag = false;
    for (int i = 0; i < n; i++){
        if (student_list[i].m_attendance < 75){
            if (flag == false){
                std::cout << "Shortage Cases: " << std::endl;
                flag = true;
            }
            std::cout << student_list[i].m_name << " ==> " << student_list[i].m_attendance << "%" << std::endl;
        }
    }
    if (flag == false)
        std::cout << "No Shortage Case !" << std::endl;
    student_list[0].printLines();
}

void showTop5(Students student_list[], int n)
{
    float marks[10];
    for (int i = 0; i < n;i++){
        marks[i] = student_list[i].m_percentage;
    }
    std::sort(marks, marks + n,std::greater<int>());
    std::cout << "Top 5 Students: " << std::endl;
        for (int i = 0; i < 5;i++){
            for (int j = 0; j < n; j++){
                if (student_list[j].m_percentage == marks[i]){
                    std::cout << "Name ==> " << student_list[j].m_name << " | Percentage ==> " << student_list[j].m_percentage << "%" << std::endl;
                    student_list[j].m_percentage = 0;
                    break;
                }
            }
    }
    student_list[0].printLines();
}


void show90(Students student_list[], int n){
    bool flag = false;
    for (int i = 0; i < n; i++){
        if (student_list[i].m_attendance >= 90 && (student_list[i].m_total_marks)/5 >= 90){
            if (flag == false){
                std::cout << "Students with Percentage & Attendance more than 90 are: " << std::endl;
                flag = true;
            }
            std::cout << "Name ==> " << student_list[i].m_name << " | Percentage ==> " << (student_list[i].m_total_marks)/5 << "% | Attendance ==> "  << student_list[i].m_attendance << "%" << std::endl;
        }   
    }
    if (flag == false)
        std::cout << "No Student with Percentage & Attendance more than 90!" << std::endl;
    student_list[0].printLines();
}


int main()
{
    static int n = 50;
    Students students[n];
    int len = 0;
    int decision = 0;
    
    do{
        (students+len)->getDetails();
        std::cout << "Do you want to enter more (Yes = 1 | No = 0) : ";
        std::cin >> decision;
        (students+len)->printLines();
        len++;

    }while(decision == 1);

    showShortage(students,len);
    showTop5(students,len);
    show90(students,len);
}