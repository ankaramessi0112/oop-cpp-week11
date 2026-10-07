#include <iostream>
#include <string>

using namespace std;

struct Date {
    int year;
    int month;
    int day;
    
    Date() { year = 0; month = 0; day = 0; }
    Date(int y, int m, int d) { year = y; month = m; day = d; }
};

class Student {
//properties - những tính chat của đối tượng 
//private/public: OOP = Data hiding -> Encapsulation 
private:
    string name;
    string address;  
    Date birthdate; 
    string cccd; 

//methods
public: 
    //constructors: các hàm khởi tạo dữ lieu -> thông báo hđh cap phát vùng nhớ để lưu trữ 
    Student() {
        name = ""; address = ""; birthdate = Date(); cccd = "";
    }
    Student(string n) {
        name = n; address = ""; birthdate = Date(); cccd = "";
    }  
    Student(Date d) {
        name = ""; address = ""; birthdate = d; cccd = "";
    }
    Student(string n, string addr) {
        name = n; address = addr; birthdate = Date(); cccd = "";
    }
    Student(string n, string addr, Date d) {
        name = n; address = addr; birthdate = d; cccd = "";
    }
    Student(string n, string addr, Date d, string id) {
        name = n; address = addr; birthdate = d; cccd = id;
    }

    int getBirthYear() { return birthdate.year; }
    string getAddress() { return address; }

    void setStudentInfo() { //nhập thông tin sinh viên 
        cout << "Nhap ten: ";
        getline(cin, name);
        cout << "Nhap dia chi (tinh/thanh pho): ";
        getline(cin, address);
        cout << "Nhap nam sinh: ";
        cin >> birthdate.year;
        cout << "Nhap thang sinh: ";
        cin >> birthdate.month;
        cout << "Nhap ngay sinh: ";
        cin >> birthdate.day;
        cin.ignore();
        cout << "Nhap CCCD: ";
        getline(cin, cccd);
    }

    Student getStudentInfo(string search_cccd) { //lấy thông tin sinh viên 
        if (this->cccd == search_cccd) {
            return *this;
        }
        return Student();
    }

    void printInfo() {
        cout << "- Ten: " << name 
             << " | Tinh: " << address 
             << " | Ngay sinh: " << birthdate.day << "/" << birthdate.month << "/" << birthdate.year
             << " | CCCD: " << cccd << endl;
    }
};

void thongKeTheoNamSinh(Student arr[], int size, int targetYear) {
    int count = 0;
    cout << "\n--- THONG KE SINH VIEN SINH NAM " << targetYear << " ---" << endl;
    for (int i = 0; i < size; i++) {
        if (arr[i].getBirthYear() == targetYear) {
            arr[i].printInfo();
            count++;
        }
    }
    cout << "=> Tong so luong sinh vien sinh nam " << targetYear << " la: " << count << endl;
}

void thongKeTheoTinh(Student arr[], int size, string targetProvince) {
    int count = 0;
    cout << "\n--- THONG KE SINH VIEN O TINH: " << targetProvince << " ---" << endl;
    for (int i = 0; i < size; i++) {
        if (arr[i].getAddress() == targetProvince) {
            arr[i].printInfo();
            count++;
        }
    }
    cout << "=> Tong so luong sinh vien o " << targetProvince << " la: " << count << endl;
}

void main() {
    Student database[5] = {
        Student("Khang", "Ho Chi Minh", Date(2007, 12, 1), "001"),
        Student("Huong", "Dong Nai", Date(2000, 5, 10), "002"),
        Student("Bao", "Ho Chi Minh", Date(2001, 8, 15), "003"),
        Student("Phuc", "Binh Duong", Date(2000, 2, 20), "004"),
        Student("Linh", "Dong Nai", Date(2007, 10, 5), "005")
    };
    int total_students = 5;

    thongKeTheoNamSinh(database, total_students, 2000);
    thongKeTheoNamSinh(database, total_students, 2001);

    thongKeTheoTinh(database, total_students, "Ho Chi Minh");
    thongKeTheoTinh(database, total_students, "Dong Nai");
}