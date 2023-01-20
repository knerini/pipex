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

### How test the program  
➢ Mandatory part  
- argument's number : if more or less than 4 arguments the program should redirect an error
