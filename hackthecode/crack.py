from zipfile import ZipFile 

def UZ(pwd, file_name="crypto.zip"):
    with ZipFile(file_name, "r") as z:
        z.extractall(path="crypto", pwd=pwd.encode("utf-8"))

s1 = ["alexander", "alex", "buddy"]

for i in range(10000):
    # print(i)
    # for j in range(32):
    try:
        p = f"buddy-03/2021-Salah-{i:04}"
        # print(p)
        UZ(p)
        print(p)
        break
    except:
        pass