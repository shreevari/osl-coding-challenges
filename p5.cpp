#include <iostream>
#include <vector>

using namespace std;

vector<char> longest_substring_without_repetition(vector<char> input) {
  int output_start = 0, output_end = 0;
  vector<char> output;
  
  int curr_substr_start = 0, curr_substr_end = 0;

  for (int str_idx = 0; str_idx < input.size(); str_idx++) {
    if (curr_substr_start == curr_substr_end) {
      curr_substr_start = str_idx;
      curr_substr_end = curr_substr_start + 1;
    }
    else {

      for (int substr_idx = curr_substr_start; substr_idx < curr_substr_end; substr_idx++) {

	if (input[substr_idx] == input[str_idx]) {
	  curr_substr_start = str_idx;
	  break;
	}
	
      }
      curr_substr_end++;
    }

    if (output_end - output_start < curr_substr_end - curr_substr_start) {
      output_start = curr_substr_start;
      output_end = curr_substr_end;
    }

  }

  for (int i = output_start; i < output_end; i++) {
    output.push_back(input[i]);
  }

  return output;
}

int main(int argc, char* argv[]) {
  vector<char> input;

  for (char* c = argv[1]; *c != '\0'; c++)
    input.push_back(*c);
  
  vector<char> output = longest_substring_without_repetition(input);

  for (char chr: output)
    cout << chr;
  cout << endl;

  return 0;
}
