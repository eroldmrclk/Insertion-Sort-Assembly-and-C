#include <stdio.h>
#include <time.h>

#define IS_LESS	    5
#define IS_EQUAL	0
#define IS_MORE		1

void insertion_sort_C(int arr[], int sizeofarray);

void swap_a(void* e1, void* e2);
void insertion_sort_Assembly(int* arr[], int sizeofarray, size_t siz, int(*comparator) (const void*, const void*));
int comparator(const void* elem1, const void* elem2);

int comparator(const void* elem1, const void* elem2) {
	int* val1 = (int*)elem1;
	int* val2 = (int*)elem2;
	if (*val1 < *val2) {
		return IS_LESS;
	}
	else if (*val2 < *val1) {
		return IS_MORE;
	}
	else {
		return IS_EQUAL;
	}
}


void insertion_sort_C(int arr[], int sizeofarray) {
	int temp = 0;
	for (int i = 1; i < sizeofarray; i++) {
		temp = i;
		int temp_variable = arr[temp];
		while (arr[temp - 1] > temp_variable) {
				arr[temp] = arr[temp - 1];
				temp = temp - 1;
		}
		arr[temp] = temp_variable;
	}
}


void swap_a(void* e1, void* e2) {
	_asm {
		mov esi, e1
		mov eax, [esi]
		mov edi, e2
		mov edx, [edi]
		mov[esi], edx
		mov[edi], eax
	};
}

	void insertion_sort_Assembly(void* arr, int sizeofarray, size_t siz, int(*comparator) (const void*, const void*)) {
		_asm {
			mov ebx, 0;
			mov edx, arr;

		numcmpbase:
			inc ebx;
			mov ecx, ebx;
			cmp ebx, sizeofarray;
			jae finish;
			mov esi, siz;
			imul esi, ecx;
			add esi, arr;
			jmp whilecontrol;

		whilecontrol:
			cmp ecx, 1;
			jl numcmpbase;

			dec ecx;
			mov edi, siz;
			imul edi, ecx;
			add edi, arr;

			push ebx;
			push ecx;
			push esi;
			push edi;
			call comparator;
			add esp, 8;
			pop ecx;
			pop ebx;

			
			cmp eax, 2;

			jl swapping;
			jmp numcmpbase;

		swapping:
			push ebx;
			push ecx;
			push edi;
			push esi;
			call swap_a;
			add esp, 8;
			pop ecx;
			pop ebx;

			sub esi, siz;
			jmp whilecontrol;

		finish:

		};
	}

int main(int argc, char* argv[]) {
	int i;
	int arr[4000];
	clock_t cas;

	for (i = 0; i < 4000; i++) {
		arr[i] = 4000 - i;
	}
	cas = clock();
	insertion_sort_C(arr, 4000);
	cas = clock() - cas;
	printf("\nC Sort took %f seconds.\n", (double)cas / CLOCKS_PER_SEC);

	for (i = 0; i < 4000; i++) {
		printf("%d ", arr[i]);
	}

	for (i = 0; i < 4000; i++) {
		arr[i] = 4000 - i;
	}

	cas = clock();
	insertion_sort_Assembly(arr, 4000, sizeof(int), comparator);
	cas = clock() - cas;
	printf("\n Assembly Sort took %f seconds.\n", (double)cas / CLOCKS_PER_SEC);

	for (i = 0; i < 4000; i++) {
		printf("%d ", arr[i]);
	}

	system("pause");

	return 0;
}