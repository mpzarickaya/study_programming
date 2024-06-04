#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

struct Student {
    std::string name;
    int age;
    std::string major;
    float gpa;
    std::string graduation_year;
};

std::vector<Student> load_students_from_file(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<Student> students;

    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            std::istringstream iss(line);
            Student s;
            iss >> s.name >> s.age >> s.major >> s.gpa >> s.graduation_year;
            students.push_back(s);
        }
        file.close();
    }

    return students;
}

void save_students_to_file(const std::string& filename, const std::vector<Student>& students) {
    std::ofstream file(filename);

    if (file.is_open()) {
        for (const auto& s : students) {
            file << s.name << " " << s.age << " " << s.major << " " << s.gpa << " " << s.graduation_year << std::endl;
        }
        file.close();
    }
}

void display_students(const std::vector<Student>& students) {
    for (const auto& s : students) {
        std::cout << "Name: " << s.name << ", Age: " << s.age << ", Major: " << s.major << ", GPA: " << s.gpa << ", Graduation Year: " << s.graduation_year << std::endl;
    }
}

int main() {
    const std::string filename = "students.txt";
    std::vector<Student> students = load_students_from_file(filename);

    while (true) {
        std::cout << "1. Add student\n2. Edit student\n3. Delete student\n4. Search student\n5. Display all students\n6. Exit\n";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                Student s;
                std::cout << "Enter student name: ";
                std::cin.ignore();
                getline(std::cin, s.name);
                std::cout << "Enter student age: ";
                std::cin >> s.age;
                std::cout << "Enter student major: ";
                std::cin.ignore();
                getline(std::cin, s.major);
                std::cout << "Enter student GPA: ";
                std::cin >> s.gpa;
                std::cout << "Enter student graduation year: ";
                std::cin.ignore();
                getline(std::cin, s.graduation_year);
                students.push_back(s);
                save_students_to_file(filename, students);
                break;
            }
            case 2: {
                // TODO: Implement editing student
                break;
            }
            case 3: {
                // TODO: Implement deleting student
                break;
            }
            case 4: {
                // TODO: Implement searching student
                break;
            }
            case 5: {
                display_students(students);
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                std::cout << "Invalid choice. Please try again.\n";
            }
        }
    }

    return 0;
}
