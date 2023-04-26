Simple Shell
The Holberton Shell project, developed during the first trimester of Holberton School, aims to help students understand the advanced concepts behind the shell program, including process management, system calls, bit manipulation, file management, and error handling.

Overview
The Holberton Shell covers the following topics:

The creators of the original Unix operating system
The author of the first version of the UNIX shell
The inventor of the B programming language (the direct predecessor to the C programming language)
Who is Ken Thompson
How a shell works
The concepts of pid and ppid
Manipulating the environment of the current process
The differences between a function and a system call
Creating processes
The three prototypes of main
How the shell uses the PATH to find programs
Executing another program with the execve system call
Suspending the execution of a process until one of its children terminates
The concept of EOF / “end-of-file”
Installing HSH
To install the shell and take advantage of its features, clone the current project and compile it. Please ensure the shell is tested and guarantees work based on gcc-4.8 and the C90 standard.

Features

Displays a prompt and waits for the user to enter a command. A command line always ends with a new line.
Prints an error message and displays the prompt again if an executable cannot be found.
Handles errors.
Handles the “end of file” condition (Ctrl+D).
Handles command lines with arguments.
Handles the PATH.
Supports the exit features and the exit status.
Handles Ctrl-C to prevent the shell from terminating.
Handles the command separator ;.
Handles && and || logical operators.
Handles variable replacements $? and $$.
Handles comments with #.
Supports the history feature.
Supports file input.

Built-ins

The exit built-in: exit [STATUS]
The cd built-in: cd [DIRECTORY] | [OPTION]
The env built-in: Displays the environment variables.
The setenv built-in: Initializes new environment variables or creates them if not matched. Usage: setenv [VARIABLE] [VALUE]
The unsetenv built-in: Removes an environment variable. Usage: unsetenv [VARIABLE]
The alias built-in: Supports aliases. Usage: alias [name [='value'] ...]
The help built-in: Displays help. Usage: help [BUILTIN]
The history built-in: Displays the history.
