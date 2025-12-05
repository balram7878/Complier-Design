

Go to the GitHub page:
-> https://github.com/lexxmark/winflexbison

to run lex file you need to downlaod ->
https://github.com/lexxmark/winflexbison/releases

Download the latest win_flex_bison.zip.

Extract it to a permanent folder, e.g.
C:\Program Files\win_flex_bison

Add that folder to your System PATH:

Search “Edit the system environment variables”

Click “Environment Variables”

Under System variables, find Path, click Edit, then New, and paste:

C:\Program Files

Now open a new terminal (important) and test:

win_flex --version


You should see something like win_flex 2.6.4.

Then, in your commands, just use:

win_flex count.l
g++ lex.yy.c -o count
