#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student
{
    public:
    int id;
    string name;
    int age;
    string course;

    Student(int id,string name,int age,string course)
    {
        this->id=id;
        this->name=name;
        this->age=age;
        this->course=course;
    }
};
vector<Student> student;

void addStudent();
void displayStudent();
void updateStudent();
void deleteStudent();

int main()
{
    int choice;
    cout<<"\nSTUDENT MANAGRMENT SYSTEM\n";
    cout<<"1.Add student\n";
    cout<<"2.Display Student\n";
    cout<<"3.Update Student\n";
    cout<<"4.Delete Student\n";
    cout<<"5,Exit\n";

    while(true)
    {
        cout<<"Enter your choice..";
        cin>>choice;

        switch(choice)
        {
            case 1:
            addStudent();
            break;
            
            case 2:
            displayStudent();
            break;

            case 3:
            updateStudent();
            break;

            case 4:
            deleteStudent();
            break;

            case 5:
            cout<<"Exiting..."<<endl;
            return 0;

            default:
            cout<<"invalid choice,please try again!"<<endl;
            break;
        }
    }
    return 0;
}

void addStudent()
{
    int id,age;
    string name,course;
    cout<<"Enter student ID:";
    cin>>id;
    cin.ignore();
    cout<<"Enter student name:";
    cin>>name;
    cout<<"Enter student age:";
    cin>>age;
    cin.ignore();
    cout<<"Enter student course:";
    cin>>course;
    student.push_back(Student(id,name,age,course));
    cout<<"Student added successfully!"<<endl;

}

void displayStudent()
{
    if(student.empty()){
        cout<<"No student to display!"<<endl;
    }
    for(const auto&student : student)
    {
        cout<<"ID:"<<student.id<<endl;
        cout<<"Name:"<<student.name<<endl;
        cout<<"Age:"<<student.age<<endl;
        cout<<"course:"<<student.course<<endl;
    return;
    }
}
void updateStudent()
{
    int id;
    cout<<"Enter student ID to  update:";
    cin>>id;
    cin.ignore();
    for(auto&student : student)
    {
        if(student.id==id){
            cout<<"Enter new name:";
            cin>>student.name;
            cout<<"Enter new age:";
            cin>>student.age;
            cin.ignore();
            cout<<"Enter new course:";
            cin>>student.course;
            cout<<"Stdent updated successfully!"<<endl;
            return;
        }
        }
        cout<<"Student with ID"<<id<<"not found!"<<endl;
    }
    void deleteStudent()
    {
        int id;
        cout<<"Enter student ID to delete:";
        cin>>id;
        for(auto it=student.begin();it!=student.end();++it){
            if(it->id==id){
                student.erase(it);
                cout<<"Student deleted successfully!"<<endl;
                return;
            }
        }
        cout<<"Student with ID"<<id<<"not found!"<<endl;
    }

