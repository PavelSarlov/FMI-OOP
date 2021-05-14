#pragma once

#ifndef TEACHER_H
#define TEACHER_H

#include <iostream>
#include <vector>
#include "Course.h"
#include "Student.h"

class Course;

enum Title {HONORARY, CHIEF_ASSISTANT, DOCTOR, DOCENT, PROFESSOR};

class Teacher
{
public:
	Teacher();
	Teacher(std::string name, Title title);
	Teacher(std::string name, Title title, std::vector<Course> coursesTeaching);
	Teacher(const Teacher& other);
	Teacher& operator=(const Teacher& other);

	std::string get_name() const;
	Title get_title() const;

	void set_studentGrade(std::string courseCode, int facultyNum, double grade);
	void add_course(const Course& course);

	void print() const;

private:
	std::string name;
	Title title;
	std::vector<Course> coursesTeaching;
};
#endif
