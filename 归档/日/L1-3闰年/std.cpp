#include<iostream>
using namespace std;
int main() {
	int n, input;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &input);
		if (input % 400 == 0)
			printf("%04d is shiji runnian!\n", input);
		else if (input % 100 == 0)
			printf("%04d not is runnian!\n", input);
		else if (input % 4 == 0)
			printf("%04d is putong runnian!\n", input);
		else
			printf("%04d not is runnian!\n", input);
	}
}