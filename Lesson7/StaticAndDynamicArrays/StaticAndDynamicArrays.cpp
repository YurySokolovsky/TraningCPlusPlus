#include <iostream>
#include <string> 

//First struct
struct Student {
    std::string surname;
    std::string name;
    std::string faculty;
    int group;
    std::string email;

    friend std::ostream& operator<<(std::ostream& os, const Student& student);
};

//Creating a structure with the same set of fields but a different sequence
//Second struct
struct OtherStudent {
    int group;
    std::string faculty;
    std::string name;
    std::string surname;
    std::string email;
};

//Function for Student struct fields output
//When you get access to struct using the pointer
std::ostream& operator<<(std::ostream& os, const Student& student)
{
    os << student.name << " " << student.surname << ", " << "e-mail: " << student.email << ". Faculty: " << student.faculty << ", group - " << student.group;
    return os;
}

int main()
{
    //Create a static array of memory for 30 students
    std::cout << "Created a static array of students size 30" << std::endl;
    Student studentsStatic[30];

    //Create a dynamic memory array for an unknown number of students in advance
    int num;
    bool isCorrectValue = false;
    
    std::cout << "Enter the size of the dynamic array: ";

    while (!isCorrectValue) {
        std::cin >> num;

        if (std::cin.fail() || num < 1)
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "\nIncorrect value (less than 1). Repeat input please : ";
        }
        else {
            isCorrectValue = true;
        }
    }

    Student* studentsDynamic = new Student[num];
        
    //Fill static and dymamic arrays
    std::string syntesis;
    std::string syntesisEmail;

    for (int i = 0; i < 30; i++) {
        syntesis = "Syntesis_" + std::to_string(i);
        syntesisEmail = "alise" + std::to_string(i) + "@syntesys.mail";
        studentsStatic[i] = { syntesis, "Alise", "Underworld", 100030, syntesisEmail };
    }

    for (int i = 0; i < num; i++) {
        syntesis = "Syntesis_" + std::to_string(i);
        syntesisEmail = "bercouli" + std::to_string(i) + "@syntesys.mail";
        studentsDynamic[i] = { syntesis, "Bercouli", "Underworld", 1000000, syntesisEmail};
    }
        
    //Get access to the first student using pointer dereference
    std::cout << "\n\n============== First students of arrays ==============" << std::endl;
    std::cout << "First student from static array: " << *studentsStatic << std::endl;
    std::cout << "First student from dynamic array: " << *studentsDynamic << std::endl;


    //Calculate the size of memory occupied by an array of students
    std::cout << "\n\n==================== Arrays sizes ====================" << std::endl;
    std::cout << "Student static array size = " << sizeof(studentsStatic) << " bytes" << std::endl;
    std::cout << "Students dynamic array size = " << sizeof(Student) * num << " bytes" << std::endl;

    //Iterate over an array of students using a pointer increment.
    //Output to the console the address of the student structure in memory
    //Displaying a message about the amount by which the value of the pointer changes when incrementing
    std::cout << "\n\n=== The address of the student structure in memory ===" << std::endl;

    for (int i = 0; i < num; i++)
    {
        Student* temp = studentsDynamic;
   
        if (i < num -1) {
            std::cout << i+1 << ". Address: " << studentsDynamic++ << ", pointer change by: " << studentsDynamic - temp << std::endl;
        }
        else {
            std::cout << i+1 <<". Address: " << studentsDynamic << ", end of array."  << std::endl;
            studentsDynamic = studentsDynamic - num + 1;
        }
    }

    //Displaying addresses of neighboring fields of a structure
    std::cout << "\n\n=== Addresses of neighboring fields of a structure ===" << '\n'
                << "Student name address:    " << &studentsDynamic->name << '\n'
                << "Student surname address: " << &studentsDynamic->surname << '\n'
                << "Student email address:   " << &studentsDynamic->email << '\n'
                << "Student faculty address: " << &studentsDynamic->faculty << '\n'
                << "Student group address:   " << &studentsDynamic->group << std::endl;

    //Compare two structure sizes
    std::cout << "\n\n================= Structures sizes ==================="<< std::endl;
    std::cout << "Student sructure size = " << sizeof(Student) << " bytes" << std::endl;
    std::cout << "OtherStudent sructure size = " << sizeof(OtherStudent) << " bytes" << std::endl;
    
    //Output addresses of each field for both structures
    std::cout << "\n\n==== Addresses of each field for both structures ====" << std::endl;

    Student student;
    std::cout << "Addresses of fields of the Student structure:" << '\n'
                << "Student name address:    " << &student.name << '\n'
                << "Student surname address: " << &student.surname << '\n'
                << "Student email address:   " << &student.email << '\n'
                << "Student faculty address: " << &student.faculty << '\n'
                << "Student group address:   " << &student.group << std::endl;

    OtherStudent otherStudent;
    std::cout << "\nAddresses of fields of the OtherStudent structure:" << '\n'
                << "Student group address:   " << &otherStudent.group << '\n'
                << "Student faculty address: " << &otherStudent.faculty << '\n'
                << "Student name address:    " << &otherStudent.name << '\n'
                << "Student surname address: " << &otherStudent.surname << '\n'
                << "Student email address:   " << &otherStudent.email << std::endl;

    delete[] studentsDynamic;
    studentsDynamic = nullptr;
    return 0;
}
/* ============================================================================ */
/*                                       Выводы                                 */
/* ============================================================================ */
/*
1. Структуры Student и OtherStudent при разной последовательности полей в данном, 
   отдельно взятом случае занимают одинаковое количество места в памяти (116 Байт).
2. Поля структур расположены в памяти рядом друг с другом (можно судить по адресам структур).
   В отдельном случае это можно заметить на примере структуры otherStudent, где первое поле 
   имеет тип int и размер 4 байта, если обратить внимание на адрес данного поля структуры 
   и адрес поля следующего за ним (его можно достаточно легко вычислить или увидеть 
   разницу в 4 байта невооруженным глазом в частном случае).
*/