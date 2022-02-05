#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  pid_t pid;

  if ((pid = fork()) == 0) {
    if (access("./bin/Release/toaspectratio", F_OK) == 0 && access("./bin/Release/checkaspectratio", F_OK) == 0) {
      close(STDERR_FILENO);
      if (fork() == 0)
        execl("/bin/cp", "cp", "./bin/Release/toaspectratio", "/usr/local/bin/", (char *)NULL);
      else
        execl("/bin/cp", "cp", "./bin/Release/checkaspectratio", "/usr/local/bin/", (char *)NULL);

    } else
      exit(2);
  } else {
    int wstatus;
    wait(&wstatus);

    int ret_status = WEXITSTATUS(wstatus);
    if (ret_status == 1) {
      fprintf(stderr, "ERROR: Try sudo install...\n");
    } else if (ret_status == 2) {
      fprintf(stderr, "ERROR: Couldn't find target file for installation...\n");
    } else if (ret_status == 0) {
      fprintf(stderr, "Installation succesful, checkaspectratio & toaspectratio\n");
    }
  }

  return 0;
}
