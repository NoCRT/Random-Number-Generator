# random_number_generator
(windows only) Generates a random number in a given range with ugly but functional command line support. If you are going to use it for any length of time i recommend adding it to you path. The required files are included under the "build" folder.

This was created in VSCode insiders with GCC 8.10 x86_64. Although you should be able to easily edit it in any C++ IDE.

Link to random.hpp file repository ->
https://github.com/effolkronium/random

Happy Generating!!

## Command Line Options
#### Fair warning that there is no input validation with the command line options
Options should be input in the following order :

- Key symbol : rng - (this is needed to specify that cmd options are being used)
- Lower bound : this is the lowest number you want generating
- Upper bound : this is the highest number you want generating
- Amount of generations : this is the amount of random numbers you want generated
- Print toggle : this option decides wether the generated numbers are printed to the console
- Numbers per line : this is the amount of numbers you want to be printed per line in the console

### Example
to generate a number between 1 and 10 5 times :
##### rnd - 1 10 5 1 3
told you it was janky!
