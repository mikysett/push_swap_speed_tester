# Push_swap speed_tester

A little program to test different push_swaps with custom stacks

![Screenshot](/06-push_swap/speed_tester/screenshot.png)

## How to
- Compile the speed_tester with `make` rule in `speed_tester/` directory
- Compile and move the push_swap binaries you want to test in `prog_to_test/`
- Add/remove/modify the tests in `tests/`
- Run `./speed_tester`

## Disclaimer
- Only my checker is used for the checks (and it may have bugs)
- If you want to use your checker, do `make` and then replace `push_swap/checker` binary with your binary
- This program is mainly focused on comparing speeds, better not to rely too much on it for checking your arguments partising
- The program have no timeout to prevent infinite loops in the push_swaps
- You may find a little utility in `random_ints/` to generate random stacks. I'm not very satisfied of it and I suggest you to use other solutions instead if you want to generate consistently random stacks