#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

//course with one student's score
struct COURSE
{
	string name;
	double score = 0;
};
typedef struct COURSE course;

//course with all students' scores and min, max, avg and students'number cnt
struct COURSE_attribute
{
	string name;
	vector<double>score;
	double max = 0, min = 0, avg = 0, sum = 0;
	int cnt = 0;
};
typedef struct COURSE_attribute course_attribute;

//student
class student
{
public:
	int no=0;
	string name;
	vector<course> courses;
	double average=0;
	//print the data
	void print();
	//calculate the avg
	void cal_avg();
};

//the first line
vector<string> title;
//all courses
vector<course_attribute> all_course;
//students
vector<student> students;

//max width of name, no and course, able to self-adjust according to the input file
int name_width = 8;
int no_width = 3;
int course_width = 8;

int main()
{
	//first two attributes of the title
	title.push_back("no");
	title.push_back("name");

	//select the input file
	ifstream file;
	file.open("studentRecord.txt");

	//some temporary variable
	string str, temp_course, temp_name;
	double temp_score;

	//number of students
	int number = 0;
	no_width = no_width >= log(number) + 2 ? no_width : log(number) + 2;

	//get data from file, and put data into containers
	//one "while" manages one line
	while (getline(file, str))
	{
		//temporary variable
		student stu;

		stu.no = ++number;

		//the start and end of each course name or score or student name
		string::size_type  start, end;
		start = end = 0;
		str += "\t";

		//the student name
		start = str.find_first_not_of("\t", end);
		end = str.find_first_of("\t", start);
		temp_name = str.substr(start, end - start);
		//adjust the max length of name
		name_width = name_width >= temp_name.length() + 1 ? name_width : temp_name.length() + 1;
		stu.name = str.substr(start, end - start);

		//judge whether a course has appeard or not
		bool found = false;
		//while a line hasnt been all visited
		//one "while" manages one course
		while (end != str.npos)
		{
			//course name
			start = str.find_first_not_of("\t",end);
			if (start >= str.npos)
				break;
			end = str.find_first_of("\t", start);
			temp_course = str.substr(start, end - start);

			//score of the course
			start = str.find_first_not_of("\t", end);
			if (start >= str.npos)
				break;
			end = str.find_first_of("\t", start);
			//score from string to double
			temp_score = stoi(str.substr(start, end - start));
			if (temp_score < 0 || temp_score>100)
				continue;

			//adjust the max length of course
			course_width = course_width >= temp_course.length() + 1 ? course_width : temp_course.length() + 1;
			//temporary variable
			course temp_COURSE;
			temp_COURSE.name = temp_course;
			temp_COURSE.score = temp_score;
			//add the course to the student
			stu.courses.push_back(temp_COURSE);

			//judge whether a course has appeard or not
			found = false;
			//update course
			//find the course
			for (int i = 0; i < all_course.size(); i++)
			{
				//found the course, update the course
				if (all_course[i].name == temp_course)
				{
					all_course[i].score.push_back(temp_score);
					all_course[i].max = *std::max_element(std::begin(all_course[i].score),std::end(all_course[i].score));
					all_course[i].min = *std::min_element(std::begin(all_course[i].score), std::end(all_course[i].score));
					all_course[i].sum += temp_score;
					all_course[i].avg = all_course[i].sum / (++all_course[i].cnt);
					found = true;
					break;
				}
			}
			//not found the course, create new course
			if (!found)
			{
				course_attribute new_course;
				new_course.name = temp_course;
				new_course.score.push_back(temp_score);
				new_course.max = temp_score;
				new_course.min = temp_score;
				new_course.sum += temp_score;
				new_course.avg = temp_score;
				new_course.cnt++;
				//add new course to courses
				all_course.push_back(new_course);
			}
		}
		//add new student to students
		students.push_back(stu);
	}
	
	//complement the title
	for (int i = 0; i < all_course.size(); i++)
	{
		title.push_back(all_course[i].name);
	}
	title.push_back("average");

	//output the first line
	for (int i = 0; i < title.size(); i++)
	{
		//set width of output
		if(i==1)
			cout << setw(name_width) << left << title[i];
		else if(i==0)
			cout << setw(no_width) << left << title[i];
		else
			cout << setw(course_width) << left << title[i];
	}
	cout << endl;

	//output all data of students
	for (int i = 0; i < students.size(); i++)
	{
		students[i].print();
	}

	//output avg, max and min
	cout << setw(no_width) << left << ""<<setw(name_width) << left << "average";
	for (int i = 0; i < all_course.size(); i++)
	{
		cout << setw(course_width) << left << all_course[i].avg;
	}
	cout << endl;
	cout << setw(no_width) << left << "" << setw(name_width) << left << "min";
	for (int i = 0; i < all_course.size(); i++)
	{
		cout << setw(course_width) << all_course[i].min;
	}
	cout << endl; 
	cout << setw(no_width) << left << "" << setw(name_width) << left << "max";
	for (int i = 0; i < all_course.size(); i++)
	{
		cout << setw(course_width) << left << all_course[i].max ;
	}
	return 0;
}
void student::print()
{
	cout << setw(no_width) << left << no << setw(name_width) << left << name;
	bool found = false;
	//output score according to the current course
	for (int i = 0; i < all_course.size(); i++)
	{
		found = false;
		for (int j = 0; j < courses.size(); j++)
		{
			if (courses[j].name == all_course[i].name)
			{
				cout << setw(course_width) << left << courses[j].score ;
				found = true;
				break;
			}
		}
		//student doesnt choose the course
		if (!found)
		{
			cout << setw(course_width) << left << "null";
		}
	}
	cal_avg();
	if (average != -1)
	{
		cout << setw(course_width) << left << average << endl;
	}
	else
		cout << setw(course_width) << left << "null" << endl;
}
void student::cal_avg()
{
	if (courses.empty())
	{
		average = -1;
		return;
	}
	double sum=0;
	for (int i = 0; i < courses.size(); i++)
	{
		sum += courses[i].score;
	}
	average = sum / courses.size();
}