Chess in C
----------

I started this little project as a learning experience. Much of it has been a
trial and error process and it's by no means a well-polished product.

Currently, this compiles and runs but does not actually play a game of chess. It
draws the board and moves a few pieces, but does not use user input. In addition, it
lacks proper checks in several places to prevent overflows, so entering values
outside the expected range will crash the program. These are known issues and
will be correct as development continues.

When the game is run, the user selects a difficulty level which correlates to
how far ahead the computer is allowed to calculate moves, and the chances it
makes an optimal move. The board is drawn in a terminal and the player makes
moves by entering them using standard chess notation like Nf3 or Bxb5.

INSTALLATION
------------
Once the source code is downloaded, the game may be compiled by running make.
This will build the binary in the same directory as the source files and will
be named 'chess'. From there the game may be started by simply running:
$ ./chess
