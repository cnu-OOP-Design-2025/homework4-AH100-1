#include "student_manager.h"
#include "student.h"

/* StudentManager */
int StudentManager::last_student_id = 1000;

void StudentManager::addStudent(char const* name, float midterm, float final) {
    int id = ++last_student_id;
    /* TODO */
    if (num_of_students < MAX_STUDENTS) {
        students[num_of_students] = Student(name, id, midterm, final);
        num_of_students++;
    }
}

void StudentManager::deleteStudent(int id) {
    /* TODO */
    int idx = findStudentByID(id);
    if (idx >= 0) {
        for (int i = idx; i < num_of_students - 1; i++) {
            students[i] = students[i + 1];
        }
        num_of_students--;
    }
}

void StudentManager::modifyStudent(const Student& student) {
    /* TODO */
    int idx = findStudentByID(student.getID());
    if (idx >= 0) {
        students[idx] = student;
    }
}

int StudentManager::findStudentByID(int id) const {
    /* TODO */
    for (int i = 0; i < num_of_students; i++) {
        if (students[i].getID() == id) {
            return i;
        }
    }
    return -1;
}

int StudentManager::findBestStudentInMidterm() const {
    /* TODO */
    int best_student_id = -1;
    float best_midterm_score = -1.0f;
    for (int i = 0; i < num_of_students; i++)
    {
        if (students[i].getRecord().getMidterm() > best_midterm_score)
        {
            best_midterm_score = students[i].getRecord().getMidterm();
            best_student_id = students[i].getID();
        }
    }

    return best_student_id;
}

int StudentManager::findBestStudentInFinal() const {
    /* TODO */
    int best_student_id = -1;
    float best_final_score = -1.0f;
    for (int i = 0; i < num_of_students; i++)
    {
        if (students[i].getRecord().getFinal() > best_final_score)
        {
            best_final_score = students[i].getRecord().getFinal();
            best_student_id = students[i].getID();
        }
    }

    return best_student_id;
}

int StudentManager::findBestStudent() const {
    /* TODO */
    int best_student_id = -1;
    float best_total_score = -1.0f;
    for (int i = 0; i < num_of_students; i++) {
        float total_score = students[i].getRecord().getTotal();
        if (total_score > best_total_score) {
            best_total_score = total_score;
            best_student_id = students[i].getID();
        }
    }

    return best_student_id;
}

float StudentManager::getMidtermAverage() const {
    /* TODO */
    float sum = 0;
    for (int i = 0; i < num_of_students; i++) {
        sum += students[i].getRecord().getMidterm();
    }
    if (num_of_students > 0)
    {
        return sum / num_of_students;
    }
    return 0.0f;
}

float StudentManager::getFinalAverage() const {
    /* TODO */
    float sum = 0;
    for (int i = 0; i < num_of_students; i++) {
        sum += students[i].getRecord().getFinal();
    }
    if (num_of_students > 0)
    {
        return sum / num_of_students;
    }
    return 0.0f;
}

float StudentManager::getTotalAverage() const {
    /* TODO */
    float sum = 0;
    for (int i = 0; i < num_of_students; i++) {
        sum += students[i].getRecord().getTotal();
    }
    if (num_of_students > 0)
    {
        return sum / num_of_students;
    }
    return 0.0f;}

