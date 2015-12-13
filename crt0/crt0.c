#include <stdlib.h>
#include <stdio.h>
#include <dayos.h>

extern int main(int argc, char* argv[]);
extern void setup_stack_chk();
extern void InitHeap();
extern void run_constructors();
extern void run_destructors();

FILE* stdin;
FILE* stdout;
FILE* stderr;

// TODO: Parameteruebergabe!
// TODO: libdayos Initialisierung  (Heap etc.)
void _start()
{
	setup_stack_chk();
	InitHeap();
	
	pid_t vfs_service = get_service_pid("vfs");
	// FIXME: Get from kernel somehow!
	if(vfs_service)
	{
		stdin = fopen("/dayos/dev/tty", "r");
		stdout = fopen("/dayos/dev/tty", "w");
		stderr = fopen("/dayos/dev/tty", "w");
	}
	
	run_constructors();
	int retval = main(0, NULL);
	run_destructors();
	
	exit(retval);
}
