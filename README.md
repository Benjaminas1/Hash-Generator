# Hash-Generator
This is a university project to make a hashing algorithm that would meet the requirements of a good hashing algorithm.

# About the hashing algorithm

Hashing algorithm meets these requirements:

* Output is allways the same size: 256 bits / 64 symbols hex.
* Same input always has the same output.
* Input size is not limited.
* Hashing algorithm is deterministic.
* Collision resistant.
* Fast.
* Avalanche effect based.

Algorithm upsides:
Good collision resistance, avalanche effect.

Algorithm downsides:
Relativelly slow compared to other hashing algorithms (almost 2 times slower than sha256), diversity could be improved.

# How it works

The algorithm has a primary hash, that is then modified. Decimal value is taken from every character of the string and added to a list (further - "list") as well as summed with all other character decimals. If input string is shorter than 64 symbols, then algorithm loops though the list multiple times, adding every list item, as well as list sum, to characters of the hash, until every hash symbol has been changed. If the input string is longer than 64 symbols, then the algorithm loops though every item of the list and the hash, adding multiple list items to hash symbols.

# Program content

When you open the program, you can choose one of 6 options:

1. Input from command line
2. Input from file
3. Basic tests
4. Hash function effectiveness test
5. Collision test
6. Diversity test

### Input from command line

        Input: awsd
        e9d3ca659e1f1237901efaeb9f82bf472dc147076abe996faab89f3e7e75be75

### Input from file

        Input file name (without .txt extention): a   
        13d720659a62de44b15717ca0f21e94b83c1435a26cbbaa8c7970fdda8791b58

### Basic tests

        Performing basic tests: 
        .......................................
        Two files with different single symbols
        a.txt - 13d720659a62de44b15717ca0f21e94b83c1435a26cbbaa8c7970fdda8791b58
        b.txt - 5859b9b731e181bd8f609dbd0e08ae99c093b68d59003c31193e8e8011472dfc

        Two files with (>1100) random symbols
        1100randSymbols.txt - 1aef02e967200115c407cec8eab5d67b5c1c0549b31e1f497b168cff73a433ec
        1100randSymbols2.txt - 38128b01f9f5fbb79a491af84b0bf7ecdc45f6226b0ff6c1ef77f03027f0d805

        Two files with 1 different symbol
        fileA.txt - b39339b52b19674c344e29a3011f69ed7cafd0d2a1c9ede412c7249fdec6441d
        fileB.txt - e5b55bd74d3b885d455f3ab412207afe8db0e1e3b2dafef523d835a0efd7552e

        Empty file
        86ce601b0fa462069209e0b382631dcff298ca0e1f3ac1b45f162649c952fa57

### Hash function effectiveness test

        Performing algorithm affectiveness tests:
        .........................................
        Custom hash time: 6.05924s
        MB5 hash time: 1.23676s
        SHA1 hash time: 2.22947s
        SHA256 hash time: 3.73529s

### Collision test

        Performing hashing algorithm collision test
        ...........................................
        Collisions: 0 out of 100000

### Diversity test

        Performing hashing algorithm diversity test
        ...........................................
                                           bits    hex
        Maximum collisions in pair (%):   94.92  79.69
        Minimum collisions in pair (%):   57.03      0
        Average collisions in pair (%):   77.79  35.16

# How to run:
        
        g++ includes/functions.cpp hashingAlg/md5.cpp hashingAlg/sha1.cpp hashingAlg/sha256.cpp main.cpp -o3 -o main
        
        



