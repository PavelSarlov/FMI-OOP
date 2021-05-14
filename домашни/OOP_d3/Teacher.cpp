#include "Teacher.h"
#include "Course.h"

Teacher::Teacher()
{
	this->name = "New Teacher";
	this->title = HONORARY;
}
Teacher::Teacher(std::string name, Title title)
{
	this->name = name;
	this->title = title;
}
Teacher::Teacher(std::string name, Title title, std::vector<Course> coursesTeaching)
{
	this->name = name;
	this->title = title;
	this->coursesTeaching = coursesTeaching;
}
Teacher::Teacher(const Teacher& other)
{
	*this = other;
}
Teacher& Teacher::operator=(const Teacher& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->title = other.title;
		this->coursesTeaching = other.coursesTeaching;
	}
	return *this;
}

std::string Teacher::get_name() const
{
	return this->name;
}
Title Teacher::get_title() const
{
	return this->title;
}

void Teacher::add_course(const Course& course)
{
	this->coursesTeaching.push_back(course);
}

void Teacher::print() const
{
	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Title: ";
	switch (this->title)
	{
	case 0:
		std::cout << "Honorary";
		break;
	case 1:
		std::cout << "Chief Assistant";
		break;
	case 2:
		std::cout << "Doctor";
		break;
	case 3:
		std::cout << "Docent";
		break;
	case 4:
		std::cout << "Professor";
		break;
	}
	std::cout << std::endl;

	std::cout << "Courses teaching:" << std::endl;
	for (int i = 0; i < this->coursesTeaching.size(); i++)
	{
		std::cout << '\t' << i + 1 << ") ";
		this->coursesTeaching[i].print_info();
	}
	std::cout << std::endl;
}

void Teacher::set_studentGrade(std::string courseCode, int facultyNum, double grade)
{
	for (auto& course : this->coursesTeaching)
	{
		if (course.get_code() == courseCode)
		{
			try
			{
				Student* student = &course.get_student(facultyNum);

				for (auto& sCourse : student->coursesAndGrades)
				{
					if (sCourse.first.get_code() == courseCode)
					{
						sCourse.second = grade;
					}
				}
			}
			catch (std::string msg)
			{
				std::cout << msg << std::endl;
			}
		}
	}
}