import cmath

def fft(p):
    n = len(p)
    if n == 1:
        return p
    w = cmath.exp(2 * cmath.pi * complex(0, 1) / n)
    pe, po = p[::2], p[1::2]
    ye, yo = fft(pe), fft(po)
    y = [0] * n
    for j in range(n // 2):
        y[j] = ye[j] + (w**j) * yo[j]
        y[j + n // 2] = ye[j] - (w**j) * yo[j]
    return y

def ifft(p):
    n = len(p)
    p_conj = [x.conjugate() for x in p]
    result_conj = fft(p_conj)
    return [x.conjugate() / n for x in result_conj]

def multiply_polynomials(A, B):
    n = 1
    while n < max(len(A), len(B)): n = n << 1
    n <<= 1  # Ensure size is a power of 2

    # Step 1: Pad A and B with zeros to make them of size n
    A.extend([0] * (n - len(A)))
    B.extend([0] * (n - len(B)))

    # Step 2: Compute FFT of both polynomials
    fa = fft(A)
    fb = fft(B)

    # Step 3: Pointwise multiplication
    fc = [fa[i] * fb[i] for i in range(n)]

    # Step 4: Compute IFFT of the product
    result = ifft(fc)

    # Round to integer values for coefficients
    return [round(x.real) for x in result]

# Example usage:
A = [1, 2, 3, 4]  # Polynomial: x^2 + 2x + 3
B = [5, 6, 7, 8, 9]  # Polynomial: 4x^2 + 5x + 6

result = multiply_polynomials(A, B)
print(result[:9])  # Output the result of polynomial multiplication