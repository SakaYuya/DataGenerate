#include "Student.h"

int Student::getMSSV()
{
	return MSSV;
}

string Student::getName()
{
	return name;
}

double Student::getGPA()
{
	return GPA;
}

string Student::getTelephone()
{
	return tele;
}

string Student::getEmail()
{
	return email;
}

string Student::getDOB()
{
	return DOB;
}

string Student::getAddress()
{
	return address;
}

void Student::setMSSV(int MSSV)
{
	this->MSSV = MSSV;
}

void Student::setName(string name)
{
	this->name = name;
}

void Student::setGPA(double GPA)
{
	this->GPA = GPA;
}

void Student::setTelephone(string telephone)
{
	this->tele = telephone;
}

void Student::setEmail(string email)
{
	this->email = email;
}

void Student::setDOB(string DOB)
{
	this->DOB = DOB;
}

void Student::setAddress(string address)
{
	this->address = address;
}

Student::Student(int MSSV, string name, double GPA, string telephone,
	string email, string DOB, string address)
{
	this->MSSV = MSSV;
	this->name = name;
	this->GPA = GPA;
	this->tele = telephone;
	this->email = email;
	this->DOB = DOB;
	this->address = address;
}

string Student::toString()
{
	stringstream build;
	build << "Student: " << MSSV << " - " << name << endl
		<< "GPA=" << GPA << ", Telephone=" << tele << endl
		<< "Email=" << email << endl
		<< "DOB=" << DOB << endl
		<< "Address=" << address << endl;
	string ans = build.str();
	return ans;
}

RandomIntegerGenerator::RandomIntegerGenerator() {
	srand(time(NULL));
}

int RandomIntegerGenerator::next() {
	int result = rand();
	return result;
}

/// <summary>
/// Sinh số ngẫu nhiên trong nửa khoảng [0, max)
/// </summary>
/// <param name="ceiling">Giá trị tối đa</param>
/// <returns>Số nguyên ngẫu nhiên</returns>
int RandomIntegerGenerator::next(int ceiling) {
	int result = rand() % ceiling;
	return result;
}

/// <summary>
/// Sinh số ngẫu nhiên trong đoạn [left, right]
/// </summary>
/// <param name="left">Biên trái</param>
/// <param name="right">Biên phải</param>
/// <returns>Số nguyên ngẫu nhiên</returns>
int RandomIntegerGenerator::next(int left, int right) {
	int result = rand() % (left - right + 1) + left;
	return result;
}

vector<Student> Students::getStudents() {
	return students;
}

Students::Students()
{
	//TODO: read file and save to vector
}

double Students::getAverageGPA()
{
	double sum = 0;
	for (int i = 0; i < students.size(); i++) {
		sum += students[i].getGPA();
	}
	return sum / students.size();
}

void Output::printAllGPA(Students s)
{
	for (int i = 0; i < s.getStudents().size(); i++) {
		cout << s.getStudents()[i].getMSSV() << " - "	
			<< s.getStudents()[i].getName()
			<< ", GPA:" << s.getStudents()[i].getGPA();
	}
}

void Output::printGPA_Greater(Students s)
{
	int avg = s.getAverageGPA();
	for (int i = 0; i < s.getStudents().size(); i++) {
		if (s.getStudents()[i].getGPA() > avg) {
			cout << s.getStudents()[i].getMSSV() << " - "
				<< s.getStudents()[i].getName()
				<< ", GPA:" << s.getStudents()[i].getGPA();
		}
	}
}

Date RandomDateGenerator::next() {

	//Random year
	this->_year = _rng.next();

	//Random month
	this->_month = _rng.next(1, 12);

	//Random day
	switch (_month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		this->_day = _rng.next(1, 31);
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		this->_day = _rng.next(1, 30);
		break;
	case 2:
		if (this->_year % 4 == 0) this->_day = _rng.next(1, 29);
		else this->_day = _rng.next(1, 28);
	}

	Date result(_day, _month, _year);
	return result;
}

RandomStudentGenerator::RandomStudentGenerator()
{
	//
}