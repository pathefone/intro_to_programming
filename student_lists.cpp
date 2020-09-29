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
        }

        for(i=0; i <= positive_grades.size(); i++) {
                 student_time = objects[positive_grades[i]].get_time();

                if( timee > student_time ) {
                        timee = student_time;
                }
         } 

        for(i=0; i<10; i++) {
                if (objects[i].get_time() == timee) {
                        fastest_student_index = i;
                }

        }

	positive_grades.clear();

	return fastest_student_index;


}

int main() {

	Student objects[10];
	Student second_group[12];

	cout << " * * * ENTERING FIRST GROUP DATA * * * " << endl;
	
	for(int i=0; i<10; i++) {
		int grades=0, times=0;
		cout << "Enter " << i+1 << " Student grade: ";
		cin >> grades;
		cout << "Enter " << i+1 << " Student time in minutes: ";
		cin >> times;

		objects[i].set_time(times);
		objects[i].set_grade(grades);
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
	

	int f_grp_fastest=fastest_student(objects);
	int s_grp_fastest=fastest_student(second_group);

	if (objects[f_grp_fastest].get_time() > second_group[s_grp_fastest].get_time()) {
		cout << "The fastest is the student from second group No. " 
		<< s_grp_fastest+1 << " Time: " << second_group[s_grp_fastest].get_time()
	       	<< "min." << endl;
			}
	else {
		cout << "The fastest is the student from first group No. "
                << f_grp_fastest+1 << " Time: " << objects[f_grp_fastest].get_time()
	       	<< "min." << endl;
			}

	return 0;
}
