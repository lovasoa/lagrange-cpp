CC=clang++
CPPFLAGS=-std=c++14

%: %.o
	$(CC) $(CPPFLAGS) $< -o $@

all: coeffs poly_exec
clean:
	rm -rf coeffs poly_exec
