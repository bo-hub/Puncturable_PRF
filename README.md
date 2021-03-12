# Puncturable_PRF
This is a simple implementation of GGM Puncturable Pseudorandom Function[GGM’86].   
Partial Code was from [Aura](https://github.com/MonashCybersecurityLab/Aura).   
Further reading can be find in [link](https://www.cs.princeton.edu/~mzhandry/2016-Fall-COS597C/ln/ln4.pdf) and [link](https://www.ndss-symposium.org/wp-content/uploads/2021-162-paper.pdf).



## Puncturable Pseudorandom Function
A puncturable PRF consists of three algorithms (Setup, Punc , Eval).

- **Setup:** It takes a security parameter and outputs a PRF key.
- **Punc:** It takes a key and a set of elements and outputs a punctured key.
- **Eval:** It takes as input a punctured key and x , outputs y or a stop symbol if x is in the punctured set.

## Requirements
- git
- cmake
- openssl 1.1.1

## Building

```
git clone https://github.com/bo-hub/Puncturable_PRF.git  
cd Puncturable_PRF
mkdir build  
cd build  
cmake ..
make 
```

## Reference 
[GGM’86] O. Goldreich, S. Goldwasser, and S. Micali. How to construct random
functions. Journal of the ACM (JACM), 33(4):792- 807, 1986