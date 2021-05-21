# Push_swap_speed_tester - 42Lisbon

To clone with submodules: `git clone --recursive <project url>`

A little program to test different push_swaps with custom stacks

![Screenshot](screenshot.png)

## How to
- Compile the speed_tester with `make`
- Compile and move the push_swap binaries you want to test in `prog_to_test/`
- Add/remove/modify the tests in `tests/`
- Run `./speed_tester`

## Disclaimer
- Only my checker is used for the checks (and it may have bugs)
- If you want to use your checker, do `make` and then replace `checker` binary with your binary
- This program is mainly focused on comparing speeds, better not to rely too much on it for checking your arguments partising
- The program have no timeout to prevent infinite loops in the push_swaps
