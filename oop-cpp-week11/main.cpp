#include <iostream>
#include <string>
#include <ctime>
using namespace std;
struct Date{
    int year;
    int month;
    int day;

    Date() {
        year = 0; month = 0; day = 0;
    }
    Date(int y, int m, int d) {
        year = y; month = m; day = d;
    }
};

class Student{
//properties - những tính chat của đối tượng 
private:
    string name;
    string address;  
    Date birthdate; //yyyy/mm/dd hh:mm:ss
    string cccd; 


//methods
public: 
    //constructors: các hàm khởi tạo dữ lieu -> thông báo hđh cap phát vùng nhớ để lưu trữ 
Student() {
        name = ""; 
        address = "";
        birthdate = Date(); 
        cccd = "";
    }
    
    Student(string n) {
        name = n; 
        address = "";
        birthdate = Date(); 
        cccd = "";
    }  
    
    Student(Date d) {
        name = ""; 
        address = ""; 
        birthdate = d; 
        cccd = "";
    }

Student(string n, string addr) {
        name = n;
        address = addr;
        birthdate = Date();
        cccd = "";
    }
    
    Student(string n, string addr, Date d) {
        name = n;
        address = addr;
        birthdate = d;
        cccd = "";
    }
    
    Student(string n, string addr, Date d, string id) {
        name = n;
        address = addr;
        birthdate = d;
        cccd = id;
    }
	
// Hàm nhập thông tin
    void setStudentInfo() {
        cout << "Nhap ten: ";
        getline(cin, name);
        cout << "Nhap dia chi: ";
        getline(cin, address);
        cout << "Nhap CCCD: ";
        getline(cin, cccd);
    }

    // Hàm in thông tin (Thêm vào để test code)
    void printInfo() {
        cout << "- Ten: " << name 
             << " | Dia chi: " << address 
             << " | CCCD: " << cccd << endl;
    }
    
    // Lấy thông tin 1 sinh viên 
    Student getStudentInfo(string search_cccd) {
        if (this->cccd == search_cccd) {
            return *this;
        }
        return Student(); 
    }
    
    void getStudents(string search_name, Student result[], int max_size, int& out_count) {
        out_count = 0;
        
        Student database[3] = {
            Student("Huong", "Vo Van Ngan", Date(2007, 12, 1), "001"),
            Student("Khang", "Thu Duc", Date(2007, 1, 1), "002"),
            Student("Huong", "Quan 9", Date(2007, 5, 5), "003")
        };
        
        // Logic tìm kiếm
        for(int i = 0; i < 3; i++) {
            if (database[i].name == search_name && out_count < max_size) {
                result[out_count] = database[i];
                out_count++; 
            }
        }
    }

    void getStudentsbyAge(int age, Student result[], int max_size, int& out_count) {
        out_count = 0;
        
        Student database[3] = {
            Student("Huong", "Vo Van Ngan", Date(2007, 12, 1), "001"),
            Student("Khang", "Thu Duc", Date(2007, 1, 1), "002"),
            Student("Huong", "Quan 9", Date(2007, 5, 5), "003")
        };
        
        const time_t now = time(nullptr);
        const tm* current_date = localtime(&now);
        if (current_date == nullptr) {
            return;
        }

        const int current_year = current_date->tm_year + 1900;
        const int current_month = current_date->tm_mon + 1;
        const int current_day = current_date->tm_mday;

        for (int i = 0; i < 3; i++) {
            int student_age = current_year - database[i].birthdate.year;
            if (current_month < database[i].birthdate.month ||
                (current_month == database[i].birthdate.month &&
                 current_day < database[i].birthdate.day)) {
                student_age--;
            }

            if (student_age == age && out_count < max_size) {
                result[out_count] = database[i];
                out_count++;
            }
        }
    }
};


int main() {
    Student s;
    
    Student results[50];
    int found_count = 0;
    
    cout << "--- TIM KIEM SINH VIEN TEN 'Huong' ---" << endl;
    
    s.getStudents("Huong", results, 50, found_count);
    
    if (found_count == 0) {
        cout << "Khong tim thay sinh vien nao!" << endl;
    } else {
        cout << "Tim thay " << found_count << " sinh vien:" << endl;
        for(int i = 0; i < found_count; i++) {
            results[i].printInfo();
        }
    }
    
    return 0;
}