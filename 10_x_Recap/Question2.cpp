#include <iostream>
#include <algorithm>
#include <vector>

struct Student
{
    std::string name;
    int grade;
};

int getNumberOfStudents()
{
    int studentNum{};

    do
    {
        std::cout << "How many student you want to enter?: ";
        std::cin >> studentNum;
    } while (studentNum<=0);

    return studentNum;
}
    
std::vector<Student> getStudentsInfo()
{
    int studentNum{getNumberOfStudents()};
    using vector_t = std::vector<Student>;

    //vector with element of type <struct Student> and size cast to vector size_type
    vector_t class1(static_cast<vector_t::size_type>(studentNum)); 

    //numerator for element display
    int studnumber{1};

    //iteration through the vector class1 to enter the students and their grade
    for (auto& student : class1)
    {
        std::cout << "Enter student name #" << studnumber << ": ";
        std::cin >> student.name;
        std::cout << "Enter student grade #" << studnumber << ": ";
        std::cin >> student.grade;

        ++studnumber;
    }

    return class1;    
}

//function used as sorting method for std::sort
bool compareStudents(const Student& a, const Student& b)
{
    return (a.grade > b.grade);
}



int main()
{
    auto studentclass{getStudentsInfo()};

    std::sort(studentclass.begin(), studentclass.end(), compareStudents);

    for (const auto&student : studentclass)
    {
        std::cout << student.name << " got a grade of " << student.grade <<". \n";
    }
    
}
