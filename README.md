# Insertion-Sort-Assembly-and-C
## Purpose of the project: Insertion sort speed test

## Insertion Sort Algorithm
*Insertion sort algorithm is very simple to code, but it is a relatively slow sorting algorithm compared to sequences such as merge sort and quick sort. This easy-to-implement algorithm is used when used in smaller arrays rather than large arrays, and especially when the incoming dataset is very close to the already sorted or sorted state. The algorithm checks the data in order from the second element of the data set to be sorted, and if the previous record is larger than the current record (or depending on the sorting type if it is small), these two elements are moved and backward checks are continued. These operations are repeated until the array element is placed in the correct place.*

![Graph2](https://github.com/eroldmrclk/Insertion-Sort-Assembly-and-C/blob/master/images/graph-2.png)

##### Inline Assembly Implementations <br>

`Insertion_sort_Assembly method:` <br>
`mov ebx, 0;` -> ebx is the value that will control our loop. I have assigned it 0 for now. <br>
`mov edx, arr;` -> At this stage, I assign the array to be sorted to edx. <br>


`numcmpbase:` <br>
`inc ebx;` -> Add 1 to ebx. Like ebx++ in high level language. <br>
`mov ecx, ebx;` -> Here I copy the ebx to ecx because I will have to make changes to ebx in the future. Therefore, I will use ecx as a temporary variable to avoid losing the original value of ebx. <br>
`cmp ebx, sizeofarray;` -> I compare sizeofarray with ebx because ebx will increase at each stage and when it sorted all variables, ebx will end the loop. <br>
`jae finish;` -> As a result of the comparison in the previous stage, if sizeofarray is not bigger than ebx, it will jump finish stage. <br>
`mov esi, siz;` -> siz is equal to size of int, so it is 4. <br>
`imul esi, ecx;` -> We multiply esi with the temporary variable ecx, and our new esi value becomes the value we multiply because we need to use this value in the next step. <br>
`add esi, arr;` -> We add the esi value to arr. What we've done here is arr, pointing to the starting point of our array. We add 4 to the starting point and reach other values. The reason we add 4 is the values in the array are integer. <br>
`jmp whilecontrol;` -> Jump whilecontrol stage. <br>

`whilecontrol:` <br>
`cmp ecx, 1;` -> Compare ecx to 1. Why do i need to compare these values? In the inline assembly code, I wrote has a for loop and a while loop. This comparison is the necessary comparison to get out of the while loop. <br>
`jl numcmpbase;` -> jl represents for “jump if less”. So, if ecx is less than 1 go to numcmpbase stage. Because there are no more numbers to compare at this stage. <br>
`dec ecx;` -> Delete 1 to ebx. Like ecx-- in high level language. <br>
`mov edi, siz;` -> siz is equal to size of int, so it is 4. <br>
`imul edi, ecx;` -> We multiply edi with the temporary variable ecx, and our new edi value becomes the value we multiply because we need to use this value in the next step. <br>

`add edi, arr;` -> We add the edi value to arr. What we've done here is arr, pointing to the starting point of our array. We add 4 to the starting point and reach other values. The reason we add 4 is the values in the array are integer. As you can see from the code, the esi we hold in memory previously refers to the number sorted, and edi refers to the numbers compared. <br>
`push ebx;` -> We add the ebx into the stack Because we're going to call a method a little later, if we don't add it to the stack, we lose the ebx value. <br>
`push ecx;` -> We add the ecx into the stack Because we're going to call a method a little later, if we don't add it to the stack, we lose the ecx value. <br>
`push esi;` -> We add the esi into the stack Because we're going to call a method a little later, if we don't add it to the stack, comparator method cannot find number to compare. <br>
`push edi;` -> We add the edi into the stack Because we're going to call a method a little later, if we don't add it to the stack, comparator method cannot find number to compare. <br>
`call comparator;` -> We call the comparator method, and it compares the esi and edi values we provide. <br>
`add esp, 8;` ->  We add 8 esp in stack. Thus, edi and esi are removed in stack. <br>
`pop ecx;` ->  We get it from the stack and this value is ecx. <br>
`pop ebx;` -> We get it from the stack and this value is ebx. <br>
`cmp eax, 2;` -> Here, eax is the result that the comparator method returns to us. This result can be 0, 1, and 5. Therefore, it will be enough for us to compare it with 2. <br>
`jl swapping;` ->  If jump is less than, go to swapping stage. So, if eax is equal to 0 or 1, go to swapping stage. <br>
`jmp numcmpbase;` -> If it does not enter the above state, it will automatically enter here and return to the numcmpbase stage. This shows us that a number in the array is sorted. <br>

`swapping:` <br>
`push ebx;` -> We add the ebx into the stack Because we're going to call a method a little later, if we don't add it to the stack, we lose the ebx value. <br>
`push ecx;` -> We add the ecx into the stack Because we're going to call a method a little later, if we don't add it to the stack, we lose the ecx value. <br>
`push edi;` -> We add the edi into the stack Because we're going to call a method a little later, if we don't add it to the stack, swap_a method cannot find number to swap. <br>
`push esi;` -> We add the esi into the stack Because we're going to call a method a little later, if we don't add it to the stack, swap_a method cannot find number to swap. <br>
`call swap_a;` -> We call the swap_a method, and it swaps the esi and edi values we provide. <br>
`add esp, 8;` -> We add 8 esp in stack. Thus, edi and esi are removed in stack. <br>
`pop ecx;` -> We get it from the stack and this value is ecx. <br>
`pop ebx;` -> We get it from the stack and this value is ebx. <br>
`sub esi, siz;` -> subtract siz from esi because I need the number in the subindex to compare. <br>
`jmp whilecontrol;` -> Jump whilecontrol stage. <br>

`finish:` <br>
Nothing is done here and exiting insertion_sort_Assembly method. <br>


##### Graphical Result for This Project
![Graph1](https://github.com/eroldmrclk/Insertion-Sort-Assembly-and-C/blob/master/images/graph-1.png)
