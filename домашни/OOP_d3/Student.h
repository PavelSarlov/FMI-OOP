#pragma once

#ifndef STUDENT_H
#define STUDENT_H

#include <map>
#include <iostream>
#include "Course.h"

class Student
{
public:
	Student();
	Student(std::string name, unsigned int facultyNum);
	Student(std::string name, unsigned int facultyNum, std::map<Course, double> coursesAndGrades);
	Student(const Student& other);
	Student& operator=(const Student& other);

	std::string get_name() const;
	unsigned int get_facultyNum() const;
	double get_courseGrade(std::string courseCode);

	void add_course(const Course& course);

	void print() const;

private:
	std::string name;
	unsigned int facultyNum;
	std::map<Course, double> coursesAndGrades;

	friend class Teacher;
};
#endif