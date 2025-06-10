// Section 9
// Challenge
/*
    This challenge is about using a collection (list) of integers and allowing
the user to select options from a menu to perform operations on the list.

    Your program should display a menu options to the user as follows:

    P - Print numbers
    A - Add a number
    M - Display mean of the numbers
    S - Display the smallest number
    L - Display the largest number
    Q - Quit

    Enter your choice:

The program should only accept valid choices from the user, both upper and
lowercase selections should be allowed. If an illegal choice is made, you should
display, "Unknown selection, please try again" and the menu options should be
displayed again.


If the user enters 'P' or 'p', you should display all of the elements (ints) in
the list. If the list is empty you should display "[] - the list is empty" If
the list is not empty then all the list element should be displayed inside
square brackets separated by a space. For example, [ 1 2 3 4 5 ]

If the user enters 'A' or 'a' then you should prompt the user for an integer to
add to the list which you will add to the list and then display it was added.
For example, if the user enters 5 You should display, "5 added". Duplicate list
entries are OK

If the user enters 'M' or 'm'  you should calculate the mean or average of the
elements in the list and display it. If the list is empty you should display,
"Unable to calculate the mean - no data"

If the user enters 'S' or 's' you should display the smallest element in the
list. For example, if the list contains [2 4 5 1],  you should display, "The
smallest number is 1" If the list is empty you should display, "Unable to
determine the smallest number - list is empty"

If the user enters 'L' or 'l' you should display the largest element in the list
For example, if the list contains [2 4 5 1], you should display, "The largest
number is 5" If the list is empty you should display, "Unable to determine the
largest number - list is empty"

If the user enters 'Q' or 'q' then you should display 'Goodbye" and the program
should terminate.

Before you begin. Write out the steps you need to take and decide in what order
they should be done. Think about what loops you should use as well as what you
will use for your selection logic.

This exercise can be challenging! It may likely take a few attempts before you
complete it -- that's OK!

Finally, be sure to test your program as you go and at the end.

Hint: Use a vector!

Additional functionality if you wish to extend this program.

- search for a number in the list and if found display the number of times it
occurs in the list
- clearing out the list (make it empty again) (Hint: the vector class has a
.clear() method)
- don't allow duplicate entries
- come up with your own ideas!

Good luck!

*/
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void print_menu() {
  cout << "\n---------------------" << endl;
  cout << "P - Print numbers" << endl;
  cout << "A - Add a number" << endl;
  cout << "M - Display mean of the numbers" << endl;
  cout << "L - Display the largest number" << endl;
  cout << "C - Clear numbers" << endl;
  cout << "Q - Quit" << endl;
}

void add_number_to_vector(vector<int>& vec, int num) {
  for (int val : vec) {
    if (num == val) {
      cout << val << " is already in the vector. Skipping..." << endl;
      return;
    }
  }
  vec.push_back(num);
  cout << num << " added." << endl;
}

void enter_and_validate(vector<int>& vec) {
  cout << "Enter numbers to add (separated by spaces): ";
  string line;
  getline(cin >> ws, line);
  stringstream ss(line);
  string token;

  while (ss >> token) {
    try {
      size_t idx;
      int value_to_add = stoi(token, &idx);
      if (idx != (int)token.size()) {
        throw invalid_argument("Partial match");
      }
      add_number_to_vector(vec, value_to_add);

    } catch (const invalid_argument&) {
      cout << "Invalid input: '" << token << "' is not a valid integer."
           << endl;
    } catch (const out_of_range&) {
      cout << "Invalid input: '" << token << "' is out of integer range."
           << endl;
    }
  }
}

void display_mean(vector<int>& vec) {
  int size = (int)vec.size();
  int sum{0};
  float mean{0};

  if (size == 0) {
    cout << "Vector is empty. Nothing to show..." << endl;
    return;
  }

  for (int val : vec) {
    sum += val;
  }
  mean = (float)sum / size;
  cout << "Mean: " << mean;
}

void display_largest_number(vector<int>& vec) {
  int size = (int)vec.size();
  if (size == 0) {
    cout << "Vector is empty. Nothing to show..." << endl;
    return;
  }
  int largest_num{vec[0]};
  for (int val : vec) {
    largest_num = val > largest_num ? val : largest_num;
  }

  cout << "Largest num: " << largest_num << endl;
}
int main() {
  char selection{};
  std::vector<int> numbers{};

  print_menu();
  do {
    cout << "\nEnter your choice: ";
    cin >> selection;

    switch (std::tolower(selection)) {
      case 'p':
        cout << "Printing all numbers..." << endl;

        for (int val : numbers)
          cout << val << " ";
        break;
      case 'a':
        enter_and_validate(numbers);
        break;
      case 'm': {
        cout << "Displaying mean: " << endl;
        display_mean(numbers);
        break;
      }
      case 'l':
        cout << "Displaying largest number: " << endl;
        display_largest_number(numbers);
        break;
      case 'c':
        cout << "Clear numbers..." << endl;
        numbers.clear();
        break;
      case 'q':
        cout << "Quit." << endl;
        return 0;
      default:
        cout << "Invalid choice." << endl;
        print_menu();
        break;
    }
  } while (true);

  return 0;
}
