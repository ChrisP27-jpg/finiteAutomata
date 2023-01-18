# finiteAutomata

This program creates a finite automata and then tests an input string to see if it would be accepted by the newly created automata. It reads from an input file that contains the blueprint of a finite automata. First, all of the nodes of the automata are created, and then all of the transitions are made. After that, the program goes through the automata with the input string. I've included a few example blueprints, you'll have to find a string that can be accepted.

## Usage

:$ make

:$ ./painter_p1 "input file with blueprint" "input string to test" "number of transitions from the blueprint"
