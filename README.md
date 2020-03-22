# C Data Structures Library
DSlib is a C library, Epitech C coding style compliant and easy to use, to implement generics data structures.
**Memory leak free**. 

## How to
### Compile the lib:
> make
### Run unit tests
*you **must have** criterion library installed*
> make tests
### Run unit tests with coverage
*you **must have** gcovr installed*
> make coverage

## Generic doubly linked list basic usage example
```c
void add_2(dnode_t elem)
{
    elem->data = (void *)((unsigned long)elem->data + 2);
}

int main(void)
{
    dll_t list = dll_init();                              // list init
    dnode_t fetch = NULL;
    
    list->push_back(list, (void *)21);                    // add node with value 21 at the end
    list->push_front(list, (void *)42);                   // add node with value 42 at the begining
    list->insert(list, (void *)1, 1);                     // add node with value 1 at index 1
    list->for_each(list, &add_2);                         // apply the function add_2 to all nodes
    fetch = list->get_back(list);                         // get the last node
    if (fetch == NULL) {
        return 1;
    }
    printf("value: %ld\n", (unsigned long)fetch->data);   // print its value ("last node value: 21")
    list->pop_at(list, 1);                                // remove node at index 1
    printf("list size: %ld\n", list->size);               // print list size ("list size: 2")
    list->clear(list);                                    // free all nodes and list
    return 0;
}
```

## Unit tests

lines | branches
----- | --------
 95%  |   92%

The untested lines/branches are malloc return value check, if you have a clean way to test it with criterion, feel free to make a pull request.
