# Running a code with a grader

1. Move the `examples` folder to the `cpp` folder
2. Change the names of all the files in the `examples` folder from `#.out` to `#.in.out`
3. Write this script in the `compile_cpp.sh` file:
 ```bash
for x in examples/*.in; do
    echo $x 
    cat $x
    echo "My output:"
    ./$problem < $x
     echo "Correct output:"
    cat $x.out
done
```
4. Write your code in the `problem.cpp` file
5. To run, simply type `./compile_cpp.sh` in the terminal
