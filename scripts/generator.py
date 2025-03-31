import random
import string

FILE_SIZE_MB = 500
WORDS = ["hello", "world", "multithreading", "performance", "testing", "needle"]

def random_word():
    return "".join(random.choices(string.ascii_lowercase, k=random.randint(3, 10)))

def generate_large_text_file(filename, size_mb):
    size_bytes = size_mb * 1024 * 1024
    with open(filename, "w") as f:
        written = 0
        while written < size_bytes:
            line = " ".join([random.choice(WORDS) if random.random() < 0.01 else random_word() for _ in range(100)])
            f.write(line + "\n")
            written += len(line) + 1  # +1 for newline

generate_large_text_file("large_text.txt", FILE_SIZE_MB)
print(f"Generated 'large_text.txt' ({FILE_SIZE_MB}MB)")
