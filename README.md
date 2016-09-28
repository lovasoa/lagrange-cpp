# lagrange-cpp
Lagrange interpolation polynomials in C++11

## Usage
Let's create a polynomial function that passes through the points (0,0) (2,4) (10,100).

#### Compile the files
```sh
$ make
```

#### Create a file that contains the point coordinates
Une point per line. X and Y coordinates are separated by a space.
```sh
$ cat > points.txt
0 0 
2 4
10 100
```

#### Generate the polynomial coefficients
Let's write the coefficients to a file named `polynom.txt`.
```sh
$ ./coeffs < points.txt > polynomial.txt
$ cat polynomial.txt 
0
0
1
```

We can see that the generated polynomial function is `f : x -> 0 + 0*x + 1*x^2`. This is the square function, as expected.

#### Evaluate the resulting function
Let's evaluate the function between 0 and 10.
```sh
$ seq 0 10 | ./poly_exec polynomial.txt 
0
1
4
9
16
25
36
49
64
81
100
```
