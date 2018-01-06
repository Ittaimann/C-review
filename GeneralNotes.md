# [bigO Cheat Sheet](http://bigocheatsheet.com/)


# References vs pointers

- pointers can be null and be changed
- references are set to a single memory spot and must be set at instantiation

# USING NAMESPACE <libraries>
- cons: if using multiple libraries, if they have the same function it could cause errors
- pros: saves time? 

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
## overloading
- a function can be "overloaded", essentially meaning that it redefines an already existing one. For example the comparisions
    ```c++

        bool operator ==(const <class>& rhs);
        bool operator !=(const <class>& rhs);
        bool operator =>(const <class>& rhs);
        bool operator =<(const <class>& rhs);
        bool operator >(const <class>& rhs);
        bool operator <(const <class>& rhs);

    ```
# Friend
- can touch private variables...
