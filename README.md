# DynamicMemory

The implementation will consist of storing the data in a "generic vector" void *arr. Each element will be defined by a header that will describe the content, followed by the actual data. For example, the address arr will contain the specific header structure, and the address arr + sizeof(struct header) will contain the actual data of the first element.

Passing the elements for adding to the vector will be done through the data_structure structure. This contains the address to a variable struct head in which the header of the added element is stored and an address to a generic data area. In the vector, both the header and the actual data will have to be copied, we don't want to store the pointers but the bytes from that address.

The program will read commands from the keyboard until receiving the exit command, after which the program will release the memory and exit.

Orders received will come in the following format:

* insert (type, sender, sum1, sum2, receiver) - the add_last function will be called
* insert_at (index, type, sender, sum1, sum2, receiver) - the add_at function will be called
* delete_at (index) - the delete_at function will be called
* find (index) - the find function will be called
* print - the entire vector will be displayed
* exit - the memory will be freed and the program will be exited

Functions:

* add_last: The function adds an element to the end of the vector arr. It receives the address of the generic vector (arr), the address of the length of the vector represented in the number of elements in the vector (len), and the pointer to the structure to pass the element (data). The length will be increased at the end of the operations. If the operations were completed successfully, then the function will return 0, otherwise it will return a value different from 0.
* add_at: Similar to the add_last function, add_at receives the address of the vector, the address of the length and the address of the data structure, but also the index at which the element is to be stored. If the index is greater than 0, nothing will be added and an error will be returned. If it is greater than the length of the vector, it will be added to the end.
* find: The function receives the data vector, its length and the index at which the display is desired. If the index is greater than the length or less than 0, nothing is displayed. Otherwise, the element from the respective index will be displayed according to the specified format.
* delete_at: The function receives the beginning of the vector, the number of current elements in the vector, and the index of the element we want to remove. We will traverse the vector up to that index and remove the element from the vector, taking care to move the remaining bits after the element, in place of the removed element.
* print: The print function receives a pointer to the data vector and the number of elements in the vector. It goes through the vector and prints the data inside the vector corresponding to the data type inside it.
* exit: Upon receiving this command, the memory is freed and the program stops.

