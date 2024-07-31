#include <iostream>
using namespace std;
class student
{
private:
    int stuId;
    string stuName;
    string course;
    student *prev, *next;

public:
    void addStudent();
    void removeStudent();
    void searchStudent();
    void updateStuRecord();
    void filterStudent();
};
student *firstStu = NULL, *lastStu = NULL;

void student::addStudent()
{
    student *newStu = new student;
    student *temp = firstStu;
    if (newStu == NULL)
    {
        cout << "\n\nStudent record can not added\n";
        return;
    }
    cout << "\nEnter student ID: ";
    cin >> newStu->stuId;
    cin.sync();
    cout << "Enter student name: ";
    cin >> newStu->stuName;
    cin.sync();
    cout << "Enter student course: ";
    cin >> newStu->course;
    cin.sync();
    if (firstStu == NULL)
    {
        newStu->prev = NULL;
        newStu->next = NULL;
        firstStu = newStu;
        lastStu = newStu;
        cout << "\nStudent successfully added\n";
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newStu->prev = temp;
    newStu->next = NULL;
    temp->next = newStu;
    lastStu = newStu;
    cout << "\nStudent successfully added\n";
}

void student::removeStudent()
{
    if (firstStu == NULL)
    {
        cout << "\nThere is no record\n";
        return;
    }
    int id;
    student *firstTemp = firstStu->next;
    student *firstTemp1 = firstStu;
    student *lastTemp = lastStu->prev;
    student *lastTemp1 = lastStu;    
    cout << "\n\nFor removing student record";
    cout << "\nEnter student ID: ";
    cin >> id;
    if (firstTemp1->stuId == id)
    {
        if (firstTemp == NULL)
        {
            firstStu = firstTemp1->next;
            free(firstTemp1);
            cout << "\nStudent removed successfully\n";
            return;
        }
        else
        {
            firstTemp->prev = NULL;
            firstStu = firstTemp1->next;
            free(firstTemp1);
            cout << "\nStudent removed successfully\n";
            return;
        }
    }
    if ((lastTemp1->stuId == id))
    {
        lastTemp->next = NULL;
        lastStu = lastTemp;
        free(lastTemp1);
        cout << "\nStudent removed successfully\n";
        return;
    }
    while ((firstTemp != NULL) || (lastTemp != NULL))
    {        
        if ((id == firstTemp->stuId))
        {
            firstTemp->next->prev = firstTemp->prev;
            firstTemp1->next = firstTemp->next;
            free(firstTemp);
            cout << "\nStudent removed successfully\n";
            return;
        }
        else if ((lastTemp->stuId == id))
        {
            lastTemp1->prev = lastTemp->prev;
            lastTemp->prev->next = lastTemp->next;
            free(lastTemp);
            cout << "\nStudent removed successfully\n";
            return;
        }
        firstTemp = firstTemp->next;
        firstTemp1 = firstTemp1->next;
        lastTemp = lastTemp->prev;
        lastTemp1 = lastTemp1->prev;
    }
    cout << "\nStudent record is not found\n\n";
}

void student::searchStudent()
{
    if (firstStu == NULL)
    {
        cout << "\nThere is no record\n\n";
    }
    int id;
    student *firstTemp = firstStu;
    student *lastTemp = lastStu;    
    cout << "\n\nFor searching student record";
    cout << "\nEnter student ID: ";
    cin >> id;
    cout << "\n  ID\tName\t  Course\n";
    while (firstTemp != NULL || lastTemp != NULL)
    {
        if (firstTemp->stuId == id)
        {
            cout << " " << firstTemp->stuId << "\t" << firstTemp->stuName << "     " << firstTemp->course << endl;
            return;
        }
        else if (lastTemp->stuId == id)
        {
            cout << " " << lastTemp->stuId << "\t" << lastTemp->stuName << "     " << lastTemp->course << endl;
            return;
        }
        firstTemp = firstTemp->next;
        lastTemp = lastTemp->prev;
    }
    cout << "\nStudent record is not found\n";
}

void student::updateStuRecord()
{
    if (firstStu == NULL)
    {
        cout << "\nThere is no record\n\n";
    }
    int id,choose;
    string newName,newCourse;
    student *firstTemp = firstStu;
    student *lastTemp = lastStu;
    cout << "\n\nFor updating student record";
    cout << "\nEnter student ID: ";
    cin >> id;
    while (firstTemp != NULL || lastTemp != NULL)
    {
        if (firstTemp->stuId == id)
        {
            cout<<"\nYou can change only name and course name\n";
            cout<<"Press 1 to change name\n";
            cout<<"Press 2 to change course name\n";
            again:
            cout<<"Choose any option :";
            cin>>choose;
            cin.sync();
            switch (choose)
            {
            case 1:
                cout<<"Enter new name: ";
                cin>>firstTemp->stuName;
                break;
            case 2:
                cout<<"Enter new course name: ";
                cin>>firstTemp->course;
                break;
            default:cout<<"Invalid option try again\n";
                goto again;
            }
            return;
        }
        else if (lastTemp->stuId == id)
        {
            cout<<"\nYou can change only name and course name\n";
            cout<<"Press 1 to change name\n";
            cout<<"Press 2 to change course name\n";
            again1:
            cout<<"Choose any option :";
            cin>>choose;
            cin.sync();
            switch (choose)
            {
            case 1:
                cout<<"Enter new name: ";
                cin>>lastTemp->stuName;
                cout<<"\nName is successfully updated\n";
                break;
            case 2:
                cout<<"Enter new course name: ";
                cin>>lastTemp->course;
                cout<<"\nCourse name is successfully updated\n";
                break;
            default:cout<<"Invalid option try again\n";
                goto again1;
            }
            return;
        }
        firstTemp = firstTemp->next;
        lastTemp = lastTemp->prev;
    }
    cout << "\nStudent record is not found\n";
}

void student::filterStudent()
{
    if (firstStu == NULL)
    {
        cout << "\nThere is no record\n\n";
    }
    int id;
    student *firstTemp = firstStu;
    string stuCourse;
    cout << "\n\nFor filtering student record";
    cout << "\nEnter course: ";
    cin >>stuCourse;
    cin.sync();
    cout << "\n  ID\tName\t     Course\n";
    while (firstTemp != NULL)
    {
        if (!stuCourse.compare(firstTemp->course))
        {
            cout << " " << firstTemp->stuId << "\t" << firstTemp->stuName << "      " << firstTemp->course << endl;
        }
        firstTemp = firstTemp->next;
    }
    cout << "\nStudent record is not found\n";
}

int main()
{
    int choose;    
    cout << "\n\n****WELCOME TO STUDENT MANAGEMENT SYSTEM PROJECT*****\n";
    do
    {
        cout << "\nPress 1 for Add Student\n";
        cout << "Press 2 for Remove Student\n";
        cout << "Press 3 for Search Student\n";
        cout << "Press 4 for Update Student\n";
        cout << "Press 5 for Filter Student\n";
        cout << "Press 6 for Exit\n";
    again:
        cout << "Please choose any option: ";
        cin >> choose;
        cin.sync();
        switch (choose)
        {
        case 1:
            firstStu->addStudent();
            break;
        case 2:
            firstStu->removeStudent();
            break;
        case 3:
            firstStu->searchStudent();
            break;
        case 4:
            firstStu->updateStuRecord();
            break;
        case 5:
            firstStu->filterStudent();
            break;
        case 6:
            break;
        default:
            cout << "\nInvalid option please try again\n\n";
            goto again;
            break;
        }
    } while (choose != 6);
    return 0;
}