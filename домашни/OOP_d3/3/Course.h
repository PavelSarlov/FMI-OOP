#pragma once

#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <vector>

class Student;	// cannot include each other
class Teacher;	// cannot include each other

class Course
{
public:
	Course();
	Course(std::string name, std::string type, std::string code, const Teacher& teacher);
	Course(std::string name, std::string type, std::string code, const Teacher& teacher, std::vector<Student> students);
	Course(const Course& other);
	Course& operator=(const Course& other);
	~Course();

	std::string get_name() const;
	std::string get_type() const;
	std::string get_code() const;
	Teacher* get_teacher();
	Student& get_student(int facultyNum);

	void set_name(std::string newName);
	void set_type(std::string newType);
	void set_code(std::string newCode);
	void set_teacher(const Teacher& newTeacher);

	void add_student(Student& student);
	void remove_student(unsigned int facultyNum);

	void print_info() const;
	void print_studentsList() const;

private:
	std::string name;
	std::string type;
	std::string code;
	Teacher* teacher;
	std::vector<Student> students;
};

#endif

namespace std
{
	template<> struct less<Course>	// iterating the courses by sorting them by name
	{
		bool operator() (const Course& first, const Course& second) const
		{
			return first.get_name() < second.get_name();
		}
	};
}