# One quick thing Note:

I tried my hardest to learn and use Qt. However, due to the fact I couldnt seem to get `QEventLoops` working (due to the fact GUI applications should run seperate "threadding" I guess and I couldnt use `sleep()` or equivalent to stop execution of a for loop based on signal from `QPushButton`). This prevented me from even beginning to work with a GUI as the program halted before a GUI could appear (due to eventloop).

However, I had already coded the acutal work for a *QtConsoleApplication*. (Thought I'd do what I know/the hard stuff first) then try adapting for the GUI. Nope. Honestly, even if I was given since we started Qt, I don't think I would've fully understood and been able to implement it. 

Why event loops why couldn't they just make for loops simpler. Smh.

## Program Info
Anyways, place the stuff in `/REQUIRED` into where the Tutor progam says (I didnt want to create files onyour machine and QDir only knows generic locations so I used the Build Dir). Once the tutor program is run it will generate a grades.txt (or append to it). This and the questions.qsv must be placed where Supervisor program tells you to *(i.e. its BuildDir)*. 
