#include<iostream>
#include<vector>
using namespace std;

vector<int> sanjith_solution(vector<int> input) {
  int temp = 1;
  vector<int> output;
  for (int num: input) {
    output.push_back(temp);
    temp *= num;
  }
  temp = 1;
  for (int i = input.size() - 1; i >= 0; i--) {
    output[i] *= temp;
    temp *= input[i];
  }
  return output;
}

vector<int> naive_solution(vector<int> input) {

  vector<int> output;
  for (int i = 0; i < input.size(); i++) {
    int product_of_others = 1;
    for (int j = 0; j < input.size(); j++) {
      if (i != j) {
	product_of_others *= input[j];
      }
    }
    output.push_back(product_of_others);
  }
  return output;
}

vector<int> using_division(vector<int> input) {
  int product = 1;
  bool zero_present = false;
  for (int num: input)
    if (num != 0)
      product *= num;
    else
      zero_present = true;
  
  vector<int> output;

  for (int num: input) {
    int out = 0;
    if (zero_present && num == 0)
      out = product;
    else if (zero_present && num != 0)
      out = 0;
    else
      out = product / num;
    output.push_back(out);
  }
  return output;
}

int main(int argc, char* argv[]) {
  vector<int> input {10};

  vector<int> output = sanjith_solution(input);

  for (int num: output)
    cout << num << endl;
}
