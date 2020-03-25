#include <iostream>
#include <vector>

using namespace std;

int maximum_number_of_books(vector<int> prices, int target) {

  int count = 0;
  int current_total = 0;
  bool end = false;
  while (current_total < target && !end) {
    int min = target + 1;
    int min_pos = 0;
    for (int i = 0; i < prices.size(); i++) {
      if (prices[i] < min) {
	min = prices[i];
	min_pos = i;
      }
    }
    prices[min_pos] = target + 1;
    if (current_total + min <= target) {
      current_total += min;
      count++;
    } else {
      end = true;
    }
  }
  return count;
}

int main(int argc, char* argv[]) {
  vector<int> prices {30,30,10,10};
  int target = 50;

  cout << maximum_number_of_books(prices, target) << endl;

  return 0;
}
