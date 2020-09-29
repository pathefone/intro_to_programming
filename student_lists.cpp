#include <iostream>
#include <vector>

using namespace std;


class Student {
	int time=0;
	int grade=0;

	public:
	 void set_time(int i) { time = i; }
	 void set_grade(int i) { grade = i; }
	 int get_time() { return time; }
	 int get_grade() { return grade; }

};

int fastest_student(Student objects[12]) {

        int student_time = 0;
        int timee = 100;
        int i=0;
	int fastest_student_index = 0;
	vector<int> positive_grades;

        for(i=0; i<10; i++) {

                if ( objects[i].get_grade() > 4) {
                        positive_grades.push_back(i);
                }
        } // getting positive grade values and storing in vector

        for(i=0; i <= positive_grades.size(); i++) {
                 student_time = objects[positive_grades[i]].get_time();

                if( timee > student_time ) {
                        timee = student_time;
                }
         } // getting time of students with positive grades 

        for(i=0; i<10; i++) {
                if (objects[i].get_time() == timee) {
                        fastest_student_index = i;
                }

        } // finding fastest student index in array

	positive_grades.clear();

	return fastest_student_index; // returning fastest student index


}

int main() {

	Student first_group[10];
	Student second_group[12];

	cout << " * * * ENTERING FIRST GROUP DATA * * * " << endl;
	
	for(int i=0; i<10; i++) {
		int grades=0, times=0;
		cout << "Enter " << i+1 << " Student grade: ";
		cin >> grades;
		cout << "Enter " << i+1 << " Student time in minutes: ";
		cin >> times;

		first_group[i].set_time(times);
		first_group[i].set_grade(grades);
	}
	
	cout << " * * * ENTERING SECOND GROUP DATA * * * " << endl;
	
	for(int i=0; i<12; i++) {
                int grades=0, times=0;
                cout << "Enter " << i+1 << " Student grade: ";
                cin >> grades;
                cout << "Enter " << i+1 << " Student time in minutes: ";
                cin >> times;

                second_group[i].set_time(times);
                second_group[i].set_grade(grades);
        }
	

	int f_grp_fastest=fastest_student(first_group); //first group fastest student index
	int s_grp_fastest=fastest_student(second_group); //second group fastest student index

	if (first_group[f_grp_fastest].get_time() > second_group[s_grp_fastest].get_time()) {
		cout << "The fastest is the student from second group No. " 
		<< s_grp_fastest+1 << " Time: " << second_group[s_grp_fastest].get_time()
	       	<< "min." << endl;
			}
	else {
		cout << "The fastest is the student from first group No. "
                << f_grp_fastest+1 << " Time: " << first_group[f_grp_fastest].get_time()
	       	<< "min." << endl;
			}
	// finding fastest student from 2 groups by comparing speeds

	return 0;
}
