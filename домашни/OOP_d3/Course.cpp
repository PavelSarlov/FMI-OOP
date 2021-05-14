#include "Course.h"
#include "Student.h"
#include "Teacher.h"

Course::Course()
{
	this->name = "New Course";
	this->type = "Unknown";
	this->code = "Unknown";
	this->teacher = new Teacher();
}
Course::Course(std::string name, std::string type, std::string code, const Teacher& teacher)
{
	this->name = name;
	this->type = type;
	this->code = code;
	this->teacher = new Teacher(teacher);
}
Course::Course(std::string name, std::string type, std::string code, const Teacher& teacher, std::vector<Student> students)
{
	this->name = name;
	this->type = type;
	this->code = code;
	this->teacher = new Teacher(teacher);
	this->students = students;
}
Course::Course(const Course& other)
{
	*this = other;
}
Course& Course::operator=(const Course& other)
{
	if (this != &other)
	{
		delete this->teacher;

		this->name = other.name;
		this->type = other.type;
		this->code = other.code;
		this->teacher = new Teacher(*other.teacher);
		this->students = other.students;
	}
	return *this;
}
Course::~Course()
{
	delete this->teacher;
}

std::string Course::get_name() const
{
	return this->name;
}
std::string Course::get_type() const
{
	return this->type;
}
std::string Course::get_code() const
{
	return this->code;
}
Teacher* Course::get_teacher()
{
	return this->teacher;
}
Student& Course::get_student(int facultyNum)
{
	for (auto& student : this->students)
	{
		if (student.get_facultyNum() == facultyNum)
		{
			return student;
		}
	}
	throw "student not found";
}

void Course::set_name(std::string newName)
{
	this->name = newName;
}
void Course::set_type(std::string newType)
{
	this->type = newType;
}
void Course::set_code(std::string newCode)
{
	this->code = newCode;
}
void Course::set_teacher(const Teacher& newTeacher)
{
	delete this->teacher;
	this->teacher = new Teacher(newTeacher);
}

void Course::add_student(Student& student)
{
	this->students.push_back(student);
	student.add_course(*this);
}
void Course::remove_student(unsigned int facultyNum)
{
	for (int i = 0; i < students.size(); i++)
	{
		if (this->students[i].get_facultyNum() == facultyNum)
		{
			this->students.erase(this->students.begin() + i);
			return;
		}
	}

	std::cout << "ERROR! Student with given faculty number is not in the course.\n";
}

void Course::print_info() const
{
	std::cout << this->name << ", " << this->teacher->get_name() << ", " << this->type << ", " << this->code << std::endl;
}
void Course::print_studentsList() const
{
	std::cout << "Students taking the course:" << std::endl;
	for (int i = 0; i < this->students.size(); i++)
	{
		this->students[i].print();
		std::cout << std::endl;
	}
	std::cout << std::endl;
}