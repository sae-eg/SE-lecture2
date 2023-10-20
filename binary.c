#include <stdio.h>

int binary_search (int key, int m, int n, int a[]){
	int i, j, p;
	i = m;
	j = n;
	int counter = 0;

	while (i <= j){
		counter++;
		p = (i+j)/2;
		if (key < a[p])
			j = p-1;
		else if (key > a[p])
			i = p+1;
		else
			return counter;
	}
	return -1;
}

int main(){
	int a[20] = {5, 7, 15, 18, 22, 35, 40, 48, 50, 54, 60, 62, 68, 70, 77, 80, 85, 88, 90, 96};
	int key;
	printf("Key? ");
	scanf("%d", &key);
	int count = binary_search(key, 0, 19, a);
	if (count == -1)
		printf("Not Found.\n");
	else
		printf("Found (Step = %d)\n", count);

	return 0;
}