#include "Student.h"
#include "Course.h"

Student::Student()
{
	this->name = "New Student";
	this->facultyNum = 0;
}
Student::Student(std::string name, unsigned int facultyNum)
{
	this->name = name;
	this->facultyNum = facultyNum;
}
Student::Student(std::string name, unsigned int facultyNum, std::map<Course, double> coursesAndGrades)
{
	this->name = name;
	this->facultyNum = facultyNum;
	this->coursesAndGrades = coursesAndGrades;
}
Student::Student(const Student& other)
{
	*this = other;
}
Student& Student::operator=(const Student& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->facultyNum = other.facultyNum;
		this->coursesAndGrades = coursesAndGrades;
	}
	return *this;
}

std::string Student::get_name() const
{
	return this->name;
}
unsigned int Student::get_facultyNum() const
{
	return this->facultyNum;
}

void Student::add_course(const Course& course)
{
	this->coursesAndGrades.insert(std::pair<Course, double>(course, 2));
}

void Student::print() const
{
	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Faculty number: " << this->facultyNum << std::endl;
	std::cout << "Courses taken and their corresponding grades:" << std::endl;
	int i = 1;
	for (auto& course : coursesAndGrades)
	{
		std::cout << '\t' << i++ << ") ";
		course.first.print_info();
		std::cout << '\t';
		std::cout << "Grade: " << course.second << std::endl;
	}
	std::cout << std::endl;
}