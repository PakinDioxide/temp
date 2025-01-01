import PyPDF2

# Path to the locked PDF file
pdf_path = 'speed.pdf'
import itertools

# Define all characters on a standard keyboard
characters = (
    "abcdefghijklmnopqrstuvwxyz"  # Lowercase letters
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"  # Uppercase letters
    "0123456789"                  # Numbers
    "!@#$%^&*()_+-=[]{};':\",./<>?`~"  # Symbols
)

# Function to brute-force all strings of length 1 to 15
def brute_force_strings():
    for length in range(1, 16):  # Lengths from 1 to 15
        for combination in itertools.product(characters, repeat=length):
            yield "".join(combination)

# Example usage
with open(pdf_path, 'rb') as pdf_file:
        reader = PyPDF2.PdfReader(pdf_file)
        for string in brute_force_strings():
            print(string)
            if reader.decrypt(string):
                print(f"Password found: {string}")
                break
            
            if len(string) > 15:  # Safety check to stop after length 15
                break
"""
if reader.decrypt(password):
                print(f"Password found: {password}")
                return
            """