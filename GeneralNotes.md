# [bigO Cheat Sheet](http://bigocheatsheet.com/)



# arrays 
- ```c++
    int a[10]; //declares an array of size 10 with no elements currently inside;
    int a[]={5,6,7} //declares an array of size 3 with the initializer inserting 3 elements
    int a[10]={4,5} //declares an array of size 10 with the initializer giving it the first 2, the rest are essentially zero  
    ```
- Also arrays in c++ are contiguos, meaning that all of their elements rest right next to each other, so we can locate an element by taking the memory location of the first element, and add the size*element number
## passing an array
- in c++ there are multiple ways to pass an array to a function, but essentially they mean the same thing
    ```c++
        void foo(int a[]) // is equivalent to...
        
        void foo (int* a)
    ```


# References and pointers
- pointer and reference: essentially points to a place in memory, but what you can do is with them is different
- they both serve as a way to quickly get to place in memory
```c++
    int* //  is the declaration for an int pointers
    int& //is the declaration for an int  reference
```

## References vs pointers

- pointers can be null and be changed
- references are set to a single memory spot and must be set at instantiation
- There are also certain 

## uses
- pointers 
    - to access the actual values of a pointer you must use * with the variable name
    ```c++
        int a=9; // integer a allocated onto the stack
        int* g= &a // pointer g is set to the memory address of a via reference
        int *b = new int; //pointer to new int variable declared on the heap
        *b=20; // value of b is set to 20;
        delete b; //clean up
    ```
  - can be used to maintain and keep track of dynamically allocated objects (see Dynamic allocation)
  - keep track of nodes generated for data structures (which kinda goes hand in hand with dynamic allocation)
  - variants
    - unique_ptrs and shared_ptrs are ptrs that automatically deallocate on the stack when they fall out of scope, they are very hand for keeping clean track of things without worries of memory, but come with their own sets of draw backs. Unique pointers are only allowed to have one object pointing to anything on the stack, so no other pointers can touch them, leading to an exclusive object that will be deallocated, but may lead to minor incontinences later down the road. Shared pointers don't have this problem, however they do run a risk of circular references, a shared pointer object points at another one and vice versa. They will never fall out of scope regardless of if anything actually can access them, leading to memory leaks. Weak pointers are available and can fix this, but it requires some extra steps and thinking that while working alone may be fine, will not be great when in a group. 
    - Pointers can also point to other pointers via the ** identifier.
- references
    - references I've found to be less of a utility and more of a necessity. They allow for low memory cost passing of variables.
    ```c++
        int foo(const somethingCrazy& fo)
    ```
    - in this case, something crazy might be a large variable that is thousands or millions of bytes long. By default c++ passes a copy of any variables passed as arguments to a function. This means there are now _2_ huge variables in your memory, that it also needed to copy via some copy constructor most likely. In order to mitigate that, passing it by reference allows you to pass the original object. This is dangerous however as you could incidentally change the original object unintentionally, which is why we add the *const* identifier in front. 
    - ex: say you have a vector of 10,000 elements and want to return it via a function to a new vector. This would require the new vector to a) overwrite all its elements with the new ones, or b) construct a new vector from all the elements. Neither of these are efficient, however if we pass the vector by function, we are essentially telling the new vector that it is what is being returned by the function, saving a huge amount of time. 


# USING NAMESPACE <libraries>
- cons: if using multiple libraries, if they have the same function it could cause errors
- pros: saves time? 

# constant
- in c++ we can add **const** as an identifier in places to define them as constant.
- const int means that it is a constant integer that __can not__ be modified
    ```c++
        int i=1; //not constant
        const int i2=1; //constant, equivalent to int const i2=1

        i=2; //ok
        i2=5; //not ok

        const int& ri=i; //reference to const bound to non const object 
        const_cast<int&> ri=5 //ok but why would you do this

        const int& r2=i2; //const to const
        const_cast<int&> r2=7; //NOT ok, attempting to modify const i2
    ```
- where the const is in a class definition can wildly alter its meaning (see classes)
- pointers and references can have drastic different meanings with const
    - const int* i; // a pointer to a const integer
    - int* const i; // pointer that is constant to an integer
    - const int* const i;// a pointer that is constant to a constant integer

#  C++ Classes

## well behaving
- There are well behaved classes which require three elements
    - a constructor, destructor, and copy constructor
   
    ```c++
    class foo:
        public: // methods, functions, and variables in public are usable by the objects instantiated from them
            foo(); // constructor that is called at runtime
            foo(foo &other); // copy constructor that is called when creating a new object based on another
            ~foo(); // destructor called when delete is called or an object falls of the stack
        private: // methods, functions, and variables that are owned by the object but are not usable by them outside the functions 
            int fooInt; //private int variable. is 8 bits
            float fooFloat; //private float vairble. is 16 bit
            double fooDouble; // private float. is 32 bit
    ```

## initializer lists
- c++ allows us to pass values to a class via the constructor even before the function begins to execute
    ```c++
        #include <string>
        class foo
        {
            public foo(int lol, std::string lmao)
                :lol{lol},lmao{lmao}
                {};
            private:
                int lol;
                std::string lmao
        }
    ```
## setting up safely
- two files, class.cpp and class.hpp, the header file declares everything, while the cpp defines everything

    ```c++
        //hpp file
        #ifndef CLASS_FILE_NAME_HPP
        #define CLASS_FILE_NAME_HPP
        class: className
        {
            public:
                className()
            private:
        }
        #endif
        
        //cpp file

        #include "Class_file_name.hpp"

        className::className() //must declare that this function is from the class.
    ```
## inheritance
- 
    ```c++
            class fooParent{
                public:
                    virtual std::string to_string() // Virtual establishes that this function will be overriden, meaning that whatever
                                        // it is supposed to do will be handled in the derived class as opposed to the parent
                                        // also if a parent pointer object points at a derived object and calls this virtual function
                                        // it will use the derived class version instead.
            }
            class foo: public fooParent
            {
                public:
                // foo inherets all public variables and functions of its parent as public members

                std::string  to_string() // the foo child version of to_string
                private:
                // foo also inherets all private memebers as private members
            }
    ```


## Operator overloading
- Operators can be overloaded within a class's functions, this includes: arithmetic and comparisons with a variety of different data types. As well as ***=*** which acts like a copy constructor, but via overwriting the current values. These must be defined as object memebers except for << and >> as these must defined as ***std::ostream& operator<<(std::ostream& os, const T& obj)*** and ***std::istream& operator>>(std::istream& is, T& obj)***
    ```c++

        <EXPECTED RETURN TYPE IF ANY> operator <OPERATION BEING OVERLOADED>(const <class>& <RIGHT HAND ARGUEMENT> );

    ```

# function overloading
- c++ allows us to take a function with the same name, and construct another function with the same name, but different parameters, this includes things like class constructors so we can have multiple different possible derivatives.
# Friend
- can touch private variables...

