#include <iostream>
#include <vector>

using namespace std;

vector<int> list_all_duplicates(vector<int> input) {
  vector<int> output;
  for (int key: input) {
    int count = 0;
    for (int num: input) {
      if (key == num) {
	count++;
      }
    }
    if (count > 1)
      output.push_back(key);
  }
  return output;
}

int main(int argc, char* argv[]) {
  vector<int> input {1,7,5,8,1,3,8};

  vector<int> duplicates = list_all_duplicates(input);

  for (int duplicate: duplicates)
    cout << duplicate << endl;
  return 0;
}
