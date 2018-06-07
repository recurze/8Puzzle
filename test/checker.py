def slide(state, m):
    state = list(state)
    i = state.index('0')
    if m=='R':
        state[i], state[i-1] = state[i-1], state[i]
    if m=='U':
        state[i], state[i+3] = state[i+3], state[i]
    if m=='D':
        state[i], state[i-3] = state[i-3], state[i]
    if m=='L':
        state[i], state[i+1] = state[i+1], state[i]
    return "".join(state)

state, moves = [str(x) for x in raw_input().split()]
for i in moves:
    state = slide(state, i)
print state == "123456780"
