#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Student{
	string name;
	int age;
	int sco;
};

// C style   => struct Student
// c++ style => Student

void grow_up(Student& stu){
	stu.age += 1;
	stu.sco = stu.sco * 6 / 5;
	if(stu.sco > 600) {
		stu.sco = 600;
	}
}	

int main(){
	int n; 
	cin >> n;
	vector<Student> A(n);
	for(int i = 0; i < n; i++) {
		cin >> A[i].name >> A[i].age >> A[i].sco;
	}
	for(int i = 0; i < n; i++) {
		grow_up(A[i]);
	}
	for(int i = 0; i < n; i++) {
		cout<< A[i].name << ' ' << A[i].age << ' ' << A[i].sco << '\n';
	}
	return 0;
}