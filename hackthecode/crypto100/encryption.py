
from sympy import nextprime, randprime
from Crypto.Util.number import *

flag = "*********************************"

def rsa_encrypt(plaintext, e, N):
    plaintext_bytes = bytes(plaintext, 'utf-8')
    pt_int = int.from_bytes(plaintext_bytes, 'big')
    ciphertext = pow(pt_int, e, N)
    return ciphertext

base_prime1 = randprime(2**511, 2**512)

p1 = base_prime1
p2 = nextprime(p1)
p3 = nextprime(p1*p2)
p4 = nextprime(p1*p2*p3)

N = p1 * p2 * p3 * p4
e = 65537

ct = rsa_encrypt(flag, e, N)
