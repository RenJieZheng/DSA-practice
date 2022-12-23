```c++
void bubbleSort(int arr[], int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

//Swap function
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
```