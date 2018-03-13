# unordered_map
- header <unordered_map>
- operator[] will return a reference to the value in the bracket, or returns a reference to a new object created from the bracket

#unorderd_set
- header <unordered_set>

# next_permutation
- header <algorithm>
- lexiographically finds the permutations
    ```c++
    #include <algorithm>
    #include <string>
    #include <iostream>
    
    int main()
    {
        std::string s = "aba";
        std::sort(s.begin(), s.end());
        do {
            std::cout << s << '\n';
        } while(std::next_permutation(s.begin(), s.end()));
    }
    ```
    output: aab,aba,baa

# vector
- header <vector>
- dynamic array like data structure.