# C Data Structures Library 🔗
DSlib is a C library, Epitech C coding style compliant and easy to use, to implement generics data structures.
**Memory leak free**. 

## How to
### 🤖 Compile the lib:
> make
### 🛠 Run unit tests:
*you **must have** criterion library installed*
> make tests
### 🧪 Run unit tests with coverage:
*you **must have** gcovr installed*
> make coverage

## 📈 Generic doubly linked list basic usage example
```c
void print(dnode_t elem)
{
    printf("%d\n", *(int *)elem->data);
}

int main(void)
{
    dll_t list = dll_init(sizeof(int));                  // list init
    dnode_t fetch = NULL;
    int n[] = {21, 42, 1};
    
    list->push_back(list, &n[0]);                        // add node with value 21 at the end
    list->push_front(list, &n[1]);                       // add node with value 42 at the begining
    list->insert(list, 1, &n[2]);                        // add node with value 1 at index 1
    list->for_each(list, &print);                        // apply the function print to all nodes
    list->clear(list);                                   // free all nodes and list
    return 0;
}
```

## Unit tests

lines | branches
----- | --------
 95%  |   91%

The untested lines/branches are malloc return value check, feel free to make a pull request if you have a clean way to test it with criterion.
