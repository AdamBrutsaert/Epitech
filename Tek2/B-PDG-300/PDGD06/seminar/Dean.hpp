/*
** EPITECH PROJECT, 2024
** Dean.hpp
** File description:
** Dean.hpp
*/

#include "Student.hpp"

#include <string>

class Dean {
public:
    Dean(std::string name);
    ~Dean();

    void teachStudent(Student *student, std::string subject);
    void timeCheck(void);

    const std::string& getName() const { return this->_name; }
private:
    std::string _name;
    bool _isWorking;
};
