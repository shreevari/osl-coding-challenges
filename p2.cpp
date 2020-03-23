#include <iostream>
#include <vector>

using namespace std;

int smallest_missing_positive_integer(vector<int> input) {

  if (input[0] > input[1]) {
    int temp = input[0];
    input[0] = input[1];
    input[1] = temp;
  }
  if (input[1] < 0)
    return 0;
  if (input[0] < 0)
    input[0] = 0;
  for (int i = 2; i < input.size(); i++) {
    if (input[i] < input[0] && input[i] > 0) {
      input[1] = input[0];
      input[0] = input[i];
    }
    if (input[i] > input[0] && input[i] < input[1]) {
      input[1] = input[i];
    }
  }
  if (input[0] == input[1])
    return input[1] + 1;
  else
    return input[1] - 1;

  for (int i = 0; i < input.size(); i++) {
    cout << input[i] << endl;
  }
  return 0;
}

int main(int argc, char* argv[]) {

  vector<int> input {1, 4, 3, 0, 12, -12, 45};

  int output = smallest_missing_positive_integer(input);

  cout << output;
}
