"""
SCRABBLE
- GIVEN A LIST OF WORDS OUTPUT THE ONE THAT HAS MORE PUNCTUATION USING THE FOLLOWING CRITERIA
    - e, a, i, o, n, r, t, l, s, u are equal 1 point
    - d, g are equal 2 points
    - b, c, m, p are equal 3 points
    - f, h, v, w, y are equal 4 points
    - k is equal 5 points
    - j, x are equal 8 points
    - q, z are equal 10 points
    - THE MAX LENGHT OF A WORD IS 10 LETTERS
"""

def punctuation(words):
    points = 0
    prev_points = points
    highests = []
    for i in words:
        i = i.lower()
        points = 0
        for j in i:
            if j in ["e", "a", "i", "o", "n", "r", "t", "l", "s", "u"]:
                points += 1
            elif j in ["d", "g"]:
                points += 2
            elif j in ["b", "c", "m", "p"]:
                points += 3
            elif j in ["f", "h", "v", "w", "y"]:
                points += 4
            elif j in ["k"]:
                points += 5
            if j in ["j", "x"]:
                points += 8
            if j in ["q", "z"]:
                points += 10
        if points > prev_points:
            highests = []
            prev_points = points
            highests.append(i)
        elif points < prev_points:
            pass
        elif points == prev_points:
            highests.append(i)
    return highests, points

while True:
    print("\nEnter a list of words with this format: word1, word2, word3...")
    valid = False
    while valid == False:
        entry = input("-> ")
        try:
            entry = entry.replace(" ", "")
            words = entry.split(",")
            for i in words:
                i.lower()
                if len(i) > 10:
                    print(f"{i} is longer than 10 letters")
                    valid = False
                    break
                else:
                    valid = True
        except:
            print("Your entry is not valid")

    print(f"The word with the highest punctuation are {punctuation(words)[0]} with {punctuation(words)[1]} points")