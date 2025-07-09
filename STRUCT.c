/******
242                                         type_symtable = findsymbol(Text);
243                                         type = type_symtable->type;
*******/
struct EMP {
	int id;
	char gender;
};

struct EMP Employee1;

struct EMP *return_struct() {
	return (&Employee1);
}

void main() {
	Employee1.id = 12;
	Employee1.gender = 'M';
	int emp_id = (return_struct())->id;
//	struct EMP *Employee = return_struct();
//	int emp_id = Employee->id;
}
