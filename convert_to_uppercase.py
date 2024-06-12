import time

t1 = time.time()
with open("200mb (copy).txt", "r") as f:  # change file name for different files
    text = f.read().upper()
with open("200mb (copy).txt", "w") as f:  # name must be same as above file
    f.write(text)
t2 = time.time()
print(t2 - t1)