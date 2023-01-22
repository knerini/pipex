# PIPEX
### Learning skills
Pipex is a project learning how to reproduce the pipe ("|") behaviour.  

➢ I've to :  
- dealt with `execve` to execute another program
- learned what are Unix processes and how to handle them with `fork`, `waitpid`
- learned how to redirect stdin/stdout with `pipe`, `dup2`

➢ Here the doc I've used to help me understand and do this project :
- [Unix processes](https://code-vault.net/course/46qpfr4tkz:1603732431896)
- [Pipe: an Inter-Process Communication Method](https://www.codequoi.com/en/pipe-an-inter-process-communication-method/)
- [Creating and Killing Child Processes in C](https://www.codequoi.com/en/creating-and-killing-child-processes-in-c/)
- [Handling a File by its Descriptor in C](https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/)

・∙◦○●○◦•・∙◦○●○◦•・∙◦○●○◦•・∙◦○●○◦•・∙◦○●○◦•・∙◦○●○◦•・∙◦○●○◦•・∙◦○●○◦•・  

### How to execute the program
➢ Mandatory part   
- ./pipex infile cmd1 cmd2 outfile  
- ***infile*** : use as stdin by first command cmd1
- ***outfile*** : use as stdout by second command cmd2
- ***cmd1*** : first command to be executed
- ***cmd2*** : second command to be executed  


➢ Bonus part  
- ./pipex infile cmd1 cmd2 ... cmdn outfile --or-- ./pipex here_doc EOF cmd1 cmd2 ... cmdn outfile
- ***infile*** : use as stdin by first command cmd1
- ***outfile*** : use as stdout by last command cmdn
- ***cmd1*** ... cmdn : all commands to be executed in the order from 1 to n
- ***here_doc EOF*** : reproducing the behaviour of << redirection in bash where EOF is the indicated limiter to specify the end of file to stop the here_doc. When here_doc is specified, the redirection in the outfile behave like the >> redirection in bash  

### How to test the program  
➢ Mandatory part  
- ***argument's number*** : if more or less than 4 arguments, the program should redirect an error  

➢ Bonus part  
- ***argument's number*** : if here_doc and less than 5 arguments or if infile and less than 4 arguments, the program should redirect an error
- ***here_doc*** : test if the here_doc react like bash ; if the limiter is at the beginning, in the middle or at the end of another string, the limiter isn't interpreted like eof and here_doc should continue ; if the limiter is alone on a line, the limiter is interpreted as eof and the here_doc should stop here ; if ctrl+d is sent to here_doc, it should be interpreted like eof and here_doc should stop here
- ***outfile with here_doc*** : the outfile is in append mode, so its previous content should not be erased and the new content should be added after the old content

➢ Both parts  
- ***infile*** : if doesn't exists or no permission allowed the program should redirect same type of error than bash
- ***outfile*** : if already exists with allowed permission, should behave in truncated mode ; if already exists but no permission allowed the program should redirect same type of error than bash ; if not exists, should be created in truncated mode (or append mode if here_doc)
- ***cmd1*** : if command found, should take its input from infile, be executed and its output should be sent to next cmd ; if not found, the programm should redirect the same type of error than bash ; if command found but wrong option, the program should redirect the same type of error than bash
- ***last cmd*** : if command found, should be executed and its output should be sent to outfile ; if not found, the programm should redirect the same type of error than bash ; if command found but wrong option, the program should redirect the same type of error than bash
- if there is a wrong infile/outfile the command related to shouldn't be executed but the others should be
- if there is many wrong commands, all the concerned commands should redirect their error
- if there is a wrong infile/outfile and the command related to is wrong, only the file error should be redirected because the command isn't even executed
- ***command*** : verify the output of all commands is well redirected through pipes until the last command by executing a logical commands' serie like this (for example) : **./pipex Makefile cat "sed s/pipex/WORD/" "grep WORD" outfile**
