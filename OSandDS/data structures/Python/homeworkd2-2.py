# if man was mean to stay on the ground, god would have given us roots.
# С>=R и С-R <= 1

import string

text = input("Введите текст: ")
text = text.translate(str.maketrans("", "", string.punctuation + " "))
text = text.lower()

length = len(text)
rows = int(length ** 0.5)
cols = rows if rows * (rows + 1) >= length else rows + 1

fragments = []
for i in range(rows):
    fragments.append(text[i*cols:(i+1)*cols])

if length % cols != 0:
    last_fragment = text[rows*cols:] + " "
    fragments.extend(last_fragment)

for fragment in fragments:
    print(fragment, end=" ")
