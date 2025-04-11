#include <bits/stdc++.h>
using namespace std;

class Employee {
    private:
        string employeeId;
        string fullName;
        string department;
        string position;
        string hireDate;
        double salary;
    public:
        Employee() {
            string employeeId;
            string fullName;
            string department;
            string position;
            string hireDate;
            double salary;
        }

        ~Employee() {
            string employeeId;
            string fullName;
            string department;
            string position;
            string hireDate;
            double salary;
        }

        Employee(string nv, string ten, string room, string cv, string date, double money) {
            this -> employeeId = nv;
            this -> fullName = ten;
            this -> department = room;
            this -> position = cv;
            this -> hireDate = date;
            this -> salary = money;
        }

        Employee(const Employee& prd) {
            this -> employeeId = prd.employeeId;
            this -> fullName = prd.fullName;
            this -> department = prd.department;
            this -> position = prd.position;
            this -> hireDate = prd.hireDate;
            this -> salary = prd.salary;
        }

        void input() {
            cout << "Ma nhan vien: "; setEmployee(); //cin >> employeeId;
            cout << "Ho ten: "; cin >> fullName;
            cout << "Phong ban lam viec: "; cin >> department;
            cout << "Chuc vu: "; cin >> position; 
            cout << "Ngay lam: "; cin >> hireDate;
            cout << "Muc luong co ban: "; setSalary();
        }

        string getEmployeeId() {
            return employeeId;
        }

        string getfullName() {
            return fullName;
        }

        string getDepartment() {
            return department;
        }

        string getPosition() {
            return position;
        }

        string getHireDate() {
            return hireDate;
        }

        double getSalary() {
            return salary;
        }

        void setEmployee() {
            string employeeId; 
            cin >> employeeId;
            this -> employeeId = employeeId;
            for(int i = 0; i < employeeId.size(); i++) {
                if(i < 2) {
                    while (isdigit(employeeId[i]) || employeeId[i] != toupper(employeeId[i])) {
                        cout << "Sai dinh dang. Nhap lai: "; cin >> employeeId;
                    }
                }
                if(i >= 2) {
                    while (isalpha(employeeId[i])) {
                        cout << "Sai dinh dang. Nhap lai: "; cin >> employeeId;
                    }
                }
            }
        }

        void setfullName() {
            string fullName; this -> fullName = fullName;
        }

        void setDepartment() {
            string department; this -> department = department;
        }

        void setPosition() {
            string position; this -> position = position;
        }

        void setHireDate() {
            string hireDate; this -> hireDate = hireDate;
        }

        void setSalary() {
            double salary; 
            cin >> salary; //example: 10000
            this -> salary = salary;
            while(salary < 0) {
                cout << "Nhap lai"; cin >> salary;
            }
        }
    
        double caculateAnnualSalary() {
            double sum;
            sum = salary * 12;
            return sum;
        }

        void promote(string newPos, double salaryIncrease) {
            this -> position = newPos; this -> salary = salaryIncrease;
            cout << position << " - " << salary;
        }

        int caculateYearOfService() {
            getHireDate(); //string hireDate; this -> hireDate = hireDate;
            string currentDate = "2025-04-12";
            string hireYearStr = hireDate.substr(0, 4);
            string currentYearStr = currentDate.substr(0, 4);

            int hireYear, currentYear;
            stringstream ss1(hireYearStr); ss1 >> hireYear;
            stringstream ss2(currentYearStr); ss2 >> currentYear;
            int yearsWorked = currentYear - hireYear;
            return yearsWorked;
        }

        bool isEligibleForBonus(double companyProfitMargin) {
            int yearBonus = salary * (companyProfitMargin/100);
            if(caculateYearOfService() > 2 && companyProfitMargin > 10) {
                cout << "Bonus (Senior): " << yearBonus;
            }
            else return 0;
        }

        void display() {
            cout << "Ma nhan vien: " << getEmployeeId() << endl;
            cout << "Ho ten: " << getfullName() << endl;
            cout << "Phong ban lam viec: " << getDepartment() << endl;
            cout << "Chuc vu: " << getPosition() << endl;
            cout << "Ngay lam: " << getHireDate() << endl;
            cout << "Muc luong co ban: " << getSalary() << endl;
            cout << "Luong hang nam: " << caculateAnnualSalary() << endl;
            cout << "Level-up va tang luong: "; promote("Senior",salary+=5000); cout << endl;
            cout << "So nam lam viec: " << caculateYearOfService() << endl;
            if(isEligibleForBonus(20) == true){ isEligibleForBonus(20); }
            else cout << "Ko du DK !!!";
        }
};

int main() {
   Employee hl;
   Employee dt1("","","","","",2);
   Employee drp(dt1);
   hl.input(); cout << "---------------------------" << endl;
   hl.display();    
}
