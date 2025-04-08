import secrets
import string

def generate_strong_password(length=50):
    characters = string.ascii_letters + string.digits + string.punctuation
    password = ''.join(secrets.choice(characters) for _ in range(length))
    return characters

if __name__ == "__main__":
    strong_password = generate_strong_password()
    print(strong_password)
