#include <iostream>
#include <array>
#include <vector>
#include <numeric>
#include <algorithm>

using std::cout;
using std::cin;

enum Types
{
    health_potions,
    torches,
    arrows,
    max_type
};

struct Student{
    std::string first_name{};
    int grade{};
};

using Inventory = std::array<int, static_cast<std::size_t>(Types::max_type)>;

int count_total_items(const Inventory& items)
{
    return std::accumulate(items.begin(), items.end(), 0);
}

int main()
{

    Inventory items {2,5,10};
    cout << "Number of items in total : " << count_total_items(items) << "\n"
         << "number of torches : " << items[Types::torches] <<  "\n";

    cout << "\n\n\n";

    int number_of_students {0};
    cout << "How many students do you want to create ? : ";
    cin >> number_of_students;
    std::vector<Student> students(number_of_students);

    for (auto i = 0; i< number_of_students; i++)
    {
        Student temp{};
        cout << "Type name for student number "<< i+1 << ":";
        cin >> temp.first_name;
        cout << "Type grade for student number "<< i+1 << ":";
        cin >> temp.grade;
        students.push_back(temp);
    }

    std::sort(students.begin(), students.end(),
              [](const Student& a, const Student& b){ return a.grade > b.grade; });

    for(const auto element : students)
        cout << element.first_name << " got a grade of " << element.grade << "\n";

    return 0;

}
