def merge_segments(input):
    output = 0
    for i, e in enumerate(input):
        output += e << (i * 2)
    return output


if __name__ == "__main__":
    # index:
    #   1
    # 2   0
    #   3
    # 6   4
    #   5

    # value: 0=off, 1=white, 2=yellow, 3=blue

    input = [
        [2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [2, 2, 2, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1],
        [1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
        [0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0],
        [2, 2, 2, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0],
        [1, 1, 0, 1, 0, 0, 3, 0, 1, 1, 1, 0, 0, 3],
        [1, 1, 0, 1, 3, 0, 3, 0, 1, 1, 1, 3, 0, 3],
        [1, 1, 0, 1, 3, 1, 3, 0, 1, 1, 1, 3, 1, 3],
        [1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1],
        [1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1],
        [1, 1, 0, 1, 3, 0, 1, 0, 1, 1, 1, 3, 0, 1],
        [2, 2, 0, 1, 0, 0, 3, 0, 1, 1, 1, 0, 0, 3],
        [2, 2, 0, 1, 3, 0, 3, 0, 1, 1, 1, 3, 0, 3],
        [2, 2, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1],
        [2, 2, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1],
        [1, 1, 0, 1, 0, 0, 2, 0, 1, 1, 1, 2, 0, 0],
        [1, 1, 0, 1, 3, 0, 2, 0, 1, 1, 1, 2, 0, 3],
    ]

    for icon in input:
        output = merge_segments(icon)
        print(f"{hex(output)},")
