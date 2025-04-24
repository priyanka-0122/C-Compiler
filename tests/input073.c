int printf(char *fmt);

struct Employee{
	char nameInit;
	int empId;
	long salary;
};

struct Student{
	char nameInit;
	long rollNo;
	int class;
};

struct Employee Emp1;
struct Employee Emp2;
struct Student Stu1;

int main() {

	Emp1.nameInit = 'A';
	Emp1.empId = 2024;
	Emp1.salary = 54321;

        Emp2.nameInit = 'B';
        Emp2.empId = 2021;
        Emp2.salary = 12345;

	Stu1.nameInit = 'S';
	Stu1.rollNo = 23;
	Stu1.class = 5;

	printf("%c\t%d\t%d\n", Emp1.nameInit, Emp1.empId, Emp1.salary);
	printf("%c\t%d\t%d\n", Emp2.nameInit, Emp2.empId, Emp2.salary);
	printf("%c\t%d\t%d\n", Stu1.nameInit, Stu1.rollNo, Stu1.class);

	return(0);
}
